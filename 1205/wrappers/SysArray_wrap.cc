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
* block called "SysArray". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/

#if defined(STRATUS_VLG)



#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#include	"SysArray_rtl.cc"

#else 

#if defined(BDW_HUB)

#define SC_INCLUDE_DYNAMIC_PROCESSES 1
#include "esc.h"

#if defined(BDW_RTL)

#define BDW_AUTO_KNOWN 1 


#undef SysPE
#define SysPE SysPE_wrapper_r

#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#undef SysArray
#define SysArray SysArray_rtl
#	include	"SysArray_rtl.cc"
#undef SysArray


#undef SysPE

#ifdef BDW_PORTS_ONLY
#undef BDW_PORTS_ONLY
#endif



#elif defined(BDW_HOIST) 
#else

#endif

#include	"SysArray_cosim.h"




// Include the source for the behavioral model so it will be compiled.
#include	"/users/student/mr112/czwu23/JJLAB/SystolicArray/1205/SysArray/SysArray.cc"


#define		SysArray_INTERNAL


#include	"SysArray_wrap.h"


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

const char * SysArray_wrapper::simConfigName()
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

enum SysArray_wrapper::Representation SysArray_wrapper::lookupRepresentation( const char* instName )
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
	err = qbhGetRepresentation(hProj, "SysArray", simConfig, instName, &iresult );
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
								 "SysArray", simConfig, instName, leaf,  "SysArray" );
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

