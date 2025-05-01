
#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>
void main(void)
{
int i, sum;
int number[]={1,2,3,4,5,6,7,8,9,10};
sum = 0;
for(i=0;i<=9;i++)
{
sum = sum+number[i];
}
TRISD = 0;
PORTD= sum;
}