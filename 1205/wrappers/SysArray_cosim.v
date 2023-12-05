//
// Verilog co-simulation wrapper module for the SysArray module.

// This module contains the followng items:
//	- An instance of the verilog RTL module created by stratus_vlg.
//	- Wires and reg's connected to the ports of the RTL module.
//	- A clock generator using the project's clock frequency and connected to
//    the RTL module's clock port.
//
// The wires and reg's will be connected to sc_signals in the SystemC simulaton
// by esc_link_signals calls in the proxy module found in the SysArray_cosim.h 
// file.

`timescale 1 ps / 1 ps

module SysArray_cosim;

	reg clk;
	reg rst;
	wire weight_in_vec_busy_0;
	wire weight_in_vec_busy_1;
	wire weight_in_vec_busy_2;
	reg weight_in_vec_vld_0;
	reg weight_in_vec_vld_1;
	reg weight_in_vec_vld_2;
	reg[7:0] weight_in_vec_data_0;
	reg[7:0] weight_in_vec_data_1;
	reg[7:0] weight_in_vec_data_2;
	wire act_in_vec_busy_0;
	wire act_in_vec_busy_1;
	wire act_in_vec_busy_2;
	reg act_in_vec_vld_0;
	reg act_in_vec_vld_1;
	reg act_in_vec_vld_2;
	reg[7:0] act_in_vec_data_0;
	reg[7:0] act_in_vec_data_1;
	reg[7:0] act_in_vec_data_2;
	wire accum_in_vec_busy_0;
	wire accum_in_vec_busy_1;
	wire accum_in_vec_busy_2;
	reg accum_in_vec_vld_0;
	reg accum_in_vec_vld_1;
	reg accum_in_vec_vld_2;
	reg[31:0] accum_in_vec_data_0;
	reg[31:0] accum_in_vec_data_1;
	reg[31:0] accum_in_vec_data_2;
	reg accum_out_vec_busy_0;
	reg accum_out_vec_busy_1;
	reg accum_out_vec_busy_2;
	wire accum_out_vec_vld_0;
	wire accum_out_vec_vld_1;
	wire accum_out_vec_vld_2;
	wire[31:0] accum_out_vec_data_0;
	wire[31:0] accum_out_vec_data_1;
	wire[31:0] accum_out_vec_data_2;
	wire weight_inter_busy_0;
	wire weight_inter_busy_1;
	wire weight_inter_busy_2;
	reg weight_inter_vld_0;
	reg weight_inter_vld_1;
	reg weight_inter_vld_2;
	reg[7:0] weight_inter_data_0;
	reg[7:0] weight_inter_data_1;
	reg[7:0] weight_inter_data_2;
	wire act_inter_busy_0;
	wire act_inter_busy_1;
	wire act_inter_busy_2;
	reg act_inter_vld_0;
	reg act_inter_vld_1;
	reg act_inter_vld_2;
	reg[7:0] act_inter_data_0;
	reg[7:0] act_inter_data_1;
	reg[7:0] act_inter_data_2;


	`include "hub.v"

	SysArray SysArray0( .clk(clk),
	 .rst(rst),
	 .weight_in_vec_busy_0(weight_in_vec_busy_0),
	 .weight_in_vec_busy_1(weight_in_vec_busy_1),
	 .weight_in_vec_busy_2(weight_in_vec_busy_2),
	 .weight_in_vec_vld_0(weight_in_vec_vld_0),
	 .weight_in_vec_vld_1(weight_in_vec_vld_1),
	 .weight_in_vec_vld_2(weight_in_vec_vld_2),
	 .weight_in_vec_data_0(weight_in_vec_data_0),
	 .weight_in_vec_data_1(weight_in_vec_data_1),
	 .weight_in_vec_data_2(weight_in_vec_data_2),
	 .act_in_vec_busy_0(act_in_vec_busy_0),
	 .act_in_vec_busy_1(act_in_vec_busy_1),
	 .act_in_vec_busy_2(act_in_vec_busy_2),
	 .act_in_vec_vld_0(act_in_vec_vld_0),
	 .act_in_vec_vld_1(act_in_vec_vld_1),
	 .act_in_vec_vld_2(act_in_vec_vld_2),
	 .act_in_vec_data_0(act_in_vec_data_0),
	 .act_in_vec_data_1(act_in_vec_data_1),
	 .act_in_vec_data_2(act_in_vec_data_2),
	 .accum_in_vec_busy_0(accum_in_vec_busy_0),
	 .accum_in_vec_busy_1(accum_in_vec_busy_1),
	 .accum_in_vec_busy_2(accum_in_vec_busy_2),
	 .accum_in_vec_vld_0(accum_in_vec_vld_0),
	 .accum_in_vec_vld_1(accum_in_vec_vld_1),
	 .accum_in_vec_vld_2(accum_in_vec_vld_2),
	 .accum_in_vec_data_0(accum_in_vec_data_0),
	 .accum_in_vec_data_1(accum_in_vec_data_1),
	 .accum_in_vec_data_2(accum_in_vec_data_2),
	 .accum_out_vec_busy_0(accum_out_vec_busy_0),
	 .accum_out_vec_busy_1(accum_out_vec_busy_1),
	 .accum_out_vec_busy_2(accum_out_vec_busy_2),
	 .accum_out_vec_vld_0(accum_out_vec_vld_0),
	 .accum_out_vec_vld_1(accum_out_vec_vld_1),
	 .accum_out_vec_vld_2(accum_out_vec_vld_2),
	 .accum_out_vec_data_0(accum_out_vec_data_0),
	 .accum_out_vec_data_1(accum_out_vec_data_1),
	 .accum_out_vec_data_2(accum_out_vec_data_2),
	 .weight_inter_busy_0(weight_inter_busy_0),
	 .weight_inter_busy_1(weight_inter_busy_1),
	 .weight_inter_busy_2(weight_inter_busy_2),
	 .weight_inter_vld_0(weight_inter_vld_0),
	 .weight_inter_vld_1(weight_inter_vld_1),
	 .weight_inter_vld_2(weight_inter_vld_2),
	 .weight_inter_data_0(weight_inter_data_0),
	 .weight_inter_data_1(weight_inter_data_1),
	 .weight_inter_data_2(weight_inter_data_2),
	 .act_inter_busy_0(act_inter_busy_0),
	 .act_inter_busy_1(act_inter_busy_1),
	 .act_inter_busy_2(act_inter_busy_2),
	 .act_inter_vld_0(act_inter_vld_0),
	 .act_inter_vld_1(act_inter_vld_1),
	 .act_inter_vld_2(act_inter_vld_2),
	 .act_inter_data_0(act_inter_data_0),
	 .act_inter_data_1(act_inter_data_1),
	 .act_inter_data_2(act_inter_data_2) );


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
	always @( SysArray0.clk ) begin
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
	always @( SysArray0.rst ) begin
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


endmodule
