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
* This file contains the SysPE_type_wrapper module
* for use in the verilog verification wrapper SysPE_vlwrapper.v
* It creats an instance of the SysPE module and has threads
* for converting the BEH ports to RTL level ports on the wrapper.
*
****************************************************************************/


#ifndef _SYSPE_TYPE_WRAP_INCLUDED_
#define _SYSPE_TYPE_WRAP_INCLUDED_


#include <systemc.h>
#include "SysPE.h"


// Declaration of wrapper with RTL level ports

SC_MODULE(SysPE_type_wrapper)
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
    
    

	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(SysPE_type_wrapper);

	SysPE_type_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("SysPE")) )
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
		  	

		  ,SysPE0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~SysPE_type_wrapper()
    {
        DeleteInstances();
    }


protected:
	SysPE* SysPE0;
};

#endif /*  */
