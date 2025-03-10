#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct qnode_tag{
    int data;
    int priority;
    struct qnode_tag *next;
}qnode_t, *pqnode_t;

typedef struct priorityq_tag{
    pqnode_t front;
}priorityq_t,*ppriorityq_t;

pqnode_t create_node(int priority,int data);
ppriorityq_t create_priority_queue();
void enqueue(int priority,int data,ppriorityq_t priq);
int dequeue(ppriorityq_t priq);
void display(ppriorityq_t priq);
void release_queue(ppriorityq_t priq);

pqnode_t create_node(int priority,int data)
{
    pqnode_t n = (pqnode_t)malloc(sizeof(struct qnode_tag));
    n->priority = priority;
    n->data = data;
    n->next = NULL;
    return n;
}

ppriorityq_t create_priority_queue()
{
    ppriorityq_t q = (ppriorityq_t) malloc(sizeof(struct priorityq_tag));
    return q;
}

void enqueue(int priority,int data,ppriorityq_t priq)
{
    pqnode_t node = create_node(priority,data);
    if(priq->front == NULL){
        priq->front = node;
    }else if (priority<priq->front->priority){
        node->next = priq->front;
        priq->front = node;
    }else{
        pqnode_t cur = priq->front;
        while(cur->next!=NULL){
            if(cur->next->priority>priority)
                break;
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
    }
    //printf("enqueue q=%p q front=%p\n",priq,priq->front);
}

int dequeue(ppriorityq_t priq)
{
    int val = priq->front->data;
    pqnode_t temp = priq->front;
    priq->front = temp->next;
    free(temp);
    return val;
}

void display(ppriorityq_t priq)
{
    pqnode_t cur = priq->front;
    while(cur->next){
        printf(" %d (%d)-->",cur->data,cur->priority);
        cur=cur->next;
    }
    printf(" %d (%d)-->",cur->data,cur->priority);
    printf("NULL\n");
}

void release_queue(ppriorityq_t priq)
{
    if(!priq)
        return;
    if(priq->front){
        pqnode_t head = priq->front;
        while(head){
            pqnode_t temp = head;
            head = head->next;
            free(temp);
        }
    }
    free(priq);
    priq = NULL;
}

int main(const int argc, const char **argv)
{
    int optional;
    ppriorityq_t m_pq = create_priority_queue();
    do
    {
        printf("======= main menu =======\n");
        printf("1. insert element\n");
        printf("2. delete element\n");
        printf("3. display queue\n");
        printf("4. exist\n");
        scanf("%d",&optional);
        switch(optional){
            case 1:
            {
                printf("please input data and priority\n");
                int data,priority;
                scanf("%d %d",&data,&priority);
                enqueue(priority,data,m_pq);
                printf("q=%p q front=%p\n",m_pq,m_pq->front);
                break;
            }
            case 2:
            {
                int data = dequeue(m_pq);
                printf("data =%d \n",data);
                break;
            }
            case 3:
                display(m_pq);
                break;
            default:
                break;
        }
        
    } while (optional!=4);
    release_queue(m_pq);
    return 0;
}