/*

2558. Take Gifts From the Richest Pile

You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
Return the number of gifts remaining after k seconds.

 

Example 1:

Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation: 
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
Example 2:

Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation: 
In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile. 
That is, you can't take any pile with you. 
So, the total gifts remaining are 4.
 

Constraints:

1 <= gifts.length <= 103
1 <= gifts[i] <= 109
1 <= k <= 103


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

typedef struct {
    int *heap;
    int hidx;
    int hcap;
}heap_t;

void pq_push(heap_t* hobj,int val);
int pq_pop(heap_t* hobj);
void heapify(heap_t* hobj,int posidx);
void swap(int *a,int *b);

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pq_push(heap_t* hobj,int val)
{
    hobj->heap[hobj->hidx] = val;
    hobj->hidx++;
    int cidx = hobj->hidx-1;
    int pidx = (cidx-1)/2;

    while((pidx>=0) &&(hobj->heap[cidx]>hobj->heap[pidx])){
        swap(&hobj->heap[pidx],&hobj->heap[cidx]);
        cidx = pidx;
        pidx = (cidx-1)/2;
    }
}

void heapify(heap_t* hobj,int posidx)
{
    int lcidx = posidx*2+1;
    int rcidx = posidx*2+2;
    if(lcidx >hobj->hidx-1)
        lcidx =-1;
    if(rcidx >hobj->hidx-1)
        rcidx =-1;
    int maxidx = posidx;
    if((lcidx!=-1) && hobj->heap[lcidx]>hobj->heap[maxidx])
        maxidx = lcidx;
    if((rcidx!=-1) && hobj->heap[rcidx]>hobj->heap[maxidx])
        maxidx = rcidx;

    if(maxidx!=posidx){
        swap(&hobj->heap[posidx],&hobj->heap[maxidx]);
        heapify(hobj,maxidx);
    }

}

int pq_pop(heap_t* hobj)
{
    int val = hobj->heap[0];
    hobj->heap[0] = hobj->heap[hobj->hidx-1];
    hobj->hidx--;
    heapify(hobj,0);
    return val;
}

void print_heap(heap_t* hobj)
{
    for(int i =0;i<hobj->hidx;i++){
        printf("%d ",hobj->heap[i]);
    }
    printf("\n");
}

#if 0
long long pickGifts(int* gifts, int giftsSize, int k) 
{
    heap_t *pobj = (heap_t*) malloc(sizeof(heap_t));
    pobj->hcap =giftsSize+1;
    pobj->hidx =0;
    pobj->heap =(int*)malloc(sizeof(int)*giftsSize);
    
    for(int i =0;i<giftsSize;i++){
        pq_push(pobj,gifts[i]);
        //print_heap(pobj);
    }

    for (int i =0;i<k;i++){
        int val = pq_pop(pobj);
        int r = (int)sqrt(val);
        printf("val=%d r=%d\n",val,r);
        pq_push(pobj,r);
        print_heap(pobj);;
    }
    //print_heap(pobj);
    int sum = 0;
    while(pobj->hidx>0){
        int v = pq_pop(pobj);
        //printf("pop=%d\n",v);
        sum+= v;
    }


    if(pobj->heap)
        free(pobj->heap);
    if(pobj)
        free(pobj);
    return sum;
}
#else
long long pickGifts(int* gifts, int giftsSize, int k) 
{
    for(int i = 0;i<k;i++){
        int max = 0;
        int maxidx = 0;
        for(int j= 0;j<giftsSize;j++){
            if(gifts[j]>max){
                max = gifts[j];
                maxidx = j;
            }
        }
        gifts[maxidx] = (int)sqrt(max);
    }
    long long sum = 0;
    for(int i =0;i<giftsSize;i++)
        sum+=gifts[i];

    return sum;
}
#endif

int main(int argc, char** argv )
{
    //int gifts[] = {25,64,9,4,100};
    //int gifts[] = {1,1,1,1};
    int gifts[] ={70,58,12,11,41,66,63,14,39,71};
    //int k =4;
    int k = 19;
    int gsize = sizeof(gifts)/sizeof(int);
    for(int i =0;i<gsize;i++){
        printf("%d ",gifts[i]);
    }
    printf("\n");

    int ans = pickGifts(gifts,gsize,k);
    printf("ans =%d\n",ans);

	return 0;
}