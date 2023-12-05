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

#include "SysArray_type_wrapper.h"


SC_MODULE_EXPORT(SysArray_type_wrapper)

// The following threads are used to connect RTL ports to the actual
// structured ports

void SysArray_type_wrapper::InitInstances()
{
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

}

void SysArray_type_wrapper::InitThreads()
{
    
}

void SysArray_type_wrapper::DeleteInstances()
{
        delete SysArray0;
        SysArray0 = 0;
}

