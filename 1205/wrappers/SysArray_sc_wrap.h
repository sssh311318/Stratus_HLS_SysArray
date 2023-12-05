/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _SYSARRAY_SC_WRAP_INCLUDED_
#define _SYSARRAY_SC_WRAP_INCLUDED_

#include <systemc.h>

struct SysArray;

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
    
    
	// create the netlist
    void InitInstances( );
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

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
		  	

		  ,SysArray0(0)

    {
        InitInstances( );
		InitThreads();
    }

    // destructor
    ~SysArray_wrapper()
    {
        DeleteInstances();
    }

	SysArray* SysArray0;
};

#endif /* _SYSARRAY_SC_WRAP_INCLUDED_ */
