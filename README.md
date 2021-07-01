# Blink-timer

<p align="justify">The ATmega32A has three inbuilt timer/counter modules; the 8-bit timer/counter0 and timer/counter2, and the 16-bit timer/counter1. These timer/counter units can be used to create precise delays, count events and generate PWM waveforms.</p>

<p align="justify">In this code an LED is made to blink at a precise time interval using timer/counter0 Compare Match Interrupts.</p>

<p align="justify">The timer/counter0 is first initialized in CTC mode (Clear Timer on Compare mode) with 64 as the prescalar value. For 8 MHz, this will reduce the clock rate to 125 kHz. Compare Match Interrupts are enabled and the value of OCR0 is set to 125. Therefore, the Compare Match Interrupt will occur when the value in the timer/counter0 register 
TCNT0 is equal to the value in OCR0 i.e. 125. Since the clock rate is 125 kHz, the compare-match will occur every 1ms. When the interrupt occurs the Interrupt Service Routine (ISR) for Compare Match Interrupts will be executed and the value in TCNT0 will be cleared.</p>

<p align="justify">Within the ISR, the volatile variable <em>milliseconds</em> is incremented each time the ISR is run. Whenever a variable is to be used within the main function as well as within an ISR, it should be declared as <em>volatile</em>. The <em>volatile</em> keyword tells the compiler that the variable can change at any moment during the program execution and therefore, the compiler should reload the variable from memory whenever it is referenced within the program, rather than relying on a temporary copy of the variable it might have in a processor register. Essentially, if the variable is not declared volatile, any changes that are done to it within the ISR will be ignored. Additionally, if the processor notices that the value stored in memory and the value in the processor register for the same variable are different, it might assume an error and try to overwrite one value, which could lead to unexpected behaviours.</p>

<p align="justify">Whenever the value of <em>milliseconds</em> matches the value of the <em>delay</em> variable (in milliseconds), the LED pin is toggled and the value of <em>milliseconds</em> is cleared.</p>
