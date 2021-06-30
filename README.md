# Blink-timer

<p align="justify">In this code an LED is made to blink at a precise time interval using the timer/counter0 Compare Match Interrupt.</p>

<p align="justify">The timer/counter0 is first initialized in CTC mode (Clear Timer on Compare mode) with 64 as the prescalar value. For 8 MHz, this will reduce the clock rate to 125 kHz. Compare Match Interrupts are enabled and the value of OCR0 is set to 125. Therefore, the Compare Match Interrupt will occur when the value in the timer/counter0 register 
TCNT0 is equal to the value in OCR0 i.e. 125. Since the clock rate is 125 kHz, the compare-match will occur every 1ms. When the interrupt occurs the Interrupt Service Routine (ISR) will be executed and the value in TCNT0 will be cleared.</p>

<p align="justify">Within the ISR, the volatile variable <em>milliseconds</em> is incremented each time the ISR is run. Whenever a variable is to be used within the normal program as well as within an ISR, it should be declared as volatile. The <em>volatile</em> keyword tells the compiler that the variable can change at any moment during the program execution and therefore, the compiler should reload the variable from memory whenever it is referenced within the program, rather than relying on a temporary copy of the variable it might have in a processor register. If the variable is not declared volatile, when it changes within the ISR it will be saved in the memory address of the variable. But when the variable is accessed by the <em>main</em> method the program will notice that the value in the memory address does not match the value in the processor register</p>

<p align="center"></p>
