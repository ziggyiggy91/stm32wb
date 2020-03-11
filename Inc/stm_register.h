/*
 * stm_register.h
 *
 *  Created on: Mar 6, 2020
 *      Author: Ismae
 */

#ifndef STM_REGISTER_H_
#define STM_REGISTER_H_



/*
STM32WB55CE Registers



*/


/* Clock Registers


ADC Clock is derived from one of the following sources:
  - PLL VCO
  - SYSCLK
  - PLLSAI1 VCO

RF Clock is derived from one of the following sources:
  - HSI16 Clock
  - HSE Clock

*/
#define RCC_CR            (*((volatile unsigned long *)   0x58000000))
#define RCC_ICSCR         (*((volatile unsigned long *) 0x58000004))
#define RCC_CFGR          (*((volatile unsigned long *) 0x58000008))
#define RCC_PLLCFGR       (*((volatile unsigned long *) 0x5800000C))
#define RCC_PLLSAI1CFGR   (*((volatile unsigned long *) 0x58000010))
#define RCC_CIER          (*((volatile unsigned long *) 0x58000018))
#define RCC_CIFR     	  (*((volatile unsigned long *) 0x5800001C))
#define RCC_CICR     	  (*((volatile unsigned long *) 0x58000020))
#define RCC_SMPSCR	      (*((volatile unsigned long *) 0x58000024))
#define RCC_AHB1RSTR      (*((volatile unsigned long *) 0x58000028))
#define RCC_AHB2RSTR      (*((volatile unsigned long *) 0x5800002C))
#define RCC_AHB3RSTR      (*((volatile unsigned long *) 0x58000030))
#define RCC_APB1RSTR1     (*((volatile unsigned long *) 0x58000038))
#define RCC_APB1RSTR2     (*((volatile unsigned long *) 0x5800003C))
#define RCC_APB2RSTR      (*((volatile unsigned long *) 0x58000040))
#define RCC_APB3RSTR      (*((volatile unsigned long *) 0x58000044))
#define RCC_AHB1ENR       (*((volatile unsigned long *) 0x58000048))
#define RCC_AHB2ENR       (*((volatile unsigned long *) 0x5800004C))
#define RCC_AHB3ENR       (*((volatile unsigned long *) 0x58000050))
#define RCC_APB1ENR1      (*((volatile unsigned long *) 0x58000058))
#define RCC_APB1ENR2      (*((volatile unsigned long *) 0x5800005C))
#define RCC_AHB1SMENR     (*((volatile unsigned long *) 0x58000068))
#define RCC_AHB2SMENR     (*((volatile unsigned long *) 0x5800006C))
#define RCC_AHB3SMENR     (*((volatile unsigned long *) 0x58000070))
#define RCC_APB1SMENR1    (*((volatile unsigned long *) 0x58000078))
#define RCC_APB1SMENR2    (*((volatile unsigned long *) 0x5800007C))
#define RCC_APB2SMENR     (*((volatile unsigned long *) 0x58000080))
#define RCC_CCIPR    	  (*((volatile unsigned long *) 0x58000088))
#define RCC_BDCR	      (*((volatile unsigned long *) 0x58000090))
#define RCC_CSR        	  (*((volatile unsigned long *) 0x58000094))
#define RCC_CRRCR    	  (*((volatile unsigned long *) 0x58000098))
#define RCC_HSECR         (*((volatile unsigned long *) 0x5800009C))
#define RCC_EXTCFGR       (*((volatile unsigned long *) 0x58000108))
#define RCC_C2AHB1ENR     (*((volatile unsigned long *) 0x58000148))
#define RCC_C2AHB2ENR     (*((volatile unsigned long *) 0x5800014C))
#define RCC_C2AHB3ENR     (*((volatile unsigned long *) 0x58000150))
#define RCC_C2APB1ENR1    (*((volatile unsigned long *) 0x58000158))
#define RCC_C2APB1ENR2    (*((volatile unsigned long *) 0x5800015C))
#define RCC_C2APB2ENR     (*((volatile unsigned long *) 0x58000160))
#define RCC_C2APB3ENR     (*((volatile unsigned long *) 0x58000164))
#define RCC_C2AHB1SMENR   (*((volatile unsigned long *) 0x58000168))
#define RCC_C2AHB2SMENR   (*((volatile unsigned long *) 0x5800016C))
#define RCC_C2AHB3SMENR   (*((volatile unsigned long *) 0x58000170))
#define RCC_C2_APB1SMENR1 (*((volatile unsigned long *) 0x58000178))
#define RCC_C2_APB1SMENR2 (*((volatile unsigned long *) 0x5800017C))
#define RCC_C2_APB2SMENR  (*((volatile unsigned long *) 0x58000180))
#define RCC_C2_APB3SMENR  (*((volatile unsigned long *) 0x58000184))





