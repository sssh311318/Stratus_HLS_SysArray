`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 19.16-s111_1
// Generated on: Nov  1 2023 15:54:09 CST (Nov  1 2023 07:54:09 UTC)

module SysPE_And_1Ux1U_1U_1(in2, in1, out1);
  input in2, in1;
  output out1;
  wire in2, in1;
  wire out1;
  wire n_0, n_1;
  NOR2X4 g8(.A (n_0), .B (n_1), .Y (out1));
  CLKINVX4 g9(.A (in1), .Y (n_1));
  CLKINVX12 g10(.A (in2), .Y (n_0));
endmodule


