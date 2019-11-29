#include "header.h"

//the function that pushes a new element with location = loc at the top of our stack
ops_stack * push(ops_stack * stHead, int loc)
{
    ops_stack * newElement = malloc(sizeof(ops_stack));
    newElement->location = loc;
    newElement->next = stHead;
    return newElement;
}


//the function that pops an element from the top of our stack
//and modifies the symbol to the pointer popLocation to the location symbol that is just popped
ops_stack * pop(ops_stack * stHead, int * popLocation)
{
    if(stHead == NULL)
    {
        return NULL;
    }
    ops_stack * element = stHead;
    * popLocation = stHead->location;
    stHead = stHead->next;
    free(element);
    return stHead;
}


// the function to return the location of a variable after checking it in the SymTbol table
int get_location(SymT * SymTbol_table, char token[], char symbol_type)
{
  for(unsigned int i = 0; i < SIZE; i++)
  {
    if(SymTbol_table[i].type == symbol_type && SymTbol_table[i].symbol == atoi(token) || SymTbol_table[i].symbol == *token)
      return SymTbol_table[i].location;
  }
  return -1;
}




//Postfix to SML function
void postfix_SML(SymT * SymTbol_table, char *ps, int * mem,  int * instruct_counter, int * flag,  int branch_symbol, int * data_counter)
{
    //The function prototypes for the functions used in this module
    char postfix_string[20];
    int z;
    for( z =0; z<strlen(ps); z++)
        postfix_string[z]=ps[z];
    postfix_string[z]='\0';
    ops_stack * push(ops_stack *, int);
    ops_stack * pop(ops_stack *, int *);
    int get_location(SymT *, char [], char);

    char * token; //char pointer to store tokens, which are simlpy strings
    ops_stack *st = NULL; //initializing our calculations stack

    int loc, loc1, loc2;
   
   
    //Tokenizing the postfix expression by using strtok will work only when the postfix_string
    //is stored as a charcter array. If passed as a pointer, first convert it to char array before proceeding.

    //considering whitespace as a delimiter -
    //begin tokenizing
    token = strtok(postfix_string, " ");
    while(token != NULL)
    {
        if(*data_counter <= *instruct_counter)
        {
            puts("OUT OF MEMORY!");
            return;
        }

        if(isalpha(*token)) // If we encounter a variable
        {


	    loc = get_location(SymTbol_table, token, 'V');

            //Pushing the loc onto our calculations stack
            st = push(st, loc);
        }

	int check = 1, k = 0;
	//Checking for a constant
	while(token[k] != '\0')
	{
	    if(!isdigit(token[k]))
	    {
	        check = 0;
		break;
	    }
	    k++;
	}
	if(check == 1)
	{
	    loc = get_location(SymTbol_table, token, 'C');

	    //Pushing the location onto our calculations stack
	    st = push(st, loc);
	}


        if(ispunct(*token)) // If we encounter an operator
        {
            //popping the top element of the stack and storing the result in loc2
            st = pop(st, &loc2);
            //popping the top element of the stack and storing the result in loc1
            st = pop(st, &loc1);
            //Addition

            if(!strcmp(token, "+"))
            {
                mem[*instruct_counter] = 20 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 30 * SIZE + loc2;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 21 * SIZE + *data_counter;
                *instruct_counter = *instruct_counter + 1;

                st = push(st, *data_counter);
                *data_counter = *data_counter - 1;
            }
            else if(!strcmp(token, "-"))
            {
            //Subtraction
                mem[*instruct_counter] = 20 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 31 * SIZE + loc2;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 21 * SIZE + *data_counter;
                *instruct_counter = *instruct_counter + 1;

                st = push(st, *data_counter);
                *data_counter = *data_counter - 1;
            }
            else if(!strcmp(token, "*"))
            //Multiplication
            {
	      mem[*instruct_counter] = 20 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 33 * SIZE + loc2;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 21 * SIZE + *data_counter;
                *instruct_counter = *instruct_counter + 1;

                st = push(st, *data_counter);
                *data_counter = *data_counter - 1;
            }
            else if(!strcmp(token, "/"))
            //Division
            {
                mem[*instruct_counter] = 20 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 32 * SIZE + loc2;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 21 * SIZE + *data_counter;
                *instruct_counter = *instruct_counter + 1;

                st = push(st, *data_counter);
                *data_counter = *data_counter - 1;
            }
           else if(!strcmp(token, "="))
            //Assignment
            {
                
                mem[*instruct_counter] = 20 * SIZE + loc2;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 21 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                
            }
            else if(!strcmp(token, ">"))
            //Greater than
            {
                mem[*instruct_counter] = 20 * SIZE + loc2;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 31 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                if(branch_symbol == -1)
                {   flag[*instruct_counter] = 0; 
			branch_symbol=0;
		}
                mem[*instruct_counter] = 41 * SIZE + branch_symbol;
                *instruct_counter = *instruct_counter + 1;
            }
            else if(!strcmp(token, ">="))
            //Greater than or equals to
            {
                mem[*instruct_counter] = 20 * SIZE + loc2;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 31 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                if(branch_symbol == -1)
                {   flag[*instruct_counter] = 0; 
			branch_symbol=0;
		    flag[*instruct_counter+1] = 0; 
		}

                mem[*instruct_counter] = 41 * SIZE + branch_symbol;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 42 * SIZE + branch_symbol;
                *instruct_counter = *instruct_counter + 1;
            }
            else if(!strcmp(token, "<"))
            //Lesser than
            {
                mem[*instruct_counter] = 20 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 31 * SIZE + loc2;
                if(branch_symbol == -1)
                {   flag[*instruct_counter+1] = 0; 
			branch_symbol=0;
		}

                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 41 * SIZE + branch_symbol;
                *instruct_counter = *instruct_counter + 1;
            }
            else if(!strcmp(token, "<="))
            //Lesser than or equals to
            {
                mem[*instruct_counter] = 20 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 31 * SIZE + loc2;
                *instruct_counter = *instruct_counter + 1;
                if(branch_symbol == -1)
                {   flag[*instruct_counter] = 0; 
			branch_symbol=0;
		    flag[*instruct_counter+1] = 0; 
		}

                mem[*instruct_counter] = 41 * SIZE + branch_symbol;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 42 * SIZE + branch_symbol;
                *instruct_counter = *instruct_counter + 1;
            }
            else if(!strcmp(token, "=="))
            //equals
            {
                mem[*instruct_counter] = 20 * SIZE + loc2;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 31 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                if(branch_symbol == -1)
                {   flag[*instruct_counter] = 0; 
			branch_symbol=0;
		}

                mem[*instruct_counter] = 42 * SIZE + branch_symbol;
                *instruct_counter = *instruct_counter + 1;
            }
            else
            //not equals to
            {
                mem[*instruct_counter] = 20 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 31 * SIZE + loc2;
                *instruct_counter = *instruct_counter + 1;
                if(branch_symbol == -1)
                {   flag[*instruct_counter] = 0; 
			branch_symbol=0;
		    flag[*instruct_counter+3] = 0; 
			
		}

                mem[*instruct_counter] = 41 * SIZE + branch_symbol;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 20 * SIZE + loc2;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 31 * SIZE + loc1;
                *instruct_counter = *instruct_counter + 1;
                mem[*instruct_counter] = 41 * SIZE + branch_symbol;
                *instruct_counter = *instruct_counter + 1;
            }
        }

        token = strtok(NULL, " ");
    }
}
