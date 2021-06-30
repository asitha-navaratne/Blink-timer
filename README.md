# Blink-timer

<p align="justify">In this code an LED is made to blink at a precise time interval using the timer/counter0 Compare Match Interrupt.</p>

<p align="justify">The timer/counter0 is first initialized in CTC mode (Clear Timer on Compare) with 64 as the prescalar value. For 8 MHz, this will reduce the clock rate to 125 
kHz. Compare Match Interrupts are enabled and the value of OCR0 is set to 125. Therefore, the Compare Match Interrupt will occur when the value in the timer/counter0 register 
TCNT0 is equal to the value in OCR0 i.e. 125. Since the clock rate is 125 kHz the compare-match will occur every 1ms. When the interrupt occurs the Interrupt Service Routine (ISR)
will be executed and the value in TCNT0 will be cleared.</p>

<p align="justify">Within the ISR, the volatile variable <em>milliseconds</em> is incremented each time the ISR is run. In C, a variable is declared as <em>volatile</em> if it can 
change at any time within the code without the program knowing. If a variable declared outside an ISR is meant to be used within it, it must be declared as volatile or the 
program will try to "correct" it by ignoring the change.</p>