/* ADC1 Registers  */
#define ADC1        (*((volatile unsigned long *) 0x50040000))
#define ADC_ISR     (*((volatile unsigned long *) 0x50040000))
#define ADC_IER     (*((volatile unsigned long *) 0x50040004))
#define ADC_CR      (*((volatile unsigned long *) 0x50040008))
#define ADC_CFGR    (*((volatile unsigned long *) 0x5004000C))
#define ADC_CFGR2   (*((volatile unsigned long *) 0x50040010))
#define ADC_SMPR1   (*((volatile unsigned long *) 0x50040014))
#define ADC_TR3     (*((volatile unsigned long *) 0x50040028))
#define ADC_SQR1    (*((volatile unsigned long *) 0x50040030))
#define ADC_SQR2    (*((volatile unsigned long *) 0x50040034))
#define ADC_SQR3    (*((volatile unsigned long *) 0x50040038))
#define ADC_SQR4    (*((volatile unsigned long *) 0x5004003C))
#define ADC_DR      (*((volatile unsigned long *) 0x50040040))
#define ADC_JSQR    (*((volatile unsigned long *) 0x5004004C))
#define ADC_OFR1    (*((volatile unsigned long *) 0x50040060))
#define ADC_OFR2    (*((volatile unsigned long *) 0x50040064))
#define ADC_OFR3    (*((volatile unsigned long *) 0x50040068))
#define ADC_OFR4    (*((volatile unsigned long *) 0x5004006C))
#define ADC_JDR1    (*((volatile unsigned long *) 0x50040080))
#define ADC_JDR2    (*((volatile unsigned long *) 0x50040084))
#define ADC_JDR3    (*((volatile unsigned long *) 0x50040088))
#define ADC_JDR4    (*((volatile unsigned long *) 0x5004008C))
#define ADC_AWD2CR  (*((volatile unsigned long *) 0x500400A0))
#define ADC_AWD3CR  (*((volatile unsigned long *) 0x500400A4))
#define ADC_DIFSEL  (*((volatile unsigned long *) 0x500400B0))
#define ADC_CALFACT (*((volatile unsigned long *) 0x500400A0))

#define ADC_CSR     (*((volatile unsigned long *) 0x50040300))
#define ADC_CCR     (*((volatile unsigned long *) 0x50040308))


#define USART_CR1     (*((volatile unsigned long *) 0x40013800))
#define USART_CR2     (*((volatile unsigned long *) 0x40013804))
#define USART_CR3     (*((volatile unsigned long *) 0x40013808))
#define USART_BRR     (*((volatile unsigned long *) 0x4001380C))
#define USART_GTPR    (*((volatile unsigned long *) 0x40013810))
#define USART_RTOR    (*((volatile unsigned long *) 0x40013814))
#define USART_RQR     (*((volatile unsigned long *) 0x40013818))
/*Has two modes*/
#define USART_ISR     (*((volatile unsigned long *) 0x4001381C))
#define USART_ICR     (*((volatile unsigned long *) 0x40013820))
#define USART_RDR     (*((volatile unsigned long *) 0x40013820))
#define USART_TDR     (*((volatile unsigned long *) 0x40013820))
#define USART_PRESC   (*((volatile unsigned long *) 0x40013824))

















#endif /* STM_REGISTER_H_ */
