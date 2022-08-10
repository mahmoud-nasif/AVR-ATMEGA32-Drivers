


#ifndef STEPPER_H_
#define STEPPER_H_
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_Interface.h"
#include "StdTyps.h"

#define DELAY 1

#define COIL1A PINA0 
#define COIL1B PINA1 
#define COIL2A PINA2 
#define COIL2B PINA3 

#define BI_POLER         0 
#define UNI_POLER        1
#define  MOTOR_TYPE      UNI_POLER 




void  STEBBER_UniPolerCW (void) ;
void STEBBER_BipoleruCw (void);
void STEBBER_BipolerCw (void);
void STEBBER_UniPolerUCW (void);
void STEBBER_CW_WithAngle(u16 angle) ;
void STEBBER_UCW_WithAngle(u16 angle);






#endif /* STEPPER_H_ */