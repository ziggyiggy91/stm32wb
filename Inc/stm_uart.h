/*
 * stm_uart.h
 *
 *  Created on: Mar 7, 2020
 *      Author: Ismae
 */

#ifndef STM_UART_H_
#define STM_UART_H_


struct USART{
   /*RCC_CCIPR Register*/
	int USART1SEL;
   /*USART_CR1 Register*/
   int UE;
   int UESM;
   int RE;
   int TE;
   int IDLEIE;
   int RXFNEIE;
   int TCIE;
   int TXFNFIE;
   int PEIE;
   int PS;
   int PCE;
   int WAKE;
   int M0;
   int MME;
   int CMIE;
   int OVER8;
   int DEDT;
   int DEAT;
   int RTOIE;
   int EOBIE;
   int M1;
   int FIFOEN;
   int TXFEIE;/*TXFIFO Full interrupt enable: only available when FIFOEN = 1*/
   int RXFFIE;/*RXFIFO Full interrupt enable: only available when FIFOEN = 1*/
   /*USART_BRR Register*/
   int BAUDRATE;
   int BRR;
   /**/
   int PRESCALER;
   /*USART_CR2 Registers*/
   int SLVEN;
   int DIS_NSS;
   int ADDM7;
   int LBDL;
   int LBDIE;
   int LBCL;
   int CPHA;
   int CPOL;
   int CLKEN;
   int STOP;
   int LINEN;
   int SWAP;
   int RXINV;
   int TXINV;
   int DATAINV;
   int MSBFIRST;
   int ABREN;
   int ABRMOD;
   int RTOEN;
   int ADD;
   /*USART_CR3 Register*/
   int EIE;
   int IREN;
   int IRLP;
   int HDSEL;
   int NACK;
   int SCEN;
   int DMAR;
   int DMAT;
   int RTSE;
   int CTSE;
   int CTSIE;
   int ONEBIT;
   int OVRDIS;
   int DDRE;
   int DEM;
   int DEP;
   int SCARCNT;
   int WUS;
   int WUFIE;
   int TXFTIE;
   int TCBGTIE;
   int RXFTCFG;
   int RXFTIE;
   int TXFTCFG;


};


void init_usart(struct USART *);

void uart_config_clock(struct USART *);
int usart_rx();
void usart_tx(int);
void send_buffer(char *);
void receive_buffer(char *);

#endif /* STM_UART_H_ */
