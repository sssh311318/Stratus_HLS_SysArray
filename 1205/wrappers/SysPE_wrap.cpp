/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/
/****************************************************************************
*
* This file is used to wrap the three different versions of the DUT
* block called "SysPE". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/

#if defined(STRATUS_VLG)


#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#include	"SysPE_rtl.cpp"

#else 

#if defined(BDW_HUB)

#define SC_INCLUDE_DYNAMIC_PROCESSES 1
#include "esc.h"

#if defined(BDW_RTL)

#define BDW_AUTO_KNOWN 1 


#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#undef SysPE
#define SysPE SysPE_rtl
#	include	"SysPE_rtl.cpp"
#undef SysPE


#ifdef BDW_PORTS_ONLY
#undef BDW_PORTS_ONLY
#endif



#elif defined(BDW_HOIST) 
#else

#endif

#include	"SysPE_cosim.h"




// Include the source for the behavioral model so it will be compiled.
#include	"/users/student/mr112/czwu23/JJLAB/SystolicArray/1205/SysPE/SysPE.cpp"


#define		SysPE_INTERNAL


#include	"SysPE_wrap.h"


#define MAX_SIMCONFIG_LENGTH 128

#if BDW_WRITEFSDB == 1

#if (defined(XM_SYSTEMC) || defined(NC_SYSTEMC)) && defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102
#include "fsdb_nc_mix.h"
#else
#if SYSTEMC_VERSION >= 20120701
#include "fsdb_osci.h"
#else
#include "fsdb_trace_file.h"
#endif
#endif 
#if BDW_USE_SCV
#include "scv.h"
#include "scv_tr_fsdb.h"
#endif

#endif /* BDW_WRITEFSDB */

inline void esc_open_fsdb_trace( const char *file_name = "systemc" );
inline void esc_close_fsdb_trace();
inline void esc_close_fsdb_scv_trace();

// The following threads are used to connect structured ports to the actual
// RTL ports

const char * SysPE_wrapper::simConfigName()
{
	static char defineBuf[MAX_SIMCONFIG_LENGTH];
	const char *simConfig = NULL;
	if ( qbhGetDefine( "BDW_SIM_CONFIG", defineBuf, MAX_SIMCONFIG_LENGTH ) == qbhOK )
	{
		simConfig = defineBuf;
	}
	else
	{
		simConfig = getenv( "BDW_SIM_CONFIG" );
	}

	if ( simConfig == NULL )
	{
		esc_report_error( esc_fatal, "BDW_SIM_CONFIG needs to be set" );
	}

	return simConfig;
}

enum SysPE_wrapper::Representation SysPE_wrapper::lookupRepresentation( const char* instName )
{
	const char *simConfig = simConfigName();

	if ( simConfig == NULL )
		return BDWRep_None;

	Representation result;

	qbhProjectHandle hProj;
	qbhError err = qbhGetCurrentProject( &hProj );
	if ( err == qbhErrorNoProject )
	{
		err = qbhOpenProject( "project.tcl", &hProj );

		if ( err != qbhOK )
		{
			esc_report_error( esc_fatal, "could not open project file %s",
							  "project.tcl" );
			return BDWRep_None;
		}
	}

	int iresult = 0;
	err = qbhGetRepresentation(hProj, "SysPE", simConfig, instName, &iresult );
	result = (Representation)iresult;

	if ( err == qbhOK )
		return result;

	// If this module isn't mentioned in the simConfig, assume it's behavioral.
	if ( err == qbhErrorNotFound ) {
		return BDWRep_Behavioral;
	} else if ( err == qbhErrorBadInstName ) {
		if (instName && *instName) {
			const char* leaf = strrchr( instName, '.' ) + 1;
			esc_report_error( esc_warning, "Instance names were specified for module '%s' in simConfig '%s', but they did not "
			                    "match the actal instance names in the RTL.  Try '%s' or '%s'. Simulating '%s' as BEH.\n",
								 "SysPE", simConfig, instName, leaf,  "SysPE" );
		}
		return BDWRep_Behavioral;
	}

