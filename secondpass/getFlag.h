int getLineSymbolIndex(int val,SymT symbolTable[SIZE])
{
	int count = 0;
	for(int i =0; i< SIZE;i++)
	{	
		if(symbolTable[i].symbol == val && symbolTable[i].type == 'L')
			break;
		if(symbolTable[i].type == 'L')
			count++;
	}
	return count;
}

int getFlag(int index,SymT symbolTable[SIZE])
{
	for(int i =0; i< SIZE; i++)
	{	if(symbolTable[i].location  == index+1 && symbolTable[i].type == 'L')
			return getLineSymbolIndex(symbolTable[i].symbol, symbolTable);
		//we have to add the line no. present at the end of the returning value
	}
	return -1;
}

