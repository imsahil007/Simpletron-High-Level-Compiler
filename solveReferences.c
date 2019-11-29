#include "header.h"
void addbranchloc(int *SML,int *flag,int branch_loc);
int getFlag(int index,SymT symbolTable[SIZE]);
int myAtoi(char *);
int getLocation(struct tableEntry symbolTable[SIZE], int line_no);

void solveReferences(int flag[SIZE],int SML[SIZE],SymT symbolTable[SIZE], char Token[SIZE][5][LINESIZE])
{	
	int line_no, offset, branch_loc;
	for(int j=0;j<SIZE;j++)
		{	if(flag[j] ==0)
			{
				if(SML[j]/SIZE == BRANCH)	//GOTO
					offset = 2;
				else         			//if goto
					offset = 4;
						//changing address

				line_no = getFlag(j,symbolTable);
				if(line_no != -1)			//normal goto
				{	branch_loc = getLocation(symbolTable,myAtoi(Token[line_no-1][offset]));
					addbranchloc(&SML[j], &flag[j], branch_loc);
				}
				else
				{	
					line_no = getFlag(j+1,symbolTable);		// in case of 2 jump statement like i.e. (!=)
					if(line_no != -1)
					{	branch_loc = getLocation(symbolTable,myAtoi(Token[line_no-1][offset]));
						addbranchloc(&SML[j], &flag[j], branch_loc);
						j++;
						addbranchloc(&SML[j], &flag[j], branch_loc);
					}
					else						//consecutive 2 jump statements i.e (<=) or (>=)
					{	line_no = getFlag(j+3,symbolTable);
						branch_loc = getLocation(symbolTable,myAtoi(Token[line_no-1][offset]));
						addbranchloc(&SML[j], &flag[j], branch_loc);
						j += 3;
						addbranchloc(&SML[j], &flag[j], branch_loc);
					}				
				}
		
					
			}	
		}

}
