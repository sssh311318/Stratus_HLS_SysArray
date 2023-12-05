/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _SYSARRAY_SC_FOREIGN_INCLUDED_
#define _SYSARRAY_SC_FOREIGN_INCLUDED_

#include <systemc.h>

#if !defined(XM_SYSTEMC) && defined(NC_SYSTEMC)
#define xmsc_foreign_module ncsc_foreign_module
#endif


// Declaration of wrapper with RTL level ports

struct SysArray : public xmsc_foreign_module
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


    const char* hdl_name() const { return "SysArray"; }
    
	SysArray( sc_module_name name )
		: xmsc_foreign_module(name)
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
    }

};

#endif /* _SYSARRAY_SC_FOREIGN_INCLUDED_ */
