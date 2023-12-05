`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Configured at: 15:54:02 CST (+0800), Wednesday 01 November 2023
    Configured on: ic51
    Configured by: czwu23 ()
    
    Created by: Stratus DpOpt 21.05.01 
*******************************************************************************/

module SysPE_Add_32Ux16U_32U_4 (
	in2,
	in1,
	out1
	); /* architecture "behavioural" */ 
input [31:0] in2;
input [15:0] in1;
output [31:0] out1;
wire [31:0] asc001;

assign asc001 = 
	+(in2)
	+(in1);

assign out1 = asc001;
endmodule

/* CADENCE  ubD3TwA= : u9/ySxbfrwZIxEzHVQQV8Q== ** DO NOT EDIT THIS LINE ******/


