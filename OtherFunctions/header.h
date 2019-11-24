
#define SIZE 1000
#define LINESIZE 40 


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
typedef struct tableEntry SymT;

struct tableEntry
{
	int symbol;
	char type;
	int location;	/*00 to SIZE-1*/	//SML LOCATION
};

typedef struct Stack ops_stack;
struct Stack
{
    int location; //this will store the memory location of the data that the program needs
    ops_stack * next;
};

