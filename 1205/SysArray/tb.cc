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
#include "SysArray.h"
#include <vector>
#include "tb.h"
#include <esc.h>		// for the latency logging functions
#include <string>
#include <iostream>
using namespace::std;

// The source thread reads data from a file and sends it to the DUT
void tb::source()
{
  for(int i = 0 ; i < N ; i++){
	  act_in_vec[i].reset();		// reset the outputs and cycle the design's reset
	  weight_in_vec[i].reset();
  }
  rst.write( 0 );		// assert reset (active low)
	wait( 2 );		// wait 2 cycles
	rst.write( 1 );		// deassert reset
	wait();

	// Open the stimulus file
	char stim_fileA[256] = "inputA.dat";
  char stim_fileB[256] = "inputB.dat";
	infpA = fopen( stim_fileA, "r" );
	infpB = fopen( stim_fileB, "r" );
	if( infpA == NULL )
	{
		cout << "Couldn't open inputA.dat for reading." << endl;
		exit(0);
	}

  if( infpB == NULL )
	{
		cout << "Couldn't open inputB.dat for reading." << endl;
		exit(0);
	}
	// Read stimulus values from file and send to DUT
	for( int i = 0; i < N; i++ )
	{
    int valueA,valueB;
    fscanf(infpA, "%d\n", &valueA);
    fscanf(infpB, "%d\n", &valueB);
		act_in_vec[i].put( (InputType)valueA );			// send the stimulus value
    weight_in_vec[i].put( (InputType)valueB );
	accum_in_vec[i].put(0);
		//start_time[i] = sc_time_stamp();	// mark the time value was sent
	}

	// Guard condition: after 100000 cycles the sink() thread should have ended the simulation.
	// If we're still here, timeout and print error message.
	wait( 100000 );
    	fclose( infpA );
      fclose( infpB ); 
	cout << "Error! TB source thread timed out!" << endl;
	esc_stop();
}

// The sink thread reads all the expected values from the design
void tb::sink()
{
	for(int i = 0 ; i < N ; i++){
    accum_out_vec[i].reset();
  }
	wait();     // to synchronize with reset

	// Extract clock period from clk port
	sc_clock * clk_p = dynamic_cast < sc_clock * >( clk.get_interface() );
	sc_time clock_period = clk_p->period();

	// Open the simulation results file
	char output_file[256];
	sprintf( output_file, "%s/response.dat", getenv("BDW_SIM_CONFIG_DIR") );
	outfpC = fopen(output_file, "wb");
	if (outfpC == NULL)
	{
		cout << "Couldn't open output.dat for writing." << endl;
		exit(0);
	}

	// Read outputs from DUT
	//unsigned long total_latency = 0;
	for( int i = 0; i < N; i++ )
	{
		AccumType inAccum = accum_out_vec[i].get();
		fprintf( outfpC, "%d\n", (int)inAccum );	// write value to response file

		// Calculate latency for this particular output
		//unsigned long latency = (sc_time_stamp() - start_time[i]) / clock_period;
		//cout << "Latency for sample " << i << " is " <<  latency << endl;

		// Keep running total of all latency cycles for later
		//total_latency += latency;
	}

	// Calculate, log and print average latency
	//unsigned long average_latency = total_latency / 11;
	//esc_log_latency( "dut", average_latency, "average_latency" );
	//cout << "Average latency " << average_latency << "." << endl;

	// Close the results file and end the simulation
	fclose( outfpC );
	esc_stop();
}

