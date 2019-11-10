void initialize(SymT symbolTable[SIZE], int flag[SIZE],int SML[SIZE])
{
	for(int i=0; i < SIZE; i++)
	{
		flag[i] = -1;
		symbolTable[i].symbol = 0;
		symbolTable[i].location = 0;
		symbolTable[i].type = ' '; //no need
		SML[i]=0;
	}
}
