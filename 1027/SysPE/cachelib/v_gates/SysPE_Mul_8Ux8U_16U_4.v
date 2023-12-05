`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 19.16-s111_1
// Generated on: Nov  1 2023 15:54:03 CST (Nov  1 2023 07:54:03 UTC)

module SysPE_Mul_8Ux8U_16U_4(in2, in1, out1);
  input [7:0] in2, in1;
  output [15:0] out1;
  wire [7:0] in2, in1;
  wire [15:0] out1;
  wire mul_22_8_n_0, mul_22_8_n_1, mul_22_8_n_2, mul_22_8_n_3,
       mul_22_8_n_4, mul_22_8_n_5, mul_22_8_n_6, mul_22_8_n_7;
  wire mul_22_8_n_8, mul_22_8_n_9, mul_22_8_n_10, mul_22_8_n_11,
       mul_22_8_n_12, mul_22_8_n_13, mul_22_8_n_14, mul_22_8_n_15;
  wire mul_22_8_n_16, mul_22_8_n_17, mul_22_8_n_18, mul_22_8_n_19,
       mul_22_8_n_20, mul_22_8_n_21, mul_22_8_n_22, mul_22_8_n_23;
  wire mul_22_8_n_24, mul_22_8_n_25, mul_22_8_n_26, mul_22_8_n_27,
       mul_22_8_n_28, mul_22_8_n_29, mul_22_8_n_30, mul_22_8_n_31;
  wire mul_22_8_n_32, mul_22_8_n_33, mul_22_8_n_34, mul_22_8_n_35,
       mul_22_8_n_36, mul_22_8_n_37, mul_22_8_n_38, mul_22_8_n_39;
  wire mul_22_8_n_40, mul_22_8_n_41, mul_22_8_n_42, mul_22_8_n_43,
       mul_22_8_n_44, mul_22_8_n_45, mul_22_8_n_46, mul_22_8_n_48;
  wire mul_22_8_n_49, mul_22_8_n_50, mul_22_8_n_51, mul_22_8_n_52,
       mul_22_8_n_53, mul_22_8_n_54, mul_22_8_n_55, mul_22_8_n_56;
  wire mul_22_8_n_57, mul_22_8_n_58, mul_22_8_n_59, mul_22_8_n_60,
       mul_22_8_n_61, mul_22_8_n_62, mul_22_8_n_63, mul_22_8_n_64;
  wire mul_22_8_n_65, mul_22_8_n_66, mul_22_8_n_67, mul_22_8_n_68,
       mul_22_8_n_69, mul_22_8_n_70, mul_22_8_n_71, mul_22_8_n_72;
  wire mul_22_8_n_73, mul_22_8_n_74, mul_22_8_n_75, mul_22_8_n_76,
       mul_22_8_n_77, mul_22_8_n_78, mul_22_8_n_80, mul_22_8_n_81;
  wire mul_22_8_n_82, mul_22_8_n_83, mul_22_8_n_84, mul_22_8_n_86,
       mul_22_8_n_87, mul_22_8_n_88, mul_22_8_n_90, mul_22_8_n_91;
  wire mul_22_8_n_92, mul_22_8_n_93, mul_22_8_n_94, mul_22_8_n_95,
       mul_22_8_n_97, mul_22_8_n_98, mul_22_8_n_99, mul_22_8_n_100;
  wire mul_22_8_n_101, mul_22_8_n_103, mul_22_8_n_104, mul_22_8_n_105,
       mul_22_8_n_106, mul_22_8_n_107, mul_22_8_n_108, mul_22_8_n_109;
  wire mul_22_8_n_110, mul_22_8_n_111, mul_22_8_n_112, mul_22_8_n_114,
       mul_22_8_n_115, mul_22_8_n_116, mul_22_8_n_117, mul_22_8_n_118;
  wire mul_22_8_n_119, mul_22_8_n_120, mul_22_8_n_121, mul_22_8_n_122,
       mul_22_8_n_123, mul_22_8_n_124, mul_22_8_n_125, mul_22_8_n_126;
  wire mul_22_8_n_128, mul_22_8_n_129, mul_22_8_n_130, mul_22_8_n_131,
       mul_22_8_n_132, mul_22_8_n_133, mul_22_8_n_134, mul_22_8_n_135;
  wire mul_22_8_n_136, mul_22_8_n_137, mul_22_8_n_138, mul_22_8_n_139,
       mul_22_8_n_140, mul_22_8_n_141, mul_22_8_n_142, mul_22_8_n_143;
  wire mul_22_8_n_144, mul_22_8_n_145, mul_22_8_n_146, mul_22_8_n_147,
       mul_22_8_n_148, mul_22_8_n_149, mul_22_8_n_150, mul_22_8_n_152;
  wire mul_22_8_n_155, mul_22_8_n_156, mul_22_8_n_157, mul_22_8_n_158,
       mul_22_8_n_161, mul_22_8_n_165, mul_22_8_n_166, mul_22_8_n_167;
  wire mul_22_8_n_168, mul_22_8_n_169, mul_22_8_n_170, mul_22_8_n_171,
       mul_22_8_n_172, mul_22_8_n_173, mul_22_8_n_174, mul_22_8_n_175;
  wire mul_22_8_n_176, mul_22_8_n_177, mul_22_8_n_178, mul_22_8_n_179,
       mul_22_8_n_180, mul_22_8_n_181, mul_22_8_n_182, mul_22_8_n_183;
  wire mul_22_8_n_184, mul_22_8_n_185, mul_22_8_n_186, mul_22_8_n_187,
       mul_22_8_n_188, mul_22_8_n_189, mul_22_8_n_190, mul_22_8_n_191;
  wire mul_22_8_n_192, mul_22_8_n_193, mul_22_8_n_194, mul_22_8_n_195,
       mul_22_8_n_196, mul_22_8_n_197, mul_22_8_n_198, mul_22_8_n_199;
  wire mul_22_8_n_200, mul_22_8_n_201, mul_22_8_n_202, mul_22_8_n_203,
       mul_22_8_n_204, mul_22_8_n_205, mul_22_8_n_206, mul_22_8_n_207;
  wire mul_22_8_n_208, mul_22_8_n_209, mul_22_8_n_210, mul_22_8_n_211,
       mul_22_8_n_212, mul_22_8_n_213, mul_22_8_n_214, mul_22_8_n_215;
  wire mul_22_8_n_216, mul_22_8_n_217, mul_22_8_n_218, mul_22_8_n_219,
       mul_22_8_n_220, mul_22_8_n_221, mul_22_8_n_222, mul_22_8_n_223;
  wire mul_22_8_n_224, mul_22_8_n_225, mul_22_8_n_226, mul_22_8_n_227,
       mul_22_8_n_228, mul_22_8_n_229, mul_22_8_n_230, mul_22_8_n_231;
  wire mul_22_8_n_232, mul_22_8_n_233, mul_22_8_n_234;
  ADDFX1 mul_22_8_cdnfadd_003_0(.A (mul_22_8_n_8), .B (mul_22_8_n_7),
       .CI (mul_22_8_n_78), .CO (mul_22_8_n_225), .S (mul_22_8_n_213));
  ADDFX1 mul_22_8_cdnfadd_004_0(.A (mul_22_8_n_37), .B (mul_22_8_n_50),
       .CI (mul_22_8_n_12), .CO (mul_22_8_n_211), .S (mul_22_8_n_212));
  ADDFX1 mul_22_8_cdnfadd_004_1(.A (mul_22_8_n_75), .B (mul_22_8_n_65),
       .CI (mul_22_8_n_212), .CO (mul_22_8_n_226), .S (mul_22_8_n_214));
  ADDFX1 mul_22_8_cdnfadd_005_0(.A (mul_22_8_n_42), .B (mul_22_8_n_11),
       .CI (mul_22_8_n_36), .CO (mul_22_8_n_208), .S (mul_22_8_n_210));
  ADDFX1 mul_22_8_cdnfadd_005_1(.A (mul_22_8_n_41), .B (mul_22_8_n_77),
       .CI (mul_22_8_n_69), .CO (mul_22_8_n_206), .S (mul_22_8_n_209));
  ADDFX1 mul_22_8_cdnfadd_005_2(.A (mul_22_8_n_211), .B
       (mul_22_8_n_210), .CI (mul_22_8_n_209), .CO (mul_22_8_n_227), .S
       (mul_22_8_n_215));
  ADDFX1 mul_22_8_cdnfadd_006_0(.A (mul_22_8_n_0), .B (mul_22_8_n_34),
       .CI (mul_22_8_n_51), .CO (mul_22_8_n_203), .S (mul_22_8_n_207));
  ADDFX1 mul_22_8_cdnfadd_006_1(.A (mul_22_8_n_20), .B (mul_22_8_n_23),
       .CI (mul_22_8_n_70), .CO (mul_22_8_n_200), .S (mul_22_8_n_205));
  ADDFX1 mul_22_8_cdnfadd_006_2(.A (mul_22_8_n_76), .B
       (mul_22_8_n_208), .CI (mul_22_8_n_207), .CO (mul_22_8_n_198), .S
       (mul_22_8_n_204));
  ADDFX1 mul_22_8_cdnfadd_006_3(.A (mul_22_8_n_206), .B
       (mul_22_8_n_205), .CI (mul_22_8_n_204), .CO (mul_22_8_n_228), .S
       (mul_22_8_n_216));
  ADDFX1 mul_22_8_cdnfadd_007_0(.A (mul_22_8_n_16), .B (mul_22_8_n_49),
       .CI (mul_22_8_n_10), .CO (mul_22_8_n_196), .S (mul_22_8_n_201));
  ADDFX1 mul_22_8_cdnfadd_007_1(.A (mul_22_8_n_9), .B (mul_22_8_n_43),
       .CI (mul_22_8_n_17), .CO (mul_22_8_n_195), .S (mul_22_8_n_202));
  ADDFX1 mul_22_8_cdnfadd_007_2(.A (mul_22_8_n_67), .B (mul_22_8_n_73),
       .CI (mul_22_8_n_203), .CO (mul_22_8_n_192), .S (mul_22_8_n_199));
  ADDFX1 mul_22_8_cdnfadd_007_3(.A (mul_22_8_n_202), .B
       (mul_22_8_n_201), .CI (mul_22_8_n_200), .CO (mul_22_8_n_190), .S
       (mul_22_8_n_197));
  ADDFX1 mul_22_8_cdnfadd_007_4(.A (mul_22_8_n_199), .B
       (mul_22_8_n_198), .CI (mul_22_8_n_197), .CO (mul_22_8_n_229), .S
       (mul_22_8_n_217));
  ADDFX1 mul_22_8_cdnfadd_008_0(.A (mul_22_8_n_13), .B (mul_22_8_n_6),
       .CI (mul_22_8_n_45), .CO (mul_22_8_n_188), .S (mul_22_8_n_194));
  ADDFX1 mul_22_8_cdnfadd_008_1(.A (mul_22_8_n_26), .B (mul_22_8_n_38),
       .CI (mul_22_8_n_72), .CO (mul_22_8_n_185), .S (mul_22_8_n_193));
  ADDFX1 mul_22_8_cdnfadd_008_2(.A (mul_22_8_n_66), .B
       (mul_22_8_n_196), .CI (mul_22_8_n_195), .CO (mul_22_8_n_184), .S
       (mul_22_8_n_191));
  ADDFX1 mul_22_8_cdnfadd_008_3(.A (mul_22_8_n_194), .B
       (mul_22_8_n_193), .CI (mul_22_8_n_192), .CO (mul_22_8_n_181), .S
       (mul_22_8_n_189));
  ADDFX1 mul_22_8_cdnfadd_008_4(.A (mul_22_8_n_191), .B
       (mul_22_8_n_190), .CI (mul_22_8_n_189), .CO (mul_22_8_n_230), .S
       (mul_22_8_n_218));
  ADDFX1 mul_22_8_cdnfadd_009_0(.A (mul_22_8_n_25), .B (mul_22_8_n_39),
       .CI (mul_22_8_n_33), .CO (mul_22_8_n_179), .S (mul_22_8_n_186));
  ADDFX1 mul_22_8_cdnfadd_009_1(.A (mul_22_8_n_44), .B (mul_22_8_n_4),
       .CI (mul_22_8_n_19), .CO (mul_22_8_n_180), .S (mul_22_8_n_187));
  ADDFX1 mul_22_8_cdnfadd_009_2(.A (mul_22_8_n_64), .B
       (mul_22_8_n_188), .CI (mul_22_8_n_187), .CO (mul_22_8_n_176), .S
       (mul_22_8_n_183));
  ADDFX1 mul_22_8_cdnfadd_009_3(.A (mul_22_8_n_186), .B
       (mul_22_8_n_185), .CI (mul_22_8_n_184), .CO (mul_22_8_n_174), .S
       (mul_22_8_n_182));
  ADDFX1 mul_22_8_cdnfadd_009_4(.A (mul_22_8_n_183), .B
       (mul_22_8_n_182), .CI (mul_22_8_n_181), .CO (mul_22_8_n_231), .S
       (mul_22_8_n_219));
  ADDFX1 mul_22_8_cdnfadd_010_0(.A (mul_22_8_n_40), .B (mul_22_8_n_46),
       .CI (mul_22_8_n_5), .CO (mul_22_8_n_173), .S (mul_22_8_n_178));
  ADDFX1 mul_22_8_cdnfadd_010_1(.A (mul_22_8_n_14), .B (mul_22_8_n_2),
       .CI (mul_22_8_n_180), .CO (mul_22_8_n_171), .S (mul_22_8_n_177));
  ADDFX1 mul_22_8_cdnfadd_010_2(.A (mul_22_8_n_179), .B
       (mul_22_8_n_178), .CI (mul_22_8_n_177), .CO (mul_22_8_n_169), .S
       (mul_22_8_n_175));
  ADDFX1 mul_22_8_cdnfadd_010_3(.A (mul_22_8_n_176), .B
       (mul_22_8_n_175), .CI (mul_22_8_n_174), .CO (mul_22_8_n_232), .S
       (mul_22_8_n_220));
  ADDFX1 mul_22_8_cdnfadd_011_0(.A (mul_22_8_n_18), .B (mul_22_8_n_24),
       .CI (mul_22_8_n_3), .CO (mul_22_8_n_168), .S (mul_22_8_n_172));
  ADDFX1 mul_22_8_cdnfadd_011_1(.A (mul_22_8_n_15), .B
       (mul_22_8_n_173), .CI (mul_22_8_n_172), .CO (mul_22_8_n_166), .S
       (mul_22_8_n_170));
  ADDFX1 mul_22_8_cdnfadd_011_2(.A (mul_22_8_n_171), .B
       (mul_22_8_n_170), .CI (mul_22_8_n_169), .CO (mul_22_8_n_222), .S
       (mul_22_8_n_221));
  ADDFX1 mul_22_8_cdnfadd_012_0(.A (mul_22_8_n_21), .B (mul_22_8_n_1),
       .CI (mul_22_8_n_48), .CO (mul_22_8_n_165), .S (mul_22_8_n_167));
  ADDFX1 mul_22_8_cdnfadd_012_1(.A (mul_22_8_n_168), .B
       (mul_22_8_n_167), .CI (mul_22_8_n_166), .CO (mul_22_8_n_223), .S
       (mul_22_8_n_233));
  ADDFX1 mul_22_8_cdnfadd_013_0(.A (mul_22_8_n_35), .B (mul_22_8_n_22),
       .CI (mul_22_8_n_165), .CO (mul_22_8_n_224), .S (mul_22_8_n_234));
  ADDFX1 mul_22_8_g854(.A (mul_22_8_n_158), .B (mul_22_8_n_32), .CI
       (mul_22_8_n_224), .CO (out1[15]), .S (out1[14]));
  XNOR2X1 mul_22_8_g855(.A (mul_22_8_n_109), .B (mul_22_8_n_161), .Y
       (out1[13]));
  AOI21X1 mul_22_8_g856(.A0 (mul_22_8_n_139), .A1 (mul_22_8_n_156), .B0
       (mul_22_8_n_130), .Y (mul_22_8_n_161));
  XNOR2X1 mul_22_8_g857(.A (mul_22_8_n_143), .B (mul_22_8_n_156), .Y
       (out1[12]));
  XNOR2X1 mul_22_8_g858(.A (mul_22_8_n_142), .B (mul_22_8_n_155), .Y
       (out1[11]));
  OAI211X1 mul_22_8_g859(.A0 (mul_22_8_n_131), .A1 (mul_22_8_n_108),
       .B0 (mul_22_8_n_157), .C0 (mul_22_8_n_107), .Y (mul_22_8_n_158));
  NAND3BXL mul_22_8_g860(.AN (mul_22_8_n_108), .B (mul_22_8_n_156), .C
       (mul_22_8_n_139), .Y (mul_22_8_n_157));
  OAI221X1 mul_22_8_g861(.A0 (mul_22_8_n_144), .A1 (mul_22_8_n_148),
       .B0 (mul_22_8_n_144), .B1 (mul_22_8_n_149), .C0
       (mul_22_8_n_147), .Y (mul_22_8_n_156));
  AOI21X1 mul_22_8_g862(.A0 (mul_22_8_n_136), .A1 (mul_22_8_n_152), .B0
       (mul_22_8_n_132), .Y (mul_22_8_n_155));
  XNOR2X1 mul_22_8_g863(.A (mul_22_8_n_141), .B (mul_22_8_n_152), .Y
       (out1[10]));
  XNOR2X1 mul_22_8_g864(.A (mul_22_8_n_146), .B (mul_22_8_n_150), .Y
       (out1[9]));
  NAND2X1 mul_22_8_g865(.A (mul_22_8_n_149), .B (mul_22_8_n_148), .Y
       (mul_22_8_n_152));
  XNOR2X1 mul_22_8_g866(.A (mul_22_8_n_145), .B (mul_22_8_n_129), .Y
       (out1[8]));
  AOI2BB1XL mul_22_8_g867(.A0N (mul_22_8_n_134), .A1N (mul_22_8_n_129),
       .B0 (mul_22_8_n_138), .Y (mul_22_8_n_150));
  AOI21X1 mul_22_8_g868(.A0 (mul_22_8_n_138), .A1 (mul_22_8_n_133), .B0
       (mul_22_8_n_140), .Y (mul_22_8_n_149));
  NAND3BXL mul_22_8_g869(.AN (mul_22_8_n_134), .B (mul_22_8_n_128), .C
       (mul_22_8_n_133), .Y (mul_22_8_n_148));
  AOI21X1 mul_22_8_g870(.A0 (mul_22_8_n_132), .A1 (mul_22_8_n_137), .B0
       (mul_22_8_n_135), .Y (mul_22_8_n_147));
  NOR2BX1 mul_22_8_g871(.AN (mul_22_8_n_133), .B (mul_22_8_n_140), .Y
       (mul_22_8_n_146));
  NOR2X1 mul_22_8_g872(.A (mul_22_8_n_138), .B (mul_22_8_n_134), .Y
       (mul_22_8_n_145));
  NAND2X1 mul_22_8_g873(.A (mul_22_8_n_136), .B (mul_22_8_n_137), .Y
       (mul_22_8_n_144));
  NAND2X1 mul_22_8_g874(.A (mul_22_8_n_131), .B (mul_22_8_n_139), .Y
       (mul_22_8_n_143));
  NOR2BX1 mul_22_8_g875(.AN (mul_22_8_n_137), .B (mul_22_8_n_135), .Y
       (mul_22_8_n_142));
  NAND2BX1 mul_22_8_g876(.AN (mul_22_8_n_132), .B (mul_22_8_n_136), .Y
       (mul_22_8_n_141));
  NOR2X1 mul_22_8_g877(.A (mul_22_8_n_125), .B (mul_22_8_n_124), .Y
       (mul_22_8_n_140));
  NAND2X1 mul_22_8_g878(.A (mul_22_8_n_126), .B (mul_22_8_n_104), .Y
       (mul_22_8_n_139));
  NOR2X1 mul_22_8_g879(.A (mul_22_8_n_111), .B (mul_22_8_n_123), .Y
       (mul_22_8_n_138));
  NAND2X1 mul_22_8_g880(.A (mul_22_8_n_122), .B (mul_22_8_n_121), .Y
       (mul_22_8_n_137));
  NAND2X1 mul_22_8_g881(.A (mul_22_8_n_120), .B (mul_22_8_n_119), .Y
       (mul_22_8_n_136));
  INVX1 mul_22_8_g882(.A (mul_22_8_n_130), .Y (mul_22_8_n_131));
  INVXL mul_22_8_g883(.A (mul_22_8_n_129), .Y (mul_22_8_n_128));
  NOR2X1 mul_22_8_g884(.A (mul_22_8_n_122), .B (mul_22_8_n_121), .Y
       (mul_22_8_n_135));
  AND2XL mul_22_8_g885(.A (mul_22_8_n_111), .B (mul_22_8_n_123), .Y
       (mul_22_8_n_134));
  NAND2X1 mul_22_8_g886(.A (mul_22_8_n_125), .B (mul_22_8_n_124), .Y
       (mul_22_8_n_133));
  NOR2X1 mul_22_8_g887(.A (mul_22_8_n_120), .B (mul_22_8_n_119), .Y
       (mul_22_8_n_132));
  NOR2X1 mul_22_8_g888(.A (mul_22_8_n_126), .B (mul_22_8_n_104), .Y
       (mul_22_8_n_130));
  AOI221X1 mul_22_8_g889(.A0 (mul_22_8_n_116), .A1 (mul_22_8_n_101),
       .B0 (mul_22_8_n_116), .B1 (mul_22_8_n_100), .C0
       (mul_22_8_n_118), .Y (mul_22_8_n_129));
  XNOR2X1 mul_22_8_g890(.A (mul_22_8_n_117), .B (mul_22_8_n_112), .Y
       (out1[7]));
  INVX1 mul_22_8_g891(.A (mul_22_8_n_222), .Y (mul_22_8_n_126));
  INVX1 mul_22_8_g892(.A (mul_22_8_n_230), .Y (mul_22_8_n_125));
  INVX1 mul_22_8_g893(.A (mul_22_8_n_219), .Y (mul_22_8_n_124));
  INVX1 mul_22_8_g894(.A (mul_22_8_n_218), .Y (mul_22_8_n_123));
  INVX1 mul_22_8_g895(.A (mul_22_8_n_232), .Y (mul_22_8_n_122));
  INVX1 mul_22_8_g896(.A (mul_22_8_n_221), .Y (mul_22_8_n_121));
  INVX1 mul_22_8_g897(.A (mul_22_8_n_231), .Y (mul_22_8_n_120));
  INVX1 mul_22_8_g898(.A (mul_22_8_n_220), .Y (mul_22_8_n_119));
  OAI21X1 mul_22_8_g899(.A0 (mul_22_8_n_106), .A1 (mul_22_8_n_114), .B0
       (mul_22_8_n_115), .Y (mul_22_8_n_118));
  NAND2BX1 mul_22_8_g900(.AN (mul_22_8_n_114), .B (mul_22_8_n_115), .Y
       (mul_22_8_n_117));
  NOR2X1 mul_22_8_g901(.A (mul_22_8_n_105), .B (mul_22_8_n_114), .Y
       (mul_22_8_n_116));
  NAND2X1 mul_22_8_g902(.A (mul_22_8_n_228), .B (mul_22_8_n_217), .Y
       (mul_22_8_n_115));
  NOR2X1 mul_22_8_g903(.A (mul_22_8_n_228), .B (mul_22_8_n_217), .Y
       (mul_22_8_n_114));
  XNOR2X1 mul_22_8_g904(.A (mul_22_8_n_103), .B (mul_22_8_n_110), .Y
       (out1[6]));
  OAI21X1 mul_22_8_g905(.A0 (mul_22_8_n_105), .A1 (mul_22_8_n_103), .B0
       (mul_22_8_n_106), .Y (mul_22_8_n_112));
  INVX1 mul_22_8_g906(.A (mul_22_8_n_229), .Y (mul_22_8_n_111));
  NOR2BX1 mul_22_8_g907(.AN (mul_22_8_n_106), .B (mul_22_8_n_105), .Y
       (mul_22_8_n_110));
  NOR2BX1 mul_22_8_g908(.AN (mul_22_8_n_107), .B (mul_22_8_n_108), .Y
       (mul_22_8_n_109));
  NOR2X1 mul_22_8_g909(.A (mul_22_8_n_223), .B (mul_22_8_n_234), .Y
       (mul_22_8_n_108));
  NAND2X1 mul_22_8_g910(.A (mul_22_8_n_223), .B (mul_22_8_n_234), .Y
       (mul_22_8_n_107));
  NAND2X1 mul_22_8_g911(.A (mul_22_8_n_227), .B (mul_22_8_n_216), .Y
       (mul_22_8_n_106));
  NOR2X1 mul_22_8_g912(.A (mul_22_8_n_227), .B (mul_22_8_n_216), .Y
       (mul_22_8_n_105));
  INVX1 mul_22_8_g913(.A (mul_22_8_n_233), .Y (mul_22_8_n_104));
  XNOR2X1 mul_22_8_g914(.A (mul_22_8_n_95), .B (mul_22_8_n_99), .Y
       (out1[5]));
  NOR2X1 mul_22_8_g915(.A (mul_22_8_n_101), .B (mul_22_8_n_100), .Y
       (mul_22_8_n_103));
  OAI21X1 mul_22_8_g916(.A0 (mul_22_8_n_92), .A1 (mul_22_8_n_97), .B0
       (mul_22_8_n_98), .Y (mul_22_8_n_101));
  NOR2X1 mul_22_8_g917(.A (mul_22_8_n_97), .B (mul_22_8_n_94), .Y
       (mul_22_8_n_100));
  NAND2BX1 mul_22_8_g918(.AN (mul_22_8_n_97), .B (mul_22_8_n_98), .Y
       (mul_22_8_n_99));
  NAND2X1 mul_22_8_g919(.A (mul_22_8_n_226), .B (mul_22_8_n_215), .Y
       (mul_22_8_n_98));
  NOR2X1 mul_22_8_g920(.A (mul_22_8_n_226), .B (mul_22_8_n_215), .Y
       (mul_22_8_n_97));
  XNOR2X1 mul_22_8_g921(.A (mul_22_8_n_90), .B (mul_22_8_n_93), .Y
       (out1[4]));
  NAND2XL mul_22_8_g922(.A (mul_22_8_n_92), .B (mul_22_8_n_94), .Y
       (mul_22_8_n_95));
  NAND2X1 mul_22_8_g923(.A (mul_22_8_n_91), .B (mul_22_8_n_90), .Y
       (mul_22_8_n_94));
  NAND2X1 mul_22_8_g924(.A (mul_22_8_n_92), .B (mul_22_8_n_91), .Y
       (mul_22_8_n_93));
  NAND2X1 mul_22_8_g925(.A (mul_22_8_n_225), .B (mul_22_8_n_214), .Y
       (mul_22_8_n_92));
  OR2X1 mul_22_8_g926(.A (mul_22_8_n_225), .B (mul_22_8_n_214), .Y
       (mul_22_8_n_91));
  XNOR2X1 mul_22_8_g927(.A (mul_22_8_n_84), .B (mul_22_8_n_88), .Y
       (out1[3]));
  OAI221X1 mul_22_8_g928(.A0 (mul_22_8_n_87), .A1 (mul_22_8_n_83), .B0
       (mul_22_8_n_87), .B1 (mul_22_8_n_80), .C0 (mul_22_8_n_86), .Y
       (mul_22_8_n_90));
  NOR2BX1 mul_22_8_g929(.AN (mul_22_8_n_86), .B (mul_22_8_n_87), .Y
       (mul_22_8_n_88));
  NOR2X1 mul_22_8_g930(.A (mul_22_8_n_213), .B (mul_22_8_n_71), .Y
       (mul_22_8_n_87));
  NAND2X1 mul_22_8_g931(.A (mul_22_8_n_213), .B (mul_22_8_n_71), .Y
       (mul_22_8_n_86));
  XNOR2X1 mul_22_8_g932(.A (mul_22_8_n_68), .B (mul_22_8_n_82), .Y
       (out1[2]));
  AND2XL mul_22_8_g933(.A (mul_22_8_n_80), .B (mul_22_8_n_83), .Y
       (mul_22_8_n_84));
  NAND2XL mul_22_8_g934(.A (mul_22_8_n_68), .B (mul_22_8_n_81), .Y
       (mul_22_8_n_83));
  NAND2X1 mul_22_8_g935(.A (mul_22_8_n_80), .B (mul_22_8_n_81), .Y
       (mul_22_8_n_82));
  NAND2X1 mul_22_8_g936(.A (mul_22_8_n_31), .B (mul_22_8_n_74), .Y
       (mul_22_8_n_81));
  OR2X1 mul_22_8_g937(.A (mul_22_8_n_31), .B (mul_22_8_n_74), .Y
       (mul_22_8_n_80));
  AOI21X1 mul_22_8_g938(.A0 (mul_22_8_n_62), .A1 (mul_22_8_n_63), .B0
       (mul_22_8_n_68), .Y (out1[1]));
  XOR2XL mul_22_8_g939(.A (mul_22_8_n_27), .B (mul_22_8_n_57), .Y
       (mul_22_8_n_78));
  XOR2XL mul_22_8_g940(.A (mul_22_8_n_61), .B (mul_22_8_n_53), .Y
       (mul_22_8_n_77));
  XOR2XL mul_22_8_g941(.A (mul_22_8_n_28), .B (mul_22_8_n_30), .Y
       (mul_22_8_n_76));
  XOR2XL mul_22_8_g942(.A (mul_22_8_n_52), .B (mul_22_8_n_56), .Y
       (mul_22_8_n_75));
  XNOR2X1 mul_22_8_g943(.A (mul_22_8_n_55), .B (mul_22_8_n_54), .Y
       (mul_22_8_n_74));
  XOR2XL mul_22_8_g944(.A (mul_22_8_n_29), .B (mul_22_8_n_60), .Y
       (mul_22_8_n_73));
  XOR2XL mul_22_8_g945(.A (mul_22_8_n_58), .B (mul_22_8_n_59), .Y
       (mul_22_8_n_72));
  NOR2X1 mul_22_8_g946(.A (mul_22_8_n_55), .B (mul_22_8_n_54), .Y
       (mul_22_8_n_71));
  NOR2X1 mul_22_8_g947(.A (mul_22_8_n_61), .B (mul_22_8_n_53), .Y
       (mul_22_8_n_70));
  NOR2X1 mul_22_8_g948(.A (mul_22_8_n_52), .B (mul_22_8_n_56), .Y
       (mul_22_8_n_69));
  NOR2X1 mul_22_8_g949(.A (mul_22_8_n_62), .B (mul_22_8_n_63), .Y
       (mul_22_8_n_68));
  NOR2X1 mul_22_8_g950(.A (mul_22_8_n_28), .B (mul_22_8_n_30), .Y
       (mul_22_8_n_67));
  NOR2X1 mul_22_8_g951(.A (mul_22_8_n_29), .B (mul_22_8_n_60), .Y
       (mul_22_8_n_66));
  NOR2X1 mul_22_8_g952(.A (mul_22_8_n_27), .B (mul_22_8_n_57), .Y
       (mul_22_8_n_65));
  NOR2X1 mul_22_8_g953(.A (mul_22_8_n_58), .B (mul_22_8_n_59), .Y
       (mul_22_8_n_64));
  AND2XL mul_22_8_g954(.A (in1[4]), .B (in2[2]), .Y (mul_22_8_n_51));
  AND2XL mul_22_8_g955(.A (in1[0]), .B (in2[4]), .Y (mul_22_8_n_50));
  AND2XL mul_22_8_g956(.A (in1[0]), .B (in2[7]), .Y (mul_22_8_n_49));
  AND2XL mul_22_8_g957(.A (in1[5]), .B (in2[7]), .Y (mul_22_8_n_48));
  AND2XL mul_22_8_g958(.A (in1[0]), .B (in2[0]), .Y (out1[0]));
  AND2XL mul_22_8_g959(.A (in1[6]), .B (in2[4]), .Y (mul_22_8_n_46));
  AND2XL mul_22_8_g960(.A (in1[5]), .B (in2[3]), .Y (mul_22_8_n_45));
  AND2XL mul_22_8_g961(.A (in1[3]), .B (in2[6]), .Y (mul_22_8_n_44));
  AND2XL mul_22_8_g962(.A (in1[2]), .B (in2[5]), .Y (mul_22_8_n_43));
  AND2XL mul_22_8_g963(.A (in1[2]), .B (in2[3]), .Y (mul_22_8_n_42));
  AND2XL mul_22_8_g964(.A (in1[0]), .B (in2[5]), .Y (mul_22_8_n_41));
  AND2XL mul_22_8_g965(.A (in1[7]), .B (in2[3]), .Y (mul_22_8_n_40));
  AND2XL mul_22_8_g966(.A (in1[6]), .B (in2[3]), .Y (mul_22_8_n_39));
  AND2XL mul_22_8_g967(.A (in1[1]), .B (in2[7]), .Y (mul_22_8_n_38));
  AND2XL mul_22_8_g968(.A (in1[1]), .B (in2[3]), .Y (mul_22_8_n_37));
  AND2XL mul_22_8_g969(.A (in1[3]), .B (in2[2]), .Y (mul_22_8_n_36));
  AND2XL mul_22_8_g970(.A (in1[7]), .B (in2[6]), .Y (mul_22_8_n_35));
  AND2XL mul_22_8_g971(.A (in1[2]), .B (in2[4]), .Y (mul_22_8_n_34));
  AND2XL mul_22_8_g972(.A (in1[4]), .B (in2[5]), .Y (mul_22_8_n_33));
  AND2XL mul_22_8_g973(.A (in1[7]), .B (in2[7]), .Y (mul_22_8_n_32));
  NAND2X1 mul_22_8_g974(.A (in1[1]), .B (in2[0]), .Y (mul_22_8_n_63));
  NAND2X1 mul_22_8_g975(.A (in1[0]), .B (in2[1]), .Y (mul_22_8_n_62));
  NAND2X1 mul_22_8_g976(.A (in1[4]), .B (in2[1]), .Y (mul_22_8_n_61));
  NAND2X1 mul_22_8_g977(.A (in1[7]), .B (in2[0]), .Y (mul_22_8_n_60));
  NAND2X1 mul_22_8_g978(.A (in1[7]), .B (in2[1]), .Y (mul_22_8_n_59));
  NAND2X1 mul_22_8_g979(.A (in1[6]), .B (in2[2]), .Y (mul_22_8_n_58));
  NAND2X1 mul_22_8_g980(.A (in1[3]), .B (in2[0]), .Y (mul_22_8_n_57));
  NAND2X1 mul_22_8_g981(.A (in1[4]), .B (in2[0]), .Y (mul_22_8_n_56));
  NAND2X1 mul_22_8_g982(.A (in1[0]), .B (in2[2]), .Y (mul_22_8_n_55));
  NAND2X1 mul_22_8_g983(.A (in1[2]), .B (in2[0]), .Y (mul_22_8_n_54));
  NAND2X1 mul_22_8_g984(.A (in1[5]), .B (in2[0]), .Y (mul_22_8_n_53));
  NAND2X1 mul_22_8_g985(.A (in1[3]), .B (in2[1]), .Y (mul_22_8_n_52));
  AND2XL mul_22_8_g986(.A (in1[2]), .B (in2[6]), .Y (mul_22_8_n_26));
  AND2XL mul_22_8_g987(.A (in1[7]), .B (in2[2]), .Y (mul_22_8_n_25));
  AND2XL mul_22_8_g988(.A (in1[6]), .B (in2[5]), .Y (mul_22_8_n_24));
  AND2XL mul_22_8_g989(.A (in1[0]), .B (in2[6]), .Y (mul_22_8_n_23));
  AND2XL mul_22_8_g990(.A (in1[6]), .B (in2[7]), .Y (mul_22_8_n_22));
  AND2XL mul_22_8_g991(.A (in1[7]), .B (in2[5]), .Y (mul_22_8_n_21));
  AND2XL mul_22_8_g992(.A (in1[1]), .B (in2[5]), .Y (mul_22_8_n_20));
  AND2XL mul_22_8_g993(.A (in1[2]), .B (in2[7]), .Y (mul_22_8_n_19));
  AND2XL mul_22_8_g994(.A (in1[7]), .B (in2[4]), .Y (mul_22_8_n_18));
  AND2XL mul_22_8_g995(.A (in1[1]), .B (in2[6]), .Y (mul_22_8_n_17));
  AND2XL mul_22_8_g996(.A (in1[4]), .B (in2[3]), .Y (mul_22_8_n_16));
  AND2XL mul_22_8_g997(.A (in1[5]), .B (in2[6]), .Y (mul_22_8_n_15));
  AND2XL mul_22_8_g998(.A (in1[3]), .B (in2[7]), .Y (mul_22_8_n_14));
  AND2XL mul_22_8_g999(.A (in1[4]), .B (in2[4]), .Y (mul_22_8_n_13));
  AND2XL mul_22_8_g1000(.A (in1[2]), .B (in2[2]), .Y (mul_22_8_n_12));
  AND2XL mul_22_8_g1001(.A (in1[1]), .B (in2[4]), .Y (mul_22_8_n_11));
  AND2XL mul_22_8_g1002(.A (in1[3]), .B (in2[4]), .Y (mul_22_8_n_10));
  AND2XL mul_22_8_g1003(.A (in1[5]), .B (in2[2]), .Y (mul_22_8_n_9));
  AND2XL mul_22_8_g1004(.A (in1[0]), .B (in2[3]), .Y (mul_22_8_n_8));
  AND2XL mul_22_8_g1005(.A (in1[1]), .B (in2[2]), .Y (mul_22_8_n_7));
  AND2XL mul_22_8_g1006(.A (in1[3]), .B (in2[5]), .Y (mul_22_8_n_6));
  AND2XL mul_22_8_g1007(.A (in1[4]), .B (in2[6]), .Y (mul_22_8_n_5));
  AND2XL mul_22_8_g1008(.A (in1[5]), .B (in2[4]), .Y (mul_22_8_n_4));
  AND2XL mul_22_8_g1009(.A (in1[4]), .B (in2[7]), .Y (mul_22_8_n_3));
  AND2XL mul_22_8_g1010(.A (in1[5]), .B (in2[5]), .Y (mul_22_8_n_2));
  AND2XL mul_22_8_g1011(.A (in1[6]), .B (in2[6]), .Y (mul_22_8_n_1));
  AND2XL mul_22_8_g1012(.A (in1[3]), .B (in2[3]), .Y (mul_22_8_n_0));
  NAND2X1 mul_22_8_g1013(.A (in1[1]), .B (in2[1]), .Y (mul_22_8_n_31));
  NAND2X1 mul_22_8_g1014(.A (in1[6]), .B (in2[0]), .Y (mul_22_8_n_30));
  NAND2X1 mul_22_8_g1015(.A (in1[6]), .B (in2[1]), .Y (mul_22_8_n_29));
  NAND2X1 mul_22_8_g1016(.A (in1[5]), .B (in2[1]), .Y (mul_22_8_n_28));
  NAND2X1 mul_22_8_g1017(.A (in1[2]), .B (in2[1]), .Y (mul_22_8_n_27));
endmodule

