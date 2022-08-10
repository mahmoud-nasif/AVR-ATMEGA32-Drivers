
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "StdTyps.h"
#include "DIO_Interface.h"

#define     FIRST_OUT        PINA0
#define     FIRST_IN         PINB0 
#define     DEFAULT_KEY      '.'   



u8 KeyPad_Entry(void) ; 







#endif /* KEYPAD_H_ */