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
* Verilog Verification wrapper module for the SysArray module.
*
* This module contains the followng items:
*	- A foreign module definition for use in instantiatin the type_wrapper module
*      which contains the BEH module instance.
*	- An instance of the type_wrapper foreign module.
*   - alwyas blocks each type_wrapper output.
*
****************************************************************************/

`timescale 1 ps / 1 ps

module SysArray_vlwrapper(
      clk,
       rst,
       weight_in_vec_busy_0,
       weight_in_vec_busy_1,
       weight_in_vec_busy_2,
       weight_in_vec_vld_0,
       weight_in_vec_vld_1,
       weight_in_vec_vld_2,
       weight_in_vec_data_0,
       weight_in_vec_data_1,
       weight_in_vec_data_2,
       act_in_vec_busy_0,
       act_in_vec_busy_1,
       act_in_vec_busy_2,
       act_in_vec_vld_0,
       act_in_vec_vld_1,
       act_in_vec_vld_2,
       act_in_vec_data_0,
       act_in_vec_data_1,
       act_in_vec_data_2,
       accum_out_vec_busy_0,
       accum_out_vec_busy_1,
       accum_out_vec_busy_2,
       accum_out_vec_vld_0,
       accum_out_vec_vld_1,
       accum_out_vec_vld_2,
       accum_out_vec_data_0,
       accum_out_vec_data_1,
       accum_out_vec_data_2,
       weight_inter_busy_0,
       weight_inter_busy_1,
       weight_inter_busy_2,
       weight_inter_vld_0,
       weight_inter_vld_1,
       weight_inter_vld_2,
       weight_inter_data_0,
       weight_inter_data_1,
       weight_inter_data_2,
       act_inter_busy_0,
       act_inter_busy_1,
       act_inter_busy_2,
       act_inter_vld_0,
       act_inter_vld_1,
       act_inter_vld_2,
       act_inter_data_0,
       act_inter_data_1,
       act_inter_data_2,
       accum_inter_busy_0,
       accum_inter_busy_1,
       accum_inter_busy_2,
       accum_inter_vld_0,
       accum_inter_vld_1,
       accum_inter_vld_2,
       accum_inter_data_0,
       accum_inter_data_1,
       accum_inter_data_2

    );

`ifdef BDW_RTL_SysArray
	input clk;
	input rst;
	output weight_in_vec_busy_0;
	output weight_in_vec_busy_1;
	output weight_in_vec_busy_2;
	input weight_in_vec_vld_0;
	input weight_in_vec_vld_1;
	input weight_in_vec_vld_2;
	input [7:0] weight_in_vec_data_0;
	input [7:0] weight_in_vec_data_1;
	input [7:0] weight_in_vec_data_2;
	output act_in_vec_busy_0;
	output act_in_vec_busy_1;
	output act_in_vec_busy_2;
	input act_in_vec_vld_0;
	input act_in_vec_vld_1;
	input act_in_vec_vld_2;
	input [7:0] act_in_vec_data_0;
	input [7:0] act_in_vec_data_1;
	input [7:0] act_in_vec_data_2;
	input accum_out_vec_busy_0;
	input accum_out_vec_busy_1;
	input accum_out_vec_busy_2;
	output accum_out_vec_vld_0;
	output accum_out_vec_vld_1;
	output accum_out_vec_vld_2;
	output [31:0] accum_out_vec_data_0;
	output [31:0] accum_out_vec_data_1;
	output [31:0] accum_out_vec_data_2;
	output weight_inter_busy_0;
	output weight_inter_busy_1;
	output weight_inter_busy_2;
	input weight_inter_vld_0;
	input weight_inter_vld_1;
	input weight_inter_vld_2;
	input [7:0] weight_inter_data_0;
	input [7:0] weight_inter_data_1;
	input [7:0] weight_inter_data_2;
	output act_inter_busy_0;
	output act_inter_busy_1;
	output act_inter_busy_2;
	input act_inter_vld_0;
	input act_inter_vld_1;
	input act_inter_vld_2;
	input [7:0] act_inter_data_0;
	input [7:0] act_inter_data_1;
	input [7:0] act_inter_data_2;
	input accum_inter_busy_0;
	input accum_inter_busy_1;
	input accum_inter_busy_2;
	output accum_inter_vld_0;
	output accum_inter_vld_1;
	output accum_inter_vld_2;
	output [31:0] accum_inter_data_0;
	output [31:0] accum_inter_data_1;
	output [31:0] accum_inter_data_2;


    // Instantiate the Verilog module 
    SysArray SysArray_v(
        .clk(clk),
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
         .act_inter_data_2(act_inter_data_2),
         .accum_inter_busy_0(accum_inter_busy_0),
         .accum_inter_busy_1(accum_inter_busy_1),
         .accum_inter_busy_2(accum_inter_busy_2),
         .accum_inter_vld_0(accum_inter_vld_0),
         .accum_inter_vld_1(accum_inter_vld_1),
         .accum_inter_vld_2(accum_inter_vld_2),
         .accum_inter_data_0(accum_inter_data_0),
         .accum_inter_data_1(accum_inter_data_1),
         .accum_inter_data_2(accum_inter_data_2)

    );
