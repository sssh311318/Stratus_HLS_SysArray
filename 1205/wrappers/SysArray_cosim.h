/****************************************************************************
 *
 *  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
 *
 *  This file contains confidential information that may not be
 *  distributed under any circumstances without the written permision
 *  of Cadence Design Systems.
 *
 ***************************************************************************/

#ifndef _SYSARRAY_COSIM_INCLUDED_
#define _SYSARRAY_COSIM_INCLUDED_

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
struct SysArray_cosim : public xmsc_foreign_module
#else
SC_MODULE(SysArray_cosim)
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
	sc_out< bool > weight_in_vec_busy_0;
	sc_out< bool > weight_in_vec_busy_1;
	sc_out< bool > weight_in_vec_busy_2;
	sc_in< bool > weight_in_vec_vld_0;
	sc_in< bool > weight_in_vec_vld_1;
	sc_in< bool > weight_in_vec_vld_2;
	sc_in< sc_uint< 8 > > weight_in_vec_data_0;
	sc_in< sc_uint< 8 > > weight_in_vec_data_1;
	sc_in< sc_uint< 8 > > weight_in_vec_data_2;
	sc_out< bool > act_in_vec_busy_0;
	sc_out< bool > act_in_vec_busy_1;
	sc_out< bool > act_in_vec_busy_2;
	sc_in< bool > act_in_vec_vld_0;
	sc_in< bool > act_in_vec_vld_1;
	sc_in< bool > act_in_vec_vld_2;
	sc_in< sc_uint< 8 > > act_in_vec_data_0;
	sc_in< sc_uint< 8 > > act_in_vec_data_1;
	sc_in< sc_uint< 8 > > act_in_vec_data_2;
	sc_out< bool > accum_in_vec_busy_0;
	sc_out< bool > accum_in_vec_busy_1;
	sc_out< bool > accum_in_vec_busy_2;
	sc_in< bool > accum_in_vec_vld_0;
	sc_in< bool > accum_in_vec_vld_1;
	sc_in< bool > accum_in_vec_vld_2;
	sc_in< sc_uint< 32 > > accum_in_vec_data_0;
	sc_in< sc_uint< 32 > > accum_in_vec_data_1;
	sc_in< sc_uint< 32 > > accum_in_vec_data_2;
	sc_in< bool > accum_out_vec_busy_0;
	sc_in< bool > accum_out_vec_busy_1;
	sc_in< bool > accum_out_vec_busy_2;
	sc_out< bool > accum_out_vec_vld_0;
	sc_out< bool > accum_out_vec_vld_1;
	sc_out< bool > accum_out_vec_vld_2;
	sc_out< sc_uint< 32 > > accum_out_vec_data_0;
	sc_out< sc_uint< 32 > > accum_out_vec_data_1;
	sc_out< sc_uint< 32 > > accum_out_vec_data_2;
	sc_out< bool > weight_inter_busy_0;
	sc_out< bool > weight_inter_busy_1;
	sc_out< bool > weight_inter_busy_2;
	sc_in< bool > weight_inter_vld_0;
	sc_in< bool > weight_inter_vld_1;
	sc_in< bool > weight_inter_vld_2;
	sc_in< sc_uint< 8 > > weight_inter_data_0;
	sc_in< sc_uint< 8 > > weight_inter_data_1;
	sc_in< sc_uint< 8 > > weight_inter_data_2;
	sc_out< bool > act_inter_busy_0;
	sc_out< bool > act_inter_busy_1;
	sc_out< bool > act_inter_busy_2;
	sc_in< bool > act_inter_vld_0;
	sc_in< bool > act_inter_vld_1;
	sc_in< bool > act_inter_vld_2;
	sc_in< sc_uint< 8 > > act_inter_data_0;
	sc_in< sc_uint< 8 > > act_inter_data_1;
	sc_in< sc_uint< 8 > > act_inter_data_2;

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
					"More than one instance of module SysArray is being simulated in Verilog,\n"
					"but no instance names have been specified in simConfig %s.\n"
					"Additional instances can be specified using the following syntax:\n\n"
					"    simConfig <config_name> { <module> RTL_V <config> <inst1> <inst2> ...}\n\n"
					"where <inst1> and <inst2> are the leaf names of instances of SysArray in SystemC\n", 
					scName );
				return;
			} else {
				s << "SysArray0" << std::ends;
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
								  "More than %d instance(s) of module SysArray are being simulated in Verilog,\n"
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

		esc_link_signals( &rst, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_in_vec_busy_0, module_path, sim_domain, true );
		esc_link_signals( &weight_in_vec_busy_1, module_path, sim_domain, true );
		esc_link_signals( &weight_in_vec_busy_2, module_path, sim_domain, true );
		esc_link_signals( &weight_in_vec_vld_0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_in_vec_vld_1, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_in_vec_vld_2, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_in_vec_data_0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_in_vec_data_1, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_in_vec_data_2, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_in_vec_busy_0, module_path, sim_domain, true );
		esc_link_signals( &act_in_vec_busy_1, module_path, sim_domain, true );
		esc_link_signals( &act_in_vec_busy_2, module_path, sim_domain, true );
		esc_link_signals( &act_in_vec_vld_0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_in_vec_vld_1, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_in_vec_vld_2, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_in_vec_data_0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_in_vec_data_1, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_in_vec_data_2, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_in_vec_busy_0, module_path, sim_domain, true );
		esc_link_signals( &accum_in_vec_busy_1, module_path, sim_domain, true );
		esc_link_signals( &accum_in_vec_busy_2, module_path, sim_domain, true );
		esc_link_signals( &accum_in_vec_vld_0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_in_vec_vld_1, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_in_vec_vld_2, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_in_vec_data_0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_in_vec_data_1, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_in_vec_data_2, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_out_vec_busy_0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_out_vec_busy_1, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_out_vec_busy_2, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &accum_out_vec_vld_0, module_path, sim_domain, true );
		esc_link_signals( &accum_out_vec_vld_1, module_path, sim_domain, true );
		esc_link_signals( &accum_out_vec_vld_2, module_path, sim_domain, true );
		esc_link_signals( &accum_out_vec_data_0, module_path, sim_domain, true );
		esc_link_signals( &accum_out_vec_data_1, module_path, sim_domain, true );
		esc_link_signals( &accum_out_vec_data_2, module_path, sim_domain, true );
		esc_link_signals( &weight_inter_busy_0, module_path, sim_domain, true );
		esc_link_signals( &weight_inter_busy_1, module_path, sim_domain, true );
		esc_link_signals( &weight_inter_busy_2, module_path, sim_domain, true );
		esc_link_signals( &weight_inter_vld_0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_inter_vld_1, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_inter_vld_2, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_inter_data_0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_inter_data_1, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &weight_inter_data_2, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_inter_busy_0, module_path, sim_domain, true );
		esc_link_signals( &act_inter_busy_1, module_path, sim_domain, true );
		esc_link_signals( &act_inter_busy_2, module_path, sim_domain, true );
		esc_link_signals( &act_inter_vld_0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_inter_vld_1, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_inter_vld_2, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_inter_data_0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_inter_data_1, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &act_inter_data_2, module_path, sim_domain, true, inputDelay );
		

		if ( clk_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = clk[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, clk.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "SysArray", "clk", scName ) ) {
			esc_report_error( esc_error, "The port 'clk' on module 'SysArray'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( rst_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = rst[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, rst.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "SysArray", "rst", scName ) ) {
			esc_report_error( esc_error, "The port 'rst' on module 'SysArray'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}


        if ( registeredClocks == 0 )
		{
			esc_report_error( esc_fatal, 
				"The clock port in module SysArray must have\n"
				"an sc_clock bound to it to make cosimulation work" );
		}
#endif
    }

#if defined(XM_SYSTEMC) || defined(NC_SYSTEMC)
    const char* hdl_name() const 
    {
        if ( getenv("BDW_NO_NCWRAPPER") )
        {
            return "SysArray"; 
        }
        else
        {
            return "SysArray_nc_cosim"; 
        }
    } 
    SysArray_cosim( sc_module_name name )
        : xmsc_foreign_module(name)
#else
	SysArray_cosim( sc_module_name in_name=sc_module_name(sc_gen_unique_name(" SysArray") ) )
		: sc_module(in_name)
#endif
		  ,clk("clk")
		  	,rst("rst")
		  	,weight_in_vec_busy_0("weight_in_vec_busy_0")
		  	,weight_in_vec_busy_1("weight_in_vec_busy_1")
		  	,weight_in_vec_busy_2("weight_in_vec_busy_2")
		  	,weight_in_vec_vld_0("weight_in_vec_vld_0")
		  	,weight_in_vec_vld_1("weight_in_vec_vld_1")
		  	,weight_in_vec_vld_2("weight_in_vec_vld_2")
		  	,weight_in_vec_data_0("weight_in_vec_data_0")
		  	,weight_in_vec_data_1("weight_in_vec_data_1")
		  	,weight_in_vec_data_2("weight_in_vec_data_2")
		  	,act_in_vec_busy_0("act_in_vec_busy_0")
		  	,act_in_vec_busy_1("act_in_vec_busy_1")
		  	,act_in_vec_busy_2("act_in_vec_busy_2")
		  	,act_in_vec_vld_0("act_in_vec_vld_0")
		  	,act_in_vec_vld_1("act_in_vec_vld_1")
		  	,act_in_vec_vld_2("act_in_vec_vld_2")
		  	,act_in_vec_data_0("act_in_vec_data_0")
		  	,act_in_vec_data_1("act_in_vec_data_1")
		  	,act_in_vec_data_2("act_in_vec_data_2")
		  	,accum_in_vec_busy_0("accum_in_vec_busy_0")
		  	,accum_in_vec_busy_1("accum_in_vec_busy_1")
		  	,accum_in_vec_busy_2("accum_in_vec_busy_2")
		  	,accum_in_vec_vld_0("accum_in_vec_vld_0")
		  	,accum_in_vec_vld_1("accum_in_vec_vld_1")
		  	,accum_in_vec_vld_2("accum_in_vec_vld_2")
		  	,accum_in_vec_data_0("accum_in_vec_data_0")
		  	,accum_in_vec_data_1("accum_in_vec_data_1")
		  	,accum_in_vec_data_2("accum_in_vec_data_2")
		  	,accum_out_vec_busy_0("accum_out_vec_busy_0")
		  	,accum_out_vec_busy_1("accum_out_vec_busy_1")
		  	,accum_out_vec_busy_2("accum_out_vec_busy_2")
		  	,accum_out_vec_vld_0("accum_out_vec_vld_0")
		  	,accum_out_vec_vld_1("accum_out_vec_vld_1")
		  	,accum_out_vec_vld_2("accum_out_vec_vld_2")
		  	,accum_out_vec_data_0("accum_out_vec_data_0")
		  	,accum_out_vec_data_1("accum_out_vec_data_1")
		  	,accum_out_vec_data_2("accum_out_vec_data_2")
		  	,weight_inter_busy_0("weight_inter_busy_0")
		  	,weight_inter_busy_1("weight_inter_busy_1")
		  	,weight_inter_busy_2("weight_inter_busy_2")
		  	,weight_inter_vld_0("weight_inter_vld_0")
		  	,weight_inter_vld_1("weight_inter_vld_1")
		  	,weight_inter_vld_2("weight_inter_vld_2")
		  	,weight_inter_data_0("weight_inter_data_0")
		  	,weight_inter_data_1("weight_inter_data_1")
		  	,weight_inter_data_2("weight_inter_data_2")
		  	,act_inter_busy_0("act_inter_busy_0")
		  	,act_inter_busy_1("act_inter_busy_1")
		  	,act_inter_busy_2("act_inter_busy_2")
		  	,act_inter_vld_0("act_inter_vld_0")
		  	,act_inter_vld_1("act_inter_vld_1")
		  	,act_inter_vld_2("act_inter_vld_2")
		  	,act_inter_data_0("act_inter_data_0")
		  	,act_inter_data_1("act_inter_data_1")
		  	,act_inter_data_2("act_inter_data_2")
		  	

    {
    };
};

int SysArray_cosim::numLinked = 0;
SysArray_cosim::StringPair SysArray_cosim::instanceNames[] = {
	{ NULL, NULL, false } };

#endif
