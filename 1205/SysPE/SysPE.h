
#ifndef SYSPE_H
#define SYSPE_H


#include <cynw_p2p.h>
#include "defines.h"
#include <systemc.h>

SC_MODULE( SysPE )
{
	// Declare the clock and reset ports
	sc_in< bool >	clk;
	sc_in< bool >	rst;

	// Declare the input port and the output port.
	// The template specializations <DT_*> configure the
	// modular interfaces to carry the desired datatypes.
	// The input port

	/////////////////////////////////////////
	cynw_p2p < InputType >::in   weight_in;
	cynw_p2p < InputType >::in   act_in;
	cynw_p2p < AccumType >::in   accum_in;
	
	cynw_p2p < InputType >::out  weight_out;
	cynw_p2p < InputType >::out  act_out;
	cynw_p2p < AccumType >::out  accum_out;
	/////////////////////////////////////////
	SC_CTOR( SysPE )
	: clk( "clk" )
	, rst( "rst" )
	, weight_in( "weight_in" )
	, act_in( "act_in" )
	, accum_in( "accum_in" )
	, weight_out( "weight_out" )
	, act_out( "act_out" )
	, accum_out( "accum_out" )

	{
		SC_CTHREAD( thread1, clk.pos() );
		reset_signal_is( rst, 0 );
		// Connect the P2P ports to clk and rst
		weight_in.clk_rst( clk, rst );
		act_in.clk_rst( clk, rst );
		accum_in.clk_rst( clk, rst );

		weight_out.clk_rst( clk, rst );
		act_out.clk_rst( clk, rst );
		accum_out.clk_rst( clk, rst );

	}
	bool is_weight_in, is_act_in, is_accum_in;

	InputType weight_reg, weight_out_reg;
	InputType act_reg;
	AccumType accum_reg;
	
	void thread1();	// the thread function
};

#endif // DUT_H
