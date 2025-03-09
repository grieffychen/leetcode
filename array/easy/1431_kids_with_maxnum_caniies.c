/*
1431. Kids With the Greatest Number of Candies
There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

 

Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
Example 2:

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
Example 3:

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
 

Constraints:

n == candies.length
2 <= n <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50
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


bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    bool *ismaxtbl = NULL;
    ismaxtbl = (bool*) malloc(sizeof(bool)*candiesSize);
    *returnSize = candiesSize;
    int max = 0;
    for(int i = 0;i<candiesSize;i++){
        if(candies[i]>max)
            max = candies[i];
    }
    for(int i = 0;i<candiesSize;i++){
        if(candies[i]>=(max-extraCandies))
            ismaxtbl[i]=true;
        else
            ismaxtbl[i]=false;
    }

    return ismaxtbl;
}



int main(int argc, char** argv)
{
    int candies[] = {2,3,5,1,3};
    int extra = 3;
    int cndlen = sizeof(candies)/sizeof(int);
    int retlen = 0;
    printf("candiws = ");
    for (int i = 0;i<cndlen;i++){
        printf("%d ",candies[i]);
    }
    printf("\n");
    bool *maxtbl = kidsWithCandies(candies,cndlen,extra,&retlen);
    //bool maxtbl = 
    
    if(maxtbl){
        for(int i =0;i<retlen;i++)
            printf("%s ",maxtbl[i]?"true":"false");
        printf("\n");
    }

    if(maxtbl)
        free(maxtbl);
    return 0;
}
