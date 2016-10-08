/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"

/* Refer to the device datasheet for information about available
oscillator configurations and to compiler documentation for macro details. */
void ConfigureOscillator(void)
{

    /*If the PIC12 device has an OSCCAL value, the HiTech Compiler provides
    a macro called _READ_OSCCAL_DATA which can be loaded using this: */

    /* TODO Configure OSCCAL if the device has an OSCCAL register */

#if 0

    OSCCAL=_READ_OSCCAL_DATA(); /* _READ_OSCCAL_DATA macro unloads cal memory */

#endif

    /*Not all PIC12 devices require this.

    /* TODO Add clock switching code if appropriate.  */

    /* Typical actions in this function are to tweak the oscillator tuning
    register, select new clock sources, and to wait until new clock sources
    are stable before resuming execution of the main project. */

}
