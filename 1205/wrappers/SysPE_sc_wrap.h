/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _SYSPE_SC_WRAP_INCLUDED_
#define _SYSPE_SC_WRAP_INCLUDED_

#include <systemc.h>

struct SysPE;

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
    
    
	// create the netlist
    void InitInstances( );
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

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
		  	

		  ,SysPE0(0)

    {
        InitInstances( );
		InitThreads();
    }

    // destructor
    ~SysPE_wrapper()
    {
        DeleteInstances();
    }

	SysPE* SysPE0;
};

#endif /* _SYSPE_SC_WRAP_INCLUDED_ */
