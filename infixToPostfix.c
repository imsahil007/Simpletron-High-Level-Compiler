#include "header.h"
typedef struct stack Stack;
struct stack
{
    char * data;
    Stack * next;
};

Stack * pushx(Stack * stHead, char *d)
{
    Stack * newNode = malloc(sizeof(Stack));
    newNode->data = d;
    newNode->next = stHead;
    return newNode;
}

Stack * popx(Stack *stHead, char **popxData)
{
    if(stHead == NULL)
    {
	return NULL;
    }
    Stack *node = stHead;
    *popxData = stHead->data;
    stHead = stHead->next;
    free(node);
    return stHead;
}

char * getTop(Stack *stHead)
{
    return stHead->data;
}

int Prec(char[]);
Stack *pushxtoPostfix(Stack* , char* , int* , char* );

char* infixToPostfix(char infx[])
{
        Stack* sT = NULL;
        int i = 0 ,k ;
        char* pstfx = malloc(sizeof(char) * SIZE);
        char *token, *temp;
        token = strtok(infx, " ");  
        
        while (token != NULL)
        {
                if (isalpha(token[0]) || isdigit(token[strlen(token)-1]))
                {
                    k = 0;
                        while(token[k] != '\0')
                        {
                                pstfx[i] = token[k];
                                k++;
                                i++;
                        }
                        pstfx[i++]= ' ';
                }
                else
                {
                    if (sT != NULL)
                    {
                        if(Prec(getTop(sT)) >= Prec(token))
                        {
                            while (sT != NULL && Prec(getTop(sT)) >= Prec(token))
                            {
                    
                                sT  = pushxtoPostfix(sT , pstfx , &i , token );
                            }
                                sT = pushx(sT , token);
                        }
                        else
                                sT = pushx(sT , token);
                    }
                    else
                            sT = pushx(sT , token);
                }
                
            token = strtok(NULL , " ");
        }
        while (sT != NULL)
        {
            sT =  pushxtoPostfix(sT , pstfx , &i , token );  
        }
        pstfx[i - 1] = '\0';
        
      

     return pstfx;
        
}
int Prec(char ch[]) 
{ 
    if (!(strcmp(ch , "*") && strcmp(ch , "/")))
            return 5;
    else if (!(strcmp(ch , "+") && strcmp(ch , "-"))) 
        return 4;
    else if (!(strcmp(ch , "<") && strcmp(ch , ">") && strcmp(ch , "<=") && strcmp(ch , ">=")))
            return 3;
    else if (!(strcmp(ch , "==") && strcmp(ch , "!=")))
                return 2;
    else if (!(strcmp(ch , "=")))
                    return 1;
    else                
        return -1; 
} 

Stack *pushxtoPostfix(Stack *stk , char *pstfx ,int* i , char *token )
{
    int k;
    char *temp;
    stk = popx(stk , &temp);
    k = 0;
    while(temp[k] != '\0')
    {
        pstfx[*i] = temp[k];
        k++;
        (*i)++;
    }
    pstfx[(*i)++]= ' ';
    return stk;
}
