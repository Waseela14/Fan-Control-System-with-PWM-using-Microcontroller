#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

void initialize_pwm(void);
char read_keypad(void);
void set_fan_speed(char keypad_input);

int main(void)
{
	DDRA = 0b00001111; // Rows are outputs, Columns are inputs
	DDRC = 0b00000000;
	DDRE = 0xFF;
	DDRB = 0b11101111; // PB0 = clock pb1 = ocr pb2 = ale pb3 = start pb4 = eoc, PB7 = PWM output
	DDRD = 0xFF;       // LED display

	initialize_pwm();

	while (1)
	{
		char keypad_input = read_keypad();
		set_fan_speed(keypad_input);
	}

	return 0;
}

void initialize_pwm(void)
{
	TCCR2 |= (1 << WGM21) | (1 << WGM20) | (1 << COM21); // Fast PWM mode, Non-inverting mode
	TCCR2 |= (1 << CS22);                              // Clock prescaler 64
	OCR2 = 0xFF;                                       // Set TOP value for 8-bit fast PWM mode
}

char read_keypad(void)
{
	char keypad_keys[4][4] = {
		{'1', '2', '3', 'A'},
		{'4', '5', '6', 'B'},
		{'7', '8', '9', 'C'},
		{'*', '0', '#', 'D'}};

		for (int col = 0; col < 4; col++)
		{
			PORTA = ~(1 << col); // Enable one column at a time
			_delay_ms(10);       // Wait for a short time for stabilization

			for (int row = 0; row < 4; row++)
			{
				if (!(PINA & (1 << (row + 4)))) // Check if the corresponding row is low
				{
					while (!(PINA & (1 << (row + 4)))); // Wait for the key release
					return keypad_keys[row][col];
				}
			}
		}

		return '\0'; // Return null character if no key is pressed
	}

	void set_fan_speed(char keypad_input)
	{
		unsigned char pwm_value = 0;

		switch (keypad_input)
		{
			case '0':
			pwm_value = 0; // Turn off the fan
			break;
			case '1':
			pwm_value = 25; // Fan speed 25 (10%)
			break;
			case '2':
			pwm_value = 50; // Fan speed 50 (20%)
			break;
			case '3':
			pwm_value = 75; // Fan speed 75 (30%)
			break;
			case '4':
			pwm_value = 100; // Fan speed 100 (40%)
			break;
			case '5':
			pwm_value = 125; // Fan speed 125 (50%)
			break;
			case '6':
			pwm_value = 150; // Fan speed 150 (60%)
			break;
			case '7':
			pwm_value = 175; // Fan speed 175 (70%)
			break;
			case '8':
			pwm_value = 200; // Fan speed 200 (80%)
			break;
			case '9':
			pwm_value = 225; // Fan speed 225 (90%)
			break;
			case 'A':
			pwm_value = 255; // Fan speed 255 (100%)
			break;
			case 'B':
			pwm_value = 150; // Custom speed 150 (60%)
			break;
			case 'C':
			pwm_value = 80; // Custom speed 80 (32%)
			break;
			case 'D':
			pwm_value = 30; // Custom speed 30 (12%)
			break;
			default:
			pwm_value = 0; // Turn off the fan for any other key
			break;
		}

		OCR2 = pwm_value; // Update OCR2 for PWM output
	}
