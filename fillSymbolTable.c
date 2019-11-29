#include "header.h"
void addExpression(char *s, SymT symbolTable[SIZE] ,int *count, int *var,int SML[SIZE],int instructionCounter);
int myAtoi(char *);
void shlToSML(char Token[SIZE][5][LINESIZE], SymT symbolTable[SIZE],int SML[SIZE], int flag[SIZE] ,int i, int *count, int *instructionCounter,int *var);

void fillSymbolTable(char Token[SIZE][5][LINESIZE], SymT symbolTable[SIZE],int SML[SIZE], int flag[SIZE], int *lastline)
{

	int  instructionCounter = 0,count =0;		//no. of symbols
	// int loc = 0;	//location of inst
	int var=SIZE -1;
	for(int i =0; i <(*lastline); i++)		//loop for one line
	{	
			symbolTable[count].symbol =  myAtoi(Token[i][0]);
			symbolTable[count].type = 'L';
			symbolTable[count].location = instructionCounter;
			count++;
			//adding line number
			if(!strcmp(Token[i][1],"rem"))
			{	
					continue;
			}
			else if((!strcmp(Token[i][1],"input")) ||  (!strcmp(Token[i][1],"let")))
					addExpression(Token[i][2], symbolTable , &count, &var, SML,instructionCounter);
			else if(!strcmp(Token[i][1],"if"))	
			{		addExpression(Token[i][2], symbolTable , &count, &var, SML,instructionCounter);			
			}
			else if(!strcmp(Token[i][1],"goto"))
			{	//address of goto is not resolved..2nd pass	
					if(i < myAtoi(Token[i][2]))
							flag[instructionCounter] = 0;
					else if(i == myAtoi(Token[i][2]))
					{
							printf("Error! Infinite Loop at Line no. %d\n ",i+1);
							exit(0);
					}
					else if(myAtoi(Token[i][2]) > (*lastline))
					{
							printf("Error! Branching to line which is not valid. %d\n ",i+1);
							exit(0);
					}
			}
			else if(!strcmp(Token[i][1],"print"))
					addExpression(Token[i][2], symbolTable , &count, &var, SML,instructionCounter);	
			shlToSML(Token, symbolTable,SML, flag ,i, &count, &instructionCounter, &var );
			
	}	
}
