/*

134. Gas Station

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
 

Constraints:

n == gas.length == cost.length
1 <= n <= 105
0 <= gas[i], cost[i] <= 104



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

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total =0;
    int start = 0;
    int gastank =0;

    for(int i =0;i<gasSize;i++){
        gastank+=gas[i]-cost[i];
        total+=gas[i]-cost[i];
        if(gastank<0){
            gastank =0;
            start=i+1;
        }
    }
    return total<0?-1:start;
#if 0    
#if 1
    int gsum =0;
    int csum = 0;
    for(int i =0;i<gasSize;i++){
        gsum+=gas[i];
        csum+=cost[i];
    }
    if(gsum<csum)
        return -1;
    int ans = -1;
    for(int si = 0;si<gasSize;si++){
        if(gas[si]<=cost[si])
            continue;
        int rgas = 0;
        for(int i =0;i<gasSize;i++){
            int pos = (si+i)%gasSize;
            rgas = rgas+gas[pos]-cost[pos];
            if(rgas<0)
                break;
        }
        if(rgas>=0){
            ans = si;
            break;
        }
    }
    return ans;
#else
    int ans =-1;
    for(int si = 0;si<gasSize;si++){
        int rgas = 0;
        for(int i = 0;i<gasSize;i++){
            int pos = (si+i)%gasSize;
            rgas = rgas+gas[pos]-cost[pos];
            printf("%d gas in tank=%d\n",pos,rgas);
            if(rgas<0){
                break;;
            }
        }
        if(rgas>=0){
            ans = si;
            break;
        }
    }
    return ans;
#endif
#endif    
}


int main(int argc, char** argv)
{   
    //int gas[] = {1,2,3,4,5};
    //int cost[] = {3,4,5,1,2};

    int gas[] = {2,3,4};
    int cost[] = {3,4,3};
    int glen = sizeof(gas)/sizeof(gas[0]);
    int clen = sizeof(cost)/sizeof(cost[0]);

    int sidx = canCompleteCircuit(gas,glen,cost,clen);
    printf("station =%d\n",sidx);

    return 0;

}
