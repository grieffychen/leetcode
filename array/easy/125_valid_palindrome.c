/*

125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

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


bool isPalindrome(char* s) {
    int len = strlen(s);
    printf("len =%d\n",len);
    if(len==1 &&s[0]==' ')
        return true;
    char *tstr =(char*) calloc(len+1,sizeof(char));
    //filter the string
    int idx =0;
    for(int i = 0;i<len;i++){
        if((s[i]>='a')&&(s[i]<='z')){
            tstr[idx++] = s[i];
        }else if((s[i]>='A')&&(s[i]<='Z')){
            tstr[idx++] = s[i] -'A'+'a';
        }else if((s[i]>='0')&&(s[i]<='9')){
            tstr[idx++] = s[i];
        }   
    }
    len = strlen(tstr);
    printf("%d [%s]\n",len,tstr);
    int l = 0;
    int r = len-1;
    bool ans = true;
    while(l<=r){
        if(tstr[l]!=tstr[r]){
            ans = false;
            break;
        }
        l++;
        r--;
    }
    if(tstr)
        free(tstr);
    return ans;
}


int main(int argc, char** argv)
{
    //char s[] = "A man, a plan, a canal: Panama";
    //char s[] = "race a car";
    char s[] = "0P";
    //char s[]=" ";
    bool res = isPalindrome(s);
    printf("[%s]%s palindrome\n",s,res?"is":"is not");
    return 0;

}
