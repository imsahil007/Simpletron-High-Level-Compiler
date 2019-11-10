
void saveSMLfile(int SML[SIZE], FILE *output,int occupiedmemory)
{
	
	if(output == NULL)
    {
		printf("Unable to create SML file!");
		return;
    }
	
	for(int i = 0; i < occupiedmemory; i++)
	{		if(SML[i] < 0)
			 	fprintf( output, "-%04d\n", SML[i]);
			else
			 	fprintf( output, "+%04d\n", SML[i]);
	}

}
