#include <ctype.h>
int isoperator(char ch)
{
    if( (ch == '+')||(ch == '-')||(ch == '*')||(ch == '/')||
        (ch == '=')||(ch == '!')||(ch == '>')||(ch == '<'))
        return 1;
    else
        return 0;
}

void addSpaces(char *tok, char expr[20], int lineno)
{
	
    int tkn_ind=0, exprsn_ind=0,l =strlen(tok);

            while( l-- )
            {      
			        int n =0;
                   

                    if(isoperator(tok[tkn_ind]))
                    {       
                        expr[exprsn_ind++] = tok[tkn_ind++];
			if(tok[tkn_ind] != '=')
				expr[exprsn_ind++] =' ';
                    }
		    else if((tok[tkn_ind]>='a')&&(tok[tkn_ind]<='z'))
                    {       
                        expr[exprsn_ind++] = tok[tkn_ind++];
                        expr[exprsn_ind++] =' ';
                    }
                    else if(isdigit(tok[tkn_ind]))
                    {   
                        while(isdigit(tok[tkn_ind]))   
                            expr[exprsn_ind++] =tok[tkn_ind++];
                        
                        expr[exprsn_ind++] =' ';
                    }
                    else if(tok[tkn_ind] == ' ' || tok[tkn_ind] == '\n' || tok[tkn_ind] == '\0')
                    {  
                        //...do nothing
                    }
                    else
                    { 
                        printf("Syntax Error: Invalid identifier at Line no. %d\n", lineno );
                         printf("%s \n", tok );
                         exit(0);
                    }
                            
            }
                    expr[exprsn_ind] = '\0';
                     
}

void getTokens(FILE *input,char Token[SIZE][5][LINESIZE],int *lastline)
{
       
        char line[LINESIZE], expr[LINESIZE], del[4]=" \n\0";
        char *tok, *postfix;
       
        
        int j, i =*lastline;
        while( fgets(line, LINESIZE, input))
        {   
               
                j = 0;
                
                tok = strtok(line, del);
                //line no
                strcpy(Token[i][j++],tok);
                if( myAtoi(Token[i][0]) <= myAtoi(Token[i-1][0]) && i>0)
                {   //printf("%s",line );
                    printf("Syntax Error: Invalid line no. Line no. :%d\n", i+1);
                    exit(0);
                }
                // Token[i][j++] = tok;   
        
                tok = strtok(NULL, del);
                //keywords
                strcpy(Token[i][j++],tok);

                tok = strtok(NULL, del);
         
                if( !strcmp(Token[i][j-1], "let"))
		{
			addSpaces(tok,expr, i+1);
                        postfix=infixToPostfix(expr);
                        strcpy(Token[i][j++],postfix);
		}
		else if(!strcmp(Token[i][j-1], "input")
                    || !strcmp(Token[i][j-1], "print") || !strcmp(Token[i][j-1], "goto")) 
                {  
                        addSpaces(tok,expr, i+1);
                        strcpy(Token[i][j++],expr);
			if( strlen(expr) > 2 &&  strcmp(Token[i][j-2], "goto") )
			{
				 printf("Syntax Error: Line Termination - %s  at Line no. :%s\n", expr, Token[i][0]);
                         	 exit(0);
			}
        
                }
                else if(!strcmp(Token[i][j-1], "if"))
                {
                        addSpaces(tok,expr, i+1);
                        tok = strtok(NULL, del);
                        if(strcmp(tok,"goto"))
                        {
                            printf("Error: goto+branchaddress not present at line no. %d ", i+1);
                            exit(0);
                        }     
                        else
                        {       
                                strcpy(Token[i][3],"goto");
                                tok = strtok(NULL, del);
                                strcpy(Token[i][4],tok);
                        } 
                        postfix=infixToPostfix(expr);
                        strcpy(Token[i][2],postfix);
                        //goto
        
                }
                else if(!strcmp(Token[i][j-1], "end\n") || !strcmp(Token[i][j-1], "end"))
                {
                        //..do nothing
                }
		else if(!strcmp(Token[i][j-1], "rem\n") || !strcmp(Token[i][j-1], "rem"))
		{       //IGNORE REST OF COMMENT
			 i++;   
			 continue;
		}
                else
		{
                        printf("Syntax Error: Wrong keyword - %s  at Line no. :%d\n",Token[i][j-1], i+1);
                        exit(0);
                }

		char *empty = strtok(NULL,del);
		if( empty != NULL )
		{
			 printf("Syntax Error: Line Termination - %s  at Line no. :%s\n", empty, Token[i][0]);
                         exit(0);	
		}

                i++;     

               
        }  
            *lastline = i; 

}
