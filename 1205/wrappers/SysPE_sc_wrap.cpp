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
* block called "SysPE". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/


#include	"SysPE_sc_wrap.h"
#include	"SysPE_sc_foreign.h"

// The following threads are used to connect structured ports to the actual
// RTL ports

void SysPE_wrapper::InitInstances(  )
{
	
            
    SysPE0 = new SysPE( "SysPE" );

    SysPE0->clk(clk);
    SysPE0->rst(rst);
    SysPE0->weight_in_busy(weight_in.busy);
    SysPE0->weight_in_vld(weight_in.vld);
    SysPE0->weight_in_data(weight_in.data);
    SysPE0->act_in_busy(act_in.busy);
    SysPE0->act_in_vld(act_in.vld);
    SysPE0->act_in_data(act_in.data);
    SysPE0->accum_in_busy(accum_in.busy);
    SysPE0->accum_in_vld(accum_in.vld);
    SysPE0->accum_in_data(accum_in.data);
    SysPE0->weight_out_busy(weight_out.busy);
    SysPE0->weight_out_vld(weight_out.vld);
    SysPE0->weight_out_data(weight_out.data);
    SysPE0->act_out_busy(act_out.busy);
    SysPE0->act_out_vld(act_out.vld);
    SysPE0->act_out_data(act_out.data);
    SysPE0->accum_out_busy(accum_out.busy);
    SysPE0->accum_out_vld(accum_out.vld);
    SysPE0->accum_out_data(accum_out.data);

}

void SysPE_wrapper::InitThreads()
{
    
}

void SysPE_wrapper::DeleteInstances()
{
    if (SysPE0)
    {
        delete SysPE0;
        SysPE0 = 0;
    }
}

