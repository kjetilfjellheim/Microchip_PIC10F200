
#if defined(__XC)
#include <xc.h>         
#elif defined(HI_TECH_C)
#include <htc.h>        
#endif

#include <stdint.h>        
#include <stdbool.h>       

#include "system.h"        
#include "user.h"          

/**
 * Microcontroller frequency.
 */
#define _XTAL_FREQ 4000000L
/**
 * Delay 2 seconds.
 */
#define DELAY 2000

void main(void) {
    /**
     * Configure oscillator.
     */
    ConfigureOscillator();
    /**
     * Init app.
     */
    InitApp();
    /**
     * Set OSCCAL register. This is not used in this project.
     */
    OSCCAL = 0b11111110;
    /**
     * The OPTION register.
     * Bit 6 is HIGH to start counter.
     * Bit 5 is LOW to count on external TOCKI/GP2 pin.
     */
    OPTION = 0b01101111;
    /**
     * The TRISGPIO register is set with the GP0 as output and GP2 as input.
     */
    TRISGPIO = 0b00001110;
    /**
     * Timer clock counter.
     */
    unsigned int timerClockCount = 0;
    /**
     * Set output LOW for GP0.
     */
    GPIO = 0b00000000;
    /**
     * 
     */
    TMR0 = 0;
    while (true) {
        /**
         * 
         */
        timerClockCount = TMR0;
        if (timerClockCount > 10) {
            /**
             * Set output HIGH for GP0.
             */
            GPIO = 0b00000001;
            /**
             * Delay 2 seconds
             */
            __delay_ms(DELAY);
            /**
             * Reset timing
             */
            TMR0 = 0;    
            /**
             * Reset GP0
             */
            GPIO = 0b00000000;
        }
    }

}