/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _SYSPE_SC_FOREIGN_INCLUDED_
#define _SYSPE_SC_FOREIGN_INCLUDED_

#include <systemc.h>

#if !defined(XM_SYSTEMC) && defined(NC_SYSTEMC)
#define xmsc_foreign_module ncsc_foreign_module
#endif


// Declaration of wrapper with RTL level ports

struct SysPE : public xmsc_foreign_module
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


    const char* hdl_name() const { return "SysPE"; }
    
	SysPE( sc_module_name name )
		: xmsc_foreign_module(name)
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
		  	

		
    {
    }

};

#endif /* _SYSPE_SC_FOREIGN_INCLUDED_ */
