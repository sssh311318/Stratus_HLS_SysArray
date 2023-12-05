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

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

// Include some required files.
#include "SysArray.h"
#include <systemc.h>            // SystemC definitions.
#include <esc.h>                // Cadence ESC functions and utilities.
#include <stratus_hls.h>        // Cadence Stratus definitions.
#include <cynw_p2p.h>           // The cynw_p2p communication channel.
#include "defines.h"
#include "tb.h"
#include "SysArray_wrap.h"		// use the generated wrapper for all hls_modules

SC_MODULE( System )
{
	// clock and reset signals
	sc_clock clk_sig;
	sc_signal< bool > rst_sig;

	// cynw_p2p channels
	cynw_p2p< InputType >	act_in_vec[N];	// For data going into the design
	cynw_p2p< InputType >	weight_in_vec[N];
	cynw_p2p< AccumType >	accum_in_vec[N];
	cynw_p2p< AccumType >	accum_out_vec[N];
	//cynw_p2p< output_t >	chan2;	// For data coming out of the design

	// The testbench and DUT modules.
	SysArray_wrapper	*m_SysArray;		// use the generated wrapper for the DUT hls module
	tb		*m_tb;

	SC_CTOR( System )
	: clk_sig( "clk_sig", CLOCK_PERIOD, SC_NS )
	, rst_sig( "rst_sig" )
	{
		// Connect the design module
		m_SysArray = new SysArray_wrapper( "SysArray_wrapper" );
		m_SysArray->clk( clk_sig );
		m_SysArray->rst( rst_sig );

		for(int i = 0 ; i < N ; i++){
			m_SysArray->act_in_vec[i](act_in_vec[i]);
			m_SysArray->weight_in_vec[i](weight_in_vec[i]);
			m_SysArray->accum_in_vec[i](accum_in_vec[i]);
			m_SysArray->accum_out_vec[i](accum_out_vec[i]);
		}
		//m_dut->din( chan1 );
		//m_dut->dout( chan2 );

		// Connect the testbench
		m_tb = new tb( "tb" );
		m_tb->clk( clk_sig );
		m_tb->rst( rst_sig );

		for(int i = 0 ; i < N ; i++){
			m_tb->act_in_vec[i](act_in_vec[i]);
			m_tb->weight_in_vec[i](weight_in_vec[i]);
			m_tb->accum_in_vec[i](accum_in_vec[i]);
			m_tb->accum_out_vec[i](accum_out_vec[i]);
		}
		//m_tb->dout( chan1 );
		//m_tb->din( chan2 );
	}

	~System()
	{
		delete m_tb;
		delete m_SysArray;
	}
};

#endif // _SYSTEM_H_
