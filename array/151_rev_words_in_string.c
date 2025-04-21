/*

151. Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

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

#if 1

void *reverse(char* str ,int start,int end)
{
#if 1
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
#else
    char *st = str+start;
    char *ed = str+end;
    while(st<ed){
        char temp = *st;
        *st = *ed;
        *ed = temp;
        st++;
        ed--;
    }

#endif
}

char *reduce_space(char *str)
{
    int len = strlen(str);
    int start = 0;
    //int idx =0;
    int end = len-1;
    while(str[start]==' '){
        start++;
    }
    while(str[end]==' '){
        end--;
    }
    int idx = 0;
    for(int j = start;j<=end;j++){
        if(str[j] !=' '){
            str[idx++]=str[j];
        }else{
            if((j+1<=end) &&str[j+1]!=' ')
                str[idx++] = ' ';
        }
    }
    while(idx<len)
        str[idx++] = '\0';
    return str;
}


char* reverseWords(char* s)
{

    char *str = reduce_space(s);
    //printf("[%s]\n",str);
    int len = strlen(s);
    printf("%d\n",len);
    //reverse(s,0,len-1);
    reverse(str,0,len-1);
    int st = 0;
    int end = 0;

    for(end = 0;end<=len;end++){
        if(str[end] == ' '||str[end]=='\0'){
            reverse(str,st,end-1);
            st = end+1;
        }
    }
    
    //printf("[%s]\n",s);
    return str;
}

#else
void rev_single_worlds(char *begin,char *end)
{
    char temp;
    while(begin<end){
        temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}

char* reverseWords(char* s) {
    int len = strlen(s);
    //printf("%d\n",len);
    char *rstr = (char*)calloc(len,sizeof(char));
    //remove last space
    int idx = len-1;
    while(s[idx]==' '){
        idx--;
    }
    len = idx+1;
    //printf("%d\n",len);
    idx = 0;
    for(int i = len-1;i>=0;i--){
        //printf("[%c]\n",s[i]);
        if(s[i] !=' '){
            rstr[idx++] =s[i];
        }else{
            if((i-1>=0)&&(s[i-1]!=' '))
                rstr[idx++] = ' ';
        }
            
    }
    //printf("[%s]\n",rstr);


    char *begin = rstr;
    char *end = begin;
    idx = 0;
    len = strlen(rstr);
    printf("len =%d\n",len);
    //rev_single_worlds(rstr,rstr+4);
    //printf("[%s]\n",rstr);
    for(idx =0;idx<len;idx++){
        if(end[idx]==' '){
            //end = end+idx;
            rev_single_worlds(begin,&end[idx]-1);
            begin = &end[idx]+1;
        }
        //printf("end=%p\n",end);
        //end+=1;
    }
    //end=rstr+idx-1;
    //printf("idx=%d\n",idx);
    rev_single_worlds(begin,&end[idx]-1);

    //use while and poiinter , something error in leetcode
    //maybe some place index over range cause memory error
    //so change to for loop
#if 0    
    while((idx<len+1)&&end[idx]!='\0'){
    //while(*end!='\0'){
        //end++;
        if(*end == ' '){
            rev_single_worlds(begin,end-1);
            begin=end+1;
        }
        end++;
        idx++;
    }

    rev_single_worlds(begin,end-1);
#endif
    printf("[%s]\n",rstr);

    //return NULL;
    return rstr;
}

#endif


int main(int argc, char** argv)
{
    //char str[] = "the sky is blue";
    char str[] = "  hello world  ";
    //char str[] = "a good   example";
    printf("[%s]\n",str);
    char *revstr = reverseWords(str);
    if(revstr){
        
        printf("[%s]\n",revstr);
    }
    return 0;
}
