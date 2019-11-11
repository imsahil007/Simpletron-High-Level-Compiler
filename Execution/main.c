#include <stdio.h>
#include <stdlib.h>
#define SIZE 100


/*Macros for SML*/
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
/*Macros for SML*/
#define MAXRANGE (SIZE*SIZE*SIZE)
void main(int argc , char *argv[])
{

	int accumulator = 0;
	int opcode = 0;
	int operator = 0;
	int operand = 0;
	int instructionRegister = 0;
	int instructionCounter = 0;
	int memory[SIZE]={};
	if(argc != 2)
	{
		printf("Invalid arguments!\n");
		return;
	}
	FILE *f = NULL;
	f = fopen(argv[1], "r");
	if(f == NULL)
	{
		printf("Unable to open the file!\n");
		return;
	}	
	int i = 0;
	while( fscanf(f, "%d", &memory[ i++ ]) == 1);
	

	while(instructionCounter != SIZE-1)
	{
		

		instructionRegister = memory[instructionCounter];

		opcode = instructionRegister / SIZE;
		operand = instructionRegister % SIZE;

		switch(opcode)
		{
			case READ:		printf("Enter a value :\n");
							scanf("%d", &memory[operand]);
							if(memory[operand]/MAXRANGE != 0)
							{
								printf("*** memory overflow ***\n*** Simpletron execution abnormally terminated ***\n");
								return;
							}
							instructionCounter++;
							break;

			case WRITE:		printf("Output = %d\n", memory[operand]);
							instructionCounter++;
							break;

			case LOAD:		accumulator = memory[operand];
							instructionCounter++;
							break;
			case STORE:		memory[operand] = accumulator;
							instructionCounter++;
							break;

			case ADD:		accumulator += memory[operand];
							if(accumulator/MAXRANGE != 0)
							{
								printf("*** accumulator overflow ***\n*** Simpletron execution abnormally terminated ***\n");
								return;
							}
							instructionCounter++;
							break;

			case SUBTRACT:	accumulator -= memory[operand];
							if(accumulator/MAXRANGE != 0)
							{	
								printf("*** accumulator underflow ***\n*** Simpletron execution abnormally terminated ***\n");
								return;
							}
							instructionCounter++;
							break;

			case MULTIPLY:	accumulator *= memory[operand];
							if(accumulator/MAXRANGE != 0)
							{
								printf("*** accumulator overflow ***\n*** Simpletron execution abnormally terminated ***\n");
								return;
							}
							instructionCounter++;
							break;

			case DIVIDE:	accumulator /= memory[operand];
							if(memory[operand] == 0)
							{
									printf("\n*** Attempt to divide by zero ***\n*** Simpletron execution abnormally terminated ***\n");
									return;
							}
							if(accumulator/MAXRANGE != 0)
							{
								printf("*** accumulator overflow ***\n*** Simpletron execution abnormally terminated ***\n");
								return;
							}
							instructionCounter++;
							break;

			case BRANCH:	instructionCounter = operand;
							break;

			case BRANCHNEG:	if(accumulator < 0)
							{
								instructionCounter = operand;
							}
							else
							{
								instructionCounter++;
							}
							break;

			case BRANCHZERO:if(accumulator == 0)
							{
								instructionCounter = operand;
							}
							else
							{
								instructionCounter++;
							}
							break;
			case HALT:		printf("Simpletron execution terminated\n");
							return;
			default:
				printf("*** Insufficient memory! *** \n *** Simpletron execution abnormally terminated *** \n");
				exit(0);		
			}
	
	}
	fclose(f);

}

