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

#ifndef TB_H
#define TB_H

#define NUM 11		// Number of stimulus values

#include <cynw_p2p.h>	// The P2P port header file
#include "defines.h"	// The type definitions for the input and output
const static int N = SysArray::N;
SC_MODULE( tb )
{
	sc_in< bool >	clk;		// Declare clock and reset ports
	sc_out< bool >	rst;		// The source thread drives rst_out.

	cynw_p2p < InputType >::base_out act_in_vec[N]; // data going in to the design
	cynw_p2p < InputType >::base_out weight_in_vec[N];
	cynw_p2p < AccumType >::base_in accum_out_vec[N];  // data going out of the design

	SC_CTOR( tb )
	: clk( "clk" )
	, rst( "rst" )
	{	
		for(int i = 0 ; i < N ; i++){
			char act_in_name[15];
			sprintf(act_in_name, "act_in_vec%d", (i+ 1) );
			char weight_in_name[15];
			sprintf(weight_in_name, "weight_in_vec%d", (i+ 1) );
			char accum_out_name[15];
			sprintf(accum_out_name, "accum_out_vec%d", (i+ 1) );
		}
		// Declare the source and sink threads. Since they 
		// drive the reset signal, no reset_signal_is() is needed
		SC_CTHREAD( source, clk.pos() );
		SC_CTHREAD( sink, clk.pos() );
        reset_signal_is(rst,0);

                // connect clk/rst to cynw_p2p ports
		for(int i = 0 ; i < N ; i++){
      		accum_out_vec[i].clk_rst( clk, rst );
      		act_in_vec[i].clk_rst( clk, rst );
      		weight_in_vec[i].clk_rst( clk, rst );
   		}
	}
  
	void source();
	void sink();

	sc_time start_time[NUM];	// sc_time array to store times that input is sent to DUT

	FILE *infpA;			// File pointer for stimulus file
	FILE *infpB;
	FILE *outfpC;		// File pointer for results file
};

#endif // TB_H
