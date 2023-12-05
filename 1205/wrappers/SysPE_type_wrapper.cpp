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

#include "SysPE_type_wrapper.h"


SC_MODULE_EXPORT(SysPE_type_wrapper)

// The following threads are used to connect RTL ports to the actual
// structured ports

void SysPE_type_wrapper::InitInstances()
{
    SysPE0 = new SysPE( "SysPE" );

    SysPE0->clk(clk);
    SysPE0->rst(rst);
    SysPE0->weight_in.busy(weight_in_busy);
    SysPE0->weight_in.vld(weight_in_vld);
    SysPE0->weight_in.data(weight_in_data);
    SysPE0->act_in.busy(act_in_busy);
    SysPE0->act_in.vld(act_in_vld);
    SysPE0->act_in.data(act_in_data);
    SysPE0->accum_in.busy(accum_in_busy);
    SysPE0->accum_in.vld(accum_in_vld);
    SysPE0->accum_in.data(accum_in_data);
    SysPE0->weight_out.busy(weight_out_busy);
    SysPE0->weight_out.vld(weight_out_vld);
    SysPE0->weight_out.data(weight_out_data);
    SysPE0->act_out.busy(act_out_busy);
    SysPE0->act_out.vld(act_out_vld);
    SysPE0->act_out.data(act_out_data);
    SysPE0->accum_out.busy(accum_out_busy);
    SysPE0->accum_out.vld(accum_out_vld);
    SysPE0->accum_out.data(accum_out_data);

}

void SysPE_type_wrapper::InitThreads()
{
    
}

void SysPE_type_wrapper::DeleteInstances()
{
        delete SysPE0;
        SysPE0 = 0;
}