`else
	input clk;
	input rst;
	output weight_in_vec_busy_0;
	reg weight_in_vec_busy_0;
	wire m_weight_in_vec_busy_0;
	output weight_in_vec_busy_1;
	reg weight_in_vec_busy_1;
	wire m_weight_in_vec_busy_1;
	output weight_in_vec_busy_2;
	reg weight_in_vec_busy_2;
	wire m_weight_in_vec_busy_2;
	input weight_in_vec_vld_0;
	input weight_in_vec_vld_1;
	input weight_in_vec_vld_2;
	input [7:0] weight_in_vec_data_0;
	input [7:0] weight_in_vec_data_1;
	input [7:0] weight_in_vec_data_2;
	output act_in_vec_busy_0;
	reg act_in_vec_busy_0;
	wire m_act_in_vec_busy_0;
	output act_in_vec_busy_1;
	reg act_in_vec_busy_1;
	wire m_act_in_vec_busy_1;
	output act_in_vec_busy_2;
	reg act_in_vec_busy_2;
	wire m_act_in_vec_busy_2;
	input act_in_vec_vld_0;
	input act_in_vec_vld_1;
	input act_in_vec_vld_2;
	input [7:0] act_in_vec_data_0;
	input [7:0] act_in_vec_data_1;
	input [7:0] act_in_vec_data_2;
	input accum_out_vec_busy_0;
	input accum_out_vec_busy_1;
	input accum_out_vec_busy_2;
	output accum_out_vec_vld_0;
	reg accum_out_vec_vld_0;
	wire m_accum_out_vec_vld_0;
	output accum_out_vec_vld_1;
	reg accum_out_vec_vld_1;
	wire m_accum_out_vec_vld_1;
	output accum_out_vec_vld_2;
	reg accum_out_vec_vld_2;
	wire m_accum_out_vec_vld_2;
	output [31:0] accum_out_vec_data_0;
	reg[31:0] accum_out_vec_data_0;
	wire [31:0] m_accum_out_vec_data_0;
	output [31:0] accum_out_vec_data_1;
	reg[31:0] accum_out_vec_data_1;
	wire [31:0] m_accum_out_vec_data_1;
	output [31:0] accum_out_vec_data_2;
	reg[31:0] accum_out_vec_data_2;
	wire [31:0] m_accum_out_vec_data_2;
	output weight_inter_busy_0;
	reg weight_inter_busy_0;
	wire m_weight_inter_busy_0;
	output weight_inter_busy_1;
	reg weight_inter_busy_1;
	wire m_weight_inter_busy_1;
	output weight_inter_busy_2;
	reg weight_inter_busy_2;
	wire m_weight_inter_busy_2;
	input weight_inter_vld_0;
	input weight_inter_vld_1;
	input weight_inter_vld_2;
	input [7:0] weight_inter_data_0;
	input [7:0] weight_inter_data_1;
	input [7:0] weight_inter_data_2;
	output act_inter_busy_0;
	reg act_inter_busy_0;
	wire m_act_inter_busy_0;
	output act_inter_busy_1;
	reg act_inter_busy_1;
	wire m_act_inter_busy_1;
	output act_inter_busy_2;
	reg act_inter_busy_2;
	wire m_act_inter_busy_2;
	input act_inter_vld_0;
	input act_inter_vld_1;
	input act_inter_vld_2;
	input [7:0] act_inter_data_0;
	input [7:0] act_inter_data_1;
	input [7:0] act_inter_data_2;
	input accum_inter_busy_0;
	input accum_inter_busy_1;
	input accum_inter_busy_2;
	output accum_inter_vld_0;
	reg accum_inter_vld_0;
	wire m_accum_inter_vld_0;
	output accum_inter_vld_1;
	reg accum_inter_vld_1;
	wire m_accum_inter_vld_1;
	output accum_inter_vld_2;
	reg accum_inter_vld_2;
	wire m_accum_inter_vld_2;
	output [31:0] accum_inter_data_0;
	reg[31:0] accum_inter_data_0;
	wire [31:0] m_accum_inter_data_0;
	output [31:0] accum_inter_data_1;
	reg[31:0] accum_inter_data_1;
	wire [31:0] m_accum_inter_data_1;
	output [31:0] accum_inter_data_2;
	reg[31:0] accum_inter_data_2;
	wire [31:0] m_accum_inter_data_2;


    // Instantiate the Verilog module that instantiates the SystemC module
    SysArray_type_wrapper SysArray_sc(
        .clk(clk),
         .rst(rst),
         .weight_in_vec_busy_0(m_weight_in_vec_busy_0),
         .weight_in_vec_busy_1(m_weight_in_vec_busy_1),
         .weight_in_vec_busy_2(m_weight_in_vec_busy_2),
         .weight_in_vec_vld_0(weight_in_vec_vld_0),
         .weight_in_vec_vld_1(weight_in_vec_vld_1),
         .weight_in_vec_vld_2(weight_in_vec_vld_2),
         .weight_in_vec_data_0(weight_in_vec_data_0),
         .weight_in_vec_data_1(weight_in_vec_data_1),
         .weight_in_vec_data_2(weight_in_vec_data_2),
         .act_in_vec_busy_0(m_act_in_vec_busy_0),
         .act_in_vec_busy_1(m_act_in_vec_busy_1),
         .act_in_vec_busy_2(m_act_in_vec_busy_2),
         .act_in_vec_vld_0(act_in_vec_vld_0),
         .act_in_vec_vld_1(act_in_vec_vld_1),
         .act_in_vec_vld_2(act_in_vec_vld_2),
         .act_in_vec_data_0(act_in_vec_data_0),
         .act_in_vec_data_1(act_in_vec_data_1),
         .act_in_vec_data_2(act_in_vec_data_2),
         .accum_out_vec_busy_0(accum_out_vec_busy_0),
         .accum_out_vec_busy_1(accum_out_vec_busy_1),
         .accum_out_vec_busy_2(accum_out_vec_busy_2),
         .accum_out_vec_vld_0(m_accum_out_vec_vld_0),
         .accum_out_vec_vld_1(m_accum_out_vec_vld_1),
         .accum_out_vec_vld_2(m_accum_out_vec_vld_2),
         .accum_out_vec_data_0(m_accum_out_vec_data_0),
         .accum_out_vec_data_1(m_accum_out_vec_data_1),
         .accum_out_vec_data_2(m_accum_out_vec_data_2),
         .weight_inter_busy_0(m_weight_inter_busy_0),
         .weight_inter_busy_1(m_weight_inter_busy_1),
         .weight_inter_busy_2(m_weight_inter_busy_2),
         .weight_inter_vld_0(weight_inter_vld_0),
         .weight_inter_vld_1(weight_inter_vld_1),
         .weight_inter_vld_2(weight_inter_vld_2),
         .weight_inter_data_0(weight_inter_data_0),
         .weight_inter_data_1(weight_inter_data_1),
         .weight_inter_data_2(weight_inter_data_2),
         .act_inter_busy_0(m_act_inter_busy_0),
         .act_inter_busy_1(m_act_inter_busy_1),
         .act_inter_busy_2(m_act_inter_busy_2),
         .act_inter_vld_0(act_inter_vld_0),
         .act_inter_vld_1(act_inter_vld_1),
         .act_inter_vld_2(act_inter_vld_2),
         .act_inter_data_0(act_inter_data_0),
         .act_inter_data_1(act_inter_data_1),
         .act_inter_data_2(act_inter_data_2),
         .accum_inter_busy_0(accum_inter_busy_0),
         .accum_inter_busy_1(accum_inter_busy_1),
         .accum_inter_busy_2(accum_inter_busy_2),
         .accum_inter_vld_0(m_accum_inter_vld_0),
         .accum_inter_vld_1(m_accum_inter_vld_1),
         .accum_inter_vld_2(m_accum_inter_vld_2),
         .accum_inter_data_0(m_accum_inter_data_0),
         .accum_inter_data_1(m_accum_inter_data_1),
         .accum_inter_data_2(m_accum_inter_data_2)

    );

    // Always blocks for non-blocking assignments of type_wrapper outputs to
    // Verilog Verificatoin wrapper outputs.

    always @(m_weight_in_vec_busy_0)
     begin
      weight_in_vec_busy_0 <= m_weight_in_vec_busy_0;
     end
    always @(m_weight_in_vec_busy_1)
     begin
      weight_in_vec_busy_1 <= m_weight_in_vec_busy_1;
     end
    always @(m_weight_in_vec_busy_2)
     begin
      weight_in_vec_busy_2 <= m_weight_in_vec_busy_2;
     end
    always @(m_act_in_vec_busy_0)
     begin
      act_in_vec_busy_0 <= m_act_in_vec_busy_0;
     end
    always @(m_act_in_vec_busy_1)
     begin
      act_in_vec_busy_1 <= m_act_in_vec_busy_1;
     end
    always @(m_act_in_vec_busy_2)
     begin
      act_in_vec_busy_2 <= m_act_in_vec_busy_2;
     end
    always @(m_accum_out_vec_vld_0)
     begin
      accum_out_vec_vld_0 <= m_accum_out_vec_vld_0;
     end
    always @(m_accum_out_vec_vld_1)
     begin
      accum_out_vec_vld_1 <= m_accum_out_vec_vld_1;
     end
    always @(m_accum_out_vec_vld_2)
     begin
      accum_out_vec_vld_2 <= m_accum_out_vec_vld_2;
     end
    always @(m_accum_out_vec_data_0)
     begin
      accum_out_vec_data_0 <= m_accum_out_vec_data_0;
     end
    always @(m_accum_out_vec_data_1)
     begin
      accum_out_vec_data_1 <= m_accum_out_vec_data_1;
     end
    always @(m_accum_out_vec_data_2)
     begin
      accum_out_vec_data_2 <= m_accum_out_vec_data_2;
     end
    always @(m_weight_inter_busy_0)
     begin
      weight_inter_busy_0 <= m_weight_inter_busy_0;
     end
    always @(m_weight_inter_busy_1)
     begin
      weight_inter_busy_1 <= m_weight_inter_busy_1;
     end
    always @(m_weight_inter_busy_2)
     begin
      weight_inter_busy_2 <= m_weight_inter_busy_2;
     end
    always @(m_act_inter_busy_0)
     begin
      act_inter_busy_0 <= m_act_inter_busy_0;
     end
    always @(m_act_inter_busy_1)
     begin
      act_inter_busy_1 <= m_act_inter_busy_1;
     end
    always @(m_act_inter_busy_2)
     begin
      act_inter_busy_2 <= m_act_inter_busy_2;
     end
    always @(m_accum_inter_vld_0)
     begin
      accum_inter_vld_0 <= m_accum_inter_vld_0;
     end
    always @(m_accum_inter_vld_1)
     begin
      accum_inter_vld_1 <= m_accum_inter_vld_1;
     end
    always @(m_accum_inter_vld_2)
     begin
      accum_inter_vld_2 <= m_accum_inter_vld_2;
     end
    always @(m_accum_inter_data_0)
     begin
      accum_inter_data_0 <= m_accum_inter_data_0;
     end
    always @(m_accum_inter_data_1)
     begin
      accum_inter_data_1 <= m_accum_inter_data_1;
     end
    always @(m_accum_inter_data_2)
     begin
      accum_inter_data_2 <= m_accum_inter_data_2;
     end


`endif

