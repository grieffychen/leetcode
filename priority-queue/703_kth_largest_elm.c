/*
703. Kth Largest Element in a Stream

You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]

Explanation:

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8

Example 2:

Input:
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

Output: [null, 7, 7, 7, 8]

Explanation:

KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8
 

Constraints:

0 <= nums.length <= 104
1 <= k <= nums.length + 1
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.

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

#define HEAP_SIZE   20010
typedef struct {
    int *heap;
    int hlen;
    int hcap;
    int kth;
} KthLargest;

void pq_push(KthLargest* kobj,int val);
int pq_pop(KthLargest* kobj);
void heapyify(KthLargest* kobj,int index);
void swap(int* a,int* b);
void printkheap(KthLargest* kobj);

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapyify(KthLargest* kobj,int index)
{
    int minidx = index;
    int lidx = index*2+1;
    int ridx = index*2+2;
    if(lidx>kobj->hlen-1)
        lidx = -1;
    if(ridx>kobj->hlen-1)
        ridx = -1;
    if((lidx!=-1)&&(kobj->heap[lidx]<kobj->heap[minidx]))
        minidx = lidx;
    if((ridx!=-1)&&(kobj->heap[ridx]<kobj->heap[minidx]))
        minidx = ridx;
    //printf("max %d c=%d l=%d r=%d\n",maxidx,index,lidx,ridx);
    if(minidx!=index){
        swap(&kobj->heap[index],&kobj->heap[minidx]);
        heapyify(kobj,minidx);
    }else{
        return;
    }
}

void pq_push(KthLargest* kobj,int val)
{
    kobj->heap[kobj->hlen] = val;
    kobj->hlen++;
    int cidx = kobj->hlen-1;
    int pidx = (cidx-1)/2;
    while((pidx>=0)&&(kobj->heap[pidx]>kobj->heap[cidx])){
        swap(&kobj->heap[pidx],&kobj->heap[cidx]);
        cidx = pidx;
        pidx = (cidx-1)/2;
    }
} 

int pq_pop(KthLargest* kobj)
{
    int val = kobj->heap[0];
    kobj->heap[0] = kobj->heap[kobj->hlen-1];
    kobj->hlen--;
    //printf("==================\n");
    heapyify(kobj,0);
    return val;
}

void printkheap(KthLargest* kobj)
{
    for(int i = 0;i<kobj->hlen;i++){
        printf("%d ",kobj->heap[i]);
    }
    printf("\n");
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *kobj =(KthLargest*) malloc(sizeof(KthLargest));
    if(!kobj)
        return NULL;
    kobj->heap =(int*) malloc(sizeof(int)*HEAP_SIZE);
    if(!kobj->heap)
        return NULL;
    kobj->hcap = HEAP_SIZE;
    kobj->kth = k;
    kobj->hlen = 0;
    for(int i = 0;i<numsSize;i++){
        pq_push(kobj,nums[i]);
        if(kobj->hlen>k)
            pq_pop(kobj);
    }
    return kobj;
}

int kthLargestAdd(KthLargest* obj, int val) {
#if 1
    int retval;
    pq_push(obj,val);
    if(obj->hlen>obj->kth)
        pq_pop(obj);
    return obj->heap[0];
#else
    int cnt = 0;
    pq_push(obj,val);
    int retval;
    int *retbuf = (int*) malloc(sizeof(int) *(obj->kth+1));
    while(cnt<obj->kth){
        retbuf[cnt] = pq_pop(obj);
        //pq_push(obj,retval);
        cnt++;
    }
    cnt = 0;
    while(cnt<obj->kth){
        pq_push(obj,retbuf[cnt]);
        cnt++;
    }

    retval = retbuf[obj->kth-1];
    if(retbuf)
        free(retbuf);
    return retval;
#endif    
}

void kthLargestFree(KthLargest* obj) {
    if(obj->heap)
        free(obj->heap);
    if(obj)
        free(obj);
}



int main(int argc, char** argv )
{
    int nums[] = {4,5,8,2};
    int len = sizeof(nums)/sizeof(int);
    int k = 3;
    KthLargest *kobj = kthLargestCreate(k,nums,len);
    printkheap(kobj);
    //pq_pop(kobj);
#if 1    
    int aval;    
    aval = kthLargestAdd(kobj,3);
    printf("val =%d\n",aval);
    aval = kthLargestAdd(kobj,5);
    printf("val =%d\n",aval);
    aval = kthLargestAdd(kobj,10);
    printf("val =%d\n",aval);
    aval = kthLargestAdd(kobj,9);
    printf("val =%d\n",aval);
    aval = kthLargestAdd(kobj,4);
    printf("val =%d\n",aval);
#endif    
    printkheap(kobj);
    kthLargestFree(kobj);
	return 0;
}