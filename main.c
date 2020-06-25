#ifndef _NSC_MAIN_H
#define _NSC_MAIN_H

#include "stm32f10x.h"
#define Q_FLAG 0x08000000

#endif

uint16_t a = 0;
uint16_t range = 300;
//uint16_t locked = 0;
uint16_t c = 0;
//uint32_t xPSR = 0; 
unsigned int APSR;
//int a, range=300;
//char c;

int main (void)
{
register unsigned int apsr __asm("apsr");
	
	while (1)
	{
		for(a=0;a<range;a++)					//a goes from 0 to 300
		{
			//c = a;
			c = __SSAT	(a, 9);				//c will saturate at 255
		}
	APSR = 	__get_APSR ();
		if(APSR&Q_FLAG)	
		{															//Using Compiler optimisation level 3, the if, then, else statement 
			range--;										//will be constructed using conditional instructions
		}	
		apsr = apsr&~Q_FLAG;
	
	}
}
