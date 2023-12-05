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
* This file contains the SysArray_type_wrapper module
* for use in the verilog verification wrapper SysArray_vlwrapper.v
* It creats an instance of the SysArray module and has threads
* for converting the BEH ports to RTL level ports on the wrapper.
*
****************************************************************************/


#ifndef _SYSARRAY_TYPE_WRAP_INCLUDED_
#define _SYSARRAY_TYPE_WRAP_INCLUDED_


#include <systemc.h>
#include "SysArray.h"


// Declaration of wrapper with RTL level ports

SC_MODULE(SysArray_type_wrapper)
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
	sc_in< bool > accum_inter_busy_0;
	sc_in< bool > accum_inter_busy_1;
	sc_in< bool > accum_inter_busy_2;
	sc_out< bool > accum_inter_vld_0;
	sc_out< bool > accum_inter_vld_1;
	sc_out< bool > accum_inter_vld_2;
	sc_out< sc_uint< 32 > > accum_inter_data_0;
	sc_out< sc_uint< 32 > > accum_inter_data_1;
	sc_out< sc_uint< 32 > > accum_inter_data_2;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    

	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(SysArray_type_wrapper);

	SysArray_type_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("SysArray")) )
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
		  	,accum_inter_busy_0("accum_inter_busy_0")
		  	,accum_inter_busy_1("accum_inter_busy_1")
		  	,accum_inter_busy_2("accum_inter_busy_2")
		  	,accum_inter_vld_0("accum_inter_vld_0")
		  	,accum_inter_vld_1("accum_inter_vld_1")
		  	,accum_inter_vld_2("accum_inter_vld_2")
		  	,accum_inter_data_0("accum_inter_data_0")
		  	,accum_inter_data_1("accum_inter_data_1")
		  	,accum_inter_data_2("accum_inter_data_2")
		  	

		  ,SysArray0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~SysArray_type_wrapper()
    {
        DeleteInstances();
    }


protected:
	SysArray* SysArray0;
};

#endif /*  */
