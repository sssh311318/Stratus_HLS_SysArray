/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _SYSPE_WRAP_INCLUDED_
#define _SYSPE_WRAP_INCLUDED_

#ifndef BDW_NO_SUBMOD_WRAPPERS


/* Save ioConfig define values for parent module and define those for this module's ioConfigs. */


#if defined(STRATUS_VLG) 

#include <systemc.h>

#define SysPE_wrapper SysPE

/* This is the section that is seen during processing by stratus_vlg of a module
 * that instantiates the module defined by this wrapper.
 */
SC_MODULE(SysPE)
{
public:
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

	SC_CTOR(SysPE);
};

#elif defined(CYNTHHL) || defined(BDW_EXTRACT)

/* This is the section seen during processing by stratus_hls or bdw_extract of a module 
 * that instantiates the module defined by this wrapper.
 */
#include <systemc.h>

#include "cynw_p2p.h"
#include "hls_enums.h"


#define SysPE_wrapper SysPE

/* Only port declarations are required for nested modules.
 */
SC_MODULE(SysPE)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > weight_in;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > act_in;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > accum_in;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > weight_out;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > act_out;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > accum_out;


	SC_HAS_PROCESS(SysPE);
    	SysPE_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("SysPE")) );
};

#else

#include <esc.h>


/* This is the section seen during processing by gcc either when the module
 * itself is compiled, or when a module that instantiates it is compiled.
 */

struct SysPE;
struct SysPE_cosim;
struct SysPE_rtl;

#include "cynw_p2p.h"
#include "hls_enums.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(SysPE_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > weight_in;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > act_in;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > accum_in;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > weight_out;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)8 >, HLS::hls_enum <(int)1 > > act_out;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)32 >, HLS::hls_enum <(int)1 > > accum_out;

    
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
    

	SC_HAS_PROCESS(SysPE_wrapper);

    	SysPE_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("SysPE")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,weight_in("weight_in")
		  	,act_in("act_in")
		  	,accum_in("accum_in")
		  	,weight_out("weight_out")
		  	,act_out("act_out")
		  	,accum_out("accum_out")
		  	

          		  ,SysPE0(0), SysPE_cosim0(0), SysPE_rtl0(0)
		

    {
        InitInstances( );
		InitThreads();
    }


    // destructor
    ~SysPE_wrapper()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( SysPE_wrapper::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( SysPE_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( SysPE_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( SysPE_wrapper::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
    
        
#ifdef SysPE_INTERNAL
	SysPE* behModule() { return SysPE0; }
#else
	SysPE* behModule() { return SysPE0; }
#endif
	SysPE_cosim* cosimModule() { return SysPE_cosim0; }
    	SysPE_rtl* rtlModule() { return SysPE_rtl0; }

#ifdef SysPE_INTERNAL
	SysPE* SysPE0;
#else
	SysPE* SysPE0;
#endif
	SysPE_cosim* SysPE_cosim0;
	SysPE_rtl* SysPE_rtl0;
	};

// Declaration of wrapper with RTL level ports

SC_MODULE(SysPE_wrapper_r)
{
public:

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
    

	SC_HAS_PROCESS(SysPE_wrapper_r);

	SysPE_wrapper_r( sc_module_name name = sc_module_name( sc_gen_unique_name("SysPE")) )
		: sc_module(name)
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
		  	

          		  ,SysPE0(0), SysPE_cosim0(0), SysPE_rtl0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~SysPE_wrapper_r()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( SysPE_wrapper_r::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( SysPE_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( SysPE_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( SysPE_wrapper_r::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
	
#ifdef SysPE_INTERNAL
	SysPE* behModule() { return SysPE0; }
#else
	SysPE* behModule() { return SysPE0; }
#endif
	SysPE_cosim* cosimModule() { return SysPE_cosim0; }
		SysPE_rtl* rtlModule() { return SysPE_rtl0; }

protected:
#ifdef SysPE_INTERNAL
	SysPE* SysPE0;
#else
	SysPE* SysPE0;
#endif
	SysPE_cosim* SysPE_cosim0;
	SysPE_rtl* SysPE_rtl0;
	};

#endif

/* Restore ioConfig define values for parent module. */


#else /* BDW_NO_SUBMOD_WRAPPERS */

#define SysPE_wrapper SysPE
#include "SysPE.h"

#endif /* BDW_NO_SUBMOD_WRAPPERS */

#endif /*  */
