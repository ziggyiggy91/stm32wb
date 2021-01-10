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
#define RCC_CIFR          (*((volatile unsigned long *) 0x5800001C))
#define RCC_CICR          (*((volatile unsigned long *) 0x58000020))
#define RCC_SMPSCR        (*((volatile unsigned long *) 0x58000024))
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
#define RCC_CCIPR         (*((volatile unsigned long *) 0x58000088))
#define RCC_BDCR          (*((volatile unsigned long *) 0x58000090))
#define RCC_CSR           (*((volatile unsigned long *) 0x58000094))
#define RCC_CRRCR         (*((volatile unsigned long *) 0x58000098))
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

/*GPIO Registers*/
#define GPIOA_MODER       (*((volatile unsigned long *) 0x48000000))
#define GPIOB_MODER       (*((volatile unsigned long *) 0x48000400))
#define GPIOC_MODER       (*((volatile unsigned long *) 0x48000800))
#define GPIOD_MODER       (*((volatile unsigned long *) 0x48000C00))

#define GPIOA_OTYPER      (*((volatile unsigned long *) 0x48000004))
#define GPIOB_OTYPER      (*((volatile unsigned long *) 0x48000404))
#define GPIOC_OTYPER      (*((volatile unsigned long *) 0x48000804))
#define GPIOD_OTYPER      (*((volatile unsigned long *) 0x48000C04))

#define GPIOA_OSPEEDR     (*((volatile unsigned long *) 0x48000008))
#define GPIOB_OSPEEDR     (*((volatile unsigned long *) 0x48000408))
#define GPIOC_OSPEEDR     (*((volatile unsigned long *) 0x48000808))
#define GPIOD_OSPEEDR     (*((volatile unsigned long *) 0x48000C08))

#define GPIOA_PUPDR       (*((volatile unsigned long *) 0x4800000C))
#define GPIOB_PUPDR       (*((volatile unsigned long *) 0x4800040C))
#define GPIOC_PUPDR       (*((volatile unsigned long *) 0x4800080C))
#define GPIOD_PUPDR       (*((volatile unsigned long *) 0x48000C0C))

#define GPIOA_IDR         (*((volatile unsigned long *) 0x48000010))
#define GPIOB_IDR         (*((volatile unsigned long *) 0x48000410))
#define GPIOC_IDR         (*((volatile unsigned long *) 0x48000810))
#define GPIOD_IDR         (*((volatile unsigned long *) 0x48000C10))

#define GPIOA_ODR         (*((volatile unsigned long *) 0x48000014))
#define GPIOB_ODR         (*((volatile unsigned long *) 0x48000414))
#define GPIOC_ODR         (*((volatile unsigned long *) 0x48000814))
#define GPIOD_ODR         (*((volatile unsigned long *) 0x48000C14))

#define GPIOA_BSRR        (*((volatile unsigned long *) 0x48000018))
#define GPIOB_BSRR        (*((volatile unsigned long *) 0x48000418))
#define GPIOC_BSRR        (*((volatile unsigned long *) 0x48000818))
#define GPIOD_BSRR        (*((volatile unsigned long *) 0x48000C18))

#define GPIOA_LCKR        (*((volatile unsigned long *) 0x4800001C))
#define GPIOB_LCKR        (*((volatile unsigned long *) 0x4800041C))
#define GPIOC_LCKR        (*((volatile unsigned long *) 0x4800081C))
#define GPIOD_LCKR        (*((volatile unsigned long *) 0x48000C1C))

#define GPIOA_AFRL        (*((volatile unsigned long *) 0x48000020))
#define GPIOB_AFRL        (*((volatile unsigned long *) 0x48000420))
#define GPIOC_AFRL        (*((volatile unsigned long *) 0x48000820))
#define GPIOD_AFRL        (*((volatile unsigned long *) 0x48000C20))

#define GPIOA_AFRH        (*((volatile unsigned long *) 0x48000024))
#define GPIOB_AFRH        (*((volatile unsigned long *) 0x48000424))
#define GPIOC_AFRH        (*((volatile unsigned long *) 0x48000824))
#define GPIOD_AFRH        (*((volatile unsigned long *) 0x48000C24))

#define GPIOA_BRR         (*((volatile unsigned long *) 0x48000028))
#define GPIOB_BRR         (*((volatile unsigned long *) 0x48000428))
#define GPIOC_BRR         (*((volatile unsigned long *) 0x48000828))
#define GPIOD_BRR         (*((volatile unsigned long *) 0x48000C28))




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






