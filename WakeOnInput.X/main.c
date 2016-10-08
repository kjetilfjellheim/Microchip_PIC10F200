
#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

/**
 * 
 */
#define _XTAL_FREQ 4000000L

void main(void) {
    ConfigureOscillator();

    InitApp();

    /**
     * Set OSCCAL register. 
     */
    OSCCAL = 0b00000001;
    /**
     * The OPTION register. Bit 7 is set LOW to allow for wakeup.
     */
    OPTION = 0b01111111;
    /**
     * The TRISGPIO register is set with the GP0 as output and GP1 as input.
     */
    TRISGPIO = 0b00001110;
    
    /**
     * Set all outputs to LOW.
     */
    GPIO = 0b00000000;
    __delay_ms(2000);
    while (true) {
        /**
         * Set output HIGH for GP0.
         */
        GPIO = 0b00000001;  
        __delay_ms(2000);
        SLEEP();  
    }

}

