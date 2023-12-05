/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _SYSARRAY_WRAP_INCLUDED_
#define _SYSARRAY_WRAP_INCLUDED_

#ifndef BDW_NO_SUBMOD_WRAPPERS


/* Save ioConfig define values for parent module and define those for this module's ioConfigs. */


#if defined(STRATUS_VLG) 

#include <systemc.h>

#define SysArray_wrapper SysArray

/* This is the section that is seen during processing by stratus_vlg of a module
 * that instantiates the module defined by this wrapper.
 */
SC_MODULE(SysArray)
{
public:
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

	SC_CTOR(SysArray);
};

#elif defined(CYNTHHL) || defined(BDW_EXTRACT)

/* This is the section seen during processing by stratus_hls or bdw_extract of a module 
 * that instantiates the module defined by this wrapper.
 */
#include <systemc.h>

#include "cynw_p2p.h"
#include "hls_enums.h"


#define SysArray_wrapper SysArray

/* Only port declarations are required for nested modules.
 */
SC_MODULE(SysArray)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > weight_in_vec[3];
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > act_in_vec[3];
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > accum_in_vec[3];
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > accum_out_vec[3];
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > weight_inter[3];
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > act_inter[3];


	SC_HAS_PROCESS(SysArray);
    	SysArray_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("SysArray")) );
};

#else

#include <esc.h>


/* This is the section seen during processing by gcc either when the module
 * itself is compiled, or when a module that instantiates it is compiled.
 */

struct SysArray;
struct SysArray_cosim;
struct SysArray_rtl;

#include "cynw_p2p.h"
#include "hls_enums.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(SysArray_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > weight_in_vec[3];
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > act_in_vec[3];
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > accum_in_vec[3];
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > accum_out_vec[3];
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > weight_inter[3];
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > act_inter[3];

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };
	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances( );
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(SysArray_wrapper);

    	SysArray_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("SysArray")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,weight_in_vec()
		  	,act_in_vec()
		  	,accum_in_vec()
		  	,accum_out_vec()
		  	,weight_inter()
		  	,act_inter()
		  	

          		  ,SysArray0(0), SysArray_cosim0(0), SysArray_rtl0(0)
		

    {
        InitInstances( );
		InitThreads();
    }


    // destructor
    ~SysArray_wrapper()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( SysArray_wrapper::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( SysArray_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( SysArray_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( SysArray_wrapper::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
    
        
#ifdef SysArray_INTERNAL
	SysArray* behModule() { return SysArray0; }
#else
	SysArray* behModule() { return SysArray0; }
#endif
	SysArray_cosim* cosimModule() { return SysArray_cosim0; }
    	SysArray_rtl* rtlModule() { return SysArray_rtl0; }

#ifdef SysArray_INTERNAL
	SysArray* SysArray0;
#else
	SysArray* SysArray0;
#endif
	SysArray_cosim* SysArray_cosim0;
	SysArray_rtl* SysArray_rtl0;
	};

// Declaration of wrapper with RTL level ports

SC_MODULE(SysArray_wrapper_r)
{
public:

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

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };

	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(SysArray_wrapper_r);

	SysArray_wrapper_r( sc_module_name name = sc_module_name( sc_gen_unique_name("SysArray")) )
		: sc_module(name)
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
		  	

          		  ,SysArray0(0), SysArray_cosim0(0), SysArray_rtl0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~SysArray_wrapper_r()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( SysArray_wrapper_r::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( SysArray_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( SysArray_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( SysArray_wrapper_r::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
	
#ifdef SysArray_INTERNAL
	SysArray* behModule() { return SysArray0; }
#else
	SysArray* behModule() { return SysArray0; }
#endif
	SysArray_cosim* cosimModule() { return SysArray_cosim0; }
		SysArray_rtl* rtlModule() { return SysArray_rtl0; }

protected:
#ifdef SysArray_INTERNAL
	SysArray* SysArray0;
#else
	SysArray* SysArray0;
#endif
	SysArray_cosim* SysArray_cosim0;
	SysArray_rtl* SysArray_rtl0;
	};

#endif

/* Restore ioConfig define values for parent module. */


#else /* BDW_NO_SUBMOD_WRAPPERS */

#define SysArray_wrapper SysArray
#include "SysArray.h"

#endif /* BDW_NO_SUBMOD_WRAPPERS */

#endif /*  */
