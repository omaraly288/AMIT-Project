/*
 * ATM
 *
 * Created: 18/10/2020 3:09:12 pm
 * Author : Omar
 
 This program will ask the user to enter their pin number, which is assumed to be saved in the data base, in case the pin
 is entered wrong 3 times an alarm will turn on (buzzer) in case the pin is entered correctly, they user will be asked
 to choose the amount they want to withdraw, the amount is entered in units (ex: 3 for 300 egp) when the amount is entered
 the servo motor will move with a number equal to the number entered to pull out 100 egp notes.
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "KP.h"
#include "ServoBuzzer.h"

#define F_CPU 16000000 ul


int main(void)
{
    KP_Init();
	LCD_init();
	Buzzer_Int();			// Initializing all drivers used
	Servo_Int();
	LCD_clearScreen();
	
	uint8_t key = 0;
	
	uint8_t pw[4];  // array to store the 4 digits pin entered by user
	
	uint8 count = 0;	// variable to count number of digits entered		// declaring all variables used later
	uint8 trial = 0;	// counting number of incorrect trials for the pin

	uint8 amount = 0;  // variable to store amount to be withdrawn, entered by the user
	int x = 0;		// counting variable for servo motor
	
	
	LCD_SendString("Enter Pin:");
	LCD_GotoXY(1,2);
	
    while (1) 
    {
		
		
		while (count < 4)
		
		{
			
		
		key = KP_GetKey();		// Getting input from keypad
		
		_delay_ms(100);
		
		if(key != 0)
		
		{
			LCD_SendCharacter(key);
			
			pw[count] = key;      // After making sure a value is entered by the user storing it in array (limitation is
								// pw can't have 0)
			
			_delay_ms(100);
			
			count++;
			
		}
		}
		
		if (count == 4)
		{
			
		
		if(pw[0] == '1' && pw[1] == '2' && pw[2] == '3' && pw [3] == '4')
		
		{
			LCD_clearScreen();
			
			LCD_SendString("Correct PW");		// After 4 digits are entered, they are compared with the value in database
			_delay_ms(2000);
			LCD_clearScreen();
			
			
			
			LCD_SendString("Withdraw Amount:");
				while(amount == 0)
				{
					
				
				
				LCD_GotoXY(1,2);
				amount = KP_GetKey();			// Taking input from keypad for amount the user will withdraw
				LCD_SendCharacter(amount);
				
				}
					
				
			int value = amount - '0';			// Converting char entered by user to int to be used in loop
			
			
			while(x < value)
			
			{
				Servo_Move();
				_delay_ms(500);				// Pulling out notes by the amount entered by user
				x++;
			}
			
				
			
		}
		
		else
		
		{
			LCD_clearScreen();
			LCD_SendString("Incorrect PW");			// In case wrong PW is entered, another chance is given
			LCD_GotoXY(1,2);
			trial ++;
			count = 0;
		}
		
		
		}
		
		
		if(trial == 3)
		{
			Buzzer_Ring();			// after 3 incorrect attempts, buzzer will ring
		}
    }
}

