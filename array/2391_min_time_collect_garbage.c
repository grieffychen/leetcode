/*


2391. Minimum Amount of Time to Collect Garbage

You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.

You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.

There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.

Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.

Return the minimum number of minutes needed to pick up all the garbage.

 

Example 1:

Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21
Explanation:
The paper garbage truck:
1. Travels from house 0 to house 1
2. Collects the paper garbage at house 1
3. Travels from house 1 to house 2
4. Collects the paper garbage at house 2
Altogether, it takes 8 minutes to pick up all the paper garbage.
The glass garbage truck:
1. Collects the glass garbage at house 0
2. Travels from house 0 to house 1
3. Travels from house 1 to house 2
4. Collects the glass garbage at house 2
5. Travels from house 2 to house 3
6. Collects the glass garbage at house 3
Altogether, it takes 13 minutes to pick up all the glass garbage.
Since there is no metal garbage, we do not need to consider the metal garbage truck.
Therefore, it takes a total of 8 + 13 = 21 minutes to collect all the garbage.
Example 2:

Input: garbage = ["MMM","PGM","GP"], travel = [3,10]
Output: 37
Explanation:
The metal garbage truck takes 7 minutes to pick up all the metal garbage.
The paper garbage truck takes 15 minutes to pick up all the paper garbage.
The glass garbage truck takes 15 minutes to pick up all the glass garbage.
It takes a total of 7 + 15 + 15 = 37 minutes to collect all the garbage.
 

Constraints:

2 <= garbage.length <= 105
garbage[i] consists of only the letters 'M', 'P', and 'G'.
1 <= garbage[i].length <= 10
travel.length == garbage.length - 1
1 <= travel[i] <= 100



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



int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
#if 1
    int time_m = 0;
    int time_p = 0;
    int time_g = 0;
    int flag_m = 0;
    int flag_g = 0;
    int flag_p = 0;
    for(int i = garbageSize-1 ;i>=0;i--){
        int gcnt = strlen(garbage[i]);

        for(int g = 0;g<gcnt;g++){
            if(garbage[i][g] == 'M'){
                time_m++;
                flag_m=1;
            }else if(garbage[i][g] =='P'){
                time_p++;
                flag_p=1;
            }else if(garbage[i][g] == 'G'){
                time_g++;
                flag_g=1;
            }
        }
        printf("%d\n",i);
        if(i == 0)
            break;
        time_m+=travel[i-1]*flag_m;
        time_p+=travel[i-1]*flag_p;
        time_g+=travel[i-1]*flag_g;    
    }
    return (time_g+time_m+time_p);

#else
    int time_m = 0;
    int time_p = 0;
    int time_g = 0;
    for(int i = 0 ;i<garbageSize;i++){
        int gcnt = strlen(garbage[i]);
        for(int g = 0;g<gcnt;g++){
            if(garbage[i][g] == 'M'){
                time_m++;
            }else if(garbage[i][g] =='P'){
                time_p++;
            }else if(garbage[i][g] == 'G'){
                time_g++;
            }
        }
        
        if(i==(garbageSize-1))
            break;
        time_m+=travel[i];
        time_p+=travel[i];
        time_g+=travel[i];
    }
    return (time_g+time_m+time_p);
#endif    
}

int main(int argc, char** argv)
{
    char *garbage[] = {"G","P","GP","GG"};
    int travel[] = {2,4,3};
    //char *garbage[] = {"MMM","PGM","GP"};
    //int travel[] = {3,10};    
    int glen = sizeof(garbage)/sizeof(char*);
    int tlen = sizeof(travel)/sizeof(int);
    printf("len =%d %d\n",glen,tlen);

    int totaltime = garbageCollection(garbage,glen,travel,tlen);
    printf("min time =%d\n",totaltime);
    
    return 0;
}
