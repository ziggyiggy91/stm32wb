/*
 * stm_clk.h
 *
 *  Created on: Mar 6, 2020
 *      Author: Ismae
 */

#ifndef STM_CLK_H_
#define STM_CLK_H_

/*
 * stm_clk.c
 *
 *  Created on: Mar 6, 2020
 *      Author: Ismae
 */

  struct RCC{
   /*RCC_CR Register*/
   unsigned long MSION;
   unsigned long MSIRDY;
   unsigned long MSIPLLEN;
   unsigned long MSIRANGE;
   unsigned long HSION;
   unsigned long HSIKERON;
   unsigned long HSIRDY;
   unsigned long HSIASFS;
   unsigned long HSIKERDY;
   unsigned long HSEON;
   unsigned long HSERDY;
   unsigned long CSSON;
   unsigned long HSEPRE;
   unsigned long PLLON;
   unsigned long PLLSAI1ON;
   unsigned long PLLSAI1RDY;
   
   unsigned long MSICLK;
   
   /*RCC_ICSCR Register*/
   unsigned long MSICAL;
   unsigned long MSITRIM;
   unsigned long HSICAL;
   unsigned long HSITRIM;
   /*RCC_CFGR Register*/
   unsigned long SW;
   unsigned long SWS;
   unsigned long HPRE;
   unsigned long PPRE1;
   unsigned long PPRE2;
   unsigned long STOPWUCK;
   unsigned long HPREF;
   unsigned long PPRE1F;
   unsigned long PPRE2F;
   unsigned long MCOSEL;
   unsigned long MCOPRE;
   /*RCC_PLLCFGR Register*/
   unsigned long PLLSRC;
   unsigned long PLLM;
   unsigned long PLLN;
   unsigned long PLLPEN;
   unsigned long PLLP;
   unsigned long PLLQEN;
   unsigned long PLLQ;
   unsigned long PLLREN;
   unsigned long PLLR; 
 };


#define MSI_CALIB		64
#define HSI_CALIB		64



#define PLLR_2 		1
#define PLLR_3 		2
#define PLLR_4 		3
#define PLLR_5 		4
#define PLLR_6 		5
#define PLLR_7 		6
#define PLLR_8 		7

#define PLLQ_2 		1
#define PLLQ_3 		2
#define PLLQ_4 		3
#define PLLQ_5 		4
#define PLLQ_6 		5
#define PLLQ_7 		6
#define PLLQ_8 		7

#define PLLP_2 		1
#define PLLP_3 		2
#define PLLP_4 		3
#define PLLP_5 		4
#define PLLP_6 		5
#define PLLP_7 		6
#define PLLP_8 		7
#define PLLP_9 		8
#define PLLP_10 	9
#define PLLP_11 	10
#define PLLP_12 	11
#define PLLP_13 	12
#define PLLP_14 	13
#define PLLP_15 	14
#define PLLP_16 	15
#define PLLP_17 	16
#define PLLP_18 	17
#define PLLP_19 	18
#define PLLP_20 	19
#define PLLP_21 	20
#define PLLP_22 	21
#define PLLP_23 	22
#define PLLP_24 	23
#define PLLP_25 	24
#define PLLP_26 	25
#define PLLP_27 	26
#define PLLP_28 	27
#define PLLP_29 	28
#define PLLP_30 	29
#define PLLP_31 	30
#define PLLP_32 	31

#define PLLP_2 		1
#define PLLP_3 		2
#define PLLP_4 		3
#define PLLP_5 		4
#define PLLP_6 		5
#define PLLP_7 		6
#define PLLP_8 		7
#define PLLP_9 		8
#define PLLP_10 	9
#define PLLP_11 	10
#define PLLP_12 	11
#define PLLP_13 	12
#define PLLP_14 	13
#define PLLP_15 	14
#define PLLP_16 	15
#define PLLP_17 	16
#define PLLP_18 	17
#define PLLP_19 	18
#define PLLP_20 	19
#define PLLP_21 	20
#define PLLP_22 	21
#define PLLP_23 	22
#define PLLP_24 	23
#define PLLP_25 	24
#define PLLP_26 	25
#define PLLP_27 	26
#define PLLP_28 	27
#define PLLP_29 	28
#define PLLP_30 	29
#define PLLP_31 	30
#define PLLP_32 	31

