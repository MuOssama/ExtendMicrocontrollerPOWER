\
#define F_CPU 8000000UL
#include <avr/delay.h>
#include <avr/io.h>
#include "MCAL/DIO/DIO_INTERFACE.H"
#include "MCAL/ADC/ADC_INTERFACE.h"
#include "MCAL/ADC/ADC_REG.h"
#include "HAL/CLCD1602/CLCD_INTERFACE.h"
#include "HAL/SHIFT_REGISTER/SHIFT_REGISTER_INTERFACE.h"
#include "UTILS/STD_TYPES.h"

#define CS1 6
#define CS2 5
#define WR 7

void AnalogMux(u8 CS, u8 channel);
int main() {

	/*Pin Directions*/
	DDRA = 0b00000000;
	DDRB = 0b11111111;
	DDRC = 0b11111111;
	DDRD = 0b11111111;

    DIO_SetPin_Value(GroupB,CS1,LOW);

	LCD8Bit_init();
	ADC_init();
   u8 i =0;
   while(1){
	   if(i<32)
	      AnalogMUX(CS1,i);
	   if(i>=32&&i<64)
		  AnalogMUX(CS2,i);
	   i++;
       if(i==64)
    	   i=0;

	}

  }

void AnalogMUX(u8 CS, u8 channel){
	u16 AnalogInput;
	if(CS == CS1){
		CLR_BIT(PORTB,CS1);
		SET_BIT(PORTB,CS2);
		PORTB &= 0b11100000;
		PORTB |= channel;

		DIO_SetPin_Value(GroupB,WR,LOW);
	    AnalogInput = ADC_Read_Sych(0)*500UL/65535;
	    LCD_Send_String("A");
	    LCD_Send_Int(channel+1);
	    LCD_Send_String(": ");
	    LCD_Send_Int(AnalogInput);
	    _delay_ms(200);
		DIO_SetPin_Value(GroupB,WR,HIGH);
	    LCD8Bit_Send_Command(0x01);
	}
	else if(CS == CS2){
		CLR_BIT(PORTB,CS2);
		SET_BIT(PORTB,CS1);
		PORTD &= 0b11100000;
		PORTD |= channel;
	    LCD_Send_String("B");
	    LCD_Send_Int((channel-32+1));
	    LCD_Send_String(": ");
		DIO_SetPin_Value(GroupB,WR,LOW);
	    AnalogInput = ADC_Read_Sych(1)*500UL/65535;
	    LCD_Send_Int(AnalogInput);
	    _delay_ms(200);
		DIO_SetPin_Value(GroupB,WR,HIGH);
	    LCD8Bit_Send_Command(0x01);
	}


}

