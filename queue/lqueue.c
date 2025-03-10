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
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

typedef struct node_tag{
    int val;
    struct node_tag *next;
}node_t,*pnode_t;

typedef struct queue_tag{
    pnode_t front;
    pnode_t rear;
}queue_t,*pqueue_t;

pnode_t create_node(int val);
pqueue_t create_queue();
void enqueue(pqueue_t *q,int val);
void dqueue(pqueue_t *q);
int peek(pqueue_t q);
void print_queue(pqueue_t q);
bool isempty(pqueue_t q);

pnode_t create_node(int val)
{
    pnode_t n = (pnode_t) malloc(sizeof(struct node_tag));
    n->val = val;
    n->next = NULL;
    return n;
}

pqueue_t create_queue()
{
    pqueue_t q = (pqueue_t) malloc(sizeof(struct queue_tag));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(pqueue_t *q,int val)
{
    pnode_t n = create_node(val);
    if((*q)->front == NULL){
        (*q)->front = n;
        (*q)->rear = n;
    }else{
        (*q)->rear->next = n;
        (*q)->rear = n;
    }
}

void dqueue(pqueue_t *q)
{
    if((*q)->front !=NULL){
        pnode_t temp = (*q)->front;
        (*q)->front = (*q)->front->next;
        free(temp);
    }else{
        printf("!!the queue is empty\n");
        return ;
    }
}

int peek(pqueue_t q)
{
    return q->front->val;
}

void print_queue(pqueue_t q)
{
    printf("front -> rear\n");
    pnode_t f = q->front;
    while(f){
        printf("%d ->",f->val);
        f=f->next;
    }
    printf("end\n");
}

bool isempty(pqueue_t q)
{
    return q->front == NULL ? true:false;
}

int main(const int argc, const char **argv)
{
    pqueue_t pq = create_queue();
    enqueue(&pq,1);
    enqueue(&pq,2);
    enqueue(&pq,3);
    enqueue(&pq,4);
    enqueue(&pq,5);
    enqueue(&pq,6);
    print_queue(pq);
    printf("peek=%d\n",peek(pq));
    dqueue(&pq);
    dqueue(&pq);
    print_queue(pq);

    return 0;
}