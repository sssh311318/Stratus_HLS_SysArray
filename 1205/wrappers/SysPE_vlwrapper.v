/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/
/****************************************************************************
*
* Verilog Verification wrapper module for the SysPE module.
*
* This module contains the followng items:
*	- A foreign module definition for use in instantiatin the type_wrapper module
*      which contains the BEH module instance.
*	- An instance of the type_wrapper foreign module.
*   - alwyas blocks each type_wrapper output.
*
****************************************************************************/

`timescale 1 ps / 1 ps

module SysPE_vlwrapper(
      clk,
       rst,
       weight_in_busy,
       weight_in_vld,
       weight_in_data,
       act_in_busy,
       act_in_vld,
       act_in_data,
       accum_in_busy,
       accum_in_vld,
       accum_in_data,
       weight_out_busy,
       weight_out_vld,
       weight_out_data,
       act_out_busy,
       act_out_vld,
       act_out_data,
       accum_out_busy,
       accum_out_vld,
       accum_out_data

    );

`ifdef BDW_RTL_SysPE
	input clk;
	input rst;
	output weight_in_busy;
	input weight_in_vld;
	input [7:0] weight_in_data;
	output act_in_busy;
	input act_in_vld;
	input [7:0] act_in_data;
	output accum_in_busy;
	input accum_in_vld;
	input [31:0] accum_in_data;
	input weight_out_busy;
	output weight_out_vld;
	output [7:0] weight_out_data;
	input act_out_busy;
	output act_out_vld;
	output [7:0] act_out_data;
	input accum_out_busy;
	output accum_out_vld;
	output [31:0] accum_out_data;


    // Instantiate the Verilog module 
    SysPE SysPE_v(
        .clk(clk),
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
         .accum_out_data(accum_out_data)

    );
`else
	input clk;
	input rst;
	output weight_in_busy;
	reg weight_in_busy;
	wire m_weight_in_busy;
	input weight_in_vld;
	input [7:0] weight_in_data;
	output act_in_busy;
	reg act_in_busy;
	wire m_act_in_busy;
	input act_in_vld;
	input [7:0] act_in_data;
	output accum_in_busy;
	reg accum_in_busy;
	wire m_accum_in_busy;
	input accum_in_vld;
	input [31:0] accum_in_data;
	input weight_out_busy;
	output weight_out_vld;
	reg weight_out_vld;
	wire m_weight_out_vld;
	output [7:0] weight_out_data;
	reg[7:0] weight_out_data;
	wire [7:0] m_weight_out_data;
	input act_out_busy;
	output act_out_vld;
	reg act_out_vld;
	wire m_act_out_vld;
	output [7:0] act_out_data;
	reg[7:0] act_out_data;
	wire [7:0] m_act_out_data;
	input accum_out_busy;
	output accum_out_vld;
	reg accum_out_vld;
	wire m_accum_out_vld;
	output [31:0] accum_out_data;
	reg[31:0] accum_out_data;
	wire [31:0] m_accum_out_data;


    // Instantiate the Verilog module that instantiates the SystemC module
    SysPE_type_wrapper SysPE_sc(
        .clk(clk),
         .rst(rst),
         .weight_in_busy(m_weight_in_busy),
         .weight_in_vld(weight_in_vld),
         .weight_in_data(weight_in_data),
         .act_in_busy(m_act_in_busy),
         .act_in_vld(act_in_vld),
         .act_in_data(act_in_data),
         .accum_in_busy(m_accum_in_busy),
         .accum_in_vld(accum_in_vld),
         .accum_in_data(accum_in_data),
         .weight_out_busy(weight_out_busy),
         .weight_out_vld(m_weight_out_vld),
         .weight_out_data(m_weight_out_data),
         .act_out_busy(act_out_busy),
         .act_out_vld(m_act_out_vld),
         .act_out_data(m_act_out_data),
         .accum_out_busy(accum_out_busy),
         .accum_out_vld(m_accum_out_vld),
         .accum_out_data(m_accum_out_data)

    );

    // Always blocks for non-blocking assignments of type_wrapper outputs to
    // Verilog Verificatoin wrapper outputs.

    always @(m_weight_in_busy)
     begin
      weight_in_busy <= m_weight_in_busy;
     end
    always @(m_act_in_busy)
     begin
      act_in_busy <= m_act_in_busy;
     end
    always @(m_accum_in_busy)
     begin
      accum_in_busy <= m_accum_in_busy;
     end
    always @(m_weight_out_vld)
     begin
      weight_out_vld <= m_weight_out_vld;
     end
    always @(m_weight_out_data)
     begin
      weight_out_data <= m_weight_out_data;
     end
    always @(m_act_out_vld)
     begin
      act_out_vld <= m_act_out_vld;
     end
    always @(m_act_out_data)
     begin
      act_out_data <= m_act_out_data;
     end
    always @(m_accum_out_vld)
     begin
      accum_out_vld <= m_accum_out_vld;
     end
    always @(m_accum_out_data)
     begin
      accum_out_data <= m_accum_out_data;
     end


`endif

endmodule

// This is an internal module that instantiates the user's SystemC input module
// using the Incisive foreign module instantiation feature.
// The name of the module and the names of the inputs and outputs must match
// with those defined in the SystemC type_wrapper module

`ifndef BDW_RTL_SysPE

module SysPE_type_wrapper(
      clk,
       rst,
       weight_in_busy,
       weight_in_vld,
       weight_in_data,
       act_in_busy,
       act_in_vld,
       act_in_data,
       accum_in_busy,
       accum_in_vld,
       accum_in_data,
       weight_out_busy,
       weight_out_vld,
       weight_out_data,
       act_out_busy,
       act_out_vld,
       act_out_data,
       accum_out_busy,
       accum_out_vld,
       accum_out_data

    ) (* integer foreign = "SystemC";
    *);

	input clk;
	input rst;
	output weight_in_busy;
	input weight_in_vld;
	input [7:0] weight_in_data;
	output act_in_busy;
	input act_in_vld;
	input [7:0] act_in_data;
	output accum_in_busy;
	input accum_in_vld;
	input [31:0] accum_in_data;
	input weight_out_busy;
	output weight_out_vld;
	output [7:0] weight_out_data;
	input act_out_busy;
	output act_out_vld;
	output [7:0] act_out_data;
	input accum_out_busy;
	output accum_out_vld;
	output [31:0] accum_out_data;


endmodule

`endif
