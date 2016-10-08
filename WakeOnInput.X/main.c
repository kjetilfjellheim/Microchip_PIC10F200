
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
 * Microcontroller frequency.
 */
#define _XTAL_FREQ 4000000L
/**
 * Delay 10 seconds.
 */
#define DELAY 10000

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
     * Check if reset was done because of pin change.
     */
    unsigned char status = STATUS & 0b10000000;
    if (status) {
        /**
         * Set GP0 to LOW.
         */
        GPIO = GPIO & 0b11111110;
        __delay_ms(DELAY);
    }
    while (true) {
        /**
         * Set output HIGH for GP0.
         */
        GPIO = GPIO | 0b00000001;
        /**
         * This is done since wakeup is done base on last read.
         * 
         */
        unsigned char readValue = GPIO;
        /**
         * Sleep.
         */
        SLEEP();
    }

}

