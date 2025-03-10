/*
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.

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

typedef struct data_tag
{
    int val;
    int min;
}data_t;

typedef struct {
    data_t *stack;
    int top;
} MinStack;


MinStack* minStackCreate() {
    
    MinStack* obj=(MinStack*) malloc(sizeof(MinStack));
    obj->stack =(data_t*) malloc(sizeof(data_t)*30000);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    data_t d;
    d.val = val;
    if(obj->top ==-1){
        d.min = val;
    }else{
        if(d.val <= obj->stack[obj->top].min)
            d.min = d.val;
        else
            d.min = obj->stack[obj->top].min;
    }
    obj->stack[++obj->top] = d;
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->stack[obj->top].min;
}

void minStackFree(MinStack* obj) {
    if(obj->stack)
        free(obj->stack);
    if(obj)
        free(obj);
}


int main(int argc, char** argv)
{
    MinStack *minstack = minStackCreate(); 
    minStackPush(minstack, -2);
    minStackPush(minstack, 0);
    minStackPush(minstack, -3);
    printf("min =%d\n",minStackGetMin(minstack));
    minStackPop(minstack);
    printf("top =%d\n",minStackTop(minstack));
    printf("min =%d\n",minStackGetMin(minstack));

    minStackFree(minstack);
    return 0;
}