
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
	cynw_p2p < InputType >::base_in   weight_in;
	cynw_p2p < InputType >::base_in   act_in;
	cynw_p2p < AccumType >::base_in   accum_in;
	
	cynw_p2p < InputType >::base_out  weight_out;
	cynw_p2p < InputType >::base_out  act_out;
	cynw_p2p < AccumType >::base_out  accum_out;
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
	
	void thread1()
{
	// Reset the interfaces
	// Also initialize any variables that are part of the module class here
	{
		HLS_DEFINE_PROTOCOL( "reset" );
			weight_in.reset();
			act_in.reset();
			accum_in.reset();
			weight_out.reset();
			act_out.reset();
			accum_out.reset();
			wait();
	}

	weight_reg = 0;
	weight_out_reg = 0;
	act_reg = 0;
	accum_reg = 0;

while_1:
	while( true ) {

	weight_reg = weight_in.get();
    weight_out_reg = weight_reg;
	act_reg = act_in.get();
	accum_reg = accum_in.get();
	weight_out.put(weight_out_reg);

    AccumType accum_out_reg = act_reg * weight_reg + accum_reg;

    act_out.put(act_reg);
    accum_out.put(accum_out_reg);
		
	}
}
};

#endif // DUT_H
