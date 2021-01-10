/*
 * stm_clk.c
 *
 *  Created on: Mar 6, 2020
 *      Author: Ismae
 */
#include <stdint.h>
#include "stm_register.h"

#include "stm_clk.h"




#define MSI_RANGE_0 0x0
#define MSI_RANGE_1 0x1
#define MSI_RANGE_2 0x2
#define MSI_RANGE_3 0x3
#define MSI_RANGE_4 0x4
#define MSI_RANGE_5 0x5
#define MSI_RANGE_6 0x6
#define MSI_RANGE_7 0x7
#define MSI_RANGE_8 0x8
#define MSI_RANGE_9 0x9
#define MSI_RANGE_10 0xA
#define MSI_RANGE_11 0xB
 


void init_msi(struct RCC *msiPtr){
	/*Set MSI Clock

	0000: range 0  around 100 kHz
	0001: range 1  around 200 kHz
	0010: range 2  around 400 kHz
	0011: range 3  around 800 kHz
	0100: range 4  around 1M Hz
	0101: range 5  around 2 MHz
	0110: range 6  around 4 MHz (reset value)
	0111: range 7  around 8 MHz
	1000: range 8  around 16 MHz
	1001: range 9  around 24 MHz
	1010: range 10 around 32 MHz
	1011: range 11 around 48 MHz
	*/
	msiPtr->MSIRANGE = MSI_RANGE_10;
	msiPtr->MSITRIM = 0x00;
}


void config_msi_clock(struct RCC *stmclkPtr){
  
	/*wait for msi to be ready */
	while((RCC_CR&0x00000002) != 0){};
	
	 
	 
	  
	/*Set MSI Clock

	0000: range 0  around 100 kHz
	0001: range 1  around 200 kHz
	0010: range 2  around 400 kHz
	0011: range 3  around 800 kHz
	0100: range 4  around 1M Hz
	0101: range 5  around 2 MHz
	0110: range 6  around 4 MHz (reset value)
	0111: range 7  around 8 MHz
	1000: range 8  around 16 MHz
	1001: range 9  around 24 MHz
	1010: range 10 around 32 MHz
	1011: range 11 around 48 MHz
	*/


	stmclkPtr->MSITRIM = MSI_CALIB;

	 
 
	RCC_ICSCR = (RCC_ICSCR&~0x0000FF00) | (stmclkPtr->MSITRIM << 8);
    
	stmclkPtr->MSION    = 1;
	stmclkPtr->MSIPLLEN = 1;
	
	/*Enable MSI*/
	RCC_CR = (RCC_CR&~0x00000005)| stmclkPtr->MSION<<0 | stmclkPtr->MSIPLLEN<<2;

	/* wait for msi to stabilize */
	while((RCC_CR & 0x02) != 0x02){
		
		RCC_CR = (RCC_CR&~0x000000F0)|stmclkPtr->MSIRANGE <<4;	
		
	}



}

void get_msi_clock(struct RCC *stmclkPtr){
	int msi_clk[12] = [100000,200000,400000,800000,1000000,2000000,4000000,8000000,16000000,24000000,32000000,48000000]
	
	return msi_clk[stmclkPtr->MSIRANGE];
}

void config_hsi_clock(struct RCC *stmclkPtr){
	/*
	 * The HSI16 clock signal is generated from an internal 16 MHz oscillator
	 * */
 
	stmclkPtr->HSITRIM = HSI_CALIB;
	  
	/*Enable HSI */
	stmclkPtr->HSION    = 1;
	stmclkPtr->HSIKERON = 1;
	stmclkPtr->HSIASFS  = 1;

	RCC_CR = (RCC_CR&~0x00000B00)| stmclkPtr->HSIASFS<<11 | stmclkPtr->HSIKERON<<9 | stmclkPtr->HSION<<8;

	/* wait for hsi to stabilize */
	while((RCC_CR & 0x001400) !=0x001400){
		RCC_ICSCR = (RCC_ICSCR&~0x00FF0000) | (stmclkPtr->HSITRIM << 24);
	}


}

