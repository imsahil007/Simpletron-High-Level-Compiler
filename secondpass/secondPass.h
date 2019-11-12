
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

void secondPass(int flag[SIZE],int SML[SIZE], FILE *output,char Token[SIZE][5][LINESIZE],SymT symbolTable[SIZE])
{

	solveReferences(flag, SML, symbolTable, Token);
	int occupiedmemory =compressSML(SML);
	//int occupiedmemory =100;
	saveSMLfile(SML,output,occupiedmemory); 
	printf("\n***************\n");
	printf("\nCompiled successfully!\n");
	printf("\n***************\n");
}
