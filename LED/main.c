
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
 * Had to decrease from 4Mhz to 500Khz to avoid breadboard issue which 
 * caused restarts.
 */
#define _XTAL_FREQ 4000000L
/**
 * Delay between counter.
 */
#define DELAY 2000

void main(void)
{   
    /**
     * Configure oscillator.
     */
    ConfigureOscillator();

    /**
     * Initialize application logic.
     */
    InitApp();
    
    /**
     * Set OSCCAL register. For GP2 to be set as output the last bit in the 
     * OSCCAL regisry must be set LOW. This is the FOSC4 bit. 
     */
    OSCCAL = 0b00000000;
    /**
     * The OPTION register must be set with bit 6 LOW to allow GP2 to be set 
     * as output. Bit 6 is TOCS. 
     */
    OPTION = 0b11011111;
    /**
     * The TRISGPIO register is set with the 3 lowest bits as LOW. This means 
     * they are output.s
     */
    TRISGPIO = 0b00001000;     
    
    /**
     * Counter for the application.ds
     */
    int cnt = 0;
    
    /**
     * Start loop.
     */
    while(true)
    {        
        /**
         * Set the output.
         */
        GPIO = cnt;
        /**
         * Increase counter.s
         */
        cnt++;
        /**
         * If counter is higher than 7 then reset.
         */
        if (cnt > 7 ) {
            cnt = 0;
        }
        /**
         * Delay the application.
         */
        __delay_ms(DELAY);  
    }

}

