/*

1720. Decode XORed Array

There is a hidden integer array arr that consists of n non-negative integers.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3].

You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].

Return the original array arr. It can be proved that the answer exists and is unique.

 

Example 1:

Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
Example 2:

Input: encoded = [6,2,7,3], first = 4
Output: [4,2,0,7,4]
 

Constraints:

2 <= n <= 104
encoded.length == n - 1
0 <= encoded[i] <= 105
0 <= first <= 105
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *decodebuf = NULL;
int* decode(int* encoded, int encodedSize, int first, int* returnSize)
{
    //int *tmpbuf = (int*) malloc(sizeof(int)*encodedSize);
    //memcpy(tmpbuf,encoded,encodedSize*sizeof(int));
    //encoded = (int*) realloc(encoded,encodedSize+1);
    *returnSize = encodedSize +1;
    //int val = first;
    decodebuf[0] = first;
    //decodebuf[0] = first;
    for(int i = 0 ;i<encodedSize;i++){
        decodebuf[i+1] = decodebuf[i]^ encoded[i];
        //printf("%d xor%d = %d\n",val,tmpbuf[i],encoded[i+1]);
        //val = encoded[i+1];
        //printf("val =%d\n",val);

#if 0        
        if(i == 0){
            encoded[i] = 4;
            val = encoded[i];
        }else{
            encoded[i] = tmpbuf[i-1]^val;
            val = encoded[i];
        }
#endif     
     }

    //if(tmpbuf)
    //    free(tmpbuf);
    return decodebuf;

}

int main(int argc, char** argv )
{
    int first = 4;
    int encode_size = 4;
    int *encodebuf =(int*) malloc(sizeof(int)*encode_size);
    //int *decodebuf = NULL;
    decodebuf =(int*) malloc(sizeof(int)*(encode_size+1));
    int retsize;
    encodebuf[0] = 6;
    encodebuf[1] = 2;
    encodebuf[2] = 7;
    encodebuf[3] = 3;

    printf("encode : ");
    for (int i = 0 ;i< encode_size;i++)
        printf("%d ",encodebuf[i]);
    printf("\n");
    decodebuf = decode(encodebuf, encode_size,first,&retsize);
    printf("decode : ");
    for (int i = 0 ;i< retsize;i++)
        printf("%d ",decodebuf[i]);
    printf("\n");
    if(encodebuf)
        free(encodebuf);
    if(decodebuf)
        free(decodebuf);
    return 0;
}

