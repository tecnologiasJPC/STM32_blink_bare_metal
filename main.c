/*
*This code shows how to do a blink for LED on board stm32f411re
*Codigo hecho por: Jonathan Pioquinto
*para tecnologiasjpc
*/

#include <stdint.h>

// Definicion de registros 
#define RCC_AHB1ENR  *((volatile uint32_t *)0x40023830) // registro para habilitar reloj
#define GPIOA_MODER  *((volatile uint32_t *)0x40020000)	// registro de modo de funcionamiento
#define GPIOA_OTYPER *((volatile uint32_t *)0x40020004) // registro para tipo de salida
#define GPIOA_ODR    *((volatile uint32_t *)0x40020014)	// registro del puerto de salida
#define GPIOA_BSRR   *((volatile uint32_t *)0x40020018) // registro de estado de pines

// Macros basicos 
#define BIT_SET(reg, bit)    ((reg) |= (1UL << (bit))) 	// para poner un pin a 1
#define BIT_CLEAR(reg, bit)  ((reg) &= ~(1UL << (bit)))	// para poner un pin a 0 
#define BIT_TOGGLE(reg, bit) ((reg) ^= (1UL << (bit)))	// para cambiar el estado de un pin
#define BIT_READ(reg, bit)   (((reg) >> (bit)) & 1UL)		// para leer el estado de un bit

int main(){
		
    BIT_SET(RCC_AHB1ENR, 0);	// Habilita el reloj de microcontrolador
    
    // Establece PA5 como salida 
    GPIOA_MODER &= ~(3UL << 10);  // Limpia
    GPIOA_MODER |= (1UL << 10);   // Salida
    
    while(1){//parpadea el led conectado en la placa
			
        GPIOA_BSRR = (1UL << 5);      				 // PA5 a 1
        for(volatile int i=0; i<1000000; i++);  // retraso
        
        GPIOA_BSRR = (1UL << (5+16)); 				 // PA5 a 0
        for(volatile int i=0; i<1000000; i++);  // retraso
    }
}
