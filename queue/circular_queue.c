#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX 5

typedef struct cqueue_tag{
    int front;
    int rear;
    int *data;
}cqueue_t,*pcqueue_t;

pcqueue_t create_cqueue();
void rm_cqueue(pcqueue_t pcq);
void enqueue(pcqueue_t pcq);
int dequeue(pcqueue_t pcq);
int peek(pcqueue_t pcq);
void display(pcqueue_t pcq);



pcqueue_t create_cqueue()
{
    pcqueue_t pcq = (pcqueue_t)malloc(sizeof(struct cqueue_tag));
    pcq->front = -1;
    pcq->rear = -1;
    pcq->data = (int*) malloc(sizeof(int)*MAX);
    return pcq;
}

void rm_cqueue(pcqueue_t pcq)
{
    if (pcq->data){
        free(pcq->data);
    }
    if(pcq)
        free(pcq);
    pcq =NULL;    
}

void enqueue(pcqueue_t pcq)
{
    int val;
    printf("please enter the data\n");
    scanf("%d",&val);
    if((pcq->front ==-1)&&(pcq->rear == -1)){
        pcq->front = 0;
        pcq->rear = 0;
        pcq->data[pcq->rear] = val; 
    //}else if ( (pcq->rear == MAX-1)||(pcq->rear==pcq->front-1)){
    }else if ( ((pcq->front == 0 )&&(pcq->rear == MAX-1))||(pcq->rear==pcq->front-1)){        
        printf("the circular is full\n");
        return;
    }else{
        pcq->rear++;
        pcq->rear=pcq->rear%MAX;
        pcq->data[pcq->rear] = val;
    }
}
int dequeue(pcqueue_t pcq)
{
    if((pcq->front == -1)&&(pcq->rear == -1)){
        printf("the circular queue is empty\n");
        return -1;
    }else if (pcq->front == pcq->rear){
        int temp = pcq->front;
        pcq->front = -1;
        pcq->rear = -1;
        return pcq->data[temp]; 
    }else{
        int temppos = pcq->front;
        pcq->front++;
        pcq->front%=MAX;
        return pcq->data[temppos];
    }
}
int peek(pcqueue_t pcq)
{
    if(pcq->front==-1){
        printf("the circular queue is empty\n");
        return -1;
    }else
        return pcq->data[pcq->front];
}
void display(pcqueue_t pcq)
{
    int pos = pcq->front;
    //printf("dbg display front=%d rear=%d\n",pcq->front,pcq->rear);
    while (pos !=pcq->rear){
        //printf("pos=%d data=%d -> ",pos ,pcq->data[pos]);
        printf("data=%d -> ",pcq->data[pos]);
        pos++;
        pos=pos%MAX;
    }
    printf(" %d \n",pcq->data[pcq->rear]);
}


int main(const int argc, const char **argv)
{
    int optional;
    pcqueue_t m_pcq= create_cqueue();
    do{
        printf("======= main menu =======\n");
        printf("1. insert element\n");
        printf("2. delete element\n");
        printf("3. peek\n");
        printf("4. display queue\n");
        printf("5. exist\n");
        scanf("%d",&optional);    
        switch(optional){
            case 1:{
                enqueue(m_pcq);
                //printf("dbg data =%d f=%d r=%d \n",m_pcq->data[m_pcq->rear],m_pcq->front,m_pcq->rear);
            }
                break;
            case 2:
            {
                int val = dequeue(m_pcq);
                //printf("dbg data =%d f=%d r=%d \n",val,m_pcq->front,m_pcq->rear);
                break;
            }
            case 3:
            {
                int val= peek(m_pcq);
                printf("peek =%d\n",val);
                break;
            }
            case 4:
                display(m_pcq);
                break;
            default:
                break;
        }
    }while(optional!=5 );
    rm_cqueue(m_pcq);

    return 0;
}