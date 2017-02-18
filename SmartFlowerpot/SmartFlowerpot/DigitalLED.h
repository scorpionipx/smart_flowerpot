#ifndef DIGITALLED_H_
#define DIGITALLED_H_

/* Includes */
/*============================================================================*/
#include "DigitalLED_config.h"

/* Constants and types */
/*============================================================================*/
#define DDR_SEG_PORT  DDR(SEG_PORT)
#define PIN_SEG_PORT  PIN(SEG_PORT)
#define SEGA (~(1<<PSEGA))
#define SEGB (~(1<<PSEGB))
#define SEGC (~(1<<PSEGC))
#define SEGD (~(1<<PSEGD))
#define SEGE (~(1<<PSEGE))
#define SEGF (~(1<<PSEGF))
#define SEGG (~(1<<PSEGG))
#define DOT  (~(1<<PDOT))

#define DDR_SEL_PORT DDR(SEL_PORT)
#define PIN_SEL_PORT PIN(SEL_PORT)
#define SEL0 (~(1<<PSEL0))
#define SEL1 (~(1<<PSEL1))
#define SEL2 (~(1<<PSEL2))
#define SEL3 (~(1<<PSEL3))


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void DigitalDisplayInit(void);
void DisplayNumber(uint16 no,uint16 duration);
void DisplaySingleDigit(uint8 dig, uint8 seg);
void ClearDisplayLED(void);
#endif /* GLOBAL_H_ */ 

/* Notice: the file ends with a blank new line to avoid compiler warnings */



