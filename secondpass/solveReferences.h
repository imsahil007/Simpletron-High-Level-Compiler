void solveReferences(int flag[SIZE],int SML[SIZE],SymT symbolTable[SIZE], char Token[SIZE][5][LINESIZE])
{	
	int instruction_no=0, offset;
	for(int i=0 ; i < SIZE; i++)
	{	//i is line no. of unresolved SHL instruction
		if(flag[i] == 0)
		{
			instruction_no = getLocation(symbolTable, myAtoi( Token[i+1][0])) - 1;
			SML[instruction_no] = (SML[instruction_no] /SIZE);

			if(SML[instruction_no] == BRANCH)	//GOTO
				offset = 2;
			else         			//if goto
				offset = 4;
						//changing address
			SML[instruction_no] =  SML[instruction_no] * SIZE + getLocation(symbolTable,myAtoi(Token[i][offset]));
		}
	}
}