void get_hsi_clock(struct RCC *stmclkPtr){
	int msi_clk[12] = [100000,200000,400000,800000,1000000,2000000,4000000,8000000,16000000,24000000,32000000,48000000]
	
	return msi_clk[stmclkPtr->MSIRANGE];
}


void config_hse_clock(struct RCC *stmclkPtr){

	/* Disable HSE */
	stmclkPtr->HSEON = 0;
	RCC_CR = (RCC_CR&~0x00001000)| stmclkPtr->HSEON <<16;

	/* Wait for HSE flag to clear */
	while((RCC_CR&0x00002000) != 0){};

	/* Bypass HSE Oscillator? */

	//RCC_CR = (RCC_CR&~0x00004000)| 0 <<18;

	/* SYSCLK and PLL M divider input clocks are divided by 2 (HSE/2) ? */
	RCC_CR = (RCC_CR&~0x00010000)| 0 <<20;

	/* Do more configurations ? */

	/*Re-enable HSE */
	stmclkPtr->HSEON = 1;
	RCC_CR = (RCC_CR&~0x00001000)| stmclkPtr->HSEON <<16;


	/* Wait for HSE flag to stabalize */
	while((RCC_CR&0x00002000) != 0x2000){};
}
/**

	 f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
	 f(PLL_P) = f(VCO clock) / PLLP
	 f(PLL_Q) = f(VCO clock) / PLLQ
	 f(PLL_R) = f(VCO clock) / PLLR

**/

void config_pll_clock(struct RCC *stmclkPtr){
	
 	int vco_clk  = 0;
	int pllp_clk = 0;
	int pllq_clk = 0;
	int pllr_clk = 0;
	
	vco_clk = get_pll_in() * stmclkPtr->PLLN/stmclkPtr->PLLM;
	
	pllp_clk = vco_clk/stmclkPtr->PLLP;
	pllq_clk = vco_clk/stmclkPtr->PLLQ;
	pllr_clk = vco_clk/stmclkPtr->PLLR;
	
	/* Disable HSE */
	stmclkPtr->PLLON = 0;
	stmclkPtr->PLLSAI1ON = 0;
	RCC_CR = (RCC_CR&~0x05000000)|  stmclkPtr->PLLSAI1ON <<26 | stmclkPtr->PLLON <<24;

	/* Wait for HSE flag to clear */
 
	while((RCC_CR&0x0A000000) != 0){};
	
  
	RCC_PLLCFGR = (RCC_PLLCFGR&~0x00000003) | stmclkPtr->PLLSRC<<0;
	RCC_PLLCFGR = (RCC_PLLCFGR&~0x00000070) | stmclkPtr->PLLM<<4;
	RCC_PLLCFGR = (RCC_PLLCFGR&~0x00003F00) | stmclkPtr->PLLN<<8;
	RCC_PLLCFGR = (RCC_PLLCFGR&~0x00010000) | stmclkPtr->PLLPEN<<16;
	RCC_PLLCFGR = (RCC_PLLCFGR&~0x003E0000) | stmclkPtr->PLLP<<17;
	RCC_PLLCFGR = (RCC_PLLCFGR&~0x01000000) | stmclkPtr->PLLQEN<<24;
	RCC_PLLCFGR = (RCC_PLLCFGR&~0x0E000000) | stmclkPtr->PLLQ<<25;
	RCC_PLLCFGR = (RCC_PLLCFGR&~0x10000000) | stmclkPtr->PLLREN<<28;
	


	if(pllp_clk < 64000000){
		RCC_PLLCFGR = (RCC_PLLCFGR&~0x003E0000) | stmclkPtr->PLLP<<17;
	}else{
		//throw an error exception
	}	
	 
	if(pllq_clk < 64000000){
		RCC_PLLCFGR = (RCC_PLLCFGR&~0x0E000000) | stmclkPtr->PLLQ<<25;
	}else{
		//throw an error exception
	}
	
	if(pllr_clk < 64000000){
		RCC_PLLCFGR = (RCC_PLLCFGR&~0xE0000000) | stmclkPtr->PLLR<<29;
	}else{
		//throw an error exception
	}
 
	/*Re-enable HSE */
	stmclkPtr->PLLON = 1;
	stmclkPtr->PLLSAI1ON = 1;
	RCC_CR = (RCC_CR&~0x05000000)|  stmclkPtr->PLLSAI1ON <<26 | stmclkPtr->PLLON <<24;


	/* Wait for HSE flag to stabalize */
	while((RCC_CR&0x0A000000) != 0x0A000000){};

}

