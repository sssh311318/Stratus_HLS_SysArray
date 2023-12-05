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
#include <systemc.h>            // SystemC definitions.
#include <esc.h>                // Cadence ESC functions and utilities.
#include <stratus_hls.h>        // Cadence Stratus definitions.
#include <cynw_p2p.h>           // The cynw_p2p communication channel.
#include "defines.h"
#include "tb.h"
#include "SysPE_wrap.h"		// use the generated wrapper for all hls_modules

SC_MODULE( System )
{
	// clock and reset signals
	sc_clock clk_sig;
	sc_signal< bool > rst_sig;

	// cynw_p2p channels

	cynw_p2p< InputType >		act_in;
	cynw_p2p< InputType >		act_out;

	cynw_p2p< InputType >		weight_in;
	cynw_p2p< InputType >		weight_out;

	cynw_p2p< AccumType >		accum_in;
	cynw_p2p< AccumType >		accum_out;	

	// The testbench and SysPE modules.
	SysPE_wrapper	*m_SysPE;		// use the generated wrapper for the SysPE hls module
	tb		*m_tb;

	SC_CTOR( System )
	: clk_sig( "clk_sig", 1, SC_NS, 0.5,0,SC_NS,true )
	, rst_sig( "rst_sig" )
	, weight_in( "weight_in" )
	, act_in( "act_in" )
	, accum_in( "accum_in" )
	, weight_out( "weight_out" )
	, act_out( "act_out" )
	, accum_out( "accum_out" )

	{
		// Connect the design module
		m_SysPE = new SysPE_wrapper( "SysPE_wrapper" );
		m_SysPE->clk( clk_sig );
		m_SysPE->rst( rst_sig );

		m_SysPE->act_in(act_in);
		m_SysPE->act_out(act_out);
		m_SysPE->weight_in(weight_in);
		m_SysPE->weight_out(weight_out);
		m_SysPE->accum_in(accum_in);
		m_SysPE->accum_out(accum_out);

		// Connect the testbench
		m_tb = new tb( "tb" );
		m_tb->clk( clk_sig );
		m_tb->rst( rst_sig );

		m_tb->act_in(act_in);
		m_tb->act_out(act_out);
		m_tb->weight_in(weight_in);
		m_tb->weight_out(weight_out);
		m_tb->accum_in(accum_in);
		m_tb->accum_out(accum_out);

		//SC_THREAD( run);
	}
/*
	void run() 
{
	rst_sig = 1;
	wait(10.5, SC_NS);
	rst_sig = 0;
	cout << "@" << sc_time_stamp() << " Asserting Reset " << endl ;
	wait(1, SC_NS);
	cout << "@" << sc_time_stamp() << " Deasserting Reset " << endl ;
	rst_sig = 1;
	wait(100000,SC_NS);
	cout << "@" << sc_time_stamp() << " Stop " << endl ;
	esc_stop();
}	
*/
	
	~System()
	{
		delete m_tb;
		delete m_SysPE;
	}
};

#endif // _SYSTEM_H_
