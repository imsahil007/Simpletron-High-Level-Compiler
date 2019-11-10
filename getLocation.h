
int getLocation(struct tableEntry symbolTable[SIZE], int line_no)		
{
	//if flag[inst]=0 by default location will be 0
	for(int i=0; i<SIZE; i++)
	{	
		if(symbolTable[i].symbol == line_no && symbolTable[i].type == 'L')	
			return (symbolTable[i].location);	//will return inst line position
	}
	
	return -1;
}
