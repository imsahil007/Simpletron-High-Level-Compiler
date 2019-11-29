#include "header.h"
void getTokens(FILE *input,char Token[SIZE][5][LINESIZE],int *lastline);
void fillSymbolTable(char Token[SIZE][5][LINESIZE], SymT symbolTable[SIZE],int SML[SIZE], int flag[SIZE], int *lastline);
void initialize(SymT symbolTable[SIZE], int flag[SIZE],int SML[SIZE]);

 void firstPass(FILE *input, char Token[SIZE][5][LINESIZE],SymT symbolTable[SIZE],int SML[SIZE],int flag[SIZE],int *lastline)
 {
 	getTokens(input, Token, lastline);
 	fillSymbolTable(Token, symbolTable,SML, flag, lastline);   
 	//SHL TO SML conversion is called in fillSymbolTable
 }

