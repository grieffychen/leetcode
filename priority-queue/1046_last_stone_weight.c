/*
1046. Last Stone Weight

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
Example 2:

Input: stones = [1]
Output: 1
 

Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
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
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include <limits.h>

typedef struct priority_queue_tag{
    int *heap;
    int hsize;
    int hcapacity;
}pq_t,*ppq_t;

ppq_t create_priority_queue(int size);
void pq_push(ppq_t obj,int val);
int pq_pop(ppq_t obj);
bool is_full(ppq_t obj);
bool is_empty(ppq_t obh);
void heapify(ppq_t obj,int index);
void free_priority_queue(ppq_t obj);
void swap(int* a ,int* b );
void printq(ppq_t obj);

ppq_t create_priority_queue(int size)
{
    ppq_t obj = (ppq_t) malloc(sizeof(struct priority_queue_tag));
    if(!obj)
        return NULL;
    obj->heap = (int*) malloc(sizeof(int)*size);
    obj->hsize = 0;
    obj->hcapacity = size;
    return obj;
}
void swap(int* a ,int* b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pq_push(ppq_t obj,int val)
{
    obj->heap[obj->hsize] = val;
    obj->hsize++;
    int cidx = obj->hsize-1;
    int pidx = (cidx -1)/2;
    while(pidx>=0){
        if(obj->heap[cidx]>obj->heap[pidx]){
            swap(&obj->heap[cidx],&obj->heap[pidx]);
            cidx = pidx;
            pidx = (cidx-1)/2;
        }else{
            break;
        }
    }
}
int pq_pop(ppq_t obj)
{
    if(is_empty(obj)){
        printf("the heap is empty\n");
        return INT_MIN;
    }

    int val = obj->heap[0];
    obj->heap[0] = obj->heap[obj->hsize-1];
    obj->hsize--;
    heapify(obj,0);
    return val;
}
bool is_full(ppq_t obj)
{
    return obj->hsize == obj->hcapacity;
}
bool is_empty(ppq_t obj)
{
    return obj->hsize == 0;
}
void heapify(ppq_t obj,int index)
{
    int curidx = index;
    while(curidx<=(obj->hsize-1)/2){
        int maxidx = curidx;
        int lidx = curidx*2+1;
        int ridx = curidx*2+2;
        if(lidx>obj->hsize-1)
            lidx = -1;
        if(ridx>obj->hsize-1)
            ridx = -1;
        if((lidx!=-1) && obj->heap[lidx]>obj->heap[maxidx])
            maxidx = lidx;
        if((ridx!=-1) && obj->heap[ridx]>obj->heap[maxidx])
            maxidx = ridx;
        if(maxidx!=curidx){
            swap(&obj->heap[curidx],&obj->heap[maxidx]);
            curidx = maxidx;
        }else{
            break;
        }
    }
}
void free_priority_queue(ppq_t obj)
{
    if(obj->heap)
        free(obj->heap);
    if(obj)
        free(obj);   
}

void printq(ppq_t obj)
{
    for(int i = 0;i<obj->hsize;i++){
        printf("%d ",obj->heap[i]);
    }
    printf("\n");
}
int lastStoneWeight(int* stones, int stonesSize) {
#if 0
    int cap = 20;
    ppq_t ppqobj = create_priority_queue(cap);
    pq_push(ppqobj,1);
    pq_push(ppqobj,2);
    pq_push(ppqobj,3);
    pq_push(ppqobj,4);
    pq_push(ppqobj,5);
    pq_push(ppqobj,6);
    pq_push(ppqobj,7);
    pq_push(ppqobj,8);
    pq_push(ppqobj,9);
    pq_push(ppqobj,10);
    printq(ppqobj);

    printf("pop: out all :");
    while(!is_empty(ppqobj)){
        
        printf("%d ",pq_pop(ppqobj));

    }
    printf("\n");

    free_priority_queue(ppqobj);
#endif
    if(stonesSize==1)
        return stones[0];
    ppq_t pqobj = create_priority_queue(stonesSize+2);
    for(int i =0;i<stonesSize;i++){
        pq_push(pqobj,stones[i]);
    }
    printq(pqobj);
    int val1;
    int val2;
    while(pqobj->hsize>1){
        val1 = pq_pop(pqobj);
        printq(pqobj);
        val2 = pq_pop(pqobj);
        printq(pqobj);
        //printf("val1=%d val2=%d\n",val1,val2);
        if(val1-val2){
            pq_push(pqobj,val1-val2);
        }
        printq(pqobj);
    }
    if(pqobj->hsize ==1)
        val1 = pqobj->heap[0];
    else
        val1 = 0;
    free_priority_queue(pqobj);
    return val1;
}


int main(int argc, char** argv )
{
    //int stones[] = {2,7,4,1,8,1};
    //int stones[] = {2,2};
    int stones[] = {10,4,2,10};
    int stonelen = sizeof(stones)/sizeof(int);
    for (int i = 0;i<stonelen;i++){
        printf("%d ",stones[i]);
    }
    printf("\n");
    printf("==============\n");
    int ans = lastStoneWeight(stones,stonelen);
    printf("answer =%d\n",ans);
	return 0;
}