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


SC_MODULE( SysArray )
{
	// Declare the clock and reset ports
	sc_in< bool >	clk;
	sc_in< bool >	rst;

	const static int N = 3;
	SysPE* pe_array[N][N];
	// Declare the input port and the output port.
	// The template specializations <DT_*> configure the
	// modular interfaces to carry the desired datatypes.
	// The input port

	/////////////////////////////////////////
	cynw_p2p < InputType >::in   weight_in_vec[N];
	cynw_p2p < InputType >::in   act_in_vec[N];
	cynw_p2p < AccumType >::out  accum_out_vec[N];

	cynw_p2p <InputType>::in weight_inter[N][N];
	cynw_p2p <InputType>::in act_inter[N][N]; 
	cynw_p2p <AccumType>::out accum_inter[N][N];

  cynw_p2p <InputType> weight_chan[N][N];
	cynw_p2p <InputType> act_chan[N][N]; 
	cynw_p2p <AccumType> accum_chan[N][N];
	/////////////////////////////////////////
  /*
  **************TO DO****************
  channel數要調整，對應到PE的index也要更改
  ***********************************
  */
  SC_HAS_PROCESS(SysArray);
  SysArray(sc_module_name name_)
  : sc_module(name_),
    clk("clk"),
    rst("rst")
  {
    for(int i = 0 ; i < N ; i++){
				char act_in_vec_name[15];
				sprintf(act_in_vec_name, "act_in_vec[%d]", (i+ 1) );
				char weight_in_vec_name[15];
				sprintf(weight_in_vec_name, "weight_in_vec[%d]", (i+ 1) );
				char accum_out_vec_name[15];
				sprintf(accum_out_vec_name, "accum_out_vec[%d]", (i+ 1) );
        for(int j = 0 ; j < N ; j++){
          char act_chan_name[15];
				  sprintf(act_chan_name, "act_chan[%d][%d]", (i+1) ,(j+1) );
          char act_inter_name[15];
				  sprintf(act_inter_name, "act_inter[%d][%d]", (i+1) ,(j+1) );

				  char weight_chan_name[15];
				  sprintf(weight_chan_name, "weight_chan[%d][%d]", (i+1) ,(j+1) );
          char weight_inter_name[15];
				  sprintf(weight_inter_name, "weight_inter[%d][%d]", (i+1) ,(j+1) );

				  char accum_chan_name[15];
				  sprintf(accum_chan_name, "accum_chan[%d][%d]", (i+1) ,(j+1) );
           char accum_inter_name[15];
				  sprintf(accum_inter_name, "accum_inter[%d][%d]", (i+1) ,(j+1) );
        }
			}

    for (int i = 0; i < N; i++) {    // rows
      for (int j = 0; j < N; j++) {  // cols
        pe_array[i][j] = new SysPE(sc_gen_unique_name("pe"));
        pe_array[i][j]->clk(clk);
        pe_array[i][j]->rst(rst);
        
        // Weight Connections
        if (i == 0) {    // from Array weight (row 0)
          pe_array[i][j]->weight_in(weight_in_vec[j]);
          pe_array[i][j]->weight_out(weight_chan[i][j]);
          weight_inter[i][j](weight_chan[i][j]);
        }

        else {           // from Array weight (row 1, 2, N-1)
          pe_array[i][j]->weight_in(weight_inter[i-1][j]);
          pe_array[i][j]->weight_out(weight_chan[i][j]);
          weight_inter[i][j](weight_chan[i][j]);
        }
        // Act Connections
        if (j == 0) {  // from Array input (col 0)
          pe_array[i][j]->act_in(act_in_vec[i]);
          pe_array[i][j]->act_out(act_chan[i][j]);
          act_inter[i][j](act_chan[i][j]);
        }
        else {         // from Array input (col 1, 2...)
          pe_array[i][j]->act_in(act_inter[i][j-1]);
          pe_array[i][j]->act_out(act_chan[i][j]);
          act_inter[i][j](act_chan[i][j]);
        }
        // Accum Connections
        if (i != N-1) {  // from Array Accum (row 0, 1, N-2)
          pe_array[i][j]->accum_in(accum_chan[i][j]);
          accum_inter[i][j](accum_chan[i][j]);
          pe_array[i][j]->accum_out(accum_inter[i+1][j]);
        }
        else {           // from Array Accum (row N-1)
          pe_array[i][j]->accum_in(accum_chan[i][j]);
          accum_inter[i][j](accum_chan[i][j]);
          pe_array[i][j]->accum_out(accum_out_vec[j]);
        }
      }  
    }

    SC_CTHREAD( WeightOutRun, clk.pos() );
    reset_signal_is( rst, 0 );
      
    SC_CTHREAD( ActOutRun, clk.pos() );
    reset_signal_is( rst, 0 );
    
    SC_CTHREAD( AccumInRun, clk.pos() );
    reset_signal_is( rst, 0 );

    for(int i = 0; i < N; i++){
      weight_in_vec[i].clk_rst( clk, rst );
      act_in_vec[i].clk_rst( clk, rst );
      accum_out_vec[i].clk_rst( clk, rst );
      for(int j = 0 ; j < N ; j++){
        accum_inter[i][j].clk_rst( clk, rst );
        act_inter[i][j].clk_rst( clk, rst );
        weight_inter[i][j].clk_rst( clk, rst );
      }
    }
  }
void WeightOutRun();
void ActOutRun();
void AccumInRun();

};
#endif // DUT_H
