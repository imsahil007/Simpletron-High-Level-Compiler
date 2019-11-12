#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "OtherFunctions/header.h"
#include "OtherFunctions/functions.h"
#include "OtherFunctions/getFileExtension.h"
int main(int argc , char *argv[])
{
	FILE *input = NULL;
	FILE *output = NULL;
	int flag[SIZE];
 	int SML[SIZE]={},lastline, instructionCounter;
 	SymT symbolTable[SIZE];
	
	if(argc != 3)
	{	printf("Invalid arguments!\n");
		exit(0);
	}
	else{		
		if( !getFileExtension(argv[1], 0) )	
		{	printf("Invalid input file extension!(Extension: .shl)\n");
			exit(0);
		}
		else if( !getFileExtension(argv[2], 1) )
		{	printf("Invalid output file extension!(Extension: .sml)\n");
			exit(0);
		}
		input = fopen(argv[1], "r");
		output = fopen(argv[1], "w");
	}
	
	
	if(input == NULL)
    	{
		printf("Unable to open the input file!");
		exit(0);
    	}

    	initialize(symbolTable, flag, SML);
    	char Token[SIZE][5][LINESIZE] ;
  	firstPass(input, Token, symbolTable, SML, flag, &lastline );
  	secondPass(flag, SML, output, Token, symbolTable);
	fclose(input);
	fclose(output);    
}