    // If we couldn't get a license, then just exit.
    if ( err == qbhErrorNoLicense )
    {
        exit(1);
    }

	return BDWRep_None;
}

void SysPE_wrapper::InitInstances(  )
{
    enum SysPE_wrapper::Representation rep =
		SysPE_wrapper::lookupRepresentation( name() );

	esc_log_wrapper_inst( "SysPE" );
	esc_log_representation( "SysPE", name(), rep );

	

	switch ( rep )
	{
		case BDWRep_Gates:
		    SysPE_cosim0 = new SysPE_cosim( "SysPE" );

		    SysPE_cosim0->clk(clk);
		    SysPE_cosim0->rst(rst);
		    SysPE_cosim0->weight_in_busy(weight_in.busy);
		    SysPE_cosim0->weight_in_vld(weight_in.vld);
		    SysPE_cosim0->weight_in_data(weight_in.data);
		    SysPE_cosim0->act_in_busy(act_in.busy);
		    SysPE_cosim0->act_in_vld(act_in.vld);
		    SysPE_cosim0->act_in_data(act_in.data);
		    SysPE_cosim0->accum_in_busy(accum_in.busy);
		    SysPE_cosim0->accum_in_vld(accum_in.vld);
		    SysPE_cosim0->accum_in_data(accum_in.data);
		    SysPE_cosim0->weight_out_busy(weight_out.busy);
		    SysPE_cosim0->weight_out_vld(weight_out.vld);
		    SysPE_cosim0->weight_out_data(weight_out.data);
		    SysPE_cosim0->act_out_busy(act_out.busy);
		    SysPE_cosim0->act_out_vld(act_out.vld);
		    SysPE_cosim0->act_out_data(act_out.data);
		    SysPE_cosim0->accum_out_busy(accum_out.busy);
		    SysPE_cosim0->accum_out_vld(accum_out.vld);
		    SysPE_cosim0->accum_out_data(accum_out.data);

			break;
		case BDWRep_RTL_HDL:
		    SysPE_cosim0 = new SysPE_cosim( "SysPE" );

		    SysPE_cosim0->clk(clk);
		    SysPE_cosim0->rst(rst);
		    SysPE_cosim0->weight_in_busy(weight_in.busy);
		    SysPE_cosim0->weight_in_vld(weight_in.vld);
		    SysPE_cosim0->weight_in_data(weight_in.data);
		    SysPE_cosim0->act_in_busy(act_in.busy);
		    SysPE_cosim0->act_in_vld(act_in.vld);
		    SysPE_cosim0->act_in_data(act_in.data);
		    SysPE_cosim0->accum_in_busy(accum_in.busy);
		    SysPE_cosim0->accum_in_vld(accum_in.vld);
		    SysPE_cosim0->accum_in_data(accum_in.data);
		    SysPE_cosim0->weight_out_busy(weight_out.busy);
		    SysPE_cosim0->weight_out_vld(weight_out.vld);
		    SysPE_cosim0->weight_out_data(weight_out.data);
		    SysPE_cosim0->act_out_busy(act_out.busy);
		    SysPE_cosim0->act_out_vld(act_out.vld);
		    SysPE_cosim0->act_out_data(act_out.data);
		    SysPE_cosim0->accum_out_busy(accum_out.busy);
		    SysPE_cosim0->accum_out_vld(accum_out.vld);
		    SysPE_cosim0->accum_out_data(accum_out.data);

			break;
#if defined(BDW_RTL)
		case BDWRep_RTL_C:
		    SysPE_rtl0 = new SysPE_rtl( "SysPE" );

		    SysPE_rtl0->clk(clk);
		    SysPE_rtl0->rst(rst);
		    SysPE_rtl0->weight_in_busy(weight_in.busy);
		    SysPE_rtl0->weight_in_vld(weight_in.vld);
		    SysPE_rtl0->weight_in_data(weight_in.data);
		    SysPE_rtl0->act_in_busy(act_in.busy);
		    SysPE_rtl0->act_in_vld(act_in.vld);
		    SysPE_rtl0->act_in_data(act_in.data);
		    SysPE_rtl0->accum_in_busy(accum_in.busy);
		    SysPE_rtl0->accum_in_vld(accum_in.vld);
		    SysPE_rtl0->accum_in_data(accum_in.data);
		    SysPE_rtl0->weight_out_busy(weight_out.busy);
		    SysPE_rtl0->weight_out_vld(weight_out.vld);
		    SysPE_rtl0->weight_out_data(weight_out.data);
		    SysPE_rtl0->act_out_busy(act_out.busy);
		    SysPE_rtl0->act_out_vld(act_out.vld);
		    SysPE_rtl0->act_out_data(act_out.data);
		    SysPE_rtl0->accum_out_busy(accum_out.busy);
		    SysPE_rtl0->accum_out_vld(accum_out.vld);
		    SysPE_rtl0->accum_out_data(accum_out.data);


			{
			const char *simConfig = SysPE_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
						                                          "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
#endif
		case BDWRep_Behavioral:
		    SysPE0 = new SysPE( "SysPE" );

		    SysPE0->clk(clk);
		    SysPE0->rst(rst);
		    SysPE0->weight_in.busy(weight_in.busy);
		    SysPE0->weight_in.vld(weight_in.vld);
		    SysPE0->weight_in.data(weight_in.data);
		    SysPE0->act_in.busy(act_in.busy);
		    SysPE0->act_in.vld(act_in.vld);
		    SysPE0->act_in.data(act_in.data);
		    SysPE0->accum_in.busy(accum_in.busy);
		    SysPE0->accum_in.vld(accum_in.vld);
		    SysPE0->accum_in.data(accum_in.data);
		    SysPE0->weight_out.busy(weight_out.busy);
		    SysPE0->weight_out.vld(weight_out.vld);
		    SysPE0->weight_out.data(weight_out.data);
		    SysPE0->act_out.busy(act_out.busy);
		    SysPE0->act_out.vld(act_out.vld);
		    SysPE0->act_out.data(act_out.data);
		    SysPE0->accum_out.busy(accum_out.busy);
		    SysPE0->accum_out.vld(accum_out.vld);
		    SysPE0->accum_out.data(accum_out.data);


			{
			const char *simConfig = SysPE_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
						                                          "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
		case BDWRep_None:
		default:
			esc_report_error( esc_error, "No representation could be determined for simulating instance %s. Please make sure that you used the right name string in the module constructor",
							  name() );
			break;
	}
}

void SysPE_wrapper::InitThreads()
{
	if ( !isBEH() )
	{
		
	}
}

void SysPE_wrapper::start_of_simulation()
{

#include <SysPE_trace.h>

        esc_multiple_writers_warning();
}

void SysPE_wrapper::CloseTrace()
{
	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
	esc_close_vcd_trace();
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		esc_close_fsdb_trace();
		if ( esc_trace_is_enabled( esc_trace_scv ) ) {
			esc_close_fsdb_scv_trace();
		}
	}
}

void SysPE_wrapper::end_of_simulation()
{
      CloseTrace();
}



void SysPE_wrapper::DeleteInstances()
{
    if (SysPE0)
    {
        delete SysPE0;
        SysPE0 = 0;
    }
    if (SysPE_cosim0)
    {
        delete SysPE_cosim0;
        SysPE_cosim0 = 0;
    }
  #if defined(BDW_RTL)
    if (SysPE_rtl0)
    {
        delete SysPE_rtl0;
        SysPE_rtl0 = 0;
    }
#endif
}

// The following threads are used to connect RTL ports to the actual
// structured ports

const char * SysPE_wrapper_r::simConfigName()
{
	static char defineBuf[MAX_SIMCONFIG_LENGTH];
	const char *simConfig = NULL;
	if ( qbhGetDefine( "BDW_SIM_CONFIG", defineBuf, MAX_SIMCONFIG_LENGTH ) == qbhOK )
	{
		simConfig = defineBuf;
	}
	else
	{
		simConfig = getenv( "BDW_SIM_CONFIG" );
	}

	if ( simConfig == NULL )
	{
		esc_report_error( esc_fatal, "BDW_SIM_CONFIG needs to be set" );
	}

	return simConfig;
}

enum SysPE_wrapper_r::Representation SysPE_wrapper_r::lookupRepresentation( const char* instName )
{
	const char *simConfig = simConfigName();

	if ( simConfig == NULL )
		return BDWRep_None;

	Representation result;

	qbhProjectHandle hProj;
	qbhError err = qbhGetCurrentProject( &hProj );
	if ( err == qbhErrorNoProject )
	{
		err = qbhOpenProject( "project.tcl", &hProj );

		if ( err != qbhOK )
		{
			esc_report_error( esc_fatal, "could not open project file %s",
							  "project.tcl" );
			return BDWRep_None;
		}
	}

	int iresult = 0;
	err = qbhGetRepresentation(hProj, "SysPE", simConfig, instName, &iresult );
	result = (Representation)iresult;

	if ( err == qbhOK )
		return result;

	// If this module isn't mentioned in the simConfig, assume it's behavioral.
	if ( err == qbhErrorNotFound )
		return BDWRep_Behavioral;

    // If we couldn't get a license, then just exit.
    if ( err == qbhErrorNoLicense )
    {
        exit(1);
    }

	return BDWRep_None;
}

void SysPE_wrapper_r::InitInstances()
{
    enum SysPE_wrapper_r::Representation rep =
		SysPE_wrapper_r::lookupRepresentation( name() );

	esc_log_wrapper_inst( "SysPE" );
	esc_log_representation( "SysPE", name(), rep );

	switch ( rep )
	{
		case BDWRep_Gates:
		    SysPE_cosim0 = new SysPE_cosim( "SysPE" );

		    SysPE_cosim0->clk(clk);
		    SysPE_cosim0->rst(rst);
		    SysPE_cosim0->weight_in_busy(weight_in_busy);
		    SysPE_cosim0->weight_in_vld(weight_in_vld);
		    SysPE_cosim0->weight_in_data(weight_in_data);
		    SysPE_cosim0->act_in_busy(act_in_busy);
		    SysPE_cosim0->act_in_vld(act_in_vld);
		    SysPE_cosim0->act_in_data(act_in_data);
		    SysPE_cosim0->accum_in_busy(accum_in_busy);
		    SysPE_cosim0->accum_in_vld(accum_in_vld);
		    SysPE_cosim0->accum_in_data(accum_in_data);
		    SysPE_cosim0->weight_out_busy(weight_out_busy);
		    SysPE_cosim0->weight_out_vld(weight_out_vld);
		    SysPE_cosim0->weight_out_data(weight_out_data);
		    SysPE_cosim0->act_out_busy(act_out_busy);
		    SysPE_cosim0->act_out_vld(act_out_vld);
		    SysPE_cosim0->act_out_data(act_out_data);
		    SysPE_cosim0->accum_out_busy(accum_out_busy);
		    SysPE_cosim0->accum_out_vld(accum_out_vld);
		    SysPE_cosim0->accum_out_data(accum_out_data);

			break;
		case BDWRep_RTL_HDL:
		    SysPE_cosim0 = new SysPE_cosim( "SysPE" );

		    SysPE_cosim0->clk(clk);
		    SysPE_cosim0->rst(rst);
		    SysPE_cosim0->weight_in_busy(weight_in_busy);
		    SysPE_cosim0->weight_in_vld(weight_in_vld);
		    SysPE_cosim0->weight_in_data(weight_in_data);
		    SysPE_cosim0->act_in_busy(act_in_busy);
		    SysPE_cosim0->act_in_vld(act_in_vld);
		    SysPE_cosim0->act_in_data(act_in_data);
		    SysPE_cosim0->accum_in_busy(accum_in_busy);
		    SysPE_cosim0->accum_in_vld(accum_in_vld);
		    SysPE_cosim0->accum_in_data(accum_in_data);
		    SysPE_cosim0->weight_out_busy(weight_out_busy);
		    SysPE_cosim0->weight_out_vld(weight_out_vld);
		    SysPE_cosim0->weight_out_data(weight_out_data);
		    SysPE_cosim0->act_out_busy(act_out_busy);
		    SysPE_cosim0->act_out_vld(act_out_vld);
		    SysPE_cosim0->act_out_data(act_out_data);
		    SysPE_cosim0->accum_out_busy(accum_out_busy);
		    SysPE_cosim0->accum_out_vld(accum_out_vld);
		    SysPE_cosim0->accum_out_data(accum_out_data);

			break;
#if defined(BDW_RTL)
		case BDWRep_RTL_C:
		    SysPE_rtl0 = new SysPE_rtl( "SysPE" );

		    SysPE_rtl0->clk(clk);
		    SysPE_rtl0->rst(rst);
		    SysPE_rtl0->weight_in_busy(weight_in_busy);
		    SysPE_rtl0->weight_in_vld(weight_in_vld);
		    SysPE_rtl0->weight_in_data(weight_in_data);
		    SysPE_rtl0->act_in_busy(act_in_busy);
		    SysPE_rtl0->act_in_vld(act_in_vld);
		    SysPE_rtl0->act_in_data(act_in_data);
		    SysPE_rtl0->accum_in_busy(accum_in_busy);
		    SysPE_rtl0->accum_in_vld(accum_in_vld);
		    SysPE_rtl0->accum_in_data(accum_in_data);
		    SysPE_rtl0->weight_out_busy(weight_out_busy);
		    SysPE_rtl0->weight_out_vld(weight_out_vld);
		    SysPE_rtl0->weight_out_data(weight_out_data);
		    SysPE_rtl0->act_out_busy(act_out_busy);
		    SysPE_rtl0->act_out_vld(act_out_vld);
		    SysPE_rtl0->act_out_data(act_out_data);
		    SysPE_rtl0->accum_out_busy(accum_out_busy);
		    SysPE_rtl0->accum_out_vld(accum_out_vld);
		    SysPE_rtl0->accum_out_data(accum_out_data);


			{
			const char *simConfig = SysPE_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
						                                          "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
#endif
		case BDWRep_Behavioral:
		    SysPE0 = new SysPE( "SysPE" );

		    SysPE0->clk(clk);
		    SysPE0->rst(rst);
		    SysPE0->weight_in.busy(weight_in_busy);
		    SysPE0->weight_in.vld(weight_in_vld);
		    SysPE0->weight_in.data(weight_in_data);
		    SysPE0->act_in.busy(act_in_busy);
		    SysPE0->act_in.vld(act_in_vld);
		    SysPE0->act_in.data(act_in_data);
		    SysPE0->accum_in.busy(accum_in_busy);
		    SysPE0->accum_in.vld(accum_in_vld);
		    SysPE0->accum_in.data(accum_in_data);
		    SysPE0->weight_out.busy(weight_out_busy);
		    SysPE0->weight_out.vld(weight_out_vld);
		    SysPE0->weight_out.data(weight_out_data);
		    SysPE0->act_out.busy(act_out_busy);
		    SysPE0->act_out.vld(act_out_vld);
		    SysPE0->act_out.data(act_out_data);
		    SysPE0->accum_out.busy(accum_out_busy);
		    SysPE0->accum_out.vld(accum_out_vld);
		    SysPE0->accum_out.data(accum_out_data);


			{
			const char *simConfig = SysPE_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
						                                          "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
		case BDWRep_None:
		default:
			esc_report_error( esc_error, "No representation could be determined for simulating instance %s. Please make sure that you used the right name string in the module constructor",
							  name() );
			break;
	}
}

void SysPE_wrapper_r::InitThreads()
{
	if ( isBEH() ) 
	{
		
	}
}

void SysPE_wrapper_r::start_of_simulation()
{

#include <SysPE_trace.h>

        esc_multiple_writers_warning();
}

void SysPE_wrapper_r::CloseTrace()
{
	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
	esc_close_vcd_trace();
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		esc_close_fsdb_trace();
		if ( esc_trace_is_enabled( esc_trace_scv ) ) {
			esc_close_fsdb_scv_trace();
		}
	}
}

void SysPE_wrapper_r::end_of_simulation()
{
      CloseTrace();
}



void SysPE_wrapper_r::DeleteInstances()
{
    if (SysPE0)
    {
        delete SysPE0;
        SysPE0 = 0;
    }
    if (SysPE_cosim0)
    {
        delete SysPE_cosim0;
        SysPE_cosim0 = 0;
    }
  #if defined(BDW_RTL)
    if (SysPE_rtl0)
    {
        delete SysPE_rtl0;
        SysPE_rtl0 = 0;
    }
#endif
}

#if BDW_WRITEFSDB == 1

inline void esc_open_fsdb_trace( const char *file_name  )
{
	sc_trace_file *fsdb_file;
#if ( (defined(XM_SYSTEMC) || defined(NC_SYSTEMC)) && defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102 ) || SYSTEMC_VERSION >= 20120701
    fsdbDumpfile(file_name);
    esc_set_trace_file( fsdb_file, esc_trace_fsdb );
# else

	// SystemC suffixes .fsdb to filenames automatically. Make sure
	// that doesn't get tacked onto a filename that already has the suffix.
	if ( strrchr( file_name, '.' ) != NULL )
	{
		char *trunc_file_name = new char[strlen(file_name)+1];
		strcpy( trunc_file_name, file_name );

		fsdb_file = new fsdb_trace_file( trunc_file_name );
		esc_set_trace_file( fsdb_file, esc_trace_fsdb );

		delete trunc_file_name;
	}
	else
	{
		fsdb_file = new fsdb_trace_file( file_name );
		esc_set_trace_file( fsdb_file, esc_trace_fsdb );
	}
#endif

//
// Novas's SystemC wrapper doesn't have a way to set the time unit as of SystemC 2.1v1.
//
//		((fsdb_trace_file*)fsdb_file)->sc_set_fsdb_time_unit( -12 );
}

inline void esc_close_fsdb_trace()
{
#if ! (((defined(XM_SYSTEMC) || defined(NC_SYSTEMC)) &&  defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102) || SYSTEMC_VERSION >= 20120701)
	fsdb_trace_file * fsdb_file =
		(fsdb_trace_file *)esc_trace_file( esc_trace_fsdb );

	if ( fsdb_file != NULL )
	{
		fsdb_file->CloseFile();
		delete fsdb_file;
		esc_set_trace_file( NULL, esc_trace_fsdb );
	}
#endif
}

#else

inline void esc_open_fsdb_trace( const char *file_name )
{
}

inline void esc_close_fsdb_trace()
{
}

#endif

#if BDW_USE_SCV && BDW_WRITEFSDB == 1
static scv_tr_db* local_fsdb_scv_db = 0;

inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
	// Start SCV logging to FSDB if there is not already a database setup.
    if (!esc_get_scv_tr_db() && esc_trace_is_enabled(esc_trace_scv) )
	{
		scv_startup();
		scv_tr_fsdb_init();

		char* scv_file_name = new char[strlen(file_name) + 1];
		strcpy( scv_file_name, file_name );
		char* fsdb_suffix = strstr( scv_file_name, ".fsdb" );
		if (fsdb_suffix)
			*fsdb_suffix = 0;
		local_fsdb_scv_db = new scv_tr_db(scv_file_name);

		delete [] scv_file_name;
		esc_set_scv_tr_db(local_fsdb_scv_db);
		scv_tr_db::set_default_db(local_fsdb_scv_db);
		local_fsdb_scv_db->set_recording(true);
	}
}

inline void esc_close_fsdb_scv_trace()
{
    if ( local_fsdb_scv_db && (local_fsdb_scv_db == esc_get_scv_tr_db() ) ) 
	{
		delete local_fsdb_scv_db;
		local_fsdb_scv_db = 0;
		esc_set_scv_tr_db(0);
	}
}
#else 
inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
}

