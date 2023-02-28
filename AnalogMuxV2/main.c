#define F_CPU 8000000UL
#include <avr/delay.h>
#include <avr/io.h>
#include "MCAL/DIO/DIO_INTERFACE.H"
#include "MCAL/ADC/ADC_INTERFACE.h"
#include "MCAL/ADC/ADC_REG.h"
#include "UTILS/STD_TYPES.h"


u8 Cathode7Seg[10] = {  0b00111111, /* 0 */
  0b00000110, /* 1 */
  0b01011011, /* 2 */
  0b01001111, /* 3 */
  0b01100110, /* 4 */
  0b01101101, /* 5 */
  0b01111101, /* 6 */
  0b00000111, /* 7 */
  0b01111111, /* 8 */
  0b01101111 /* 9 */
};
u8 Anode7Seg[10] = {  ~0b00111111, /* 0 */
  ~0b00000110, /* 1 */
  ~0b01011011, /* 2 */
  ~0b01001111, /* 3 */
  ~0b01100110, /* 4 */
  ~0b01101101, /* 5 */
  ~0b01111101, /* 6 */
  ~0b00000111, /* 7 */
  ~0b01111111, /* 8 */
  ~0b01101111 /* 9 */
};
void AnalogMux(u8 channel);
int main() {


	/*Pin Directions*/
	DDRA = 0b00000111;
	DDRB = 0b11111111;
	DDRC = 0b11111111; //first 7 seg (cathode)
	DDRD = 0b11111111; //second 7 seg (anode)

	//Pull up ewrirtor for switches
    DIO_SetPin_Value(GroupA,3,HIGH);
    DIO_SetPin_Value(GroupA,4,HIGH);
    DIO_SetPin_Value(GroupA,5,HIGH);

	ADC_init();
	u32 A,B,C,num;
   while(1){
	   A = !(GET_BIT(PINA_REG,3))*1;
	   B = !(GET_BIT(PINA_REG,4))*2;
	   C = !(GET_BIT(PINA_REG,5))*4;
	   _delay_ms(10);
       num = A+B+C;
       AnalogMUX(num);
  }

}
void AnalogMUX(u8 channel){
	u16 AnalogInput;
	u8 units = 0, tens = 0;


	PORTA &= 0b11111000;
	PORTA |= channel;

	AnalogInput = ADC_Read_Sych(7)*500UL/1024UL;
	//print the number of the sensor 0-7
	PORTC = Cathode7Seg[channel];
	PORTD = 0xff;
	_delay_ms(1000);

	//print the temprature
	units = AnalogInput % 10;
	tens = AnalogInput / 10;

	PORTC = Cathode7Seg[tens];
	PORTD = Anode7Seg[units];


	_delay_ms(1000);

}

