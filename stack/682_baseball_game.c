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

typedef struct snode_tag{
    int val;
    struct snode_tag *next;
}snode_t,*psnode_t;

void push(psnode_t *st,int val);
bool isempty(psnode_t st);
int pop(psnode_t *st);
int top(psnode_t st);
void print_stack(psnode_t st);
void freest(psnode_t st);

void push(psnode_t *st,int val)
{
    psnode_t node = (psnode_t)malloc(sizeof(struct snode_tag));
    node->val = val;
    node->next = NULL;
    //empty stack
    if(*st == NULL){
        *st = node;
        return;
    }
    node->next = *st;
    *st=node;
}
bool isempty(psnode_t st)
{
    return st==NULL?true:false;
}
int top(psnode_t st)
{
    return st->val;
}
int pop(psnode_t *st)
{
    psnode_t topn = *st;
    int val = topn->val;
    *st=topn->next;
    free(topn);
    return val;
}
void print_stack(psnode_t st)
{
    printf("=======\n");
    while(st){
        printf("val=%d\n",st->val);
        st=st->next;
    }
    printf("=======\n");
}

void freest(psnode_t st)
{
    while(st){
        psnode_t temp = st;
        st=st->next;
        free(temp);
    }
}

int calPoints(char** operations, int operationsSize) {
    psnode_t stack = NULL;
    for (int i =0;i<operationsSize;i++){
        printf("%s\n",operations[i]);
        if(strcmp(operations[i],"+" )==0){
        //if(operations[i]=='+' ){
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            push(&stack,val1);
            push(&stack,val2);
            push(&stack,val1+val2);

        }else if(strcmp(operations[i],"D" )==0){
        //}else if(operations[i]=='D'){            
            int val1 = pop(&stack);
            push(&stack,val1);
            push(&stack,val1*2);
        
        }else if(strcmp(operations[i],"C" )==0){
        //}else if(operations[i]=='C'){            
            int val=pop(&stack);
            //printf("remove %d\n",val);
        
        }else{
            push(&stack,atoi(operations[i]));
        }
    }
    print_stack(stack);
    int sum = 0;
    psnode_t sth = stack;
    while(sth){
        sum+=sth->val;
        sth=sth->next;
    }
    freest(stack);
    return sum;
}



int main(int argc, char** argv)
{

       //char *a = "-100";

    //printf("%d\n",atoi(a));
    char *op[] = {"5","-2","4","C","D","9","+","+"};
    printf("op size=%ld\n",sizeof(*op));
    int sum = calPoints(op,sizeof(*op));
    printf("sum =%d\n",sum);
    return 0;
}