
/*
762. Prime Number of Set Bits in Binary Representation

Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.

Recall that the number of set bits an integer has is the number of 1's present when written in binary.

For example, 21 written in binary is 10101, which has 3 set bits.
 

Example 1:

Input: left = 6, right = 10
Output: 4
Explanation:
6  -> 110 (2 set bits, 2 is prime)
7  -> 111 (3 set bits, 3 is prime)
8  -> 1000 (1 set bit, 1 is not prime)
9  -> 1001 (2 set bits, 2 is prime)
10 -> 1010 (2 set bits, 2 is prime)
4 numbers have a prime number of set bits.
Example 2:

Input: left = 10, right = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
5 numbers have a prime number of set bits.
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

bool isprime(int num){
	int i;
	if(num==1){
		return 0;
	}else{
		for(i=2;i<num;i++){
			if(num%i==0){
				return 0;
			}
		}
	}
	return 1;
}

int countPrimeSetBits(int left, int right){

    int cnt = 0;
    for(int val = left;val<=right;val++){
        int bcnt = 0;
        int curval = val;
        while(curval){
            if(curval&1){
                bcnt++;
            }
            curval = curval>>1;
        }
        if(isprime(bcnt))
            cnt++;

    }
    return cnt;
}
int main(int argc, char** argv )
{
    int l = atoi(argv[1]);
    int r = atoi(argv[2]);
    printf("left =%d right =%d\n",l,r);

    int cnt = countPrimeSetBits(l,r);
    printf("count prime bit set=%d\n",cnt);
    return 0;
}

