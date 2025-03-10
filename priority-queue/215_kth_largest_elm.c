/*
215. Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
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
#define enqsort     0

#if enqsort

int cmp(const void* a,const void* b)
{
    int va = *((const int*)a);
    int vb = *((const int*)b);
    return vb-va;
}
int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums,numsSize,sizeof(int),cmp);
    
    return nums[k-1];
}
#else
typedef struct heap_tag{
    int *hbuf;
    int hlen;
    int hcap;
}heap_t,*pheap_t;
pheap_t create_heap(int capacity);
void swap(int *a,int*b);
void min_push(pheap_t obj,int val);
int min_pop(pheap_t obj);
//void heapify(pheap_t obj,int index);
void freeheap(pheap_t obj);
void print_heap(pheap_t obj);

void swap(int *a,int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

pheap_t create_heap(int capacity)
{
    pheap_t hobj =(pheap_t) malloc(sizeof(heap_t));
    if(!hobj)
        return NULL;
    hobj->hlen = 0;
    hobj->hcap = capacity+1;
    hobj->hbuf = (int*) malloc(sizeof(int)*hobj->hcap);
    if(!hobj->hbuf)
        return NULL;
    return hobj;
}

void freeheap(pheap_t obj)
{
    if(obj->hbuf)
        free(obj->hbuf);
    if(obj)
        free(obj);
    obj= NULL;
}

void print_heap(pheap_t obj)
{
    for(int i =0;i<obj->hlen;i++){
        printf("%d ",obj->hbuf[i]);
    }
    printf("\n");
}

void min_push(pheap_t obj,int val)
{
    obj->hbuf[obj->hlen] = val;
    int cidx = obj->hlen ;
    int pidx = (cidx-1)/2;
    obj->hlen++;

    while((cidx>0)){
        if (obj->hbuf[pidx]>obj->hbuf[cidx]){
            swap(&obj->hbuf[pidx],&obj->hbuf[cidx]);
            cidx = pidx;
            pidx = (cidx-1)/2;
        }else
            break;
    }
}

int min_pop(pheap_t obj)
{
    int val = obj->hbuf[0];
    obj->hbuf[0] = obj->hbuf[obj->hlen-1];
    obj->hlen--;

    int curidx = 0;
    int lcidx = curidx*2+1;
    int rcidx = curidx*2+2;
    int minidx = curidx;
    while(curidx<obj->hlen){
        minidx = curidx;    
        if(lcidx>obj->hlen-1)
            lcidx = -1;
        if(rcidx>obj->hlen-1)
            rcidx = -1;
        if((lcidx!=-1)&&(obj->hbuf[lcidx]<obj->hbuf[minidx]))
            minidx = lcidx;
        if((rcidx!=-1)&&(obj->hbuf[rcidx]<obj->hbuf[minidx]))
            minidx = rcidx;
        if(minidx!=curidx){
            swap(&obj->hbuf[curidx],&obj->hbuf[minidx]);
            curidx = minidx;
            lcidx = curidx*2+1;
            rcidx = curidx*2+2;
        }else{
            break;
        }
    }
    return val;
}

int findKthLargest(int* nums, int numsSize, int k) {
    pheap_t pqobj = create_heap(numsSize);
    for(int i =0;i<numsSize;i++){
        min_push(pqobj,nums[i]);
        if(i>k-1){
            min_pop(pqobj);
        }
        print_heap(pqobj);
    }
    int ans = min_pop(pqobj);
    freeheap(pqobj);
    return ans;
}

#endif

int main(int argc, char** argv )
{

    int nums[] = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    int len = sizeof(nums)/sizeof(int);
    for(int i = 0;i<len;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");

    int ans  = findKthLargest(nums,len,k);

    printf("kth largest =%d\n",ans);
	return 0;
}