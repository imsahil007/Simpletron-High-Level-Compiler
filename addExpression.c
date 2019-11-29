#include "header.h"
int check(struct tableEntry symbolTable[SIZE], int variable, char type);
void checkvar(int SML[SIZE], int *var, int instructionCounter)		
{

	for(int i=0; i<= instructionCounter; i++)
	{
		if(SML[i]%SIZE == *var)
		{	(*var)--;
			return;
		}
	}
}

void addExpression(char *s, SymT symbolTable[SIZE] ,int *count, int *var,int SML[SIZE],int instructionCounter)		
{

	for(int j =0; j < strlen(s); j++)
	{	char ch=s[j];
		if( (ch != '+') && (ch != '-') && (ch != '*') && (ch != '/') && 
			(ch != ' ') && (ch != '=') && (ch != '<')&& (ch != '>')&& (ch != '!'))
			{
				if(ch >= 'a' && ch <= 'z')
				{	if(check(symbolTable, (int) ch,'V'))
					{
						symbolTable[*count].symbol = (int) ch;
						symbolTable[*count].type = 'V';
						checkvar(SML, var, instructionCounter);
						symbolTable[*count].location = (*var);
						(*var)--;
						(*count)++;
		
					}
				}
				else if(ch >= '0' && ch <= '9')
				{
					int n = ch-'0';
					j++;
					while(s[j] >= '0' && s[j] <= '9')
					{
						n *= 10;
						n = n + s[j]-'0';
						j++;
					}
					
					if(check(symbolTable,  n,'C'))
					{
						
						symbolTable[*count].symbol =  n;
						symbolTable[*count].type = 'C';
						checkvar(SML, var, instructionCounter);
						symbolTable[*count].location = (*var);
						SML[*var] = n;
						(*var)--;
						(*count)++;
					}
				}
	
			}
	}
}

