/*
71. Simplify Path

You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.

 

Example 1:

Input: path = "/home/"

Output: "/home"

Explanation:

The trailing slash should be removed.

Example 2:

Input: path = "/home//foo/"

Output: "/home/foo"

Explanation:

Multiple consecutive slashes are replaced by a single one.

Example 3:

Input: path = "/home/user/Documents/../Pictures"

Output: "/home/user/Pictures"

Explanation:

A double period ".." refers to the directory up a level (the parent directory).

Example 4:

Input: path = "/../"

Output: "/"

Explanation:

Going one level up from the root directory is not possible.

Example 5:

Input: path = "/.../a/../b/c/../d/./"

Output: "/.../b/d"

Explanation:

"..." is a valid name for a directory in this problem.

 

Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
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


char* simplifyPath(char* path) {
#if 1
    int len = (int)strlen(path);
    char *stack = (char*) malloc((len+1)*sizeof(char));
    int top = -1;
    stack[++top] = path[0];

    for(int i = 1;i<len;i++){
        if((path[i] == '/') &&((stack[top] =='/')||(path[i+1]=='\0')||(top == 0)))
            continue;
        if((path[i-1] =='/')&&(path[i] == '.')&&(path[i+1]=='.')&&((path[i+2]=='/')||(path[i+2]=='\0'))){
            if(i != 1 &&top !=0)
                top--;
            //else{
            while((top!=-1)&&(stack[top]!='/')){
                top--;
            }
            i+=2;
            
        }else if((path[i-1]=='/')&&(path[i]=='.')&&((path[i+1]=='/')||(path[i+1]=='\0'))){
            if(i!=1&&top!=0)
                top--;
        }else{

            stack[++top] = path[i];
        }
        stack[top+1] ='\0';
    }
    if(top>0&&stack[top] == '/')
        top--;
    stack[top+1] = '\0';

    return stack;
#else
    char *stack = (char*)malloc((strlen(path)+1)*sizeof(char));
    int top = -1;
    int idx = 0;
    stack[++top] = path[idx++];
    while(path[idx]!='\0'){
        //if((path[idx] !='.')||(path[idx]!='/')){
        if(path[idx]!='/'){
            stack[++top] = path[idx];
        }else{
            if((path[idx] =='/')&&(stack[top] != '/' )){ //only one '/' , push to the stack
                stack[++top] = path[idx];
            }else if((path[idx] =='/')&&(stack[top] != '/' )){ // multi '/' ignore 

            }else if((path[idx] =='/')&&stack[top] == '.'){
                int dotcnt = 0;
                while(top>0){
                    if(stack[top] == '.'){
                        dotcnt++;
                    }else if(stack[top] == '/'){

                    }
                    top--;
                }
            }
        }
        idx++;
    }
    return stack;   
#endif    
}


int main(int argc, char** argv)
{
    //char *path = "/home//foo/";
    //char *path = "/home/user/Documents/../Pictures"
    //char *path = "/../";
    char *path = "/.../a/../b/c/../d/./";
    
    printf("path =%s\n",path);
    //printf("%d\n",sizeof(char));
    char *simple_path = simplifyPath(path);
    if(simple_path){
        printf("simple =%s\n",simple_path);
        free(simple_path);
    }

    return 0;
}