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

// Number of stimulus values		

#include "SysPE.h"
#include <systemc.h>
#include <vector>
using namespace::std;

#include <cynw_p2p.h>	// The P2P port header file
#include "defines.h"	// The type definitions for the input and output


SC_MODULE( tb )
{
	
	sc_in< bool >	clk;		// Declare clock and reset ports
	sc_out< bool >	rst;		// The source thread drives rst_out.
	
	// data going in to the design
	////////////////////////////////////////
	cynw_p2p < InputType >::out   weight_in;
	cynw_p2p < InputType >::out   act_in;
	cynw_p2p < AccumType >::out   accum_in;
	
	cynw_p2p < InputType >::in  weight_out;
	cynw_p2p < InputType >::in  act_out;
	cynw_p2p < AccumType >::in  accum_out;
	////////////////////////////////////////
	bool start_src;  
	vector<InputType> act_list{0, 1, 3, 7, 15, 31, 63, 127};
	vector<AccumType> accum_list{0, 10, 30, 70, 150, 310, 630, 1270};
	InputType weight_data = 10;
	AccumType accum_init = 0;
	InputType act_out_src;
	AccumType accum_out_src;

	SC_CTOR( tb )
	: clk( "clk" )
	, rst( "rst" )
	, weight_in( "weight_in" )
	, act_in( "act_in" )
	, accum_in( "accum_in" )
	, weight_out( "weight_out" )
	, act_out( "act_out" )
	, accum_out( "accum_out" )
	{
		// Declare the source and sink threads. Since they 
		// drive the reset signal, no reset_signal_is() is needed
		SC_CTHREAD( source, clk.pos() );
		SC_CTHREAD( pop_result, clk.pos() );
        reset_signal_is(rst,0);

		weight_in.clk_rst( clk, rst );
		act_in.clk_rst( clk, rst );
		accum_in.clk_rst( clk, rst );

		weight_out.clk_rst( clk, rst );
		act_out.clk_rst( clk, rst );
		accum_out.clk_rst( clk, rst );

	}
                // connect clk/rst to cynw_p2p ports

	void source();
	void pop_result();

};

#endif // TB_H
