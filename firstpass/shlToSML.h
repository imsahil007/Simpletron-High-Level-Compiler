

void shlToSML(char Token[SIZE][5][LINESIZE], SymT symbolTable[SIZE],int SML[SIZE], int flag[SIZE] ,int i, int *count, int *instructionCounter,int *var)
{

	int opcode=0, operand=0 ;
 	
			if(!strcmp(Token[i][1],"let")) 	
			{			
					postfix_SML(symbolTable, Token[i][2], SML ,instructionCounter, flag, -1 ,var );
					return;
			}					// Token[i][2]  postfix expression
			else if(!strcmp(Token[i][1],"input"))
			{		opcode = READ;
					for(int j=SIZE-1 ; j>=0 ; j--)
					{
						   	if(symbolTable[j].symbol == (int)Token[i][2][0] )
						   	{		operand = symbolTable[j].location;//comparing ASCII values
									break;
							}
					}
					SML[ (*instructionCounter)++ ] = (opcode * SIZE) + operand;
			}
			else if(!strcmp(Token[i][1],"rem"))
			{		//do nothing
					return;
			}
			else if(!strcmp(Token[i][1],"if"))		
			{		int branchaddress = getLocation(symbolTable , myAtoi(Token[i][4]))  ;
					postfix_SML(symbolTable, Token[i][2], SML , instructionCounter, flag, branchaddress , var );
										// Token[i][2]  postfix expression
			}
			else if(!strcmp(Token[i][1],"goto"))
			{		int branchaddress = getLocation(symbolTable , myAtoi(Token[i][2]));
					// branchaddrs=0 if unresolved
					operand=branchaddress;
					if(branchaddress == -1)
						operand=0;
					opcode=BRANCH;
					
					//printf("%d",operand);
					SML[ (*instructionCounter)++ ] = (opcode * SIZE) + operand;
				
			}
			else if(!strcmp(Token[i][1],"print"))
			{	 	opcode = WRITE;
					for(int j=SIZE-1 ; j>=0 ; j--)
					{
							if((symbolTable[j].symbol == myAtoi(Token[i][2])
								&& symbolTable[j].type=='C') ||
								(symbolTable[j].symbol == (int)(Token[i][2][0])
								&& symbolTable[j].type=='V'))
							{		
									operand = symbolTable[j].location;//comparing ASCII values
								    break;
							 }
							
					}
					SML[ (*instructionCounter)++ ] = (opcode * SIZE) + operand;

			}
			else if(!strcmp(Token[i][1],"end\n") || !strcmp(Token[i][1], "end"))
			{	 	opcode=HALT;
					operand=00;
					SML[ (*instructionCounter)++ ] = (opcode * SIZE) + operand;
			}
}
		
