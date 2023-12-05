`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Configured at: 15:54:09 CST (+0800), Wednesday 01 November 2023
    Configured on: ic51
    Configured by: czwu23 ()
    
    Created by: Stratus DpOpt 21.05.01 
*******************************************************************************/

module SysPE_Not_1U_1U_1 (
	in1,
	out1
	); /* architecture "behavioural" */ 
input  in1;
output  out1;
wire  asc001;

assign asc001 = 
	((~in1));

assign out1 = asc001;
endmodule

/* CADENCE  urT1SAk= : u9/ySxbfrwZIxEzHVQQV8Q== ** DO NOT EDIT THIS LINE ******/


