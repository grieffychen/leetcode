/*

950. Reveal Cards In Increasing Order

You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1. Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.

 

Example 1:

Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation: 
We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.
Example 2:

Input: deck = [1,1000]
Output: [1,1000]
 

Constraints:

1 <= deck.length <= 1000
1 <= deck[i] <= 106
All the values of deck are unique.

 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>                      // File Control Definitions.
#include <termios.h>            // POSIX Terminal Control Definitions.
#include <unistd.h>                     // UNIX Standard Definitions.
#include <errno.h>                      // ERROR Number Definitions.
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


typedef struct queue_tag{
    int *buf;
    int front;
    int rear;
    int qsize;
}queue_t,*pqueue_t;

pqueue_t create_queue(int qsize)
{
    pqueue_t q =(pqueue_t) malloc(sizeof(struct queue_tag));
    q->buf =(int*)malloc(sizeof(int)*(qsize+1));
    q->front = 0;
    q->rear = 0;
    q->qsize = qsize+1;
    return q;
}

bool isempty(pqueue_t pq)
{
    return pq->front==pq->rear;
}

bool isfull(pqueue_t pq)
{
    return (pq->rear+1)%pq->qsize == pq->front;
}

void enqueue(pqueue_t pq,int val)
{
    if(isfull(pq))
        return ;
    pq->buf[pq->rear] = val;
    pq->rear = (pq->rear+1)%pq->qsize;
}

void dequque(pqueue_t pq)
{
    if(isempty(pq))
        return;
    pq->front=(pq->front+1)%pq->qsize;
}

int front(pqueue_t pq)
{
    return pq->buf[pq->front];
}

void freequeue(pqueue_t pq)
{
    if(pq->buf)
        free(pq->buf);
    if(pq)
        free(pq);
    pq = NULL;
}

void printqueue(pqueue_t pq)
{
    for(int i = 0;i<pq->qsize;i++){
        printf("%d ",pq->buf[i]);
    }
    printf("\n");
}


int cmpfun(const void *a, const void *b){
    int  c = *(int*)a;
    int  d = *(int*)b;
    if((c-d)>0)
        return 1;
    else if((c-d)<0)
        return -1;
    else  
        return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {

    *returnSize = deckSize;
    qsort(deck,deckSize,sizeof(int),cmpfun);
    pqueue_t pqueue = create_queue(deckSize);
#if 0    
    for(int i =0;i<deckSize;i++){
        printf("%d ",deck[i]);
        //enqueue(pqueue,deck[i]);
    }
    printf("\n");
    //printqueue(pqueue);
#endif
    for (int i =0;i<deckSize;i++)
        enqueue(pqueue,i);
    int *ansarr = (int*) malloc(sizeof(int)*deckSize);

    for (int i =0;i<deckSize;i++){
        int d = front(pqueue);
        dequque(pqueue);
        ansarr[d] = deck[i];
        int next = front(pqueue);
        dequque(pqueue);
        enqueue(pqueue,next);
    }
    return ansarr;
}

int main(int argc, char**argv)
{
    int deck[] = {17,13,11,2,3,5,7};
    int len = sizeof(deck)/sizeof(int);
    for(int i = 0;i<len;i++)
        printf("%d ",deck[i]);
    printf("\n");


    int retlen = 0;
    int *ansarr = deckRevealedIncreasing(deck,len,&retlen);

    if(ansarr){
        for(int i = 0;i<retlen;i++)
            printf("%d ",ansarr[i]);
        printf("\n");        
        free(ansarr);
    }

    return 0;
}
