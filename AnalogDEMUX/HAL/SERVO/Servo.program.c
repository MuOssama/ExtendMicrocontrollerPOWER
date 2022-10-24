#ifndef _SERVO_INTERFACE_H
#define _SERVO_INTERFACE_H

#include "../../MCAL/TIMER/TIMER_INTERFACE.h"
#include "../../MCAL/TIMER/TIMER_REG.h"

void ServoAngle(s8 angle){
	if(angle>= -90 && angle <= 90)
		OCR1AL_REG = ((1000/180.0)*(angle+90.0))+1000.0;
	else if(OCR1AL_REG == 2000)
    	OCR1AL_REG = 1999;
    else if(OCR1AL_REG == -90)
    	OCR1AL_REG = 1001;


}

#endif
