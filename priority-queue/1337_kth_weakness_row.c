/*
1337. The K Weakest Rows in a Matrix


You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

 

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 1 
- Row 1: 4 
- Row 2: 1 
- Row 3: 1 
The rows ordered from weakest to strongest are [0,2,3,1].
 

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.


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
    int nfstrong;
    int idx;
}pair;

#if 0
typedef struct {
    //int *heap;
    pair *heap;
    int hlen;
    int hcap;
} Kthweakest;

void pq_push(Kthweakest* kobj,pair val);
pair pq_pop(Kthweakest* kobj);
void heapyify(Kthweakest* kobj,int index);
void swap(pair* a,pair* b);
int strongcnt(int* arr,int len);
void printkheap(Kthweakest* kobj);



void swap(pair* a,pair* b)
{
    pair temp = *a;
    *a = *b;
    *b = temp;
}

void heapyify(Kthweakest* kobj,int index)
{
    int maxidx = index;
    int lidx = index*2;
    int ridx = index*2+1;
    if(lidx>kobj->hlen-1)
        lidx = -1;
    if(ridx>kobj->hlen-1)
        ridx = -1;
    if((lidx!=-1)&&(kobj->heap[lidx].nfstrong>=kobj->heap[maxidx].nfstrong))
        maxidx = lidx;
    if((ridx!=-1)&&(kobj->heap[ridx].nfstrong>=kobj->heap[maxidx].nfstrong))
        maxidx = ridx;
    //printf("max %d c=%d l=%d r=%d\n",maxidx,index,lidx,ridx);
    if(maxidx!=index){
        swap(&kobj->heap[index],&kobj->heap[maxidx]);
        //printf("[%d %d]<->[%d %d]\n",kobj->heap[index].idx,kobj->heap[index].nfstrong,kobj->heap[maxidx].idx,kobj->heap[maxidx].nfstrong);
        heapyify(kobj,maxidx);
    }else{
        return;
    }
}

void pq_push(Kthweakest* kobj,pair val)
{
    kobj->heap[kobj->hlen] = val;
    kobj->hlen++;
    int cidx = kobj->hlen-1;
    int pidx = (cidx)/2;
    while((pidx>0)&&(kobj->heap[pidx].nfstrong<=kobj->heap[cidx].nfstrong)){
        //printf("[%d %d]<->[%d %d]\n",kobj->heap[pidx].idx,kobj->heap[pidx].nfstrong,kobj->heap[cidx].idx,kobj->heap[cidx].nfstrong);
        swap(&kobj->heap[pidx],&kobj->heap[cidx]);
        cidx = pidx;
        pidx = (cidx)/2;
    }
} 

pair pq_pop(Kthweakest* kobj)
{
    pair val = kobj->heap[1];
    kobj->heap[1] = kobj->heap[kobj->hlen-1];
    kobj->hlen--;
    //printf("==================\n");
    heapyify(kobj,1);
    return val;
}

void printkheap(Kthweakest* kobj)
{
    for(int i = 1;i<kobj->hlen;i++){
        printf("[%d ,%d] ",kobj->heap[i].idx,kobj->heap[i].nfstrong);
    }
    printf("\n");
}



int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {    
    Kthweakest *pobj = (Kthweakest*) malloc(sizeof(Kthweakest));
    pobj->heap =(pair*) malloc(sizeof(pair)*(matSize+3));
    pobj->hlen =1;
    pobj->hcap = matSize+3;
    //printf("======\n");
    for(int i =0;i<matSize;i++){
        pair p;
        p.nfstrong = strongcnt(mat[i],matColSize[i]);
        p.idx = i;
        pq_push(pobj,p);
        //printkheap(pobj);
        if(pobj->hlen>k+1)
            pq_pop(pobj);
    }
    //printkheap(pobj);
    *returnSize = k;
    int *ansarr = (int*) malloc(sizeof(int)*k);
    for(int i =k-1;i>=0;i--){
        int v = pq_pop(pobj).idx;
        //printf("pop=%d\n",v);
        ansarr[i] = v;
    }
    if(pobj->heap)
        free(pobj->heap);
    if(pobj)
        free(pobj);    
    return ansarr;   
}
#else
int strongcnt(int* arr,int len)
{
    int l =0;
    int r = len-1;
    int mid = l+(r-l)/2;
    while(l<=r){
        mid= l+(r-l)/2;
        if(arr[mid]==0){
            r=mid-1;
        }else{
            l= mid+1;
        }
    }
    return l;
}

int cmp(const void* a,const void *b)
{
    pair pa =*((pair*)a);
    pair pb =*((pair*)b);
    if(pa.nfstrong==pb.nfstrong)
        return pa.idx-pb.idx;
    return (pa.nfstrong-pb.nfstrong);
}


int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {    
    pair *strong = (pair*) malloc(sizeof(pair)*matSize);
    for(int i =0;i<matSize;i++){
        pair p;
        p.idx = i;
        p.nfstrong = strongcnt(mat[i],matColSize[i]);
        strong[i] =p;
    }
    qsort(strong,matSize,sizeof(pair),cmp);
    for(int i =0;i<matSize;i++){
        printf("%d %d\n",strong[i].idx,strong[i].nfstrong);
    }
    *returnSize = k;
    int *ans = (int*)malloc(sizeof(int)*k);
    for(int i =0;i<k;i++){
        ans[i]=strong[i].idx;
    }
    if(strong)
        free(strong);
    return ans;
}
#endif


/*
 mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
*/
#define R   5
#define C   5
int main(int argc, char** argv )
{
#if 1    
    int m[R][C] ={{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
    int **mat = (int**) malloc(sizeof(int*)*R);
    int *coltbl =(int*) malloc(sizeof(int)*R);
    for (int i = 0;i<R;i++){
        mat[i] = (int*)malloc(sizeof(int)*C);
        coltbl[i] = C;
        for(int j = 0;j<C;j++){
            mat[i][j] = m[i][j];
        }   
    }
    //printf("%d\n",(0-1)/2);
    for (int i =0;i<R;i++){
        for(int j= 0;j<C;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    for(int i =0;i<R;i++){
        int s = strongcnt(mat[i],C);
        printf("%d \n",s);
    }
    int retlen = 0;
    int k = 3;
    int* ansarr= kWeakestRows(mat,R,coltbl,k,&retlen);


    if(ansarr){
        printf("ans= ");
        for(int i = 0;i<retlen;i++){
            printf("%d ",ansarr[i]);
        }
    printf("\n");        
        free(ansarr);
    }
    for(int i = 0;i<R;i++)
        free(mat[i]);
    free(mat);
    free(coltbl);
#else
    Kthweakest *pobj = (Kthweakest*) malloc(sizeof(Kthweakest));
    pobj->heap =(pair*) malloc(sizeof(pair)*11);
    pobj->hlen =1;
    pobj->hcap = 11;
    for(int i =0;i<9;i++){
        pair p;
        p.idx =i;
        p.nfstrong = i+1;
        pq_push(pobj,p);
        printkheap(pobj);
    }
    printf("============\n");
    for(int i =0;i<9;i++){
        pair p = pq_pop(pobj);
        printf("%d %d\n",p.idx,p.nfstrong);
    }

#endif
	return 0;
}