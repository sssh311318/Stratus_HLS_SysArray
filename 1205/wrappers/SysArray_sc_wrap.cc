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


#include	"SysArray_sc_wrap.h"
#include	"SysArray_sc_foreign.h"

// The following threads are used to connect structured ports to the actual
// RTL ports

void SysArray_wrapper::InitInstances(  )
{
	
            
    SysArray0 = new SysArray( "SysArray" );

    SysArray0->clk(clk);
    SysArray0->rst(rst);
    SysArray0->weight_in_vec_busy_0(weight_in_vec[0].busy);
    SysArray0->weight_in_vec_busy_1(weight_in_vec[1].busy);
    SysArray0->weight_in_vec_busy_2(weight_in_vec[2].busy);
    SysArray0->weight_in_vec_vld_0(weight_in_vec[0].vld);
    SysArray0->weight_in_vec_vld_1(weight_in_vec[1].vld);
    SysArray0->weight_in_vec_vld_2(weight_in_vec[2].vld);
    SysArray0->weight_in_vec_data_0(weight_in_vec[0].data);
    SysArray0->weight_in_vec_data_1(weight_in_vec[1].data);
    SysArray0->weight_in_vec_data_2(weight_in_vec[2].data);
    SysArray0->act_in_vec_busy_0(act_in_vec[0].busy);
    SysArray0->act_in_vec_busy_1(act_in_vec[1].busy);
    SysArray0->act_in_vec_busy_2(act_in_vec[2].busy);
    SysArray0->act_in_vec_vld_0(act_in_vec[0].vld);
    SysArray0->act_in_vec_vld_1(act_in_vec[1].vld);
    SysArray0->act_in_vec_vld_2(act_in_vec[2].vld);
    SysArray0->act_in_vec_data_0(act_in_vec[0].data);
    SysArray0->act_in_vec_data_1(act_in_vec[1].data);
    SysArray0->act_in_vec_data_2(act_in_vec[2].data);
    SysArray0->accum_in_vec_busy_0(accum_in_vec[0].busy);
    SysArray0->accum_in_vec_busy_1(accum_in_vec[1].busy);
    SysArray0->accum_in_vec_busy_2(accum_in_vec[2].busy);
    SysArray0->accum_in_vec_vld_0(accum_in_vec[0].vld);
    SysArray0->accum_in_vec_vld_1(accum_in_vec[1].vld);
    SysArray0->accum_in_vec_vld_2(accum_in_vec[2].vld);
    SysArray0->accum_in_vec_data_0(accum_in_vec[0].data);
    SysArray0->accum_in_vec_data_1(accum_in_vec[1].data);
    SysArray0->accum_in_vec_data_2(accum_in_vec[2].data);
    SysArray0->accum_out_vec_busy_0(accum_out_vec[0].busy);
    SysArray0->accum_out_vec_busy_1(accum_out_vec[1].busy);
    SysArray0->accum_out_vec_busy_2(accum_out_vec[2].busy);
    SysArray0->accum_out_vec_vld_0(accum_out_vec[0].vld);
    SysArray0->accum_out_vec_vld_1(accum_out_vec[1].vld);
    SysArray0->accum_out_vec_vld_2(accum_out_vec[2].vld);
    SysArray0->accum_out_vec_data_0(accum_out_vec[0].data);
    SysArray0->accum_out_vec_data_1(accum_out_vec[1].data);
    SysArray0->accum_out_vec_data_2(accum_out_vec[2].data);
    SysArray0->weight_inter_busy_0(weight_inter[0].busy);
    SysArray0->weight_inter_busy_1(weight_inter[1].busy);
    SysArray0->weight_inter_busy_2(weight_inter[2].busy);
    SysArray0->weight_inter_vld_0(weight_inter[0].vld);
    SysArray0->weight_inter_vld_1(weight_inter[1].vld);
    SysArray0->weight_inter_vld_2(weight_inter[2].vld);
    SysArray0->weight_inter_data_0(weight_inter[0].data);
    SysArray0->weight_inter_data_1(weight_inter[1].data);
    SysArray0->weight_inter_data_2(weight_inter[2].data);
    SysArray0->act_inter_busy_0(act_inter[0].busy);
    SysArray0->act_inter_busy_1(act_inter[1].busy);
    SysArray0->act_inter_busy_2(act_inter[2].busy);
    SysArray0->act_inter_vld_0(act_inter[0].vld);
    SysArray0->act_inter_vld_1(act_inter[1].vld);
    SysArray0->act_inter_vld_2(act_inter[2].vld);
    SysArray0->act_inter_data_0(act_inter[0].data);
    SysArray0->act_inter_data_1(act_inter[1].data);
    SysArray0->act_inter_data_2(act_inter[2].data);

}

void SysArray_wrapper::InitThreads()
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

