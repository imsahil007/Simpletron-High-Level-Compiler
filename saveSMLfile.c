#include "header.h"
void saveSMLfile(int SML[SIZE], FILE *output,int occupiedmemory)
{
	
	if(output == NULL)
    {
		printf("Unable to create SML file!");
		return;
    }
	
	for(int i = 0; i < occupiedmemory; i++)
	{		if(SML[i] < 0)
			 	fprintf( output, "%02d  -%04d\n",i, SML[i]);
			else
			 	fprintf( output, "%02d  +%04d\n",i, SML[i]);
	}

}
