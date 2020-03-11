/*
 * stm_uart.c
 *
 *  Created on: Mar 6, 2020
 *      Author: Ismae
 */
#include "stm_register.h"
#include "stm_uart.h"
#include <stdint.h>


void init_usart(struct USART *usartPtr){

	/*USART_CR1 Register*/

	/*
	 * M1,M0
	 * M[1:0] = ‘00’: 1 start bit, 8 Data bits, n Stop bit
	 * M[1:0] = ‘01’: 1 start bit, 9 Data bits, n Stop bit
	 * M[1:0] = ‘10’: 1 start bit, 7 Data bits, n Stop bit
	 *
	 * */
	usartPtr->M0 = 0;
	usartPtr->M1 = 0;

	/*USART_CR2 Register*/
	usartPtr-> SLVEN    = 0;
	usartPtr-> DIS_NSS 	= 0;
	usartPtr-> ADDM7	= 1;
	usartPtr-> LBDL		= 0;
	usartPtr-> LBDIE	= 0;
	usartPtr-> LBCL		= 0;
	usartPtr-> CPHA		= 0;
	usartPtr-> CPOL		= 0;
	usartPtr-> CLKEN	= 0;
	usartPtr-> STOP		= 0;
	usartPtr-> LINEN	= 0;
	usartPtr-> SWAP		= 0;
    usartPtr-> RXINV	= 0;
    usartPtr-> TXINV	= 0;
	usartPtr-> DATAINV	= 0;
	usartPtr-> MSBFIRST	= 0;
	/*RTOEN: Auto baud rate enable*/
	usartPtr-> ABREN	= 0;
	/*ABRMOD[1:0]: Auto baud rate detection*/
	usartPtr-> ABRMOD	= 0;

	usartPtr-> RTOEN	= 0;
	/*ADD[7:0]: Address used to wake up MCU when sleep mode.*/
	usartPtr-> ADD		= 0;

	/*USART_CR3 Register*/
	usartPtr-> EIE		= 0;
	usartPtr-> IREN		= 0;
	usartPtr-> IRLP		= 0;
	usartPtr-> HDSEL	= 0;
	usartPtr-> NACK		= 0;
	usartPtr-> SCEN		= 0;
	usartPtr-> DMAR		= 0;
	usartPtr-> DMAT		= 0;
	usartPtr-> RTSE		= 0;
	usartPtr-> CTSE		= 0;
	usartPtr-> CTSIE	= 0;
	usartPtr-> ONEBIT	= 0;
	usartPtr-> OVRDIS	= 0;
	usartPtr-> DDRE		= 0;
	usartPtr-> DEM		= 0;
	usartPtr-> DEP		= 0;
	usartPtr-> SCARCNT	= 0;
	usartPtr-> WUS		= 0;
	usartPtr-> WUFIE    = 0;
	usartPtr-> TXFTIE   = 0;
	usartPtr-> TCBGTIE  = 0;
    usartPtr-> RXFTCFG  = 0x5;
    usartPtr-> RXFTIE   = 0;
	usartPtr-> TXFTCFG  = 0x5;



}



