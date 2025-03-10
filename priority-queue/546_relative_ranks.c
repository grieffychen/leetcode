/*
506. Relative Ranks

You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

 

Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

 

Constraints:

n == score.length
1 <= n <= 104
0 <= score[i] <= 106
All the values in score are unique.
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

typedef struct score_tag{
    int score;
    int idx;
}score_t;

typedef struct priority_queue_tag{
    score_t *heap;
    int hsize;
    int hcapacity;
}pq_t,*ppq_t;

ppq_t create_priority_queue(int size);
void pq_push(ppq_t obj,score_t s);
score_t pq_pop(ppq_t obj);
bool is_full(ppq_t obj);
bool is_empty(ppq_t obh);
void heapify(ppq_t obj,int index);
void free_priority_queue(ppq_t obj);
void swap(score_t* a ,score_t* b );
void printq(ppq_t obj);

ppq_t create_priority_queue(int size)
{
    ppq_t obj = (ppq_t) malloc(sizeof(struct priority_queue_tag));
    if(!obj)
        return NULL;
    obj->heap = (score_t*) malloc(sizeof(struct score_tag)*size);
    obj->hsize = 0;
    obj->hcapacity = size;
    return obj;
}
void swap(score_t* a ,score_t* b )
{
    score_t temp = *a;
    *a = *b;
    *b = temp;
}

void pq_push(ppq_t obj,score_t s)
{
    obj->heap[obj->hsize] = s;
    obj->hsize++;
    int cidx = obj->hsize-1;
    int pidx = (cidx -1)/2;
    while(pidx>=0){
        if(obj->heap[cidx].score>obj->heap[pidx].score){
            swap(&obj->heap[cidx],&obj->heap[pidx]);
            cidx = pidx;
            pidx = (cidx-1)/2;
        }else{
            break;
        }
    }
}
score_t pq_pop(ppq_t obj)
{
    score_t val = obj->heap[0];
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
        if((lidx!=-1) && obj->heap[lidx].score>obj->heap[maxidx].score)
            maxidx = lidx;
        if((ridx!=-1) && obj->heap[ridx].score>obj->heap[maxidx].score)
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
        printf("[%d  %d] ",obj->heap[i].score,obj->heap[i].idx);
    }
    printf("\n");
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    ppq_t pqobj = create_priority_queue(scoreSize+1);
    for(int i =0;i<scoreSize;i++){
        score_t s;
        s.score = score[i];
        s.idx = i;
        pq_push(pqobj,s);
    }
    printq(pqobj);
    char **ansm =(char**) malloc(sizeof(char*)*scoreSize);
    int r = 0;
    while(!is_empty(pqobj)){
        score_t s = pq_pop(pqobj);
        if(r==0){
            ansm[s.idx] = (char*)malloc((strlen("Gold Medal")+1)*sizeof(char));
            //ansm[s.idx] = "Gold Medal";
            strcpy(ansm[s.idx],"Gold Medal");
        }else if(r==1){
            ansm[s.idx] = (char*)malloc((strlen("Silver Medal")+1)*sizeof(char));
            //ansm[s.idx] = "Silver Medal";
            strcpy(ansm[s.idx],"Silver Medal");
        }else if(r==2){
            ansm[s.idx] = (char*)malloc((strlen("Bronze Medal")+1)*sizeof(char));
            //ansm[s.idx] = "Bronze Medal";
            strcpy(ansm[s.idx],"Bronze Medal");
        }else{
            char buf[2];
            ansm[s.idx] = (char*)malloc(sizeof(char)*10);
            sprintf(ansm[s.idx],"%d",r+1);
            //ansm[s.idx] = &buf[0];
        }
        //printf("%s\n",ansm[s.idx]);
        r++;
    }
    free_priority_queue(pqobj);
    return ansm;    
}


int main(int argc, char** argv )
{
    int score[] = {10,3,8,9,4};
    //int score[] = {5,4,3,2,1};
    int slen = sizeof(score)/sizeof(int);
    int retlen = 0;
    for(int i =0 ;i<slen;i++){
        printf("%d ",score[i]);
    }
    printf("\n============\n");
    //char **ans 

    char **ansmat = findRelativeRanks(score,slen,&retlen);
    if(ansmat){
        for(int i = 0;i<retlen;i++){
            printf("%s\n",ansmat[i]);
        }
#if 1
        for(int i = 0;i<retlen;i++){
            if(ansmat[i])
                free(ansmat[i]);
        }
        free(ansmat);
#endif    
    }
    //char *a= "Gold Medal";
    //printf("a=%p %s\n",a,a);

	return 0;
}