/*
 * IPX_Clock.c
 *
 * Created: 4/16/2017 11:42:12 PM
 *  Author: ScorpionIPX
 */ 

#include "Global.h"
#include "IPX_Clock.h"

// INCREASE TIME BY ONE SECOND
void increment_clock()
{
	CLOCK.S ++;
	if(CLOCK.S >= 60)
	{
		CLOCK.S = 0;
		CLOCK.M ++;
		if(CLOCK.M >= 60)
		{
			CLOCK.M = 0;
			CLOCK.H ++;
			if(CLOCK.H >= 24)
			{
				CLOCK.H = 0;
			}
		}
	}
}
