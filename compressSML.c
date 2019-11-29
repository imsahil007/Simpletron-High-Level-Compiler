#include "header.h"
int compressSML(int SML[SIZE])
{
	int lastinst, zeros = 0;
	for(int i = 0; i < SIZE; i++)
	{
		if(SML[i] == 0 )
		{	
			lastinst=i;
			break;
		}
	}
	
	int min=SIZE;
	for(int i = 0; i <lastinst ;i++)
		if( SML[i]%SIZE < min &&  SML[i]/SIZE < BRANCH )
			min = SML[i]%SIZE;

	for(int i = min, j= lastinst; i<SIZE; i++, j++)
	{		SML[j] = SML[i];
			SML[i] = 0;		//Dropping memory
	}

	
	for(int i = 0; i < lastinst; i++)
	{
		if((SML[i]/SIZE) < BRANCH)
		{
				int operand = (SML[i]%SIZE) - min + lastinst;
			 	SML[i] = ((SML[i]/SIZE)* SIZE) + operand;
				//changing variable addres
		}
	}
	
	return SIZE-min+lastinst;
}
