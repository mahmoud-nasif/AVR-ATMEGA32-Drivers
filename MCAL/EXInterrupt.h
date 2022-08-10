


#ifndef EXINTERRUPT_H_
#define EXINTERRUPT_H_

#include "StdTyps.h"
#include "MemMap.h"
#include "Utils.h"

typedef enum {
	EX_INT0 =0 , 
	EX_INT1 ,
	EX_INT2 
}EXInterruptSource_type ; 

typedef enum {
	LOW_LEVEL =0 , 
	ANY_LOGIC_CHANGE ,
	FALLING_EDGE , 
	RISING_EDGE 
}TriggerEdge_type ; 

void EXI_Enable(EXInterruptSource_type interrupt ) ;
void EXI_Disable(EXInterruptSource_type interrupt) ;
void EXI_TriggerEdge(EXInterruptSource_type interrupt , TriggerEdge_type edge ) ;
void EXI_SetCallBack(EXInterruptSource_type interrupt,void(*pf_local)(void));





#endif /* EXINTERRUPT_H_ */