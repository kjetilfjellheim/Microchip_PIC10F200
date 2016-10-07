
#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

/**
 * Watchdog timer is on.s
 */
#pragma config WDTE = OFF        
/**
 * Turn off code protection.
 */
#pragma config CP = OFF         
/**
 * Use master clear rather than GP3 as input.
 */
#pragma config MCLRE = ON
