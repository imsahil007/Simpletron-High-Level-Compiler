#include "header.h"


void saveSMLfile(int SML[SIZE], FILE *output,int occupiedmemory);

int compressSML(int SML[SIZE]);

void solveReferences(int flag[SIZE],int SML[SIZE],SymT symbolTable[SIZE], char Token[SIZE][5][LINESIZE]);

void secondPass(int flag[SIZE],int SML[SIZE], FILE *output,char Token[SIZE][5][LINESIZE],SymT symbolTable[SIZE])
{

	solveReferences(flag, SML, symbolTable, Token);
	int occupiedmemory =compressSML(SML);
	//int occupiedmemory =100;
	saveSMLfile(SML,output,occupiedmemory); 
	printf("\n***************\n");
	printf("\nCompiled successfully!\n");
	printf("\n***************\n");
}
