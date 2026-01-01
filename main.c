/*
*This code shows how to do a blink for LED on board stm32f411re
*Este código muestra como hacer parpadar un LED en stm32f411re
*Made by: Jonathan Pioquinto
*for tecnologiasjpc
*/

#include <stdint.h>

// Definition of registers - Definicion de registros 
// enables clock - registro para habilitar reloj
#define RCC_AHB1ENR  *((volatile uint32_t *)0x40023830)
// mode register - registro de modo de funcionamiento
#define GPIOA_MODER  *((volatile uint32_t *)0x40020000)
// output type register - registro para tipo de salida
#define GPIOA_OTYPER *((volatile uint32_t *)0x40020004) 
// output data register - registro del puerto de salida
#define GPIOA_ODR    *((volatile uint32_t *)0x40020014)	
// bit set/reset register - registro de estado de pines
#define GPIOA_BSRR   *((volatile uint32_t *)0x40020018) 

// Macros basicos - Basic macros
#define BIT_SET(reg, bit)    ((reg) |= (1UL << (bit))) 	// pin to 1
#define BIT_CLEAR(reg, bit)  ((reg) &= ~(1UL << (bit)))	// pin to 0 
#define BIT_TOGGLE(reg, bit) ((reg) ^= (1UL << (bit)))	// change state of pin
#define BIT_READ(reg, bit)   (((reg) >> (bit)) & 1UL)		// read state of pin

int main(){
	
		// Enables clock - Habilita el reloj de microcontrolador
    BIT_SET(RCC_AHB1ENR, 0);	
    
    // Defines PA5 as output - Establece PA5 como salida 
    GPIOA_MODER &= ~(3UL << 10);  // Clean register - Limpia registro
    GPIOA_MODER |= (1UL << 10);   // output mode - modo de salida
    
    while(1){// blinks on board LED - parpadea el led conectado en la placa
			
        //GPIOA_BSRR = (1UL << 5);      				// previous implementation
				BIT_SET(GPIOA_BSRR, 5);									// PA5 to 1
        for(volatile int i=0; i<1000000; i++);  // delay - retraso
        
        //GPIOA_BSRR = (1UL << (5+16)); 				// previous implementation
				BIT_SET(GPIOA_BSRR, (5+16));						// PA5 to 0
        for(volatile int i=0; i<1000000; i++);  // delay - retraso
    }
}
