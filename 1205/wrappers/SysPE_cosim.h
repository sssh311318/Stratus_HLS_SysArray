/****************************************************************************
 *
 *  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
 *
 *  This file contains confidential information that may not be
 *  distributed under any circumstances without the written permision
 *  of Cadence Design Systems.
 *
 ***************************************************************************/

#ifndef _SYSPE_COSIM_INCLUDED_
#define _SYSPE_COSIM_INCLUDED_

#include "systemc.h"
#include "cynthhl.h"
#include "esc.h"
#if __GNUC__ < 3
#include <ostream.h>
#else
#include <ostream>

#endif

#if !defined(XM_SYSTEMC) && defined(NC_SYSTEMC)
#define xmsc_foreign_module ncsc_foreign_module
#endif

#if defined(XM_SYSTEMC) || defined(NC_SYSTEMC)
struct SysPE_cosim : public xmsc_foreign_module
#else
SC_MODULE(SysPE_cosim)
#endif
{
	struct StringPair {
		const char* simConfigName;
		const char* instanceName;
		bool linked;
	};

	// Instance number used during elaboration-time SystemC-to-HDL signal linkage.
	static int numLinked;
	static StringPair instanceNames[];

	static int numInstanceNames( const char* simConfigName ) {
		int nin = 0;
		for ( int i = 0; instanceNames[i].simConfigName != NULL; ++i )
			if ( strcmp( instanceNames[i].simConfigName, simConfigName ) == 0 )
				++nin;
		return nin;
	}

	// Port declarations.
	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > weight_in_busy;
	sc_in< bool > weight_in_vld;
	sc_in< sc_uint< 8 > > weight_in_data;
	sc_out< bool > act_in_busy;
	sc_in< bool > act_in_vld;
	sc_in< sc_uint< 8 > > act_in_data;
	sc_out< bool > accum_in_busy;
	sc_in< bool > accum_in_vld;
	sc_in< sc_uint< 32 > > accum_in_data;
	sc_in< bool > weight_out_busy;
	sc_out< bool > weight_out_vld;
	sc_out< sc_uint< 8 > > weight_out_data;
	sc_in< bool > act_out_busy;
	sc_out< bool > act_out_vld;
	sc_out< sc_uint< 8 > > act_out_data;
	sc_in< bool > accum_out_busy;
	sc_out< bool > accum_out_vld;
	sc_out< sc_uint< 32 > > accum_out_data;

    void end_of_elaboration()
    {
#if __GNUC__ < 3
		strstream s;
#else
		std::ostringstream s;
#endif


		s << "top/";

		const char* scName = getenv("BDW_SIM_CONFIG");
		if (!scName) 
			scName = "?";

		int nin = numInstanceNames(scName);
		if ( nin == 0 )
		{
			if ( numLinked > 0 ) 
			{
				esc_report_error( esc_fatal, 
					"More than one instance of module SysPE is being simulated in Verilog,\n"
					"but no instance names have been specified in simConfig %s.\n"
					"Additional instances can be specified using the following syntax:\n\n"
					"    simConfig <config_name> { <module> RTL_V <config> <inst1> <inst2> ...}\n\n"
					"where <inst1> and <inst2> are the leaf names of instances of SysPE in SystemC\n", 
					scName );
				return;
			} else {
				s << "SysPE0" << std::ends;
			}
		}
		else
		{
			StringPair *instPair = &instanceNames[ numLinked ];
			while ( instPair->instanceName != NULL )
			{
				if ( ( ! instPair->linked )
					 && ( ! strcmp( instPair->simConfigName, scName ) ) )
				{
					const char *instName = instPair->instanceName;

					// Hierarchical SystemC instance names must be escaped for Verilog.
					if ( strchr( instName, '.' ) != NULL )
						s << '\\' << instName << ' ' << std::ends;
					else
						s << instName << std::ends;

					instPair->linked = true;
					break;
				}

				++instPair;
			}

			if ( instPair->instanceName == NULL )
			{
				esc_report_error( esc_fatal, 
								  "More than %d instance(s) of module SysPE are being simulated in Verilog,\n"
								  "but only %d instance name(s) have been specified in simConfig %s.\n",
								  nin, nin, scName );
				return;
			}
		}
		numLinked++;


#if __GNUC__ < 3
		char *c = s.str();
#else
		char *c = (char *)strdup( s.str().c_str() );
#endif

        link_signals(c, "verilog");
#if __GNUC__ < 3
		delete c;
#else
		free( c );
#endif
    }

    void link_signals(const char *module_path, const char *sim_domain)
    {
#if !defined(XM_SYSTEMC) && !defined(NC_SYSTEMC)
        int registeredClocks = 0;

		double inputDelay = 0.0;
		const char* scName = getenv("BDW_SIM_CONFIG");
		if (!scName) scName = "?";
		if ( qbhVerilogInputDelay( qbhEmptyHandle, scName, &inputDelay ) != qbhOK )
			inputDelay = 0.0;

		// Try to register the boolean input ports as clocks.
		int clk_is_clock = esc_link_clockgen( &clk, sc_time( 0, SC_NS ), module_path, sim_domain, "clk" );
		int rst_is_clock = esc_link_clockgen( &rst, sc_time( 0, SC_NS ), module_path, sim_domain, "rst" );
		int weight_in_vld_is_clock = esc_link_clockgen( &weight_in_vld, sc_time( 0, SC_NS ), module_path, sim_domain, "weight_in_vld" );
		int act_in_vld_is_clock = esc_link_clockgen( &act_in_vld, sc_time( 0, SC_NS ), module_path, sim_domain, "act_in_vld" );
		int accum_in_vld_is_clock = esc_link_clockgen( &accum_in_vld, sc_time( 0, SC_NS ), module_path, sim_domain, "accum_in_vld" );
		int weight_out_busy_is_clock = esc_link_clockgen( &weight_out_busy, sc_time( 0, SC_NS ), module_path, sim_domain, "weight_out_busy" );
		int act_out_busy_is_clock = esc_link_clockgen( &act_out_busy, sc_time( 0, SC_NS ), module_path, sim_domain, "act_out_busy" );
		int accum_out_busy_is_clock = esc_link_clockgen( &accum_out_busy, sc_time( 0, SC_NS ), module_path, sim_domain, "accum_out_busy" );

		esc_link_signals( &rst, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_in_busy, module_path, sim_domain, true );
		esc_link_signals( &weight_in_vld, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_in_data, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_in_busy, module_path, sim_domain, true );
		esc_link_signals( &act_in_vld, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_in_data, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_in_busy, module_path, sim_domain, true );
		esc_link_signals( &accum_in_vld, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_in_data, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_out_busy, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_out_vld, module_path, sim_domain, true );
		esc_link_signals( &weight_out_data, module_path, sim_domain, true );
		esc_link_signals( &act_out_busy, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_out_vld, module_path, sim_domain, true );
		esc_link_signals( &act_out_data, module_path, sim_domain, true );
		esc_link_signals( &accum_out_busy, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_out_vld, module_path, sim_domain, true );
		esc_link_signals( &accum_out_data, module_path, sim_domain, true );
		

		if ( clk_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = clk[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, clk.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "SysPE", "clk", scName ) ) {
			esc_report_error( esc_error, "The port 'clk' on module 'SysPE'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( rst_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = rst[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, rst.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "SysPE", "rst", scName ) ) {
			esc_report_error( esc_error, "The port 'rst' on module 'SysPE'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( weight_in_vld_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = weight_in_vld[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, weight_in_vld.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "SysPE", "vld", scName ) ) {
			esc_report_error( esc_error, "The port 'vld' on module 'SysPE'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( act_in_vld_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = act_in_vld[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, act_in_vld.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "SysPE", "vld", scName ) ) {
			esc_report_error( esc_error, "The port 'vld' on module 'SysPE'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( accum_in_vld_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = accum_in_vld[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, accum_in_vld.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "SysPE", "vld", scName ) ) {
			esc_report_error( esc_error, "The port 'vld' on module 'SysPE'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( weight_out_busy_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = weight_out_busy[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, weight_out_busy.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "SysPE", "busy", scName ) ) {
			esc_report_error( esc_error, "The port 'busy' on module 'SysPE'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( act_out_busy_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = act_out_busy[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, act_out_busy.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "SysPE", "busy", scName ) ) {
			esc_report_error( esc_error, "The port 'busy' on module 'SysPE'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( accum_out_busy_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = accum_out_busy[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, accum_out_busy.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "SysPE", "busy", scName ) ) {
			esc_report_error( esc_error, "The port 'busy' on module 'SysPE'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}


        if ( registeredClocks == 0 )
		{
			esc_report_error( esc_fatal, 
				"The clock port in module SysPE must have\n"
				"an sc_clock bound to it to make cosimulation work" );
		}
#endif
    }

#if defined(XM_SYSTEMC) || defined(NC_SYSTEMC)
    const char* hdl_name() const 
    {
        if ( getenv("BDW_NO_NCWRAPPER") )
        {
            return "SysPE"; 
        }
        else
        {
            return "SysPE_nc_cosim"; 
        }
    } 
    SysPE_cosim( sc_module_name name )
        : xmsc_foreign_module(name)
#else
	SysPE_cosim( sc_module_name in_name=sc_module_name(sc_gen_unique_name(" SysPE") ) )
		: sc_module(in_name)
#endif
		  ,clk("clk")
		  	,rst("rst")
		  	,weight_in_busy("weight_in_busy")
		  	,weight_in_vld("weight_in_vld")
		  	,weight_in_data("weight_in_data")
		  	,act_in_busy("act_in_busy")
		  	,act_in_vld("act_in_vld")
		  	,act_in_data("act_in_data")
		  	,accum_in_busy("accum_in_busy")
		  	,accum_in_vld("accum_in_vld")
		  	,accum_in_data("accum_in_data")
		  	,weight_out_busy("weight_out_busy")
		  	,weight_out_vld("weight_out_vld")
		  	,weight_out_data("weight_out_data")
		  	,act_out_busy("act_out_busy")
		  	,act_out_vld("act_out_vld")
		  	,act_out_data("act_out_data")
		  	,accum_out_busy("accum_out_busy")
		  	,accum_out_vld("accum_out_vld")
		  	,accum_out_data("accum_out_data")
		  	

    {
    };
};

int SysPE_cosim::numLinked = 0;
SysPE_cosim::StringPair SysPE_cosim::instanceNames[] = {
	{ NULL, NULL, false } };

#endif
