
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
 #define F_CPU 4000000UL
#include <util/delay.h>

typedef struct 
{
    uint8_t port;
    uint8_t pin;
} led_def_t;

#define PB   1
#define PC   2
#define PD   3
    
const led_def_t leds[] = 
{
    {.port=PB, .pin=0},
    {.port=PB, .pin=1},
    {.port=PB, .pin=2},
    {.port=PB, .pin=3},
    {.port=PB, .pin=4},
    {.port=PB, .pin=5},
    {.port=PB, .pin=6},
    {.port=PB, .pin=7},
    {.port=PC, .pin=2},
    {.port=PC, .pin=4},
    {.port=PC, .pin=5},
    {.port=PC, .pin=6},
    {.port=PC, .pin=7},
    {.port=PD, .pin=0},
    {.port=PD, .pin=1},
    {.port=PD, .pin=2},
    {.port=PD, .pin=3},
    {.port=PD, .pin=4},
    {.port=PD, .pin=5},
    {.port=PD, .pin=6},
    {.port=PD, .pin=7},
};

    
    
int main() 
{
    uint8_t idx;
    
    cli();
    
    //__disable_interrupt();
    //__watchdog_reset();
    /* Clear WDRF in MCUSR */
    MCUSR &= ~(1<<WDRF);
    /* Write logical one to WDCE and WDE */
    /* Keep old prescaler setting to prevent unintentional time-out */
    WDTCSR |= (1<<WDCE) | (1<<WDE);
    /* Turn off WDT */
    WDTCSR = 0x00;
    //__enable_interrupt();
    _delay_ms(1000);
    DDRB = 0xff;
    DDRC = _BV(2) | _BV(4) | _BV(5) | _BV(6) | _BV(7);
    DDRD = 0xff;

    idx = 0;
    
    while (1) {
	PORTB = 0xff;
	PORTC = 0xf4;
	PORTD = 0xff;

	if (leds[idx].port == PB) {
	    PORTB &= ~_BV(leds[idx].pin);
	} else if (leds[idx].port == PC) {
	    PORTC &= ~_BV(leds[idx].pin);
	} else if (leds[idx].port == PD) {
	    PORTD &= ~_BV(leds[idx].pin);
	}
	
	idx++;
	if (idx >= sizeof(leds)/sizeof(leds[0]))
	    idx = 0;
	
	
	_delay_ms(25);
    }

}