void SysArray_wrapper::InitInstances(  )
{
    enum SysArray_wrapper::Representation rep =
		SysArray_wrapper::lookupRepresentation( name() );

	esc_log_wrapper_inst( "SysArray" );
	esc_log_representation( "SysArray", name(), rep );

	

	switch ( rep )
	{
		case BDWRep_Gates:
		    SysArray_cosim0 = new SysArray_cosim( "SysArray" );

		    SysArray_cosim0->clk(clk);
		    SysArray_cosim0->rst(rst);
		    SysArray_cosim0->weight_in_vec_busy_0(weight_in_vec[0].busy);
		    SysArray_cosim0->weight_in_vec_busy_1(weight_in_vec[1].busy);
		    SysArray_cosim0->weight_in_vec_busy_2(weight_in_vec[2].busy);
		    SysArray_cosim0->weight_in_vec_vld_0(weight_in_vec[0].vld);
		    SysArray_cosim0->weight_in_vec_vld_1(weight_in_vec[1].vld);
		    SysArray_cosim0->weight_in_vec_vld_2(weight_in_vec[2].vld);
		    SysArray_cosim0->weight_in_vec_data_0(weight_in_vec[0].data);
		    SysArray_cosim0->weight_in_vec_data_1(weight_in_vec[1].data);
		    SysArray_cosim0->weight_in_vec_data_2(weight_in_vec[2].data);
		    SysArray_cosim0->act_in_vec_busy_0(act_in_vec[0].busy);
		    SysArray_cosim0->act_in_vec_busy_1(act_in_vec[1].busy);
		    SysArray_cosim0->act_in_vec_busy_2(act_in_vec[2].busy);
		    SysArray_cosim0->act_in_vec_vld_0(act_in_vec[0].vld);
		    SysArray_cosim0->act_in_vec_vld_1(act_in_vec[1].vld);
		    SysArray_cosim0->act_in_vec_vld_2(act_in_vec[2].vld);
		    SysArray_cosim0->act_in_vec_data_0(act_in_vec[0].data);
		    SysArray_cosim0->act_in_vec_data_1(act_in_vec[1].data);
		    SysArray_cosim0->act_in_vec_data_2(act_in_vec[2].data);
		    SysArray_cosim0->accum_in_vec_busy_0(accum_in_vec[0].busy);
		    SysArray_cosim0->accum_in_vec_busy_1(accum_in_vec[1].busy);
		    SysArray_cosim0->accum_in_vec_busy_2(accum_in_vec[2].busy);
		    SysArray_cosim0->accum_in_vec_vld_0(accum_in_vec[0].vld);
		    SysArray_cosim0->accum_in_vec_vld_1(accum_in_vec[1].vld);
		    SysArray_cosim0->accum_in_vec_vld_2(accum_in_vec[2].vld);
		    SysArray_cosim0->accum_in_vec_data_0(accum_in_vec[0].data);
		    SysArray_cosim0->accum_in_vec_data_1(accum_in_vec[1].data);
		    SysArray_cosim0->accum_in_vec_data_2(accum_in_vec[2].data);
		    SysArray_cosim0->accum_out_vec_busy_0(accum_out_vec[0].busy);
		    SysArray_cosim0->accum_out_vec_busy_1(accum_out_vec[1].busy);
		    SysArray_cosim0->accum_out_vec_busy_2(accum_out_vec[2].busy);
		    SysArray_cosim0->accum_out_vec_vld_0(accum_out_vec[0].vld);
		    SysArray_cosim0->accum_out_vec_vld_1(accum_out_vec[1].vld);
		    SysArray_cosim0->accum_out_vec_vld_2(accum_out_vec[2].vld);
		    SysArray_cosim0->accum_out_vec_data_0(accum_out_vec[0].data);
		    SysArray_cosim0->accum_out_vec_data_1(accum_out_vec[1].data);
		    SysArray_cosim0->accum_out_vec_data_2(accum_out_vec[2].data);
		    SysArray_cosim0->weight_inter_busy_0(weight_inter[0].busy);
		    SysArray_cosim0->weight_inter_busy_1(weight_inter[1].busy);
		    SysArray_cosim0->weight_inter_busy_2(weight_inter[2].busy);
		    SysArray_cosim0->weight_inter_vld_0(weight_inter[0].vld);
		    SysArray_cosim0->weight_inter_vld_1(weight_inter[1].vld);
		    SysArray_cosim0->weight_inter_vld_2(weight_inter[2].vld);
		    SysArray_cosim0->weight_inter_data_0(weight_inter[0].data);
		    SysArray_cosim0->weight_inter_data_1(weight_inter[1].data);
		    SysArray_cosim0->weight_inter_data_2(weight_inter[2].data);
		    SysArray_cosim0->act_inter_busy_0(act_inter[0].busy);
		    SysArray_cosim0->act_inter_busy_1(act_inter[1].busy);
		    SysArray_cosim0->act_inter_busy_2(act_inter[2].busy);
		    SysArray_cosim0->act_inter_vld_0(act_inter[0].vld);
		    SysArray_cosim0->act_inter_vld_1(act_inter[1].vld);
		    SysArray_cosim0->act_inter_vld_2(act_inter[2].vld);
		    SysArray_cosim0->act_inter_data_0(act_inter[0].data);
		    SysArray_cosim0->act_inter_data_1(act_inter[1].data);
		    SysArray_cosim0->act_inter_data_2(act_inter[2].data);

			break;
		case BDWRep_RTL_HDL:
		    SysArray_cosim0 = new SysArray_cosim( "SysArray" );

		    SysArray_cosim0->clk(clk);
		    SysArray_cosim0->rst(rst);
		    SysArray_cosim0->weight_in_vec_busy_0(weight_in_vec[0].busy);
		    SysArray_cosim0->weight_in_vec_busy_1(weight_in_vec[1].busy);
		    SysArray_cosim0->weight_in_vec_busy_2(weight_in_vec[2].busy);
		    SysArray_cosim0->weight_in_vec_vld_0(weight_in_vec[0].vld);
		    SysArray_cosim0->weight_in_vec_vld_1(weight_in_vec[1].vld);
		    SysArray_cosim0->weight_in_vec_vld_2(weight_in_vec[2].vld);
		    SysArray_cosim0->weight_in_vec_data_0(weight_in_vec[0].data);
		    SysArray_cosim0->weight_in_vec_data_1(weight_in_vec[1].data);
		    SysArray_cosim0->weight_in_vec_data_2(weight_in_vec[2].data);
		    SysArray_cosim0->act_in_vec_busy_0(act_in_vec[0].busy);
		    SysArray_cosim0->act_in_vec_busy_1(act_in_vec[1].busy);
		    SysArray_cosim0->act_in_vec_busy_2(act_in_vec[2].busy);
		    SysArray_cosim0->act_in_vec_vld_0(act_in_vec[0].vld);
		    SysArray_cosim0->act_in_vec_vld_1(act_in_vec[1].vld);
		    SysArray_cosim0->act_in_vec_vld_2(act_in_vec[2].vld);
		    SysArray_cosim0->act_in_vec_data_0(act_in_vec[0].data);
		    SysArray_cosim0->act_in_vec_data_1(act_in_vec[1].data);
		    SysArray_cosim0->act_in_vec_data_2(act_in_vec[2].data);
		    SysArray_cosim0->accum_in_vec_busy_0(accum_in_vec[0].busy);
		    SysArray_cosim0->accum_in_vec_busy_1(accum_in_vec[1].busy);
		    SysArray_cosim0->accum_in_vec_busy_2(accum_in_vec[2].busy);
		    SysArray_cosim0->accum_in_vec_vld_0(accum_in_vec[0].vld);
		    SysArray_cosim0->accum_in_vec_vld_1(accum_in_vec[1].vld);
		    SysArray_cosim0->accum_in_vec_vld_2(accum_in_vec[2].vld);
		    SysArray_cosim0->accum_in_vec_data_0(accum_in_vec[0].data);
		    SysArray_cosim0->accum_in_vec_data_1(accum_in_vec[1].data);
		    SysArray_cosim0->accum_in_vec_data_2(accum_in_vec[2].data);
		    SysArray_cosim0->accum_out_vec_busy_0(accum_out_vec[0].busy);
		    SysArray_cosim0->accum_out_vec_busy_1(accum_out_vec[1].busy);
		    SysArray_cosim0->accum_out_vec_busy_2(accum_out_vec[2].busy);
		    SysArray_cosim0->accum_out_vec_vld_0(accum_out_vec[0].vld);
		    SysArray_cosim0->accum_out_vec_vld_1(accum_out_vec[1].vld);
		    SysArray_cosim0->accum_out_vec_vld_2(accum_out_vec[2].vld);
		    SysArray_cosim0->accum_out_vec_data_0(accum_out_vec[0].data);
		    SysArray_cosim0->accum_out_vec_data_1(accum_out_vec[1].data);
		    SysArray_cosim0->accum_out_vec_data_2(accum_out_vec[2].data);
		    SysArray_cosim0->weight_inter_busy_0(weight_inter[0].busy);
		    SysArray_cosim0->weight_inter_busy_1(weight_inter[1].busy);
		    SysArray_cosim0->weight_inter_busy_2(weight_inter[2].busy);
		    SysArray_cosim0->weight_inter_vld_0(weight_inter[0].vld);
		    SysArray_cosim0->weight_inter_vld_1(weight_inter[1].vld);
		    SysArray_cosim0->weight_inter_vld_2(weight_inter[2].vld);
		    SysArray_cosim0->weight_inter_data_0(weight_inter[0].data);
		    SysArray_cosim0->weight_inter_data_1(weight_inter[1].data);
		    SysArray_cosim0->weight_inter_data_2(weight_inter[2].data);
		    SysArray_cosim0->act_inter_busy_0(act_inter[0].busy);
		    SysArray_cosim0->act_inter_busy_1(act_inter[1].busy);
		    SysArray_cosim0->act_inter_busy_2(act_inter[2].busy);
		    SysArray_cosim0->act_inter_vld_0(act_inter[0].vld);
		    SysArray_cosim0->act_inter_vld_1(act_inter[1].vld);
		    SysArray_cosim0->act_inter_vld_2(act_inter[2].vld);
		    SysArray_cosim0->act_inter_data_0(act_inter[0].data);
		    SysArray_cosim0->act_inter_data_1(act_inter[1].data);
		    SysArray_cosim0->act_inter_data_2(act_inter[2].data);

			break;
#if defined(BDW_RTL)
		case BDWRep_RTL_C:
		    SysArray_rtl0 = new SysArray_rtl( "SysArray" );

		    SysArray_rtl0->clk(clk);
		    SysArray_rtl0->rst(rst);
		    SysArray_rtl0->weight_in_vec_busy_0(weight_in_vec[0].busy);
		    SysArray_rtl0->weight_in_vec_busy_1(weight_in_vec[1].busy);
		    SysArray_rtl0->weight_in_vec_busy_2(weight_in_vec[2].busy);
		    SysArray_rtl0->weight_in_vec_vld_0(weight_in_vec[0].vld);
		    SysArray_rtl0->weight_in_vec_vld_1(weight_in_vec[1].vld);
		    SysArray_rtl0->weight_in_vec_vld_2(weight_in_vec[2].vld);
		    SysArray_rtl0->weight_in_vec_data_0(weight_in_vec[0].data);
		    SysArray_rtl0->weight_in_vec_data_1(weight_in_vec[1].data);
		    SysArray_rtl0->weight_in_vec_data_2(weight_in_vec[2].data);
		    SysArray_rtl0->act_in_vec_busy_0(act_in_vec[0].busy);
		    SysArray_rtl0->act_in_vec_busy_1(act_in_vec[1].busy);
		    SysArray_rtl0->act_in_vec_busy_2(act_in_vec[2].busy);
		    SysArray_rtl0->act_in_vec_vld_0(act_in_vec[0].vld);
		    SysArray_rtl0->act_in_vec_vld_1(act_in_vec[1].vld);
		    SysArray_rtl0->act_in_vec_vld_2(act_in_vec[2].vld);
		    SysArray_rtl0->act_in_vec_data_0(act_in_vec[0].data);
		    SysArray_rtl0->act_in_vec_data_1(act_in_vec[1].data);
		    SysArray_rtl0->act_in_vec_data_2(act_in_vec[2].data);
		    SysArray_rtl0->accum_in_vec_busy_0(accum_in_vec[0].busy);
		    SysArray_rtl0->accum_in_vec_busy_1(accum_in_vec[1].busy);
		    SysArray_rtl0->accum_in_vec_busy_2(accum_in_vec[2].busy);
		    SysArray_rtl0->accum_in_vec_vld_0(accum_in_vec[0].vld);
		    SysArray_rtl0->accum_in_vec_vld_1(accum_in_vec[1].vld);
		    SysArray_rtl0->accum_in_vec_vld_2(accum_in_vec[2].vld);
		    SysArray_rtl0->accum_in_vec_data_0(accum_in_vec[0].data);
		    SysArray_rtl0->accum_in_vec_data_1(accum_in_vec[1].data);
		    SysArray_rtl0->accum_in_vec_data_2(accum_in_vec[2].data);
		    SysArray_rtl0->accum_out_vec_busy_0(accum_out_vec[0].busy);
		    SysArray_rtl0->accum_out_vec_busy_1(accum_out_vec[1].busy);
		    SysArray_rtl0->accum_out_vec_busy_2(accum_out_vec[2].busy);
		    SysArray_rtl0->accum_out_vec_vld_0(accum_out_vec[0].vld);
		    SysArray_rtl0->accum_out_vec_vld_1(accum_out_vec[1].vld);
		    SysArray_rtl0->accum_out_vec_vld_2(accum_out_vec[2].vld);
		    SysArray_rtl0->accum_out_vec_data_0(accum_out_vec[0].data);
		    SysArray_rtl0->accum_out_vec_data_1(accum_out_vec[1].data);
		    SysArray_rtl0->accum_out_vec_data_2(accum_out_vec[2].data);
		    SysArray_rtl0->weight_inter_busy_0(weight_inter[0].busy);
		    SysArray_rtl0->weight_inter_busy_1(weight_inter[1].busy);
		    SysArray_rtl0->weight_inter_busy_2(weight_inter[2].busy);
		    SysArray_rtl0->weight_inter_vld_0(weight_inter[0].vld);
		    SysArray_rtl0->weight_inter_vld_1(weight_inter[1].vld);
		    SysArray_rtl0->weight_inter_vld_2(weight_inter[2].vld);
		    SysArray_rtl0->weight_inter_data_0(weight_inter[0].data);
		    SysArray_rtl0->weight_inter_data_1(weight_inter[1].data);
		    SysArray_rtl0->weight_inter_data_2(weight_inter[2].data);
		    SysArray_rtl0->act_inter_busy_0(act_inter[0].busy);
		    SysArray_rtl0->act_inter_busy_1(act_inter[1].busy);
		    SysArray_rtl0->act_inter_busy_2(act_inter[2].busy);
		    SysArray_rtl0->act_inter_vld_0(act_inter[0].vld);
		    SysArray_rtl0->act_inter_vld_1(act_inter[1].vld);
		    SysArray_rtl0->act_inter_vld_2(act_inter[2].vld);
		    SysArray_rtl0->act_inter_data_0(act_inter[0].data);
		    SysArray_rtl0->act_inter_data_1(act_inter[1].data);
		    SysArray_rtl0->act_inter_data_2(act_inter[2].data);


			{
			const char *simConfig = SysArray_wrapper::simConfigName();
			
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
		    SysArray0 = new SysArray( "SysArray" );

		    SysArray0->clk(clk);
		    SysArray0->rst(rst);
		    SysArray0->weight_in_vec[0].busy(weight_in_vec[0].busy);
		    SysArray0->weight_in_vec[1].busy(weight_in_vec[1].busy);
		    SysArray0->weight_in_vec[2].busy(weight_in_vec[2].busy);
		    SysArray0->weight_in_vec[0].vld(weight_in_vec[0].vld);
		    SysArray0->weight_in_vec[1].vld(weight_in_vec[1].vld);
		    SysArray0->weight_in_vec[2].vld(weight_in_vec[2].vld);
		    SysArray0->weight_in_vec[0].data(weight_in_vec[0].data);
		    SysArray0->weight_in_vec[1].data(weight_in_vec[1].data);
		    SysArray0->weight_in_vec[2].data(weight_in_vec[2].data);
		    SysArray0->act_in_vec[0].busy(act_in_vec[0].busy);
		    SysArray0->act_in_vec[1].busy(act_in_vec[1].busy);
		    SysArray0->act_in_vec[2].busy(act_in_vec[2].busy);
		    SysArray0->act_in_vec[0].vld(act_in_vec[0].vld);
		    SysArray0->act_in_vec[1].vld(act_in_vec[1].vld);
		    SysArray0->act_in_vec[2].vld(act_in_vec[2].vld);
		    SysArray0->act_in_vec[0].data(act_in_vec[0].data);
		    SysArray0->act_in_vec[1].data(act_in_vec[1].data);
		    SysArray0->act_in_vec[2].data(act_in_vec[2].data);
		    SysArray0->accum_in_vec[0].busy(accum_in_vec[0].busy);
		    SysArray0->accum_in_vec[1].busy(accum_in_vec[1].busy);
		    SysArray0->accum_in_vec[2].busy(accum_in_vec[2].busy);
		    SysArray0->accum_in_vec[0].vld(accum_in_vec[0].vld);
		    SysArray0->accum_in_vec[1].vld(accum_in_vec[1].vld);
		    SysArray0->accum_in_vec[2].vld(accum_in_vec[2].vld);
		    SysArray0->accum_in_vec[0].data(accum_in_vec[0].data);
		    SysArray0->accum_in_vec[1].data(accum_in_vec[1].data);
		    SysArray0->accum_in_vec[2].data(accum_in_vec[2].data);
		    SysArray0->accum_out_vec[0].busy(accum_out_vec[0].busy);
		    SysArray0->accum_out_vec[1].busy(accum_out_vec[1].busy);
		    SysArray0->accum_out_vec[2].busy(accum_out_vec[2].busy);
		    SysArray0->accum_out_vec[0].vld(accum_out_vec[0].vld);
		    SysArray0->accum_out_vec[1].vld(accum_out_vec[1].vld);
		    SysArray0->accum_out_vec[2].vld(accum_out_vec[2].vld);
		    SysArray0->accum_out_vec[0].data(accum_out_vec[0].data);
		    SysArray0->accum_out_vec[1].data(accum_out_vec[1].data);
		    SysArray0->accum_out_vec[2].data(accum_out_vec[2].data);
		    SysArray0->weight_inter[0].busy(weight_inter[0].busy);
		    SysArray0->weight_inter[1].busy(weight_inter[1].busy);
		    SysArray0->weight_inter[2].busy(weight_inter[2].busy);
		    SysArray0->weight_inter[0].vld(weight_inter[0].vld);
		    SysArray0->weight_inter[1].vld(weight_inter[1].vld);
		    SysArray0->weight_inter[2].vld(weight_inter[2].vld);
		    SysArray0->weight_inter[0].data(weight_inter[0].data);
		    SysArray0->weight_inter[1].data(weight_inter[1].data);
		    SysArray0->weight_inter[2].data(weight_inter[2].data);
		    SysArray0->act_inter[0].busy(act_inter[0].busy);
		    SysArray0->act_inter[1].busy(act_inter[1].busy);
		    SysArray0->act_inter[2].busy(act_inter[2].busy);
		    SysArray0->act_inter[0].vld(act_inter[0].vld);
		    SysArray0->act_inter[1].vld(act_inter[1].vld);
		    SysArray0->act_inter[2].vld(act_inter[2].vld);
		    SysArray0->act_inter[0].data(act_inter[0].data);
		    SysArray0->act_inter[1].data(act_inter[1].data);
		    SysArray0->act_inter[2].data(act_inter[2].data);


			{
			const char *simConfig = SysArray_wrapper::simConfigName();
			
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

void SysArray_wrapper::InitThreads()
{
	if ( !isBEH() )
	{
		
	}
}

void SysArray_wrapper::start_of_simulation()
{

#include <SysArray_trace.h>

        esc_multiple_writers_warning();
}

void SysArray_wrapper::CloseTrace()
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

void SysArray_wrapper::end_of_simulation()
{
      CloseTrace();
}



void SysArray_wrapper::DeleteInstances()
{
    if (SysArray0)
    {
        delete SysArray0;
        SysArray0 = 0;
    }
    if (SysArray_cosim0)
    {
        delete SysArray_cosim0;
        SysArray_cosim0 = 0;
    }
  #if defined(BDW_RTL)
    if (SysArray_rtl0)
    {
        delete SysArray_rtl0;
        SysArray_rtl0 = 0;
    }
#endif
}

// The following threads are used to connect RTL ports to the actual
// structured ports

const char * SysArray_wrapper_r::simConfigName()
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

enum SysArray_wrapper_r::Representation SysArray_wrapper_r::lookupRepresentation( const char* instName )
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
	err = qbhGetRepresentation(hProj, "SysArray", simConfig, instName, &iresult );
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

void SysArray_wrapper_r::InitInstances()
{
    enum SysArray_wrapper_r::Representation rep =
		SysArray_wrapper_r::lookupRepresentation( name() );

	esc_log_wrapper_inst( "SysArray" );
	esc_log_representation( "SysArray", name(), rep );

	switch ( rep )
	{
		case BDWRep_Gates:
		    SysArray_cosim0 = new SysArray_cosim( "SysArray" );

		    SysArray_cosim0->clk(clk);
		    SysArray_cosim0->rst(rst);
		    SysArray_cosim0->weight_in_vec_busy_0(weight_in_vec_busy_0);
		    SysArray_cosim0->weight_in_vec_busy_1(weight_in_vec_busy_1);
		    SysArray_cosim0->weight_in_vec_busy_2(weight_in_vec_busy_2);
		    SysArray_cosim0->weight_in_vec_vld_0(weight_in_vec_vld_0);
		    SysArray_cosim0->weight_in_vec_vld_1(weight_in_vec_vld_1);
		    SysArray_cosim0->weight_in_vec_vld_2(weight_in_vec_vld_2);
		    SysArray_cosim0->weight_in_vec_data_0(weight_in_vec_data_0);
		    SysArray_cosim0->weight_in_vec_data_1(weight_in_vec_data_1);
		    SysArray_cosim0->weight_in_vec_data_2(weight_in_vec_data_2);
		    SysArray_cosim0->act_in_vec_busy_0(act_in_vec_busy_0);
		    SysArray_cosim0->act_in_vec_busy_1(act_in_vec_busy_1);
		    SysArray_cosim0->act_in_vec_busy_2(act_in_vec_busy_2);
		    SysArray_cosim0->act_in_vec_vld_0(act_in_vec_vld_0);
		    SysArray_cosim0->act_in_vec_vld_1(act_in_vec_vld_1);
		    SysArray_cosim0->act_in_vec_vld_2(act_in_vec_vld_2);
		    SysArray_cosim0->act_in_vec_data_0(act_in_vec_data_0);
		    SysArray_cosim0->act_in_vec_data_1(act_in_vec_data_1);
		    SysArray_cosim0->act_in_vec_data_2(act_in_vec_data_2);
		    SysArray_cosim0->accum_in_vec_busy_0(accum_in_vec_busy_0);
		    SysArray_cosim0->accum_in_vec_busy_1(accum_in_vec_busy_1);
		    SysArray_cosim0->accum_in_vec_busy_2(accum_in_vec_busy_2);
		    SysArray_cosim0->accum_in_vec_vld_0(accum_in_vec_vld_0);
		    SysArray_cosim0->accum_in_vec_vld_1(accum_in_vec_vld_1);
		    SysArray_cosim0->accum_in_vec_vld_2(accum_in_vec_vld_2);
		    SysArray_cosim0->accum_in_vec_data_0(accum_in_vec_data_0);
		    SysArray_cosim0->accum_in_vec_data_1(accum_in_vec_data_1);
		    SysArray_cosim0->accum_in_vec_data_2(accum_in_vec_data_2);
		    SysArray_cosim0->accum_out_vec_busy_0(accum_out_vec_busy_0);
		    SysArray_cosim0->accum_out_vec_busy_1(accum_out_vec_busy_1);
		    SysArray_cosim0->accum_out_vec_busy_2(accum_out_vec_busy_2);
		    SysArray_cosim0->accum_out_vec_vld_0(accum_out_vec_vld_0);
		    SysArray_cosim0->accum_out_vec_vld_1(accum_out_vec_vld_1);
		    SysArray_cosim0->accum_out_vec_vld_2(accum_out_vec_vld_2);
		    SysArray_cosim0->accum_out_vec_data_0(accum_out_vec_data_0);
		    SysArray_cosim0->accum_out_vec_data_1(accum_out_vec_data_1);
		    SysArray_cosim0->accum_out_vec_data_2(accum_out_vec_data_2);
		    SysArray_cosim0->weight_inter_busy_0(weight_inter_busy_0);
		    SysArray_cosim0->weight_inter_busy_1(weight_inter_busy_1);
		    SysArray_cosim0->weight_inter_busy_2(weight_inter_busy_2);
		    SysArray_cosim0->weight_inter_vld_0(weight_inter_vld_0);
		    SysArray_cosim0->weight_inter_vld_1(weight_inter_vld_1);
		    SysArray_cosim0->weight_inter_vld_2(weight_inter_vld_2);
		    SysArray_cosim0->weight_inter_data_0(weight_inter_data_0);
		    SysArray_cosim0->weight_inter_data_1(weight_inter_data_1);
		    SysArray_cosim0->weight_inter_data_2(weight_inter_data_2);
		    SysArray_cosim0->act_inter_busy_0(act_inter_busy_0);
		    SysArray_cosim0->act_inter_busy_1(act_inter_busy_1);
		    SysArray_cosim0->act_inter_busy_2(act_inter_busy_2);
		    SysArray_cosim0->act_inter_vld_0(act_inter_vld_0);
		    SysArray_cosim0->act_inter_vld_1(act_inter_vld_1);
		    SysArray_cosim0->act_inter_vld_2(act_inter_vld_2);
		    SysArray_cosim0->act_inter_data_0(act_inter_data_0);
		    SysArray_cosim0->act_inter_data_1(act_inter_data_1);
		    SysArray_cosim0->act_inter_data_2(act_inter_data_2);

			break;
		case BDWRep_RTL_HDL:
		    SysArray_cosim0 = new SysArray_cosim( "SysArray" );

		    SysArray_cosim0->clk(clk);
		    SysArray_cosim0->rst(rst);
		    SysArray_cosim0->weight_in_vec_busy_0(weight_in_vec_busy_0);
		    SysArray_cosim0->weight_in_vec_busy_1(weight_in_vec_busy_1);
		    SysArray_cosim0->weight_in_vec_busy_2(weight_in_vec_busy_2);
		    SysArray_cosim0->weight_in_vec_vld_0(weight_in_vec_vld_0);
		    SysArray_cosim0->weight_in_vec_vld_1(weight_in_vec_vld_1);
		    SysArray_cosim0->weight_in_vec_vld_2(weight_in_vec_vld_2);
		    SysArray_cosim0->weight_in_vec_data_0(weight_in_vec_data_0);
		    SysArray_cosim0->weight_in_vec_data_1(weight_in_vec_data_1);
		    SysArray_cosim0->weight_in_vec_data_2(weight_in_vec_data_2);
		    SysArray_cosim0->act_in_vec_busy_0(act_in_vec_busy_0);
		    SysArray_cosim0->act_in_vec_busy_1(act_in_vec_busy_1);
		    SysArray_cosim0->act_in_vec_busy_2(act_in_vec_busy_2);
		    SysArray_cosim0->act_in_vec_vld_0(act_in_vec_vld_0);
		    SysArray_cosim0->act_in_vec_vld_1(act_in_vec_vld_1);
		    SysArray_cosim0->act_in_vec_vld_2(act_in_vec_vld_2);
		    SysArray_cosim0->act_in_vec_data_0(act_in_vec_data_0);
		    SysArray_cosim0->act_in_vec_data_1(act_in_vec_data_1);
		    SysArray_cosim0->act_in_vec_data_2(act_in_vec_data_2);
		    SysArray_cosim0->accum_in_vec_busy_0(accum_in_vec_busy_0);
		    SysArray_cosim0->accum_in_vec_busy_1(accum_in_vec_busy_1);
		    SysArray_cosim0->accum_in_vec_busy_2(accum_in_vec_busy_2);
		    SysArray_cosim0->accum_in_vec_vld_0(accum_in_vec_vld_0);
		    SysArray_cosim0->accum_in_vec_vld_1(accum_in_vec_vld_1);
		    SysArray_cosim0->accum_in_vec_vld_2(accum_in_vec_vld_2);
		    SysArray_cosim0->accum_in_vec_data_0(accum_in_vec_data_0);
		    SysArray_cosim0->accum_in_vec_data_1(accum_in_vec_data_1);
		    SysArray_cosim0->accum_in_vec_data_2(accum_in_vec_data_2);
		    SysArray_cosim0->accum_out_vec_busy_0(accum_out_vec_busy_0);
		    SysArray_cosim0->accum_out_vec_busy_1(accum_out_vec_busy_1);
		    SysArray_cosim0->accum_out_vec_busy_2(accum_out_vec_busy_2);
		    SysArray_cosim0->accum_out_vec_vld_0(accum_out_vec_vld_0);
		    SysArray_cosim0->accum_out_vec_vld_1(accum_out_vec_vld_1);
		    SysArray_cosim0->accum_out_vec_vld_2(accum_out_vec_vld_2);
		    SysArray_cosim0->accum_out_vec_data_0(accum_out_vec_data_0);
		    SysArray_cosim0->accum_out_vec_data_1(accum_out_vec_data_1);
		    SysArray_cosim0->accum_out_vec_data_2(accum_out_vec_data_2);
		    SysArray_cosim0->weight_inter_busy_0(weight_inter_busy_0);
		    SysArray_cosim0->weight_inter_busy_1(weight_inter_busy_1);
		    SysArray_cosim0->weight_inter_busy_2(weight_inter_busy_2);
		    SysArray_cosim0->weight_inter_vld_0(weight_inter_vld_0);
		    SysArray_cosim0->weight_inter_vld_1(weight_inter_vld_1);
		    SysArray_cosim0->weight_inter_vld_2(weight_inter_vld_2);
		    SysArray_cosim0->weight_inter_data_0(weight_inter_data_0);
		    SysArray_cosim0->weight_inter_data_1(weight_inter_data_1);
		    SysArray_cosim0->weight_inter_data_2(weight_inter_data_2);
		    SysArray_cosim0->act_inter_busy_0(act_inter_busy_0);
		    SysArray_cosim0->act_inter_busy_1(act_inter_busy_1);
		    SysArray_cosim0->act_inter_busy_2(act_inter_busy_2);
		    SysArray_cosim0->act_inter_vld_0(act_inter_vld_0);
		    SysArray_cosim0->act_inter_vld_1(act_inter_vld_1);
		    SysArray_cosim0->act_inter_vld_2(act_inter_vld_2);
		    SysArray_cosim0->act_inter_data_0(act_inter_data_0);
		    SysArray_cosim0->act_inter_data_1(act_inter_data_1);
		    SysArray_cosim0->act_inter_data_2(act_inter_data_2);

			break;
#if defined(BDW_RTL)
		case BDWRep_RTL_C:
		    SysArray_rtl0 = new SysArray_rtl( "SysArray" );

		    SysArray_rtl0->clk(clk);
		    SysArray_rtl0->rst(rst);
		    SysArray_rtl0->weight_in_vec_busy_0(weight_in_vec_busy_0);
		    SysArray_rtl0->weight_in_vec_busy_1(weight_in_vec_busy_1);
		    SysArray_rtl0->weight_in_vec_busy_2(weight_in_vec_busy_2);
		    SysArray_rtl0->weight_in_vec_vld_0(weight_in_vec_vld_0);
		    SysArray_rtl0->weight_in_vec_vld_1(weight_in_vec_vld_1);
		    SysArray_rtl0->weight_in_vec_vld_2(weight_in_vec_vld_2);
		    SysArray_rtl0->weight_in_vec_data_0(weight_in_vec_data_0);
		    SysArray_rtl0->weight_in_vec_data_1(weight_in_vec_data_1);
		    SysArray_rtl0->weight_in_vec_data_2(weight_in_vec_data_2);
		    SysArray_rtl0->act_in_vec_busy_0(act_in_vec_busy_0);
		    SysArray_rtl0->act_in_vec_busy_1(act_in_vec_busy_1);
		    SysArray_rtl0->act_in_vec_busy_2(act_in_vec_busy_2);
		    SysArray_rtl0->act_in_vec_vld_0(act_in_vec_vld_0);
		    SysArray_rtl0->act_in_vec_vld_1(act_in_vec_vld_1);
		    SysArray_rtl0->act_in_vec_vld_2(act_in_vec_vld_2);
		    SysArray_rtl0->act_in_vec_data_0(act_in_vec_data_0);
		    SysArray_rtl0->act_in_vec_data_1(act_in_vec_data_1);
		    SysArray_rtl0->act_in_vec_data_2(act_in_vec_data_2);
		    SysArray_rtl0->accum_in_vec_busy_0(accum_in_vec_busy_0);
		    SysArray_rtl0->accum_in_vec_busy_1(accum_in_vec_busy_1);
		    SysArray_rtl0->accum_in_vec_busy_2(accum_in_vec_busy_2);
		    SysArray_rtl0->accum_in_vec_vld_0(accum_in_vec_vld_0);
		    SysArray_rtl0->accum_in_vec_vld_1(accum_in_vec_vld_1);
		    SysArray_rtl0->accum_in_vec_vld_2(accum_in_vec_vld_2);
		    SysArray_rtl0->accum_in_vec_data_0(accum_in_vec_data_0);
		    SysArray_rtl0->accum_in_vec_data_1(accum_in_vec_data_1);
		    SysArray_rtl0->accum_in_vec_data_2(accum_in_vec_data_2);
		    SysArray_rtl0->accum_out_vec_busy_0(accum_out_vec_busy_0);
		    SysArray_rtl0->accum_out_vec_busy_1(accum_out_vec_busy_1);
		    SysArray_rtl0->accum_out_vec_busy_2(accum_out_vec_busy_2);
		    SysArray_rtl0->accum_out_vec_vld_0(accum_out_vec_vld_0);
		    SysArray_rtl0->accum_out_vec_vld_1(accum_out_vec_vld_1);
		    SysArray_rtl0->accum_out_vec_vld_2(accum_out_vec_vld_2);
		    SysArray_rtl0->accum_out_vec_data_0(accum_out_vec_data_0);
		    SysArray_rtl0->accum_out_vec_data_1(accum_out_vec_data_1);
		    SysArray_rtl0->accum_out_vec_data_2(accum_out_vec_data_2);
		    SysArray_rtl0->weight_inter_busy_0(weight_inter_busy_0);
		    SysArray_rtl0->weight_inter_busy_1(weight_inter_busy_1);
		    SysArray_rtl0->weight_inter_busy_2(weight_inter_busy_2);
		    SysArray_rtl0->weight_inter_vld_0(weight_inter_vld_0);
		    SysArray_rtl0->weight_inter_vld_1(weight_inter_vld_1);
		    SysArray_rtl0->weight_inter_vld_2(weight_inter_vld_2);
		    SysArray_rtl0->weight_inter_data_0(weight_inter_data_0);
		    SysArray_rtl0->weight_inter_data_1(weight_inter_data_1);
		    SysArray_rtl0->weight_inter_data_2(weight_inter_data_2);
		    SysArray_rtl0->act_inter_busy_0(act_inter_busy_0);
		    SysArray_rtl0->act_inter_busy_1(act_inter_busy_1);
		    SysArray_rtl0->act_inter_busy_2(act_inter_busy_2);
		    SysArray_rtl0->act_inter_vld_0(act_inter_vld_0);
		    SysArray_rtl0->act_inter_vld_1(act_inter_vld_1);
		    SysArray_rtl0->act_inter_vld_2(act_inter_vld_2);
		    SysArray_rtl0->act_inter_data_0(act_inter_data_0);
		    SysArray_rtl0->act_inter_data_1(act_inter_data_1);
		    SysArray_rtl0->act_inter_data_2(act_inter_data_2);


			{
			const char *simConfig = SysArray_wrapper::simConfigName();
			
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
		    SysArray0 = new SysArray( "SysArray" );

		    SysArray0->clk(clk);
		    SysArray0->rst(rst);
		    SysArray0->weight_in_vec[0].busy(weight_in_vec_busy_0);
		    SysArray0->weight_in_vec[1].busy(weight_in_vec_busy_1);
		    SysArray0->weight_in_vec[2].busy(weight_in_vec_busy_2);
		    SysArray0->weight_in_vec[0].vld(weight_in_vec_vld_0);
		    SysArray0->weight_in_vec[1].vld(weight_in_vec_vld_1);
		    SysArray0->weight_in_vec[2].vld(weight_in_vec_vld_2);
		    SysArray0->weight_in_vec[0].data(weight_in_vec_data_0);
		    SysArray0->weight_in_vec[1].data(weight_in_vec_data_1);
		    SysArray0->weight_in_vec[2].data(weight_in_vec_data_2);
		    SysArray0->act_in_vec[0].busy(act_in_vec_busy_0);
		    SysArray0->act_in_vec[1].busy(act_in_vec_busy_1);
		    SysArray0->act_in_vec[2].busy(act_in_vec_busy_2);
		    SysArray0->act_in_vec[0].vld(act_in_vec_vld_0);
		    SysArray0->act_in_vec[1].vld(act_in_vec_vld_1);
		    SysArray0->act_in_vec[2].vld(act_in_vec_vld_2);
		    SysArray0->act_in_vec[0].data(act_in_vec_data_0);
		    SysArray0->act_in_vec[1].data(act_in_vec_data_1);
		    SysArray0->act_in_vec[2].data(act_in_vec_data_2);
		    SysArray0->accum_in_vec[0].busy(accum_in_vec_busy_0);
		    SysArray0->accum_in_vec[1].busy(accum_in_vec_busy_1);
		    SysArray0->accum_in_vec[2].busy(accum_in_vec_busy_2);
		    SysArray0->accum_in_vec[0].vld(accum_in_vec_vld_0);
		    SysArray0->accum_in_vec[1].vld(accum_in_vec_vld_1);
		    SysArray0->accum_in_vec[2].vld(accum_in_vec_vld_2);
		    SysArray0->accum_in_vec[0].data(accum_in_vec_data_0);
		    SysArray0->accum_in_vec[1].data(accum_in_vec_data_1);
		    SysArray0->accum_in_vec[2].data(accum_in_vec_data_2);
		    SysArray0->accum_out_vec[0].busy(accum_out_vec_busy_0);
		    SysArray0->accum_out_vec[1].busy(accum_out_vec_busy_1);
		    SysArray0->accum_out_vec[2].busy(accum_out_vec_busy_2);
		    SysArray0->accum_out_vec[0].vld(accum_out_vec_vld_0);
		    SysArray0->accum_out_vec[1].vld(accum_out_vec_vld_1);
		    SysArray0->accum_out_vec[2].vld(accum_out_vec_vld_2);
		    SysArray0->accum_out_vec[0].data(accum_out_vec_data_0);
		    SysArray0->accum_out_vec[1].data(accum_out_vec_data_1);
		    SysArray0->accum_out_vec[2].data(accum_out_vec_data_2);
		    SysArray0->weight_inter[0].busy(weight_inter_busy_0);
		    SysArray0->weight_inter[1].busy(weight_inter_busy_1);
		    SysArray0->weight_inter[2].busy(weight_inter_busy_2);
		    SysArray0->weight_inter[0].vld(weight_inter_vld_0);
		    SysArray0->weight_inter[1].vld(weight_inter_vld_1);
		    SysArray0->weight_inter[2].vld(weight_inter_vld_2);
		    SysArray0->weight_inter[0].data(weight_inter_data_0);
		    SysArray0->weight_inter[1].data(weight_inter_data_1);
		    SysArray0->weight_inter[2].data(weight_inter_data_2);
		    SysArray0->act_inter[0].busy(act_inter_busy_0);
		    SysArray0->act_inter[1].busy(act_inter_busy_1);
		    SysArray0->act_inter[2].busy(act_inter_busy_2);
		    SysArray0->act_inter[0].vld(act_inter_vld_0);
		    SysArray0->act_inter[1].vld(act_inter_vld_1);
		    SysArray0->act_inter[2].vld(act_inter_vld_2);
		    SysArray0->act_inter[0].data(act_inter_data_0);
		    SysArray0->act_inter[1].data(act_inter_data_1);
		    SysArray0->act_inter[2].data(act_inter_data_2);


			{
			const char *simConfig = SysArray_wrapper::simConfigName();
			
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

void SysArray_wrapper_r::InitThreads()
{
	if ( isBEH() ) 
	{
		
	}
}

void SysArray_wrapper_r::start_of_simulation()
{

#include <SysArray_trace.h>

        esc_multiple_writers_warning();
}

void SysArray_wrapper_r::CloseTrace()
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

void SysArray_wrapper_r::end_of_simulation()
{
      CloseTrace();
}



void SysArray_wrapper_r::DeleteInstances()
{
    if (SysArray0)
    {
        delete SysArray0;
        SysArray0 = 0;
    }
    if (SysArray_cosim0)
    {
        delete SysArray_cosim0;
        SysArray_cosim0 = 0;
    }
  #if defined(BDW_RTL)
    if (SysArray_rtl0)
    {
        delete SysArray_rtl0;
        SysArray_rtl0 = 0;
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

class SysArray_wrapper_fsdb_opener {
public:
	SysArray_wrapper_fsdb_opener() {
		esc_set_open_fsdb_trace( esc_open_fsdb_trace );
		esc_set_open_fsdb_scv_trace( esc_open_fsdb_scv_trace );
	}
};

static SysArray_wrapper_fsdb_opener
  SysArray_wrapper_fsdb_opener_inst;

#else

// Visible to uses of the wrapper outside of the BDW environment.
// Only behavioral SystemC simulation is supported.


// Include the source for the behavioral model so it will be compiled.
#include	"/users/student/mr112/czwu23/JJLAB/SystolicArray/1205/SysArray/SysArray.cc"

#define		SysArray_INTERNAL


#include	"SysArray_wrap.h"

const char * SysArray_wrapper::simConfigName()
{
  return "";
}

enum SysArray_wrapper::Representation SysArray_wrapper::lookupRepresentation( const char* instName )
{
  return BDWRep_Behavioral;
}

void SysArray_wrapper::InitInstances( sc_core::sc_module_name  )
{
	SysArray0 = new SysArray( "SysArray" );

	SysArray0->clk(clk);
	SysArray0->rst(rst);
	SysArray0->weight_in_vec[0].busy(weight_in_vec[0].busy);
	SysArray0->weight_in_vec[1].busy(weight_in_vec[1].busy);
	SysArray0->weight_in_vec[2].busy(weight_in_vec[2].busy);
	SysArray0->weight_in_vec[0].vld(weight_in_vec[0].vld);
	SysArray0->weight_in_vec[1].vld(weight_in_vec[1].vld);
	SysArray0->weight_in_vec[2].vld(weight_in_vec[2].vld);
	SysArray0->weight_in_vec[0].data(weight_in_vec[0].data);
	SysArray0->weight_in_vec[1].data(weight_in_vec[1].data);
	SysArray0->weight_in_vec[2].data(weight_in_vec[2].data);
	SysArray0->act_in_vec[0].busy(act_in_vec[0].busy);
	SysArray0->act_in_vec[1].busy(act_in_vec[1].busy);
	SysArray0->act_in_vec[2].busy(act_in_vec[2].busy);
	SysArray0->act_in_vec[0].vld(act_in_vec[0].vld);
	SysArray0->act_in_vec[1].vld(act_in_vec[1].vld);
	SysArray0->act_in_vec[2].vld(act_in_vec[2].vld);
	SysArray0->act_in_vec[0].data(act_in_vec[0].data);
	SysArray0->act_in_vec[1].data(act_in_vec[1].data);
	SysArray0->act_in_vec[2].data(act_in_vec[2].data);
	SysArray0->accum_in_vec[0].busy(accum_in_vec[0].busy);
	SysArray0->accum_in_vec[1].busy(accum_in_vec[1].busy);
	SysArray0->accum_in_vec[2].busy(accum_in_vec[2].busy);
	SysArray0->accum_in_vec[0].vld(accum_in_vec[0].vld);
	SysArray0->accum_in_vec[1].vld(accum_in_vec[1].vld);
	SysArray0->accum_in_vec[2].vld(accum_in_vec[2].vld);
	SysArray0->accum_in_vec[0].data(accum_in_vec[0].data);
	SysArray0->accum_in_vec[1].data(accum_in_vec[1].data);
	SysArray0->accum_in_vec[2].data(accum_in_vec[2].data);
	SysArray0->accum_out_vec[0].busy(accum_out_vec[0].busy);
	SysArray0->accum_out_vec[1].busy(accum_out_vec[1].busy);
	SysArray0->accum_out_vec[2].busy(accum_out_vec[2].busy);
	SysArray0->accum_out_vec[0].vld(accum_out_vec[0].vld);
	SysArray0->accum_out_vec[1].vld(accum_out_vec[1].vld);
	SysArray0->accum_out_vec[2].vld(accum_out_vec[2].vld);
	SysArray0->accum_out_vec[0].data(accum_out_vec[0].data);
	SysArray0->accum_out_vec[1].data(accum_out_vec[1].data);
	SysArray0->accum_out_vec[2].data(accum_out_vec[2].data);
	SysArray0->weight_inter[0].busy(weight_inter[0].busy);
	SysArray0->weight_inter[1].busy(weight_inter[1].busy);
	SysArray0->weight_inter[2].busy(weight_inter[2].busy);
	SysArray0->weight_inter[0].vld(weight_inter[0].vld);
	SysArray0->weight_inter[1].vld(weight_inter[1].vld);
	SysArray0->weight_inter[2].vld(weight_inter[2].vld);
	SysArray0->weight_inter[0].data(weight_inter[0].data);
	SysArray0->weight_inter[1].data(weight_inter[1].data);
	SysArray0->weight_inter[2].data(weight_inter[2].data);
	SysArray0->act_inter[0].busy(act_inter[0].busy);
	SysArray0->act_inter[1].busy(act_inter[1].busy);
	SysArray0->act_inter[2].busy(act_inter[2].busy);
	SysArray0->act_inter[0].vld(act_inter[0].vld);
	SysArray0->act_inter[1].vld(act_inter[1].vld);
	SysArray0->act_inter[2].vld(act_inter[2].vld);
	SysArray0->act_inter[0].data(act_inter[0].data);
	SysArray0->act_inter[1].data(act_inter[1].data);
	SysArray0->act_inter[2].data(act_inter[2].data);

}

void SysArray_wrapper::InitThreads()
{
}

void SysArray_wrapper::CloseTrace()
{
}

void SysArray_wrapper::DeleteInstances()
{
    if (SysArray0)
    {
        delete SysArray0;
        SysArray0 = 0;
    }
}

void SysArray_wrapper::start_of_simulation()
{
}

void SysArray_wrapper::end_of_simulation()
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

class SysArray_wrapper_fsdb_opener {
public:
	SysArray_wrapper_fsdb_opener() {
	}
};

static SysArray_wrapper_fsdb_opener
  SysArray_wrapper_fsdb_opener_inst;

#endif

#endif
