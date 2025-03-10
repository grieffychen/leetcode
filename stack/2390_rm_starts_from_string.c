/*
2390. Removing Stars From a String

You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters and stars *.
The operation above can be performed on s.
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
//#include <stdio.h>
#include <string.h>

char* removeStars(char* s) {
    int len = strlen(s)+1;
    printf("%s\n",s);
    char *stk = (char*)malloc(sizeof(char)*len);
    int top = -1;
    for(int i =0;i<len-1;i++){
        if(s[i]!='*'){
            stk[++top] = s[i];
        }else{
            if(top!=-1)
                top--;
        }
    }
    stk[++top] = '\0';
    return stk;
}

int main(const int argc, const char **argv)
{
    char *s = "leet**cod*e";
    char *ans = removeStars(s);
    if(ans){
        printf("%s\n",ans);
        free(ans);
    }
    return 0;
}