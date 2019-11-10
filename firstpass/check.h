
int check(struct tableEntry symbolTable[SIZE], int variable, char type)		
{

	for(int i=0; i<SIZE; i++)
	{
		if(symbolTable[i].symbol == variable && symbolTable[i].type == type)
			return 0;
	}
	return 1;
}



