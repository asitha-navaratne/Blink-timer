#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_DDR 	DDRC							///< DDR of indicator LED.
#define LED_PORT 	PORTC							///< Port of indicator LED.
#define LED_PIN		PC0								///< Pin of indicator LED.

void TIMER_INIT(void);

volatile uint16_t milliseconds = 0;					///< Variable to hold the milliseconds elapsed.

/*!
 *	@brief ISR for Timer/Counter0 Compare Match Interrupt; increments milliseconds when a compare-match occurs.
 */

ISR(TIMER0_COMP_vect){
	milliseconds++;
}

int main(void){
	LED_DDR |= (1<<LED_PIN);
	TIMER_INIT();
	uint16_t delay = 1000;							///< Variable to hold the required delay time in milliseconds.
	
	sei();											///< Enable global interrupts.
	
	while(1){
		if(milliseconds >= delay){
			LED_PORT ^= (1<<LED_PIN);
			milliseconds = 0;
		}
	}
}

/*!
 *	@brief Initialize Timer/Counter0 in CTC mode.
 */

void TIMER_INIT(void){
	TCCR0 = (1<<WGM00)|(1<<WGM01)|(1<<CS01)|(1<<CS00);		///< Initialize timer0 in CTC mode with prescalar 64.
	TIMSK = (1<<OCIE0);										///< Enable compare match interrupt.
	OCR0 = 125;													///< Set OCR0 to 125 to generate an interrupt every 1 ms.
}