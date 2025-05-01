#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>

void main(void)
{
    unsigned char num1, num2, sum;

    num1 = 0xA0;
    num2 = 0x02;
    sum = num1 + num2;

    TRISD = 0; // Set Port D as output

    while (1)
    {
        PORTD = sum; // Display the sum on Port D
    }
}
