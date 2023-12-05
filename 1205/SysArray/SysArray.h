///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2020 Cadence Design Systems, Inc. All rights reserved worldwide.
//
// The code contained herein is the proprietary and confidential information
// of Cadence or its licensors, and is supplied subject to a previously
// executed license and maintenance agreement between Cadence and customer.
// This code is intended for use with Cadence high-level synthesis tools and
// may not be used with other high-level synthesis tools. Permission is only
// granted to distribute the code as indicated. Cadence grants permission for
// customer to distribute a copy of this code to any partner to aid in designing
// or verifying the customer's intellectual property, as long as such
// distribution includes a restriction of no additional distributions from the
// partner, unless the partner receives permission directly from Cadence.
//
// ALL CODE FURNISHED BY CADENCE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, AND CADENCE SPECIFICALLY DISCLAIMS ANY WARRANTY OF NONINFRINGEMENT,
// FITNESS FOR A PARTICULAR PURPOSE OR MERCHANTABILITY. CADENCE SHALL NOT BE
// LIABLE FOR ANY COSTS OF PROCUREMENT OF SUBSTITUTES, LOSS OF PROFITS,
// INTERRUPTION OF BUSINESS, OR FOR ANY OTHER SPECIAL, CONSEQUENTIAL OR
// INCIDENTAL DAMAGES, HOWEVER CAUSED, WHETHER FOR BREACH OF WARRANTY,
// CONTRACT, TORT, NEGLIGENCE, STRICT LIABILITY OR OTHERWISE.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef DUT_H
#define DUT_H

#include <cynw_p2p.h>
#include "defines.h"
#include "SysPE.h"
#include "string"
//#include "SysPE_wrap.h"


SC_MODULE( SysArray )
{
	// Declare the clock and reset ports
	sc_in< bool >	clk;
	sc_in< bool >	rst;

	const static int N = 3;
	SysPE*   pe_array[N][N];
	// Declare the input port and the output port.
	// The template specializations <DT_*> configure the
	// modular interfaces to carry the desired datatypes.
	// The input port

	/////////////////////////////////////////
  //connect to tb
	cynw_p2p < InputType >::base_in   weight_in_vec[N];
	cynw_p2p < InputType >::base_in   act_in_vec[N];
  cynw_p2p < AccumType >::base_in   accum_in_vec[N];
	cynw_p2p < AccumType >::base_out  accum_out_vec[N];

  //interconnect with PE
  //inter ports PE out . channel
  //next PE's in . channel
  ///////////////////////////////////////////
  //inter port have some problem should be fixed
  //maybe add channel to connect the inter port with the PE in/out ports 

	cynw_p2p <InputType>::base_in weight_inter[N];
	cynw_p2p <InputType>::base_in act_inter[N]; 

  //interconnect channels
  cynw_p2p <InputType> weight_chan[N][N];
	cynw_p2p <InputType> act_chan[N][N]; 
	cynw_p2p <AccumType> accum_chan[N-1][N];
	/////////////////////////////////////////

  SC_CTOR( SysArray )
	: clk( "clk" )
	, rst( "rst" )
  { 
    for (int i = 0; i < N; i++) {    // rows
      for (int j = 0; j < N; j++) {  // cols
        pe_array[i][j] = new SysPE(sc_gen_unique_name("pe"));
        pe_array[i][j]->clk(clk);
        pe_array[i][j]->rst(rst);
        // Weight Connections
        if (i == 0) {    // from Array weight (row 0)
          pe_array[i][j]->weight_in(weight_in_vec[j]);
          pe_array[i][j]->weight_out(weight_chan[i][j]);
        }

        else if(i == N-1){         // from Array weight (row 1, 2, N-2)
          pe_array[i][j]->weight_in(weight_chan[i-1][j]);
          pe_array[i][j]->weight_out(weight_chan[i][j]);
          weight_inter[j](weight_chan[i][j]);
        }
        else{         // from Array weight (row 1, 2, N-2)
          pe_array[i][j]->weight_in(weight_chan[i-1][j]);
          pe_array[i][j]->weight_out(weight_chan[i][j]);
        }
        
        // Act Connections
        //item i-1 or j-1 may cause binding port error
        if (j == 0) {  // from Array input (col 0)
          pe_array[i][j]->act_in(act_in_vec[i]);
          pe_array[i][j]->act_out(act_chan[i][j]);
        }
        else if(j == N-1){                     // from Array input (col 1, 2...)
          pe_array[i][j]->act_in(act_chan[i][j-1]);
          pe_array[i][j]->act_out(act_chan[i][j]);
          act_inter[i](act_chan[i][j]);
        }
        else{
          pe_array[i][j]->act_in(act_chan[i][j-1]);
          pe_array[i][j]->act_out(act_chan[i][j]);
        }
        // Accum Connections
        /*
        Error: (E109) complete binding failed: port not bound: port 'system.SysArray_wrapper.p2p_out_5_data' (sc_out)
        In file: ../../../src/sysc/communication/sc_port.cpp:235    
        */
        if (i == 0) {  // from Array Accum (row 0, 1, N-2)
          pe_array[i][j]->accum_in(accum_in_vec[j]);
          pe_array[i][j]->accum_out(accum_chan[i][j]);
        }

        else if(i == N-1){
          pe_array[i][j]->accum_in(accum_chan[i-1][j]);
          pe_array[i][j]->accum_out(accum_out_vec[j]);
        }
        else{
          pe_array[i][j]->accum_in(accum_chan[i-1][j]);
          pe_array[i][j]->accum_out(accum_chan[i][j]);
        }
      }  
    }
    
    SC_CTHREAD( WeightOutRun, clk.pos() );
    reset_signal_is( rst, 0 );
      
    SC_CTHREAD( ActOutRun, clk.pos() );
    reset_signal_is( rst, 0 );
    

    

    for(int i = 0; i < N; i++){
      weight_in_vec[i].clk_rst( clk, rst );
      act_in_vec[i].clk_rst( clk, rst );
      accum_in_vec[i].clk_rst( clk, rst );
      accum_out_vec[i].clk_rst( clk, rst );
      act_inter[i].clk_rst( clk, rst );
      weight_inter[i].clk_rst( clk, rst );
    }
  }
void WeightOutRun();
void ActOutRun();

};
#endif // DUT_H
