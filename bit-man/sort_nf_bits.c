
/*
1356. Sort Integers by The Number of 1 Bits
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

 

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 104
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

#if 0
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize){
    int *bitarray = (int*)malloc(arrSize*sizeof(int));
    memset(bitarray,0,sizeof(arrSize)*sizeof(int));
    //int *sorbitarr = (int*)malloc(arrSize*sizeof(int));
    //memset(sorbitarr,0,sizeof(arrSize)*sizeof(int));
    /**
    for(int i = 0 ;i<arrSize;i++){
        bitarray[i] = 0;
        sorbitarr[i] = 0;
    }
    */
    *returnSize = arrSize;
    //sorbitarr[0]=arr[0];
    for (int i = 0 ;i<arrSize;i++){
        int cntbit = 0;
        int val = arr[i];
        while(val>0){
            if(val&1)
                cntbit++;
            val=val>>1;
        }
        bitarray[i] = cntbit;
        //sorbitarr[i]=arr[i];
        for(int j =i;j>0;j--){
            printf("j =%d\n",j);
            if(bitarray[j]<bitarray[j-1]){

                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                    temp = bitarray[j-1];
                    bitarray[j-1] = bitarray[j] ;
                    bitarray[j] = temp;
            }
#if 1            
            else if(bitarray[j]==bitarray[j-1]){
                if(arr[j]<arr[j-1]){
                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                    temp = bitarray[j-1];
                    bitarray[j-1] = bitarray[j] ;
                    bitarray[j] = temp;
                }
            }
#endif            
        }

    }

    printf("bit: ");
    for(int i = 0;i<arrSize;i++){
        printf(" %d",bitarray[i]);
    }
    printf("\n");
    if (bitarray)
        free(bitarray);
    return arr;
}

#else

int cmp(int *a, int* b)
{
    int abitcnt = 0;
    int bbitcnt = 0;
    int aclone = *a;
    int bclone = *b;
    
    while(aclone){
        if(aclone &1){
            abitcnt++;
        }
        aclone = aclone>>1;
    }
    
    while(bclone){
        if(bclone &1){
            bbitcnt++;
        }
        bclone = bclone>>1;
    }
    
    if(abitcnt != bbitcnt)
        return abitcnt - bbitcnt;
    else
        return *a - *b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize){

    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = arrSize;
    return arr;
    
}
#endif


int main(int argc, char** argv )
{
    //int nums[] = {0,1,2,3,4,5,6,7,8};
    //int nums[] = {1024,512,256,128,64,32,16,8,4,2,1};
    int nums[] = {10000,10000};
    int len = sizeof(nums)/sizeof(int);
    int retlen = 0;
    printf("arr: ");
    for(int i = 0;i<len;i++){
        printf(" %d",nums[i]);
    }
    printf("\n");
    int *resarr = sortByBits(nums,len,&retlen);
    printf("len =%d\n",retlen);
    printf("res: ");
    for(int i = 0;i<retlen;i++){
        printf(" %d",resarr[i]);
    }
    printf("\n");
    //printf("the array %s into pair\n",res?"can":"can't");
 #if 0   
    if(resarr)
        free(resarr);
#endif 
    return 0;
}

