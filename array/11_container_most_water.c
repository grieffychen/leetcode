/*
11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1

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

int maxArea(int* height, int heightSize)
{
    int l_idx = 0;
    int r_idx = heightSize-1;
    int area = 0;
    int max_area = 0;
    while(l_idx<r_idx){
        area = (r_idx-l_idx) *(height[l_idx]<height[r_idx]?height[l_idx]:height[r_idx]);
        if(area>max_area)
            max_area = area;
        if(height[l_idx]<height[r_idx])
            l_idx++;
        else
            r_idx--;
    }

    return max_area;
}


int main(int argc, char** argv)
{
    int height_arr[] = {1,8,6,2,5,4,8,3,7};
    int len = sizeof(height_arr)/sizeof(int);
    for (int i = 0;i<len;i++){
        printf("%d ",height_arr[i]);
    }
    printf("\n");
    int area = maxArea(height_arr,len);
    printf("max area =%d\n",area);
    return 0;
}