endmodule

// This is an internal module that instantiates the user's SystemC input module
// using the Incisive foreign module instantiation feature.
// The name of the module and the names of the inputs and outputs must match
// with those defined in the SystemC type_wrapper module

`ifndef BDW_RTL_SysArray

module SysArray_type_wrapper(
      clk,
       rst,
       weight_in_vec_busy_0,
       weight_in_vec_busy_1,
       weight_in_vec_busy_2,
       weight_in_vec_vld_0,
       weight_in_vec_vld_1,
       weight_in_vec_vld_2,
       weight_in_vec_data_0,
       weight_in_vec_data_1,
       weight_in_vec_data_2,
       act_in_vec_busy_0,
       act_in_vec_busy_1,
       act_in_vec_busy_2,
       act_in_vec_vld_0,
       act_in_vec_vld_1,
       act_in_vec_vld_2,
       act_in_vec_data_0,
       act_in_vec_data_1,
       act_in_vec_data_2,
       accum_out_vec_busy_0,
       accum_out_vec_busy_1,
       accum_out_vec_busy_2,
       accum_out_vec_vld_0,
       accum_out_vec_vld_1,
       accum_out_vec_vld_2,
       accum_out_vec_data_0,
       accum_out_vec_data_1,
       accum_out_vec_data_2,
       weight_inter_busy_0,
       weight_inter_busy_1,
       weight_inter_busy_2,
       weight_inter_vld_0,
       weight_inter_vld_1,
       weight_inter_vld_2,
       weight_inter_data_0,
       weight_inter_data_1,
       weight_inter_data_2,
       act_inter_busy_0,
       act_inter_busy_1,
       act_inter_busy_2,
       act_inter_vld_0,
       act_inter_vld_1,
       act_inter_vld_2,
       act_inter_data_0,
       act_inter_data_1,
       act_inter_data_2,
       accum_inter_busy_0,
       accum_inter_busy_1,
       accum_inter_busy_2,
       accum_inter_vld_0,
       accum_inter_vld_1,
       accum_inter_vld_2,
       accum_inter_data_0,
       accum_inter_data_1,
       accum_inter_data_2

    ) (* integer foreign = "SystemC";
    *);

	input clk;
	input rst;
	output weight_in_vec_busy_0;
	output weight_in_vec_busy_1;
	output weight_in_vec_busy_2;
	input weight_in_vec_vld_0;
	input weight_in_vec_vld_1;
	input weight_in_vec_vld_2;
	input [7:0] weight_in_vec_data_0;
	input [7:0] weight_in_vec_data_1;
	input [7:0] weight_in_vec_data_2;
	output act_in_vec_busy_0;
	output act_in_vec_busy_1;
	output act_in_vec_busy_2;
	input act_in_vec_vld_0;
	input act_in_vec_vld_1;
	input act_in_vec_vld_2;
	input [7:0] act_in_vec_data_0;
	input [7:0] act_in_vec_data_1;
	input [7:0] act_in_vec_data_2;
	input accum_out_vec_busy_0;
	input accum_out_vec_busy_1;
	input accum_out_vec_busy_2;
	output accum_out_vec_vld_0;
	output accum_out_vec_vld_1;
	output accum_out_vec_vld_2;
	output [31:0] accum_out_vec_data_0;
	output [31:0] accum_out_vec_data_1;
	output [31:0] accum_out_vec_data_2;
	output weight_inter_busy_0;
	output weight_inter_busy_1;
	output weight_inter_busy_2;
	input weight_inter_vld_0;
	input weight_inter_vld_1;
	input weight_inter_vld_2;
	input [7:0] weight_inter_data_0;
	input [7:0] weight_inter_data_1;
	input [7:0] weight_inter_data_2;
	output act_inter_busy_0;
	output act_inter_busy_1;
	output act_inter_busy_2;
	input act_inter_vld_0;
	input act_inter_vld_1;
	input act_inter_vld_2;
	input [7:0] act_inter_data_0;
	input [7:0] act_inter_data_1;
	input [7:0] act_inter_data_2;
	input accum_inter_busy_0;
	input accum_inter_busy_1;
	input accum_inter_busy_2;
	output accum_inter_vld_0;
	output accum_inter_vld_1;
	output accum_inter_vld_2;
	output [31:0] accum_inter_data_0;
	output [31:0] accum_inter_data_1;
	output [31:0] accum_inter_data_2;


endmodule

`endif
