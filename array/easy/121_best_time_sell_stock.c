/*

121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104




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


int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    for(int i =0;i<pricesSize-1;i++){
        //int diff = 0;
        for(int j = i+1;j<pricesSize;j++){
            if(prices[j]>=prices[i])
                max = max>(prices[j]-prices[i])?max:(prices[j]-prices[i]);
        }
    }
    return max;
}

int maxProfit2(int* prices, int pricesSize) {
    int min =prices[0];
    int maxp = 0;
    for(int i =1;i<pricesSize;i++){
        min = min<prices[i]?min:prices[i];
        int cur = prices[i]-min;
        maxp = maxp>cur?maxp:cur;
    }
    return maxp;
}

int main(int argc, char** argv)
{   
    int prices[] = {7,1,5,3,6,4};
    int len = sizeof(prices)/sizeof(prices[0]);
    for(int i =0;i<len;i++){
        printf("%d ",prices[i]);
    }
    printf("\n");

    int ans = maxProfit(prices,len);
    printf("%d\n",ans);
    ans = maxProfit2(prices,len);
    printf("%d\n",ans);
    return 0;

}
