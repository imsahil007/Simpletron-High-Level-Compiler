#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"
#include "functions.h"

int main(int argc , char *argv[])
{
	FILE *input = NULL;
	FILE *output = NULL;
	int flag[SIZE];
 	int SML[SIZE]={},lastline, instructionCounter;
 	SymT symbolTable[SIZE];
	if(argc != 3)
	{	
		printf("Invalid arguments\n");
		return 0;
	}


	input = fopen(argv[1], "r");
	output = fopen(argv[2], "w");
	
	if(input == NULL)
    	{
		printf("Unable to open the input file!");
		return 1;
    	}
    
    	initialize(symbolTable, flag, SML);
    	char Token[SIZE][5][LINESIZE] ;
  	firstPass(input, Token, symbolTable, SML, flag, &lastline );
  	secondPass(flag, SML, output, Token, symbolTable);
	fclose(input);
	fclose(output);    
}
