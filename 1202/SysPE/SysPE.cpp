
#include "SysPE.h"
#include <iostream>

// The thread function for the design

void SysPE::thread1()
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
