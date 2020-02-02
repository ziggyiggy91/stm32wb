/*
STM32WB55CE Registers



*/


/* Clock Registers */
#define RCC             ((void *) 0x58000000)
#define RCC_CR          ((void *) 0x00000000)

#define RCC_ICSCR         ((void *) 0x00000004)
#define RCC_CFGR          ((void *) 0x00000008)
#define RCC_PLLCFGR       ((void *) 0x0000000C)
#define RCC_PLLSAI1CFGR   ((void *) 0x00000010)
#define RCC_CIER          ((void *) 0x00000018)
#define RCC_CIFR     	  ((void *) 0x0000001C)
#define RCC_CICR     	  ((void *) 0x00000020)
#define RCC_SMPSCR	      ((void *) 0x00000024)
#define RCC_AHB1RSTR      ((void *) 0x00000028)
#define RCC_AHB2RSTR      ((void *) 0x0000002C)
#define RCC_AHB3RSTR      ((void *) 0x00000030)
#define RCC_APB1RSTR1     ((void *) 0x00000038)
#define RCC_APB1RSTR2     ((void *) 0x0000003C)
#define RCC_APB2RSTR      ((void *) 0x00000040)
#define RCC_APB3RSTR      ((void *) 0x00000044)
#define RCC_AHB1ENR       ((void *) 0x00000048)
#define RCC_AHB2ENR       ((void *) 0x0000004C)
#define RCC_AHB3ENR       ((void *) 0x00000050)
#define RCC_APB1ENR1      ((void *) 0x00000058)
#define RCC_APB1ENR2      ((void *) 0x0000005C)
#define RCC_AHB1SMENR     ((void *) 0x00000068)
#define RCC_AHB2SMENR     ((void *) 0x0000006C)
#define RCC_AHB3SMENR     ((void *) 0x00000070)
#define RCC_APB1SMENR1    ((void *) 0x00000078)
#define RCC_APB1SMENR2    ((void *) 0x0000007C)
#define RCC_APB2SMENR     ((void *) 0x00000080)
#define RCC_CCIPR    	  ((void *) 0x00000088)
#define RCC_BDCR	      ((void *) 0x00000090)
#define RCC_CSR        	  ((void *) 0x00000094)
#define RCC_CRRCR    	  ((void *) 0x00000098)
#define RCC_HSECR         ((void *) 0x0000009C)
#define RCC_EXTCFGR       ((void *) 0x00000108)
#define RCC_C2AHB1ENR     ((void *) 0x00000148)
#define RCC_C2AHB2ENR     ((void *) 0x0000014C)
#define RCC_C2AHB3ENR     ((void *) 0x00000150)
#define RCC_C2APB1ENR1    ((void *) 0x00000158)
#define RCC_C2APB1ENR2    ((void *) 0x0000015C)
#define RCC_C2APB2ENR     ((void *) 0x00000160)
#define RCC_C2APB3ENR     ((void *) 0x00000164)
#define RCC_C2AHB1SMENR   ((void *) 0x00000168)
#define RCC_C2AHB2SMENR   ((void *) 0x0000016C)
#define RCC_C2AHB3SMENR   ((void *) 0x00000170)
#define RCC_C2_APB1SMENR1 ((void *) 0x00000178)
#define RCC_C2_APB1SMENR2 ((void *) 0x0000017C)
#define RCC_C2_APB2SMENR  ((void *) 0x00000180)
#define RCC_C2_APB3SMENR  ((void *) 0x00000184)





/* ADC1 Registers  */
#define ADC1        ((void *) 0x50040000)
#define ADC_ISR     ((void *) 0x00000000)
#define ADC_IER     ((void *) 0x00000004)
#define ADC_CR      ((void *) 0x00000008)
#define ADC_CFGR    ((void *) 0x0000000C)
#define ADC_CFGR2   ((void *) 0x00000010)
#define ADC_SMPR1   ((void *) 0x00000014)
#define ADC_TR3     ((void *) 0x00000028)
#define ADC_SQR1    ((void *) 0x00000030)
#define ADC_SQR2    ((void *) 0x00000034)
#define ADC_SQR3    ((void *) 0x00000038)
#define ADC_SQR4    ((void *) 0x0000003C)
#define ADC_DR      ((void *) 0x00000040)
#define ADC_JSQR    ((void *) 0x0000004C)
#define ADC_OFR1    ((void *) 0x00000060)
#define ADC_OFR2    ((void *) 0x00000064)
#define ADC_OFR3    ((void *) 0x00000068)
#define ADC_OFR4    ((void *) 0x0000006C)
#define ADC_JDR1    ((void *) 0x00000080)
#define ADC_JDR1    ((void *) 0x00000084)
#define ADC_JDR1    ((void *) 0x00000088)
#define ADC_JDR1    ((void *) 0x0000008C)
#define ADC_AWD2CR  ((void *) 0x000000A0)
#define ADC_AWD3CR  ((void *) 0x000000A4)
#define ADC_DIFSEL  ((void *) 0x000000B0)
#define ADC_CALFACT ((void *) 0x000000A0)

#define ADC_CSR     ((void *) 0x00000300)
#define ADC_CCR     ((void *) 0x00000308)


