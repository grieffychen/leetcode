#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct info_tag{
    int idk;
    int tickets;
}info_t;

typedef struct qnode_tag{
    info_t info;
    struct qnode_tag *next;
}qnode_t,*pqnode_t;

pqnode_t create_node(int id, int ts);
void enqueue(pqnode_t *pq,info_t data);
info_t dequeue(pqnode_t *pq);
bool isempty(pqnode_t pq);
void release_q(pqnode_t *pq);

void display(pqnode_t pq);

pqnode_t create_node(int id, int ts)
{
    pqnode_t pq =(pqnode_t) malloc(sizeof(struct qnode_tag));
    pq->info.idk = id;
    pq->info.tickets = ts;
    pq->next = NULL;
    return pq;
}
void enqueue(pqnode_t *pq,info_t data)
{
    pqnode_t pnode = create_node(data.idk,data.tickets);
    if(*pq == NULL){
        *pq = pnode;
    }else{
        //pqnode_t phead = *pq;
        //pqnode_t cur= phead;
        pqnode_t cur= *pq;
        while(cur->next)
            cur=cur->next;
        cur->next = pnode;
    }
}
info_t dequeue(pqnode_t *pq)
{
    //the item in queue
    if ((*pq)->next ==NULL){
        info_t data = (*pq)->info;
        free(*pq);
        (*pq) = NULL;
        return data;
    }else{
        pqnode_t temp = (*pq);
        *pq = temp->next;
        info_t data = temp->info;
        free(temp);
        return data;
    }
}
bool isempty(pqnode_t pq)
{
    return (pq == NULL? true:false);
}
void release_q(pqnode_t *pq)
{
    pqnode_t cur = *pq;
    while(cur){
        pqnode_t temp = cur;
        cur=cur->next;
        free(temp);
    }
    *pq = NULL;
}

void display(pqnode_t pq)
{
    pqnode_t cur = pq;
    while (cur){
        printf("[%d,%d]-->",cur->info.idk,cur->info.tickets);
        cur = cur->next;
    }
    printf("NULL\n");
}

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    pqnode_t p_queue = NULL;
    for (int i = 0;i<ticketsSize;i++){
        info_t data;
        data.idk=i;
        data.tickets = tickets[i];
        enqueue(&p_queue,data);
    }
    display(p_queue);
    int times = 0;

    while(!isempty(p_queue)){
        info_t tdata = dequeue(&p_queue);
        if((tdata.idk == k)&&(tdata.tickets == 1)){
            times++;
            break;
        }else if(tdata.tickets>1){
            //info_t temp;
            //temp.idk = tdata.idk;
            //temp.tickets = tdata.tickets-1;
            tdata.tickets--;
            enqueue(&p_queue,tdata);
        }
        times++;
        printf("time =%d ",times);
        display(p_queue);
    }


    release_q(&p_queue);
    return times;   
}


int main(const int argc, const char **argv)
{
    //int tickets[] ={2,3,2};
    //int k = 2;
    int tickets[] ={5,1,1,1};
    int k = 0;
    int ticklen = sizeof(tickets)/sizeof(int);
    int times = timeRequiredToBuy(tickets,ticklen,k);
    printf("times =%d\n",times);

    return 0;
}