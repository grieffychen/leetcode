/*

187. Repeated DNA Sequences

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.


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


#define bf 1

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRepeatedDnaSequences(char* s, int* returnSize) {
    if(strlen(s)<=10){
        *returnSize = 0;
        return NULL;
    }
    char **ansstr_arry = (char**) malloc(sizeof(char*)*(strlen(s)-10));
    int cntseq = 0;

    for(int i = 0;i<strlen(s)-10;i++){
        char *cmpstr = (char*)malloc(sizeof(char)*11);
        strncpy(cmpstr,s+i,10);
        cmpstr[10]='\0';
        //printf("cmp=%s\n",cmpstr);
        //printf("=============\n");
        printf("left string %d =%s\n",i+1,s+i+1);
        if(strstr(s+i+1,cmpstr)!=NULL){
            //printf("left string %d =%s\n",i+1,s+i+1);
            
            //check if match array already in ansarr string;
            //if not in the list append to the asnwer string array
            bool inlist = false;
            for(int j = 0;j<cntseq;j++){
                if(strcmp(ansstr_arry[j],cmpstr)==0){
                    inlist = true;
                    break;
                }
            }
            if(!inlist){
                ansstr_arry[cntseq] = cmpstr;
                cntseq++;
            }
        }
        //printf("==============\n");
    }
    *returnSize = cntseq;
    return ansstr_arry;
}

int main(int argc, char** argv)
{

    char *str  = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    //char *str = 
    
    //char *str ="AAAAAAAAAAAAA";
    //printf("%s\n",str);
    printf("===========================================\n");
    int retlen = 0;
    char **ansstr = findRepeatedDnaSequences(str,&retlen);

    printf("====answer ====\n");
    for (int i = 0; i<retlen;i++){
        printf("%s\n",ansstr[i]);
    }

    if(ansstr){
        for(int i = 0;i<retlen;i++)
            free(ansstr[i]);
        free(ansstr);
    }
    return 0;
}

