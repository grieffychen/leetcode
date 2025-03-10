#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct qnode_tag{
    int data;
    struct qnode_tag *next;
}qnode_t, *pqnode_t;

typedef struct queue_tag{
    pqnode_t front;
    pqnode_t rear;
}queue_t,*pqueue_t;

pqnode_t create_qnode(int val);
pqueue_t create_queue();
void insert(pqueue_t *q);
int peek(pqueue_t q);
int delete_elm(pqueue_t *q);
void display(pqueue_t q);
void rm_queue(pqueue_t *q);
bool isempty(pqueue_t pq);

pqnode_t create_qnode(int val)
{
    pqnode_t node = (pqnode_t) malloc(sizeof (struct qnode_tag));
    node->data = val;
    node->next = NULL;
} 

pqueue_t create_queue()
{
    pqueue_t q = (pqueue_t) malloc(sizeof(struct queue_tag));
    q->front = NULL;
    q->rear = NULL;
}



void insert(pqueue_t *q)
{
    printf("please insert value\n");
    int val;
    scanf("%d",&val);
    pqnode_t pnode =create_qnode(val);
    if((*q)->front ==NULL){
        (*q)->front = pnode;
        (*q)->rear = pnode;
    }else{
        (*q)->rear->next = pnode;
        (*q)->rear = pnode;
    }
}

int peek(pqueue_t q)
{
    if(q->front ==NULL){
        printf("the queue is empty\n");
        return -1;
    }else{
        return q->front->data;
    }
}

int delete_elm(pqueue_t *q)
{
    if((*q)->front == NULL){
        printf("the queue is empty\n");
        return -1;
    }else{
        int val = (*q)->front->data;
        pqnode_t temp = (*q)->front;
        (*q)->front = temp->next;
        free(temp);
        return val;
    }
}

void display(pqueue_t q)
{
    pqnode_t cur = q->front;
    while(cur !=q->rear){
        printf("%d -->",cur->data);
        cur= cur->next;
    }
    printf("%d -->NULL\n",q->rear->data);
}

bool isempty(pqueue_t pq)
{
    return (pq->front==NULL)?true:false;
}

void rm_queue(pqueue_t *q){
    pqueue_t pq = *q;
    //while(pq->front!=pq->rear)
    while(!isempty(pq)){
        delete_elm(&pq);
    }
    *q = NULL;
}

int main(const int argc, const char **argv)
{

    int optioanl = -1;
    pqueue_t pq = create_queue();
    //int val =-1;
    do{
        printf("======= main menu =======\n");
        printf("1. insert element\n");
        printf("2. delete element\n");
        printf("3. peek\n");
        printf("4. display queue\n");
        printf("5. exist\n");
        scanf("%d",&optioanl);
        switch(optioanl){
            case 1:
                insert(&pq);
                break;
            case 2:
                delete_elm(&pq);
                break;
            case 3:
            {
                int val = peek(pq);
                printf("peek =%d\n",val);
                break;
            }
            case 4:
                display(pq);
                break;;
        }

    }while(optioanl !=5);
    rm_queue(&pq);
    return 0;
}