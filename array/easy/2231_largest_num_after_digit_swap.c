/*
2231. Largest Number After Digit Swaps by Parity

You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.

 

Example 1:

Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
Example 2:

Input: num = 65875
Output: 87655
Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
Swap the first digit 5 with the digit 7, this results in the number 87655.
Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.
 

Constraints:

1 <= num <= 109

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


int cmp(const void* a,const void* b)
{
    int va = *((const int*)a);
    int vb = *((const int*)b);

    return (vb-va);
}

#if 0
int largestInteger(int num) {
    printf("nums=%d\n",num);
    int len1 = 0;
    int len2 = 0;
    int temp = num;
    int total = 0;
    int *buf1 = (int*)malloc(sizeof(int)*6);
    int *buf2 = (int*)malloc(sizeof(int)*6);
    while(temp){
        total++;
        if(total%2){
            buf1[len1++] = temp%10;
        }else{
            buf2[len2++] = temp%10;
        }
        temp=temp/10;
    }
    //printf("total =%d len1=%d len2=%d\n",total,len1,len2);

    qsort(buf1,len1,sizeof(int),cmp);
    qsort(buf2,len2,sizeof(int),cmp);
#if 0
    for(int i =0;i<len1;i++){
        printf("%d ",buf1[i]);
    }
    printf("\n");
    for(int i =0;i<len2;i++){
        printf("%d ",buf2[i]);
    }
    printf("\n");
#endif    
    int l1idx =0;
    int l2idx =0;
    int ans =0;
    for(int i = 0;i<total;i++){
        int dig;
        if(total%2){
            //buf1 first
            if((i+1)%2)
                dig=buf1[l1idx++];
            else
                dig=buf2[l2idx++];
        }else{
            //buf2 first 
            if((i+1)%2)
                dig=buf2[l2idx++];
            else
                dig=buf1[l1idx++];            
        }
        //printf("ans=%d,dig=%d\n",ans,dig);
        ans=ans*10;
        ans += dig;
    }
    if(buf1)
        free(buf1);
    if(buf2)
        free(buf2);
    return ans;
}
#else

void swap(int *a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int largestInteger(int num) {
    printf("num=%d\n",num);
    int nfdig = 0;
    int temp = num;
    while(temp){
        nfdig++;
        temp/=10;
    }
    int *digbuf = (int*) malloc(sizeof(int)*nfdig);
    int *oddbuf = (int*) malloc(sizeof(int)*nfdig);
    temp = num;
    for(int i =0;i<nfdig;i++){
        int dig = temp%10;
        digbuf[nfdig-1-i] = dig;
        if(dig%2)
            oddbuf[nfdig-1-i] = 1;
        else
            oddbuf[nfdig-1-i] = 0;
        temp/=10;
    }
    for(int i =0;i<nfdig;i++){
        printf("%d ",digbuf[i]);
    }
    printf("\n");
    for(int i =0;i<nfdig;i++){
        printf("%d ",oddbuf[i]);
    }
    printf("\n");

    for(int i =0;i<nfdig-1;i++){
        for(int j =i+1;j<nfdig;j++){
            if(oddbuf[i]==oddbuf[j]){
                if(digbuf[i]<digbuf[j])
                    swap(&digbuf[i],&digbuf[j]);
            }
        }
    }
    for(int i =0;i<nfdig;i++){
        printf("%d ",digbuf[i]);
    }
    printf("\n");
    int ans = 0;
    for(int i =0;i<nfdig;i++){
        ans *=10;
        ans +=digbuf[i];
    }

    if(digbuf)
        free(digbuf);
    if(oddbuf)
        free(oddbuf);

    return ans;
}
#endif

int main(int argc, char** argv)
{
    //int num = 65875;
    //int num = 1234;
    int num = 247;
    int ans = largestInteger(num);
    printf("ans=%d\n",ans);

    return 0;
}