#define PLLN_2 		1
#define PLLN_3 		2
#define PLLN_4 		3
#define PLLN_5 		4
#define PLLN_6 		5
#define PLLN_7 		6
#define PLLN_8 		7
#define PLLN_9 		8
#define PLLN_10 	9
#define PLLN_11 	10
#define PLLN_12 	11
#define PLLN_13 	12
#define PLLN_14 	13
#define PLLN_15 	14
#define PLLN_16 	15
#define PLLN_17 	16
#define PLLN_18 	17
#define PLLN_19 	18
#define PLLN_20 	19
#define PLLN_21 	20
#define PLLN_22 	21
#define PLLN_23 	22
#define PLLN_24 	23
#define PLLN_25 	24
#define PLLN_26 	25
#define PLLN_27 	26
#define PLLN_28 	27
#define PLLN_29 	28
#define PLLN_30 	29
#define PLLN_31 	30
#define PLLN_32 	31
#define PLLN_33 	32
#define PLLN_34 	33
#define PLLN_35 	34
#define PLLN_36 	35
#define PLLN_37 	36
#define PLLN_38 	37
#define PLLN_39 	38
#define PLLN_40 	39
#define PLLN_41 	40
#define PLLN_42 	41
#define PLLN_43 	42
#define PLLN_44 	43
#define PLLN_45 	44
#define PLLN_46 	45
#define PLLN_47 	46
#define PLLN_48 	47
#define PLLN_49 	48
#define PLLN_50 	49
#define PLLN_51 	50
#define PLLN_52 	51
#define PLLN_53 	52
#define PLLN_54 	53
#define PLLN_55 	54
#define PLLN_56 	55
#define PLLN_57 	56
#define PLLN_58 	57
#define PLLN_59 	58
#define PLLN_60 	59
#define PLLN_61 	60
#define PLLN_62 	61
#define PLLN_63 	62
#define PLLN_64 	63
#define PLLN_65 	64
#define PLLN_66 	65
#define PLLN_67 	66
#define PLLN_68 	67
#define PLLN_69 	68
#define PLLN_70 	69
#define PLLN_71 	70
#define PLLN_72 	71
#define PLLN_73 	72
#define PLLN_74 	73
#define PLLN_75 	74
#define PLLN_76 	75
#define PLLN_77 	76
#define PLLN_78 	77
#define PLLN_79 	78
#define PLLN_80 	79
#define PLLN_81 	80
#define PLLN_82 	81
#define PLLN_83 	82
#define PLLN_84 	83
#define PLLN_85 	84
#define PLLN_86 	85
#define PLLN_87 	86
#define PLLN_88 	87
#define PLLN_89 	88
#define PLLN_90 	89
#define PLLN_91 	90
#define PLLN_92 	91
#define PLLN_93 	92
#define PLLN_94 	93
#define PLLN_95 	94
#define PLLN_96 	95
#define PLLN_97 	96
#define PLLN_98 	97
#define PLLN_99 	98
#define PLLN_100 	99
#define PLLN_101 	100
#define PLLN_102 	101
#define PLLN_103 	102
#define PLLN_104 	103
#define PLLN_105 	104
#define PLLN_106 	105
#define PLLN_107 	106
#define PLLN_108 	107
#define PLLN_109 	108
#define PLLN_110 	109
#define PLLN_111 	110
#define PLLN_112 	111
#define PLLN_113 	112
#define PLLN_114 	113
#define PLLN_115 	114
#define PLLN_116 	115
#define PLLN_117 	116
#define PLLN_118 	117
#define PLLN_119 	118
#define PLLN_120 	119
#define PLLN_121 	120
#define PLLN_122 	121
#define PLLN_123 	122
#define PLLN_124 	123
#define PLLN_125 	124
#define PLLN_126 	125
#define PLLN_127 	126
 

void init_msi(struct RCC *);

void config_msi_clock(struct RCC *);
void config_hsi_clock(struct RCC *);
void config_hse_clock(struct RCC *);
void config_pll_clock(struct RCC *);
void configure_system_clock(struct RCC *);



#endif /* STM_CLK_H_ */
