/*
150. Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>			// File Control Definitions.
#include <termios.h>		// POSIX Terminal Control Definitions.
#include <unistd.h>			// UNIX Standard Definitions.
#include <errno.h>			// ERROR Number Definitions.
#include <pthread.h>
#include <sys/select.h>
#include <sys/time.h>
#include <signal.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int evalRPN(char** tokens, int tokensSize) {

    int *stack = (int*) malloc(sizeof(int)*(tokensSize+1));
    int top = -1;
    int idx = 0;
    stack[++top] = atoi(tokens[idx++]);
    while((idx<tokensSize)&&(top!=-1)){
        char *ch = tokens[idx++];
        //printf("%s top =%d idx =%d\n",ch,top,idx);
        if(!strcmp(ch,"+")){
            int val2 = stack[top--];
            int val1 = stack[top--];
            stack[++top] = val1+val2;

        }else if(!strcmp(ch,"-")){
            if(top == 0){
                int val2 = stack[top--];
                stack[++top] = 0-val2;
            }else{
                int val2 = stack[top--];
                int val1 = stack[top--];
                stack[++top] = val1-val2;                
            }
        }else if(!strcmp(ch,"*")){
            int val2 = stack[top--];
            int val1 = stack[top--];
            stack[++top] = val1*val2;            
        }else if(!strcmp(ch,"/")){
            int val2 = stack[top--];
            int val1 = stack[top--];
            stack[++top] = val1/val2;            
        }else{
            stack[++top] = atoi(ch);
        }
    }
    //printf("top =%d\n",top);
    int ans = stack[top];
    if(stack)
        free(stack);
    return ans;
}


int main(int argc, char** argv)
{
    //char *token[] = {"2","1","+","3","*"};
    char *token[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int tksize = sizeof(token)/sizeof(char*);
    printf("tksize=%d\n",tksize);
    for(int i = 0;i<tksize;i++){
        printf("%s ",token[i]);
    }
    printf("\n");

    int ans = evalRPN(token,tksize);
    printf("ans =%d\n",ans);

    return 0;
}