uint32_t get_pll_in(void){
	int pll_clk;
	if(stmclkPtr->PLLSRC == 3)
		pll_clk = 0;
	}else if(stmclkPtr->PLLSRC == 1){
		pll_clk = get_msi_clock();
	}else if(stmclkPtr->PLLSRC == 2){
		pll_clk = 16000000;
	}else {
		pll_clk = 32000000;	
	}
	
	return pll_clk;
}


void configure_system_clock(struct RCC *stmclkPtr){
	int  sys_clk;

	/* Select sys clock switch
	  00: MSI CLK Selected
	  01: HSI16 CLK Selected
	  10: HSE CLK Selected
	  11: PLL CLK Selected
	*/
	stmclkPtr->SW =0x00;
	RCC_CFGR = (RCC_CFGR & ~0x00000003) | ((stmclkPtr->SW)&0x03) ;

	//printf("sys_clk: 0x%x\n\r", sys_clk);

	/* sys_clk division */

	/*
	HPRE [3:0] HCLK 1 prescaler

	0001: SYSCLK divided by 3
	0010: SYSCLK divided by 5
	0101: SYSCLK divided by 6
	0110: SYSCLK divided by 10
	0111: SYSCLK divided by 32
	1000: SYSCLK divided by 2
	1001: SYSCLK divided by 4
	1010: SYSCLK divided by 8
	1011: SYSCLK divided by 16
	1100: SYSCLK divided by 64
	1101: SYSCLK divided by 128
	1110: SYSCLK divided by 256
	1111: SYSCLK divided by 512
	*/

	stmclkPtr->HPRE = 0x0001;
	RCC_CFGR = (RCC_CFGR & ~0x000000F0) | (stmclkPtr->HPRE)<<4;

    /* check if prescaler is set */

	/*printf("HPREF 0x%x \n\r",  RCC_CFGR & 0x00010000);
	printf("PPRE1F 0x%x \n\r", RCC_CFGR & 0x00020000);
	printf("PPRE2F 0x%x \n\r", RCC_CFGR & 0x00040000);*/


	/* Configure Microcontroller Output */

	/* Set Microcontroller Output
	  0000: MCO output disabled, no clock on MCO
	  0001: SYSCLK system clock selected
	  0010: MSI clock selected.0011: HSI16 clock selected.
      0100: HSE clock selected (after stabilization)
      0101: Main PLLRCLK clock selected
      0110: LSI1 clock selected
      0111: LSI2 clock selected
      1000: LSE clock selected
      1001: Internal HSI48 clock selected
      1100: HSE clock selected (before stabilization)
	*/
	stmclkPtr->MCOSEL = 0x0001;
 	RCC_CFGR = (RCC_CFGR & ~0x0F000000) | (stmclkPtr->MCOSEL)<<24;

	/*
	MCOPRE[2:0] Microcontroller clock output prescaler.
	  000: MCO is divided by 1
	  001: MCO is divided by 2
	  010: MCO is divided by 4
	  011: MCO is divided by 8
	  100: MCO is divided by 16
	*/
 	stmclkPtr->MCOPRE = 0;
	RCC_CFGR = (RCC_CFGR & ~0x70000000) | (stmclkPtr->MCOPRE) <<28;

}
