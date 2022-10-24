#define F_CPU 8000000UL
#include <avr/delay.h>
#include <avr/io.h>
#include "../ShiftRegisters/MCAL/DIO/DIO_INTERFACE.H"
#include "../ShiftRegisters/HAL/SHIFT_REGISTER/SHIFT_REGISTER_INTERFACE.h"

u8  latch = 2, data = 1, clk = 0, shiftPort = 1;
int main() {
	DIO_SetPin_Direction(shiftPort,latch,OUTPUT);
	DIO_SetPin_Direction(shiftPort,data,OUTPUT);
	DIO_SetPin_Direction(shiftPort,clk,OUTPUT);


	while (1) {
	    Shift(shiftPort,latch,data,clk,(unsigned int)0b0110000001111111);
	    _delay_ms(1);
	    Shift(shiftPort,latch,data,clk,(unsigned int)0b1101101010111111);
	    _delay_ms(1);
	    Shift(shiftPort,latch,data,clk,(unsigned int)0b1111001011011111);
	    _delay_ms(1);
	    Shift(shiftPort,latch,data,clk,(unsigned int)0b0110011011101111);
	    _delay_ms(1);

	}
}
