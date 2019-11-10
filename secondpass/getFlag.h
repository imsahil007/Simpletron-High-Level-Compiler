int getFlag(int index,SymT symbolTable[SIZE])
{
	for(int i =0; i< SIZE; i++)
	{	if(symbolTable[i].location  == index+1 && symbolTable[i].type == 'L')
			return symbolTable[i].symbol -1 ;
		//we have to add the line no. present at the end of the returning value
	}
	return -1;
}