/*
64 MHz max clock. 

*/



typedef struct{
  int div;
  


}sysclk;


void config_clocks(){
 
 
 /* PLL Configuration 
 1) Disable clocks
 2) Wait for pllxxrdy to clear.
 3) Change parameters.
 4) Enable pll. 
 5) 
 
 
 */
 /* Disable Clock */
  RCC_CR = 0x00000000;
  /* Wait for pllxxrdy to clear */
  while((RCC_CR&0x800000) != 0){};
  
  
  /*
  PLL Source: RCC_PLLCFGR[1:0]
   0: no clock sent to PLL.
   1: MSI clock selected as PLL.
   2: HSI16 clock selected as PLL.
   3: HSE clock selected as PLL.
  
  vco = pll * pllN/pllM
  */
  
  
  /*
  MSI Range: 32 MHz 
  */
  RCC_CR = 0x000000A0;

  
  RCC_CFGR = 0x22000003;
  /*
   Microcontroller Output : MSI Clock
  */
  RCC_PLLCFGR = 0x12000831;
  /* Select clock for */
  switch(){
   case "LSI1_CLK":
   case "LSI2_CLK":
   case "LSE_CLK":
   case "HSE_CLK":
   case "SYS_CLK":
   case "PLL_CLK":
   case "HSI16_CLK":
   case "MSI_CLK":
   case "HSI48_CLK":
   
   break;  
  }	
  
  RCC_CCIPR
}


void config_msi_clock(){
	int msi_trim;
	/*Disable MSI */
	RCC_CR = (RCC_CR&~0x00000005)| 0;

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
	
	RCC_CR = (RCC_CR&~0x000000F0)|0x000000A0;
	
	printf("MSI calibration value 0x%x\n\r",RCC_ICSCR & 0x000000FF);
	
	msi_trim = 0x00;
	
	RCC_ICSCR = (RCC_ICSCR&~0x0000FF00) | (msi_trim << 8);
	
	printf("MSI calibration value 0x%x\n\r",RCC_ICSCR & 0x000000FF);
	
	/* MSI Interrupt */
	printf("MSI interrupt ready? 0x%x\n\r",RCC_CIFR & 0x00000004);

	/*Disable MSI */
	RCC_CR = (RCC_CR&~0x00000005)| 0x05;
	
	/* wait for msi to stabilize */ 
	while((RCC_CR & 0x02) != 1){};
	
	
	
}

void config_hsi_clock(){
int hsi_trim;
	/*Disable MSI */
	RCC_CR = (RCC_CR&~0x00000B00)| 0;
 
	printf("HSI calibration value 0x%x\n\r",RCC_ICSCR & 0x00FF0000);
	
	hsi_trim = 0x00;
	
	RCC_ICSCR = (RCC_ICSCR&~0x00FF0000) | (hsi_trim << 24);
	
	printf("HSI calibration value 0x%x\n\r",RCC_ICSCR & 0x00FF0000);
	
	/* HSI Interrupt */
	printf("HSI interrupt ready? 0x%x\n\r",RCC_CIFR & 0x00000008);

	/*Enable HSI */
    RCC_CR = (RCC_CR&~0x00000B00)| 0xB00;	
	
	/* wait for hsi to stabilize */ 
	while((RCC_CR & 0x000400) != 1){};
		
	
	
	
}

void config_hse_clock(){
	
	/* Disable HSE */
	RCC_CR = (RCC_CR&~0x00001000)| 0 <<16; 
	
	/* Wait for HSE flag to clear */
	
	while((RCC_CR&0x00002000) != 0){};
	
	/* Bypass HSE Oscillator? */ 
	RCC_CR = (RCC_CR&~0x00004000)| 0 <<18;
	
	/* SYSCLK and PLL M divider input clocks are divided by 2 (HSE/2) ? */
	RCC_CR = (RCC_CR&~0x00010000)| 0 <<20;
	
	/* Do more configurations ? */
	
	/*Re-enable HSE */
	RCC_CR = (RCC_CR&~0x00001000)| 1 <<16; 
	
		
	/* Wait for HSE flag to stabalize */
	while((RCC_CR&0x00002000) != 1){};
}

 
void config_pll_clock(){
	/* Disable HSE */
	RCC_CR = (RCC_CR&~0x05000000)| 0 <<24; 
	
	/* Wait for HSE flag to clear */
	
	while((RCC_CR&0x0A000000) != 0){};
	  
	/* Do more configurations ? */
	
	RCC_PLLCFGR = (
	
	
	
	
	
	
	
	/*Re-enable HSE */
	RCC_CR = (RCC_CR&~0x05000000)| 0x05 <<24; 
	
		
	/* Wait for HSE flag to stabalize */
	while((RCC_CR&0x0A000000) != 0x0A000000){};	
	
}


void configure_system_clock(){
	int  sys_clk;
	int  hpre;
	int  mco_prescaler;
	
	/* Select sys clock switch 
	  00: MSI CLK Selected
	  01: HSI16 CLK Selected
	  10: HSE CLK Selected
	  11: PLL CLK Selected
	*/
	
	sys_clk = 0;
	hpre    = 0;
	mso     = 0;
	
	RCC_CFGR = (RCC_CFGR & 0x00000003) | (sys_clk&0x03) ;
	
	sys_clk = (RCC_CFGR & 0x00000030);
	
	printf("sys_clk: 0x%x\n\r", sys_clk);
	
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
	RCC_CFGR = (RCC_CFGR & ~0x000000F0) | hpre;
	
    /* check if prescaler is set */
	printf("HPREF 0x%x \n\r",  RCC_CFGR & 0x00010000);
	printf("PPRE1F 0x%x \n\r", RCC_CFGR & 0x00020000);
	printf("PPRE2F 0x%x \n\r", RCC_CFGR & 0x0000000);
	
	
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
	
	mco = 0x01;// SYSCLK selected.
	RCC_CFGR = (RCC_CFGR & ~0x0F000000) | mco <<24;
	
	/*
	MCOPRE[2:0] Microcontroller clock output prescaler.
	  000: MCO is divided by 1
	  001: MCO is divided by 2
	  010: MCO is divided by 4
	  011: MCO is divided by 8
	  100: MCO is divided by 16
	*/
	mco_prescaler = 0;
	RCC_CFGR = (RCC_CFGR & ~0x70000000) | mco_prescaler <<28;
	
}




/* struct for RCC_CCIPR register 
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

typedef struct {
	int RNGSEL;
	int ADCSEL;
	int CLK48SEL;
	int SAI1SEL;
	int LPTIM2SEL;
	int LPTIM1SEL;
	int I2C3SEL;
	int I2C1SEL;
	int LPUART1SEL;
	int USART1SEL;
}ccipr;

 