/*SYSCFG Registers*/
#define SYSCFG_MEMRMP  (*((volatile unsigned long *) 0x40010000))
#define SYSCFG_CFGR1   (*((volatile unsigned long *) 0x40010004))
#define SYSCFG_EXTICR1 (*((volatile unsigned long *) 0x40010008))
#define SYSCFG_EXTICR2 (*((volatile unsigned long *) 0x4001000C))
#define SYSCFG_EXTICR3 (*((volatile unsigned long *) 0x40010010))
#define SYSCFG_EXTICR4 (*((volatile unsigned long *) 0x40010014))
#define SYSCFG_SCSR    (*((volatile unsigned long *) 0x40010018))
#define SYSCFG_CFGR2   (*((volatile unsigned long *) 0x4001001C))
#define SYSCFG_SWPR    (*((volatile unsigned long *) 0x40010020))
#define SYSCFG_SKR     (*((volatile unsigned long *) 0x40010024))
#define SYSCFG_SWPR2   (*((volatile unsigned long *) 0x40010028))
#define VREFBUF_CSR    (*((volatile unsigned long *) 0x40010030))
#define VREFBUF_CCR    (*((volatile unsigned long *) 0x40010034))
#define SYSCFG_IMR1    (*((volatile unsigned long *) 0x40010100))
#define SYSCFG_IMR2    (*((volatile unsigned long *) 0x40010104))
#define SYSCFG_C2IMR1  (*((volatile unsigned long *) 0x40010108))
#define SYSCFG_C2IMR2  (*((volatile unsigned long *) 0x4001010c))
#define SYSCFG_SIPCR   (*((volatile unsigned long *) 0x40010110))



/*EXTI Registers*/
#define RTSR1          (*((volatile unsigned long *) 0x58000800))
#define FTSR1          (*((volatile unsigned long *) 0x58000804))
#define SWIER1         (*((volatile unsigned long *) 0x58000808))
#define PR1            (*((volatile unsigned long *) 0x5800080C))
#define RTSR2          (*((volatile unsigned long *) 0x58000820))
#define FTSR2          (*((volatile unsigned long *) 0x58000824))
#define SWIER2         (*((volatile unsigned long *) 0x58000828))
#define PR2            (*((volatile unsigned long *) 0x5800082C))
#define C1IMR1         (*((volatile unsigned long *) 0x58000880))
#define C2IMR1         (*((volatile unsigned long *) 0x580008C0))
#define C1EMR1         (*((volatile unsigned long *) 0x58000884))
#define C2EMR1         (*((volatile unsigned long *) 0x580008C4))
#define C1IMR2         (*((volatile unsigned long *) 0x58000890))
#define C2IMR2         (*((volatile unsigned long *) 0x580008D0))
#define C1EMR2         (*((volatile unsigned long *) 0x58000894))
#define C2EMR2         (*((volatile unsigned long *) 0x580008D4))
#define HWCFGR5        (*((volatile unsigned long *) 0x58000BE0))
#define HWCFGR6        (*((volatile unsigned long *) 0x58000BDC))
#define HWCFGR7        (*((volatile unsigned long *) 0x58000BD8))
#define HWCFGR2        (*((volatile unsigned long *) 0x58000BEC))
#define HWCFGR3        (*((volatile unsigned long *) 0x58000BE8))
#define HWCFGR4        (*((volatile unsigned long *) 0x58000BE4))
#define HWCFGR1        (*((volatile unsigned long *) 0x58000BF0))
#define VERR           (*((volatile unsigned long *) 0x58000BF4))
#define IPIDR          (*((volatile unsigned long *) 0x58000BF8))
#define SIDR           (*((volatile unsigned long *) 0x58000BFC))


 
/* Interrupt Registers*/
#define ISER0         (*((volatile unsigned long *) 0xE000E100))
#define ISER1         (*((volatile unsigned long *) 0xE000E104))
#define ICER0         (*((volatile unsigned long *) 0xE000E180))
#define ICER1         (*((volatile unsigned long *) 0xE000E184))
#define ISPR0         (*((volatile unsigned long *) 0xE000E200))
#define ISPR1         (*((volatile unsigned long *) 0xE000E204))
#define ICPR0         (*((volatile unsigned long *) 0xE000E280))
#define ICPR1         (*((volatile unsigned long *) 0xE000E284))
#define IABR0         (*((volatile unsigned long *) 0xE000E300))
#define IABR1         (*((volatile unsigned long *) 0xE000E304))
#define IPR0          (*((volatile unsigned long *) 0xE000E400))
#define IPR1          (*((volatile unsigned long *) 0xE000E404))
#define IPR2          (*((volatile unsigned long *) 0xE000E408))
#define IPR3          (*((volatile unsigned long *) 0xE000E40C))
#define IPR4          (*((volatile unsigned long *) 0xE000E410))
#define IPR5          (*((volatile unsigned long *) 0xE000E414))
#define IPR6          (*((volatile unsigned long *) 0xE000E418))
#define IPR7          (*((volatile unsigned long *) 0xE000E41C))
#define IPR8          (*((volatile unsigned long *) 0xE000E420))
#define IPR9          (*((volatile unsigned long *) 0xE000E424))
#define IPR10         (*((volatile unsigned long *) 0xE000E428))
#define IPR11         (*((volatile unsigned long *) 0xE000E42C))
#define IPR12         (*((volatile unsigned long *) 0xE000E430))
#define IPR13         (*((volatile unsigned long *) 0xE000E434))
#define IPR14         (*((volatile unsigned long *) 0xE000E438))
#define IPR15         (*((volatile unsigned long *) 0xE000E43C))
#define IPR16         (*((volatile unsigned long *) 0xE000E440))
#define IPR17         (*((volatile unsigned long *) 0xE000E444))














#endif /* STM_REGISTER_H_ */