void uart_config_clock(struct USART *usartPtr){
	uint32_t clk;
	uint32_t  bbr_data_15to4;
    uint32_t bbr_data_3to0;

    clk = 8000000;

	/*Disable USART*/
	usartPtr->UE = 0;
	USART_CR1 = (USART_CR1 & ~0x00000001) | usartPtr->UE<<0;

	/*USART1SEL Clock select
	 * 00: PCLK selected as USART1 clock
	 * 01: System clock (SYSCLK) selected as USART1 clock
	 * 10: HSI16 clock selected as USART1 clock
	 * 11: LSE clock selected as USART1 clock
	 */

	usartPtr->USART1SEL = 0x1;
	RCC_CCIPR = (RCC_CCIPR & ~0x00000003) | (usartPtr->USART1SEL&0x3);

	/*
	 * PRESCALER[3:0] Clock Prescalar
		0000: input clock not divided
		0001: input clock divided by 2
		0010: input clock divided by 4
		0011: input clock divided by 6
		0100: input clock divided by 8
		0101: input clock divided by 10
		0110: input clock divided by 12
		0111: input clock divided by 16
		1000: input clock divided by 32
		1001: input clock divided by 64
		1010: input clock divided by 128
		1011: input clock divided by 256
	   */
	usartPtr->PRESCALER = 0x0000;
	USART_PRESC = (USART_PRESC & 0x000000FF) | usartPtr->PRESCALER;


	USART_CR1 = (USART_CR1& ~0x00000001) | usartPtr->UE<<0;

	/*USART Low Power Mode*/
	USART_CR1 = (USART_CR1& ~0x00000002) | 0<<1;

	/*Receiver Enable*/
	USART_CR1 = (USART_CR1& ~0x00000004) | 1<<2;

	/*Transmitter Enable*/
	USART_CR1 = (USART_CR1& ~0x00000008) | 1<<3;

	/* IDLE interrupt enable*/
	USART_CR1 = (USART_CR1& ~0x00000010) | 0<<4;

	/* RXFIFO no empty interrupt enable*/
	USART_CR1 = (USART_CR1& ~0x00000020) | 0<<5;

	/* Transmission complete interrupt enable*/
	USART_CR1 = (USART_CR1& ~0x00000040) | 0<<6;

	/* TXFIFO not full interrupt enable*/
	USART_CR1 = (USART_CR1& ~0x00000080) | 0<<7;

	/* PE interrupt enable*/
	USART_CR1 = (USART_CR1& ~0x00000100) | 0<<8;

	/* Parity selection*/
	USART_CR1 = (USART_CR1& ~0x00000200) | 0<<9;

	/* Parity control enable*/
	USART_CR1 = (USART_CR1& ~0x00000400) | 0<<10;

	/* wake*/
	USART_CR1 = (USART_CR1& ~0x00000800) | 0<<11;

	/*  word length M0 ?*/
	USART_CR1 = (USART_CR1& ~0x00001000) | usartPtr->M0<<12;

	/*  Mute mode enable */
	USART_CR1 = (USART_CR1& ~0x00002000) | 0<<13;

	/* character match interrupt enable*/
	USART_CR1 = (USART_CR1& ~0x00004000) | 0<<14;

	/*  Oversampling mode*/
	USART_CR1 = (USART_CR1& ~0x00008000) | 0<<15;

	/* DEDT[4:0] Driver Enable deassertion time */
	USART_CR1 = (USART_CR1& ~0x001F0000) | 0<<16;

	/*  DEAT[4:0] Driver Enable  assertion time*/
	USART_CR1 = (USART_CR1& ~0x01E00000) | 0<<21;

	/* Receiver timeout interrupt enable*/
	USART_CR1 = (USART_CR1& ~0x00200000) | 0<<26;

	/* End of block interrupt enable*/
	USART_CR1 = (USART_CR1& ~0x00200000) | 0<<27;

	/* Word Lengh M1*/
	USART_CR1 = (USART_CR1& ~0x00200000) | usartPtr->M1<<28;

	/* FIFO Mode enabled*/
	USART_CR1 = (USART_CR1& ~0x20000000) | 1<<29;

	/* TXFIFO empty interrupt enable*/
	USART_CR1 = (USART_CR1& ~0x00200000) | 0<<30;

	/* RXFIFO FULL interrupt enable*/
	USART_CR1 = (USART_CR1& ~0x00200000) | 0<<31;

	bbr_data_15to4 = ((clk / usartPtr->BAUDRATE)&0xFFF0);
    bbr_data_3to0 = ((clk / usartPtr->BAUDRATE)&0xF);

    USART_CR2 = (USART_CR2&~0xFFFFFF79) | ((usartPtr->ADD)<<24)	     | ((usartPtr->RTOEN)<<23)   | ((usartPtr->ABRMOD)<<21) | ((usartPtr->ABREN)<<20) |
    									  ((usartPtr->MSBFIRST)<<19) | ((usartPtr->DATAINV)<<18) | ((usartPtr->TXINV)<<17)  | ((usartPtr->RXINV)<<16) |
										  ((usartPtr->SWAP)<<15)     | ((usartPtr->LINEN)<<14)   | ((usartPtr->STOP)<<12)   | ((usartPtr->CLKEN)<<11) |
										  ((usartPtr->CPOL)<<10)     | ((usartPtr->CPHA)<<9)     | ((usartPtr->LBCL)<<8)    | ((usartPtr->LBDIE)<<6)  |
										  ((usartPtr->LBDL)<<5)      | ((usartPtr->ADDM7)<<4)    | ((usartPtr->DIS_NSS)<<3) | ((usartPtr->SLVEN)<<0);

    USART_CR3 = (USART_CR3&~0xFFFEFFFF) | ((usartPtr->TXFTCFG)<<29) | ((usartPtr->RXFTIE)<<24) | ((usartPtr->RXFTCFG)<<25) | ((usartPtr->TCBGTIE)<<24) |
										  ((usartPtr->TXFTIE)<<24)  | ((usartPtr->WUFIE)<<23)  | ((usartPtr->WUS)<<21)     | ((usartPtr->SCARCNT)<<20) |
										  ((usartPtr->DEP)<<19)     | ((usartPtr->DEM)<<18)    | ((usartPtr->DDRE)<<17)    | ((usartPtr->OVRDIS)<<12)  |
										  ((usartPtr->ONEBIT)<<11)  | ((usartPtr->CTSIE)<<10)  | ((usartPtr->CTSE)<<9)     | ((usartPtr->RTSE)<<8)     |
										  ((usartPtr->DMAT)<<7)     | ((usartPtr->DMAR)<<6)    | ((usartPtr->SCEN)<<5)     | ((usartPtr->NACK)<<4)     |
										  ((usartPtr->HDSEL)<<3)    | ((usartPtr->IRLP)<<2)    | ((usartPtr->IREN)<<1)     | ((usartPtr->EIE)<<0);

    if(usartPtr->OVER8 == 1){
    /*USARTDIV[15:4], USARTDIV[3:0] shifted one bit to the right,
     * USART_BRR[3] MUST BE KEPT CLEARED */

     bbr_data_3to0 = bbr_data_3to0>>1;
     usartPtr->BRR = clk / (usartPtr->BAUDRATE);
     usartPtr->BRR = (bbr_data_15to4 | bbr_data_3to0);

    }else{
   /*USARTDIV[15:0]*/
      usartPtr->BRR = (bbr_data_15to4 | bbr_data_3to0);
    }


	/*Enable USART*/
	usartPtr->UE = 1;
	USART_CR1 = (USART_CR1& ~0x00000001) | usartPtr->UE<<0;

}

int usart_rx(){
	int rx_buffer;

	/*check if buffer is full*/
	//while(){}
	while((USART_ISR & 1<<24) == 0 || (USART_ISR & 1<<26) == 0){
	 rx_buffer = USART_RDR;
	}

	return rx_buffer;
}

void usart_tx(int data){
	/*Send data when FIFO is empty*/

	if((USART_ISR & 1<<23) == 1 || (USART_ISR & 1<<27) == 0){
	 USART_TDR = data;
	}
	/*wait until transfer is completed*/
	while((USART_ISR&0x00000040) != 0x00000040);
}


void send_buffer(char *buff){
	int index;

	index = 0;

	while(*buff != '\0'){
		  usart_tx(*(buff+index));
		  index++;
	}
}


void receive_buffer(char *buff){
  int rData;
  int index;

  rData = 0;
  index = 0;
  while(rData != '\0'){
    rData = usart_rx();
    *(buff + index) = rData;
    index++;
  }

}
