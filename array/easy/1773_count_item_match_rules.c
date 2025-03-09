/*
1773. Count Items Matching a Rule
You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == colori.
ruleKey == "name" and ruleValue == namei.
Return the number of items that match the given rule.

 

Example 1:

Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
Output: 1
Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
Example 2:

Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
Output: 2
Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.
 

Constraints:

1 <= items.length <= 104
1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10
ruleKey is equal to either "type", "color", or "name".
All strings consist only of lowercase letters.

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

enum{
    Type,
    color,
    name,
};


int countMatches(char ***items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int rkey = -1;
    if(strcmp(ruleKey,"type") ==0)
        rkey=Type;
    else if(strcmp(ruleKey,"color") ==0)
        rkey=color;
    else if(strcmp(ruleKey,"name") ==0)
        rkey = name;
    else
        return 0;
    int match = 0;
    printf("1\n");
    for(int i =0;i<itemsSize;i++){
        printf("%d\n",i);
        if(strcmp(items[i][rkey],ruleValue)==0)
            match++;
    }
    return match;
}

int main(int argc, char** argv)
{
#if 0    
    char* items[][3] = {{"phone","blue","pixel"},{"computer","silver","phone"},{"phone","gold","iphone"}};
    char* rulekey ="type";
    char* ruleValue = "phone";

    int cnt = countMatches(items,3,NULL,rulekey,ruleValue);
    printf("result =%d\n",cnt);
    //char *items[] ={"123","1231"};
#endif
    return 0;
}
