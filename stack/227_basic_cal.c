/*
227. Basic Calculator II

Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.
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


int calculate(char* s) {
#if 1
    int len = strlen(s);
    int *stack = (int*) malloc(sizeof(int)*(len+1));
    int ans = 0;
    int num = 0;
    int top = -1;
    char sign = '+';
    for(int i = 0;i<len;i++){
        if(isdigit(s[i])){
            num = num*10+s[i] -'0';
        }//else if(isspace(s[i])){
        //    stack[++top] = num;
        //    num = 0;
        //    continue;
        //}else if(i == (len-1)){// last number 
        //    stack[++top] = num;
        //} 
        if(s[i] =='+' ||s[i] =='-' ||s[i]=='*'||s[i]=='/'||i==(len-1)){
            //stack[++top] = num;
            //num = 0;
            if(sign == '+'){
                stack[++top] = num;
            }else if(sign == '-'){
                stack[++top] = (-1)*num;
            }else if(sign == '*'){
                int val = stack[top--];
                stack[++top] = val*num; 
            }else if(sign == '/'){ // s[i] == '/'
                int val = stack[top--];
                stack[++top] = val/num;
            }
            num = 0;
            sign = s[i];
        }
    }
    for(int i =0;i<top+1;i++){
        //printf("%d\n",stack[i]);
        ans+=stack[i];
    }

    if(stack)
        free(stack);
    return ans;
#else
    char *postfix = (char*)malloc(sizeof(char)*(strlen(s)+1));
    char *stack = (char*)malloc(sizeof(char)*(strlen(s)+1));
    int top = -1;
    int idx = 0;
    for(int i = 0;i<strlen(s);i++){
        if((s[i]=='+') ||(s[i] =='-')){
            if(top != -1){
                //stack[++top] = s[i];
                postfix[idx++] = stack[top--];
            }
            stack[++top] = s[i];
        }else if((s[i]=='*')|| (s[i]=='/')){
            if(top != -1){
                if(stack[top] == '*' || stack[top] == '/'){
                    postfix[idx++] = stack[top--];
                    stack[++top] = s[i];
                }
            }
            stack[++top] = s[i];

        }else if(s[i] ==' '){
            //ignore space
        }else{
            postfix[idx++] = s[i];
        }
    }
   
    while(top!=-1){
        postfix[idx++]=stack[top--];
    }
    postfix[idx] ='\0';
    if(stack)
        free(stack);

    int *st = (int*) malloc(sizeof(int)*(strlen(postfix)+1));
    idx = 0;
    top = -1;
    //st[++top] = atoi(postfix[idx++]);
    st[++top] = postfix[idx++] - 48;
    while((idx<strlen(postfix))&&(top!=-1)){
        if(postfix[idx] =='+'){
            int val2 = st[top--];
            int val1 = st[top--];
            st[++top] = val1+val2;            
        }else if (postfix[idx] =='-'){
            int val2 = st[top--];
            int val1 = st[top--];
            st[++top] = val1-val2; 
        }else if (postfix[idx] == '*'){
            int val2 = st[top--];
            int val1 = st[top--];
            st[++top] = val1*val2;             
        }else if (postfix[idx] =='/'){
            int val2 = st[top--];
            int val1 = st[top--];
            st[++top] = val1/val2;
        }else{
             //st[++top] = atoi(postfix[idx++]);
             st[++top] = postfix[idx] - 48;
        }
        idx++;
    }


    printf("%s\n",postfix);
    int ans = st[top];
    printf("top=%d\n",top);
    if(postfix)
        free(postfix);
    if(st)
        free(st);
    return ans;
#endif    
}


int main(int argc, char** argv)
{
    //char *exp ="3+2*2";
    //char *exp = "1+2*2-3";
    //char *exp = "3/2";
    char *exp = "3+5 / 2";
    printf("%s\n",exp);
    int ans = calculate(exp);
    printf("ans =%d\n",ans);
    return 0;
}