#include <avr/io.h>

#include <util/delay.h>

#include "DIO.h"

#define F_CPU 16000000 ul


void Wait()
{
   uint8_t i;
   for(i=0;i<50;i++)
   {
      _delay_loop_2(0);
      _delay_loop_2(0);				// A loop for delay
      _delay_loop_2(0);
   }

}

void Servo_Move()

{
	OCR1A=97;   //0 degree
	Wait();

	OCR1A=535;  //180 degree
	Wait();
}

void Servo_Int()
{
   //Configure TIMER1
   TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
   TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)

   ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).

   DDRD|=(1<<PD4)|(1<<PD5);   //PWM Pins as Out

   
}


void Buzzer_Int()

{
	Dio_WritePinDir('A',3,OUT);			// Setting buzzer pin as output
}

void Buzzer_Ring()

{
	Dio_WritePin('A',3,STD_high);		// Setting pin as high to turn buzzer on 
}