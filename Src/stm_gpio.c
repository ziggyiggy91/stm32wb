#define "stm_gpio.h"





#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3


 

/**


**/

void gpio_initd(struct GPIO  *gpioPtr){
		/*Enable GPIO clock*/
	
		__uint32_t pin = 0;
		__uint32_t ord_ext_9_5 = 0;
		__uint32_t ord_ext_15_10 = 0;

	do {
	    GPIOC_MODER    = ((GPIOC_MODER) & ~( 0x3 << (2*pin))) | (gpioPtr[pin].GPIO_MODE & 0x3)<<(2*pin);
	    GPIOC_PUPDR    = ((GPIOC_PUPDR) & ~( 0x3 << (2*pin))) | (gpioPtr[pin].GPIO_PUPD & 0x3)<<(2*pin);
  
	    //Interrupt
	    if(pin >= 0 && pin < 4){
	    	SYSCFG_EXTICR1 = (SYSCFG_EXTICR1 &  ~( 0x7 << (3*(pin%4)))) |      (gpioPtr[pin].GPIO_EXTI_EN  <<2 )<< (3*(pin%4));
 	    }else if(pin >= 4 && pin < 7){
	    	SYSCFG_EXTICR2 = (SYSCFG_EXTICR2 &  ~( 0x7 << (3*(pin%4)))) |      (gpioPtr[pin].GPIO_EXTI_EN  <<2 )<< (3*(pin%4));
 	    }else if(pin >= 7 && pin < 10){
	    	SYSCFG_EXTICR3 = (SYSCFG_EXTICR3 &  ~( 0x7 << (3*(pin%4)))) |      (gpioPtr[pin].GPIO_EXTI_EN  <<2 )<< (3*(pin%4));
 	    }else{
	    	SYSCFG_EXTICR4 = (SYSCFG_EXTICR4 &  ~( 0x7 << (3*(pin%4)))) |      (gpioPtr[pin].GPIO_EXTI_EN  <<2 )<< (3*(pin%4));
 	    }

	    if(pin >= 0 && pin <= 4){
 	    	ISER0 = (ISER0 & ~(0x1) << (pin + EXTI0)) | gpioPtr[pin].GPIO_EXTI_EN  << (pin + EXTI0);
	    }else if(pin  == 5){
	    	ord_ext_9_5 =  gpioPtr[pin].GPIO_EXTI_EN 	 | gpioPtr[pin + 1].GPIO_EXTI_EN | gpioPtr[pin + 2].GPIO_EXTI_EN |
						   gpioPtr[pin + 3].GPIO_EXTI_EN | gpioPtr[pin + 4].GPIO_EXTI_EN;

	    	ISER0 = (ISER0 & ~(0x1) << (EXTI_9_5)) | ord_ext_9_5  << (pin + EXTI_9_5);
			
	    }else if(pin  == 10){
	    	ord_ext_15_10 =  gpioPtr[pin].GPIO_EXTI_EN 	   | gpioPtr[pin + 1].GPIO_EXTI_EN | gpioPtr[pin + 2].GPIO_EXTI_EN |
							 gpioPtr[pin + 3].GPIO_EXTI_EN | gpioPtr[pin + 4].GPIO_EXTI_EN;

	    	ISER0 = (ISER0 & ~(0x1) << (pin + EXTI_15_10)) | ord_ext_15_10  << (pin + EXTI_15_10);
	    }else{

	    }
	    pin++;
	}while(pin < 16 );
  
}


