#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>

void main(void)
{
	int mul,div;
	mul=0;
	div=0;
	
	mul=0x04 * 0x01;
	div= 0x06 / 0x02;
	
	TRISC = 0;
	PORTC = mul;

	TRISD = 0;
	PORTD = div;
}