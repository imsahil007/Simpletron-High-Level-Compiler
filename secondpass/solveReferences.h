void solveReferences(int flag[SIZE],int SML[SIZE],SymT symbolTable[SIZE], char Token[SIZE][5][LINESIZE])
{	
	int line_no, offset;
	for(int j=0;j<SIZE;j++)
		{	if(flag[j] ==0)
			{
				if(SML[j]/SIZE == BRANCH)	//GOTO
					offset = 2;
				else         			//if goto
					offset = 4;
						//changing address

				line_no = getFlag(j,symbolTable);
				if(line_no==-1)
				{	
					line_no = getFlag(j+3,symbolTable);		//2 jump statement ==
					if(line_no == -1)
						line_no	=getFlag(j+1,symbolTable);	//<= or >=
					else
						printf("ERROR!\n");	
				}
		
				SML[j] = (SML[j] /SIZE);			
				SML[j] =  SML[j] * SIZE + getLocation(symbolTable,myAtoi(Token[line_no-1][offset]));
	
			}	
		}

}