void set_gpio_mode(int mode,int pin,int value){
	
	switch(mode){
		case GPIOA:
			GPIOA_MODER    = ((GPIOA_MODER) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
		case GPIOB:
			GPIOB_MODER    = ((GPIOB_MODER) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
		case GPIOC:
			GPIOC_MODER    = ((GPIOC_MODER) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
		case GPIOD:
			GPIOD_MODER    = ((GPIOD_MODER) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
	}
	
	
}

void set_gpio_otype(int mode,int pin,int value){
	
	switch(mode){
		case GPIOA:
			GPIOA_OTYPER    = ((GPIOA_OTYPER) & ~0x1 << (pin)) | (value & 0x1)<<(pin);
			break;
		case GPIOB:
			GPIOB_OTYPER    = ((GPIOB_OTYPER) & ~0x1 << (pin)) | (value & 0x1)<<(pin);
			break;
		case GPIOC:
			GPIOC_OTYPER    = ((GPIOC_OTYPER) & ~0x1 << (pin)) | (value & 0x1)<<(pin);
			break;
		case GPIOD:
			GPIOD_OTYPER    = ((GPIOD_OTYPER) & ~0x1 << (pin)) | (value & 0x1)<<(pin);
			break;
	}
}

void set_gpio_ospeed(int mode,int pin,int value){
	
	switch(mode){
		case GPIOA:
			GPIOA_OSPEEDR    = ((GPIOA_OSPEEDR) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
		case GPIOB:
			GPIOB_OSPEEDR    = ((GPIOB_OSPEEDR) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
		case GPIOC:
			GPIOC_OSPEEDR    = ((GPIOC_OSPEEDR) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
		case GPIOD:
			GPIOD_OSPEEDR    = ((GPIOD_OSPEEDR) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
	}
}

void set_gpio_pupdr(int mode,int pin,int value){
	
	switch(mode){
		case GPIOA:
			GPIOA_PUPDR    = ((GPIOA_PUPDR) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
		case GPIOB:
			GPIOB_PUPDR    = ((GPIOB_PUPDR) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
		case GPIOC:
			GPIOC_PUPDR    = ((GPIOC_PUPDR) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
		case GPIOD:
			GPIOD_PUPDR    = ((GPIOD_PUPDR) & ~0x3 << (2*pin)) | (value & 0x3)<<(2*pin);
			break;
	}
}


int get_gpio_idr(int mode){
	int gpio_return;
	
	switch(mode){
		case GPIOA:
			gpio_return    =  GPIOA_IDR;
			break;
		case GPIOB:
			gpio_return    =  GPIOB_IDR;
			break;
		case GPIOC:
			gpio_return    =  GPIOC_IDR;
			break;
		case GPIOD:
			gpio_return    =  GPIOD_IDR;
			break;
	}
	return gpio_return;
}

void set_gpio_odr(int mode,int pin,int value){
	
	switch(mode){
		case GPIOA:
			GPIOA_ODR    = ((GPIOA_ODR) & ~0x1 << (pin)) | (value & 0x1)<<(pin);
			break;
		case GPIOB:
			GPIOB_ODR    = ((GPIOB_ODR) & ~0x1 << (pin)) | (value & 0x1)<<(pin);
			break;
		case GPIOC:
			GPIOC_ODR    = ((GPIOC_ODR) & ~0x1 << (pin)) | (value & 0x1)<<(pin);
			break;
		case GPIOD:
			GPIOD_ODR    = ((GPIOD_ODR) & ~0x1 << (pin)) | (value & 0x1)<<(pin);
			break;
	}
}

void set_gpio_alternate(int mode,int pin,int value){
 
	switch(mode){
		case GPIOA:
			if(pin <= 7){
				GPIOA_AFRL    = ((GPIOA_AFRL) & ~0xF << (4*pin)) | (value & 0xF)<<(4*pin);
			}else{
				GPIOA_AFRH    = ((GPIOA_AFRH) & ~0xF << (4*(pin/2))) | (value & 0xF)<<(4*(pin/2));
			}
			break;
		case GPIOB:
			if(pin <= 7){
				GPIOB_AFRL    = ((GPIOB_AFRL) & ~0xF << (4*pin)) | (value & 0xF)<<(4*pin);
			}else{
				GPIOB_AFRH    = ((GPIOB_AFRH) & ~0xF << (4*(pin/2))) | (value & 0xF)<<(4*(pin/2));
			}			
			break;
		case GPIOC:
			if(pin <= 7){
				GPIOC_AFRL    = ((GPIOC_AFRL) & ~0xF << (4*pin)) | (value & 0xF)<<(4*pin);
			}else{
				GPIOC_AFRH    = ((GPIOC_AFRH) & ~0xF << (4*(pin/2))) | (value & 0xF)<<(4*(pin/2));
			}			
			break;
		case GPIOD:
			if(pin <= 7){
				GPIOD_AFRL    = ((GPIOD_AFRL) & ~0xF << (4*pin)) | (value & 0xF)<<(4*pin);
			}else{
				GPIOD_AFRH    = ((GPIOD_AFRH) & ~0xF << (4*(pin/2))) | (value & 0xF)<<(4*(pin/2));
			}			
			break;
	}
}
