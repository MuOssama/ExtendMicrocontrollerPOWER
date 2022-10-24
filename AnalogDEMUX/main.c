#define F_CPU 8000000UL
#include <avr/delay.h>
#include <avr/io.h>
#include "MCAL/DIO/DIO_INTERFACE.H"
#include "UTILS/STD_TYPES.h"


#define demuxPORT 3

void AnalogDemux(u8 channel, s8 angle);
int main() {

	/*Pin Directions*/
	DDRB = 0b11111111;
	DDRD = 0b11111111;


	Timer1_init();
    u8 i = 0;
    s16 ANGLE = 0;
   while(1){
	   if(i<8){
	      AnalogDemux(i,ANGLE);
	      i++;
	      ANGLE += 5;
	   }
       if(ANGLE > 90)
    	   ANGLE = -89;
       if(i==8)
    	   i=0;
	   }
   }

void AnalogDemux(u8 channel, s8 angle){

		PORTD &= 0b11100000;
		PORTD |= channel;
		ServoAngle(angle);
		_delay_ms(200);
}

