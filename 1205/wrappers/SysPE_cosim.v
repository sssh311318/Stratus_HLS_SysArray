//
// Verilog co-simulation wrapper module for the SysPE module.

// This module contains the followng items:
//	- An instance of the verilog RTL module created by stratus_vlg.
//	- Wires and reg's connected to the ports of the RTL module.
//	- A clock generator using the project's clock frequency and connected to
//    the RTL module's clock port.
//
// The wires and reg's will be connected to sc_signals in the SystemC simulaton
// by esc_link_signals calls in the proxy module found in the SysPE_cosim.h 
// file.

`timescale 1 ps / 1 ps

module SysPE_cosim;

	reg clk;
	reg rst;
	wire weight_in_busy;
	reg weight_in_vld;
	reg[7:0] weight_in_data;
	wire act_in_busy;
	reg act_in_vld;
	reg[7:0] act_in_data;
	wire accum_in_busy;
	reg accum_in_vld;
	reg[31:0] accum_in_data;
	reg weight_out_busy;
	wire weight_out_vld;
	wire[7:0] weight_out_data;
	reg act_out_busy;
	wire act_out_vld;
	wire[7:0] act_out_data;
	reg accum_out_busy;
	wire accum_out_vld;
	wire[31:0] accum_out_data;


	`include "hub.v"

	SysPE SysPE0( .clk(clk),
	 .rst(rst),
	 .weight_in_busy(weight_in_busy),
	 .weight_in_vld(weight_in_vld),
	 .weight_in_data(weight_in_data),
	 .act_in_busy(act_in_busy),
	 .act_in_vld(act_in_vld),
	 .act_in_data(act_in_data),
	 .accum_in_busy(accum_in_busy),
	 .accum_in_vld(accum_in_vld),
	 .accum_in_data(accum_in_data),
	 .weight_out_busy(weight_out_busy),
	 .weight_out_vld(weight_out_vld),
	 .weight_out_data(weight_out_data),
	 .act_out_busy(act_out_busy),
	 .act_out_vld(act_out_vld),
	 .act_out_data(act_out_data),
	 .accum_out_busy(accum_out_busy),
	 .accum_out_vld(accum_out_vld),
	 .accum_out_data(accum_out_data) );


	// Variables that can be set externally
	reg clk_firstEdge;
	reg clk_initialized;
	reg clk_started;
	real clk_startTime;
	real clk_firstHalf;
	real clk_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    clk_firstEdge = 1'b1;
	    clk_startTime = 0.000;		// Offset from time 0 to first edge.
	    clk_firstHalf = 5.000;	// Delay for first half of cycle.
	    clk_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on clk_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( clk_initialized !== 1'b1 )
	        @( clk_initialized );
	
	    if ( clk_startTime > 0.0 ) begin
	        clk_started = #clk_startTime 1;
	    end
	    else begin
	        clk_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( SysPE0.clk ) begin
	    if ( clk_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( clk_started !== 1'b1 )
	        @( clk_started );
	
	    clk <= clk_firstEdge;
	    if ( clk_firstHalf > 0.0 ) begin
	        #clk_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        clk = ~clk_firstEdge;
	    end
	    else begin
	        clk = ~clk_firstEdge;
	    end
	    if ( clk_secondHalf > 0.0 ) begin
	        #clk_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg rst_firstEdge;
	reg rst_initialized;
	reg rst_started;
	real rst_startTime;
	real rst_firstHalf;
	real rst_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    rst_firstEdge = 1'b1;
	    rst_startTime = 0.000;		// Offset from time 0 to first edge.
	    rst_firstHalf = 5.000;	// Delay for first half of cycle.
	    rst_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on rst_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( rst_initialized !== 1'b1 )
	        @( rst_initialized );
	
	    if ( rst_startTime > 0.0 ) begin
	        rst_started = #rst_startTime 1;
	    end
	    else begin
	        rst_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( SysPE0.rst ) begin
	    if ( rst_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( rst_started !== 1'b1 )
	        @( rst_started );
	
	    rst <= rst_firstEdge;
	    if ( rst_firstHalf > 0.0 ) begin
	        #rst_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        rst = ~rst_firstEdge;
	    end
	    else begin
	        rst = ~rst_firstEdge;
	    end
	    if ( rst_secondHalf > 0.0 ) begin
	        #rst_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg weight_in_vld_firstEdge;
	reg weight_in_vld_initialized;
	reg weight_in_vld_started;
	real weight_in_vld_startTime;
	real weight_in_vld_firstHalf;
	real weight_in_vld_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    weight_in_vld_firstEdge = 1'b1;
	    weight_in_vld_startTime = 0.000;		// Offset from time 0 to first edge.
	    weight_in_vld_firstHalf = 5.000;	// Delay for first half of cycle.
	    weight_in_vld_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on weight_in_vld_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( weight_in_vld_initialized !== 1'b1 )
	        @( weight_in_vld_initialized );
	
	    if ( weight_in_vld_startTime > 0.0 ) begin
	        weight_in_vld_started = #weight_in_vld_startTime 1;
	    end
	    else begin
	        weight_in_vld_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( SysPE0.weight_in_vld ) begin
	    if ( weight_in_vld_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( weight_in_vld_started !== 1'b1 )
	        @( weight_in_vld_started );
	
	    weight_in_vld <= weight_in_vld_firstEdge;
	    if ( weight_in_vld_firstHalf > 0.0 ) begin
	        #weight_in_vld_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        weight_in_vld = ~weight_in_vld_firstEdge;
	    end
	    else begin
	        weight_in_vld = ~weight_in_vld_firstEdge;
	    end
	    if ( weight_in_vld_secondHalf > 0.0 ) begin
	        #weight_in_vld_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg act_in_vld_firstEdge;
	reg act_in_vld_initialized;
	reg act_in_vld_started;
	real act_in_vld_startTime;
	real act_in_vld_firstHalf;
	real act_in_vld_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    act_in_vld_firstEdge = 1'b1;
	    act_in_vld_startTime = 0.000;		// Offset from time 0 to first edge.
	    act_in_vld_firstHalf = 5.000;	// Delay for first half of cycle.
	    act_in_vld_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on act_in_vld_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( act_in_vld_initialized !== 1'b1 )
	        @( act_in_vld_initialized );
	
	    if ( act_in_vld_startTime > 0.0 ) begin
	        act_in_vld_started = #act_in_vld_startTime 1;
	    end
	    else begin
	        act_in_vld_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( SysPE0.act_in_vld ) begin
	    if ( act_in_vld_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( act_in_vld_started !== 1'b1 )
	        @( act_in_vld_started );
	
	    act_in_vld <= act_in_vld_firstEdge;
	    if ( act_in_vld_firstHalf > 0.0 ) begin
	        #act_in_vld_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        act_in_vld = ~act_in_vld_firstEdge;
	    end
	    else begin
	        act_in_vld = ~act_in_vld_firstEdge;
	    end
	    if ( act_in_vld_secondHalf > 0.0 ) begin
	        #act_in_vld_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg accum_in_vld_firstEdge;
	reg accum_in_vld_initialized;
	reg accum_in_vld_started;
	real accum_in_vld_startTime;
	real accum_in_vld_firstHalf;
	real accum_in_vld_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    accum_in_vld_firstEdge = 1'b1;
	    accum_in_vld_startTime = 0.000;		// Offset from time 0 to first edge.
	    accum_in_vld_firstHalf = 5.000;	// Delay for first half of cycle.
	    accum_in_vld_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on accum_in_vld_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( accum_in_vld_initialized !== 1'b1 )
	        @( accum_in_vld_initialized );
	
	    if ( accum_in_vld_startTime > 0.0 ) begin
	        accum_in_vld_started = #accum_in_vld_startTime 1;
	    end
	    else begin
	        accum_in_vld_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( SysPE0.accum_in_vld ) begin
	    if ( accum_in_vld_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( accum_in_vld_started !== 1'b1 )
	        @( accum_in_vld_started );
	
	    accum_in_vld <= accum_in_vld_firstEdge;
	    if ( accum_in_vld_firstHalf > 0.0 ) begin
	        #accum_in_vld_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        accum_in_vld = ~accum_in_vld_firstEdge;
	    end
	    else begin
	        accum_in_vld = ~accum_in_vld_firstEdge;
	    end
	    if ( accum_in_vld_secondHalf > 0.0 ) begin
	        #accum_in_vld_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg weight_out_busy_firstEdge;
	reg weight_out_busy_initialized;
	reg weight_out_busy_started;
	real weight_out_busy_startTime;
	real weight_out_busy_firstHalf;
	real weight_out_busy_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    weight_out_busy_firstEdge = 1'b1;
	    weight_out_busy_startTime = 0.000;		// Offset from time 0 to first edge.
	    weight_out_busy_firstHalf = 5.000;	// Delay for first half of cycle.
	    weight_out_busy_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on weight_out_busy_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( weight_out_busy_initialized !== 1'b1 )
	        @( weight_out_busy_initialized );
	
	    if ( weight_out_busy_startTime > 0.0 ) begin
	        weight_out_busy_started = #weight_out_busy_startTime 1;
	    end
	    else begin
	        weight_out_busy_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( SysPE0.weight_out_busy ) begin
	    if ( weight_out_busy_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( weight_out_busy_started !== 1'b1 )
	        @( weight_out_busy_started );
	
	    weight_out_busy <= weight_out_busy_firstEdge;
	    if ( weight_out_busy_firstHalf > 0.0 ) begin
	        #weight_out_busy_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        weight_out_busy = ~weight_out_busy_firstEdge;
	    end
	    else begin
	        weight_out_busy = ~weight_out_busy_firstEdge;
	    end
	    if ( weight_out_busy_secondHalf > 0.0 ) begin
	        #weight_out_busy_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg act_out_busy_firstEdge;
	reg act_out_busy_initialized;
	reg act_out_busy_started;
	real act_out_busy_startTime;
	real act_out_busy_firstHalf;
	real act_out_busy_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    act_out_busy_firstEdge = 1'b1;
	    act_out_busy_startTime = 0.000;		// Offset from time 0 to first edge.
	    act_out_busy_firstHalf = 5.000;	// Delay for first half of cycle.
	    act_out_busy_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on act_out_busy_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( act_out_busy_initialized !== 1'b1 )
	        @( act_out_busy_initialized );
	
	    if ( act_out_busy_startTime > 0.0 ) begin
	        act_out_busy_started = #act_out_busy_startTime 1;
	    end
	    else begin
	        act_out_busy_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( SysPE0.act_out_busy ) begin
	    if ( act_out_busy_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( act_out_busy_started !== 1'b1 )
	        @( act_out_busy_started );
	
	    act_out_busy <= act_out_busy_firstEdge;
	    if ( act_out_busy_firstHalf > 0.0 ) begin
	        #act_out_busy_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        act_out_busy = ~act_out_busy_firstEdge;
	    end
	    else begin
	        act_out_busy = ~act_out_busy_firstEdge;
	    end
	    if ( act_out_busy_secondHalf > 0.0 ) begin
	        #act_out_busy_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg accum_out_busy_firstEdge;
	reg accum_out_busy_initialized;
	reg accum_out_busy_started;
	real accum_out_busy_startTime;
	real accum_out_busy_firstHalf;
	real accum_out_busy_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    accum_out_busy_firstEdge = 1'b1;
	    accum_out_busy_startTime = 0.000;		// Offset from time 0 to first edge.
	    accum_out_busy_firstHalf = 5.000;	// Delay for first half of cycle.
	    accum_out_busy_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on accum_out_busy_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( accum_out_busy_initialized !== 1'b1 )
	        @( accum_out_busy_initialized );
	
	    if ( accum_out_busy_startTime > 0.0 ) begin
	        accum_out_busy_started = #accum_out_busy_startTime 1;
	    end
	    else begin
	        accum_out_busy_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( SysPE0.accum_out_busy ) begin
	    if ( accum_out_busy_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( accum_out_busy_started !== 1'b1 )
	        @( accum_out_busy_started );
	
	    accum_out_busy <= accum_out_busy_firstEdge;
	    if ( accum_out_busy_firstHalf > 0.0 ) begin
	        #accum_out_busy_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        accum_out_busy = ~accum_out_busy_firstEdge;
	    end
	    else begin
	        accum_out_busy = ~accum_out_busy_firstEdge;
	    end
	    if ( accum_out_busy_secondHalf > 0.0 ) begin
	        #accum_out_busy_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end


endmodule
