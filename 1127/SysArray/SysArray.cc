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

// The thread function for the design
void SysArray::WeightOutRun()
{
	// Reset the interfaces
	// Also initialize any variables that are part of the module class here
	{
		HLS_DEFINE_PROTOCOL( "reset" );
			for(int j = 0 ; j < N ; j++){
				weight_inter[N-1][j].reset();
			}
			wait();
	}
    while(1) {
      for (int j = 0; j < N; j++) {
        InputType weight_tmp; 
        weight_tmp = weight_inter[N-1][j].get();
      }
      wait();
    }

}

void SysArray::ActOutRun() {
  {
  HLS_DEFINE_PROTOCOL( "reset" );
    for (int i = 0; i < N; i++) {
       act_inter[i][N-1].reset();
    }
    wait();
  }
    while(1) {
      for (int i = 0; i < N; i++) {
        InputType act_tmp; 
        act_tmp = act_inter[i][N-1].get();
      }
      wait();
    }
}

void SysArray::AccumInRun() {
  {
    HLS_DEFINE_PROTOCOL( "reset" );
    for (int j = 0; j < N; j++) {
       accum_inter[0][j].reset();
    }
    wait();
  }
    while(1) {
      for (int j = 0; j < N; j++) {
        accum_inter[0][j].put(0);
      }
      wait();
    }
}
