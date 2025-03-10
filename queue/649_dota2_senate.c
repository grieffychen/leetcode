/*
649. Dota2 Senate

In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".

 

Example 1:

Input: senate = "RD"
Output: "Radiant"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
Example 2:

Input: senate = "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in round 1. 
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
 

Constraints:

n == senate.length
1 <= n <= 104
senate[i] is either 'R' or 'D'.

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


typedef struct qnode_tag{
    int pos;
    struct qnode_tag *next;
}qnode_tag,*pqnode_t;

typedef struct queue_tag{
    pqnode_t front;
    pqnode_t rear;
}queue_t,*pqueue_t;

pqnode_t create_node(int val)
{
    pqnode_t n = (pqnode_t)malloc(sizeof(struct qnode_tag));
    n->pos = val;
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

bool isempty(pqueue_t pq)
{
    return pq->front == NULL;
}

int front_val(pqueue_t pq)
{
    return pq->front->pos;
}

void enqueue(pqueue_t pq,int pos)
{
    pqnode_t n = create_node(pos);
    if(pq->front ==NULL){
        pq->front = n;
        pq->rear = n;
    }else{
        pq->rear->next = n;
        pq->rear = n;
    }
}

void dqueue(pqueue_t pq)
{
    pqnode_t n = pq->front;
#if 1
    pq->front =n->next;
#else
    if(pq->front == pq->rear){
        pq->front == NULL;
    }else{
        pq->front = n->next;
    }
#endif    
    free(n);
}

void release_q(pqueue_t pq)
{
    pqnode_t head = pq->front;
    while(head){
        pqnode_t temp = head;
        head=head->next;
        free(temp);
    }
    pq->front = NULL;
}

char* predictPartyVictory(char* senate) {

    pqueue_t p_rq = create_queue();
    pqueue_t p_dq = create_queue();
    int nfsenate = strlen(senate);
    printf("nf senate =%d\n",nfsenate);
    for(int i = 0;i<nfsenate;i++){
        if(senate[i] == 'R'){
            enqueue(p_rq,i);
        }else{
            enqueue(p_dq,i);
        }
    }
    //dbgprintq(p_rq);
    //dbgprintq(p_dq);

    while((!isempty(p_rq)) &&(!isempty(p_dq))){
        int r_front = front_val(p_rq);
        int d_front = front_val(p_dq);
        if(r_front<d_front){
            dqueue(p_dq);
            dqueue(p_rq);
            enqueue(p_rq,r_front+nfsenate);
        }else{
            dqueue(p_dq);
            dqueue(p_rq);
            enqueue(p_dq,d_front+nfsenate);
        }
    }
    char *ans = NULL;
    if(!isempty(p_rq))
        ans = "Radiant";
    else
        ans = "Dire";

    release_q(p_rq);
    release_q(p_dq);
    if(p_rq)
        free(p_rq);
    if(p_dq)
        free(p_dq);    
    return ans;   
}

void dbgprintq(pqueue_t pq)
{
    pqnode_t head = pq->front;
    while(head){
        printf("%d ->",head->pos);
        head=head->next;
    }
    printf("NULL\n");
}

#define test 0
int main(int argc, char**argv)
{
#if test    
    pqueue_t testq = create_queue();
    enqueue(testq,1);
    enqueue(testq,2);
    enqueue(testq,3);
    enqueue(testq,4);
    enqueue(testq,5);
    while(!isempty(testq)){
        printf("front=%d\n",front_val(testq));
        dqueue(testq);
    }
    release_q(testq);
    free(testq);
#else
    char *senate = "RDD";

    printf("ans =%s\n",predictPartyVictory(senate));

#endif


    return 0;
}
