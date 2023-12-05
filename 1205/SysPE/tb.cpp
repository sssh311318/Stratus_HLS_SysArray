
#include "tb.h"
#include <esc.h>		// for the latency logging functions
#include <string>
#include <iostream>
#include <systemc.h>
#include <vector>
using namespace::std;

// The source thread reads data from a file and sends it to the DUT
void tb::source()
{	
	InputType _act;
    AccumType _acc;

    act_in.reset();
    weight_in.reset();
    accum_in.reset();

    rst.write( 0 );		// assert reset (active low)
	wait( 2 );		// wait 2 cycles
	rst.write( 1 );		// deassert reset    
	wait();

    for (int i=0; i< (int) act_list.size(); i++) {
        weight_in.put(weight_data);
        _act = act_list[i];
        _acc = accum_list[i];
        act_in.put(_act);
        accum_in.put(_acc);
    } // for
    wait(5);
}

void tb::pop_result()
{
    weight_out.reset();
    act_out.reset();
    accum_out.reset();
    wait();

    //sc_clock * clk_p = dynamic_cast < sc_clock * >( clk.get_interface() );
	//sc_time clock_period = clk_p->period();
    //source的wait應該要比pop_result大
    unsigned int i = 0, j = 0;
    bool correct = 1;
    while (1) {
        InputType tmp;
        tmp = weight_out.get();
        if (tmp >= 0) {
           cout << sc_time_stamp() << ": Received Output Weight:" << " \t " << tmp << endl;
        }
        act_out_src = act_out.get();
        if (act_out_src >= 0) { 
           cout << sc_time_stamp() << ": Received Output Activation:" << " \t " << act_out_src << "\t| Reference \t" << act_list[i] << endl;
           correct &= (act_list[i] == act_out_src);
	   i++;
        }
        accum_out_src = accum_out.get();
        if (accum_out_src >= 0) {
           int acc_ref = accum_list[j] + act_list[j]*weight_data;
           cout << sc_time_stamp() << ": Received Accumulated Output:" << "\t " << accum_out_src << "\t| Reference \t" << acc_ref << endl;
           correct &= (acc_ref == accum_out_src);
	   j++;
        }
        wait();
      if (i == act_list.size() && j == act_list.size()) break;  
    }// while
    
   if (correct == 1) cout << "Implementation Correct :)" << endl;
   else  cout << "Implementation Incorrect (:" << endl;
   //esc_log_latency( "dut", latency, "latency" );
   //cout << endl << "latency is " << latency << "." << endl;
    
    esc_stop();
}// void pop_result()

