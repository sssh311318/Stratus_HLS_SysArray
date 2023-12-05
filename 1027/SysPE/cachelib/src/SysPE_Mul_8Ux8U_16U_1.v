`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Configured at: 15:54:07 CST (+0800), Wednesday 01 November 2023
    Configured on: ic51
    Configured by: czwu23 ()
    
    Created by: Stratus DpOpt 21.05.01 
*******************************************************************************/

module SysPE_Mul_8Ux8U_16U_1 (
	in2,
	in1,
	out1
	); /* architecture "behavioural" */ 
input [7:0] in2,
	in1;
output [15:0] out1;
wire [15:0] asc001;

assign asc001 = 
	+(in1 * in2);

assign out1 = asc001;
endmodule

/* CADENCE  urj1SA8= : u9/ySxbfrwZIxEzHVQQV8Q== ** DO NOT EDIT THIS LINE ******/