inline void esc_close_fsdb_scv_trace()
{
}

#endif

class SysPE_wrapper_fsdb_opener {
public:
	SysPE_wrapper_fsdb_opener() {
		esc_set_open_fsdb_trace( esc_open_fsdb_trace );
		esc_set_open_fsdb_scv_trace( esc_open_fsdb_scv_trace );
	}
};

static SysPE_wrapper_fsdb_opener
  SysPE_wrapper_fsdb_opener_inst;

#else

// Visible to uses of the wrapper outside of the BDW environment.
// Only behavioral SystemC simulation is supported.


// Include the source for the behavioral model so it will be compiled.
#include	"/users/student/mr112/czwu23/JJLAB/SystolicArray/1205/SysPE/SysPE.cpp"

#define		SysPE_INTERNAL


#include	"SysPE_wrap.h"

const char * SysPE_wrapper::simConfigName()
{
  return "";
}

enum SysPE_wrapper::Representation SysPE_wrapper::lookupRepresentation( const char* instName )
{
  return BDWRep_Behavioral;
}

void SysPE_wrapper::InitInstances( sc_core::sc_module_name  )
{
	SysPE0 = new SysPE( "SysPE" );

	SysPE0->clk(clk);
	SysPE0->rst(rst);
	SysPE0->weight_in.busy(weight_in.busy);
	SysPE0->weight_in.vld(weight_in.vld);
	SysPE0->weight_in.data(weight_in.data);
	SysPE0->act_in.busy(act_in.busy);
	SysPE0->act_in.vld(act_in.vld);
	SysPE0->act_in.data(act_in.data);
	SysPE0->accum_in.busy(accum_in.busy);
	SysPE0->accum_in.vld(accum_in.vld);
	SysPE0->accum_in.data(accum_in.data);
	SysPE0->weight_out.busy(weight_out.busy);
	SysPE0->weight_out.vld(weight_out.vld);
	SysPE0->weight_out.data(weight_out.data);
	SysPE0->act_out.busy(act_out.busy);
	SysPE0->act_out.vld(act_out.vld);
	SysPE0->act_out.data(act_out.data);
	SysPE0->accum_out.busy(accum_out.busy);
	SysPE0->accum_out.vld(accum_out.vld);
	SysPE0->accum_out.data(accum_out.data);

}

void SysPE_wrapper::InitThreads()
{
}

void SysPE_wrapper::CloseTrace()
{
}

void SysPE_wrapper::DeleteInstances()
{
    if (SysPE0)
    {
        delete SysPE0;
        SysPE0 = 0;
    }
}

void SysPE_wrapper::start_of_simulation()
{
}

void SysPE_wrapper::end_of_simulation()
{
}



inline void esc_open_fsdb_trace( const char *file_name )
{
}

inline void esc_close_fsdb_trace()
{
}


inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
}

inline void esc_close_fsdb_scv_trace()
{
}

class SysPE_wrapper_fsdb_opener {
public:
	SysPE_wrapper_fsdb_opener() {
	}
};

static SysPE_wrapper_fsdb_opener
  SysPE_wrapper_fsdb_opener_inst;

#endif

#endif
