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
   int MSION;
   int MSIRDY;
   int MSIPLLEN;
   int MSIRANGE;
   int HSION;
   int HSIKERON;
   int HSIRDY;
   int HSIASFS;
   int HSIKERDY;
   int HSEON;
   int HSERDY;
   int CSSON;
   int HSEPRE;
   int PLLON;
   int PLLSAI1ON;
   int PLLSAI1RDY;
   /*RCC_ICSCR Register*/
   int MSICAL;
   int MSITRIM;
   int HSICAL;
   int HSITRIM;
   /*RCC_CFGR Register*/
   int SW;
   int SWS;
   int HPRE;
   int PPRE1;
   int PPRE2;
   int STOPWUCK;
   int HPREF;
   int PPRE1F;
   int PPRE2F;
   int MCOSEL;
   int MCOPRE;
 };








void init_msi(struct RCC *);

void config_msi_clock(struct RCC *);
void config_hsi_clock(struct RCC *);
void config_hse_clock(struct RCC *);
void config_pll_clock(struct RCC *);
void configure_system_clock(struct RCC *);



#endif /* STM_CLK_H_ */
