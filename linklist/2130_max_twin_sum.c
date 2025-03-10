/*
2130. Maximum Twin Sum of a Linked List


In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 

Example 1:


Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 
Example 2:


Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
Example 3:


Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.

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

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* create_node(int val)
{
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
}

void append_list(struct ListNode** head,int val)
{
    struct ListNode* n = create_node(val);
    if(*head == NULL){
        *head = n;
        return;
    }
    struct ListNode* cur = *head;
    while(cur->next){
        cur=cur->next;
    }
    cur->next = n;
}

void printlist(struct ListNode* lh)
{
    while(lh){
        printf("%d->",lh->val);
        lh=lh->next;
    }
    printf("NULL\n");
}

void freelist(struct ListNode* lh)
{
    while(lh){
        struct ListNode* temp = lh;
        lh=lh->next;
        free(temp);
    }
}

struct ListNode* reverse_list(struct ListNode* head)
{
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    while(cur->next){
        struct ListNode* next = cur->next;
        cur->next = pre;
        pre=cur;
        cur=next;
    }
    cur->next = pre;
    return cur;
}

int pairSum(struct ListNode* head) {
    int *buf = (int*) malloc(sizeof(int)*1);

    struct ListNode* cur = head;
    int cnt = 0;
    while(cur->next){
        buf[cnt] = cur->val;
        cur=cur->next;
        cnt++;
        buf = (int*)realloc(buf,sizeof(int)*(cnt+1));
    }
    buf[cnt] = cur->val;
    int max = 0;
    int len = cnt+1;
    for(int i =0;i<len;i++){
        printf("%d ",buf[i]);
    }
    printf("\n");
    for(int i = 0;i<len/2;i++){
        max = (buf[i]+buf[len-i-1])>max?(buf[i]+buf[len-i-1]):max;
    }

    return max;
}


int pairSum2(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
#if 0    
    struct ListNode* testlist = head;
    testlist = reverse_list(testlist);
    printlist(testlist);
#endif    
    while((fast!=NULL)&&(fast->next!=NULL)){
        slow=slow->next;
        fast=fast->next->next;
    }
    printlist(slow);
    slow = reverse_list(slow);

    struct ListNode* cur = head;
    printlist(slow);
    int max = 0;
    while(slow){
        int sum = slow->val+cur->val;
        printf("%d %d sum=%d\n",slow->val,cur->val,sum);
        max = sum>max?sum:max;
        slow=slow->next;
        cur=cur->next;
    }

    return max;
}

int main(int argc, char** argv)
{
    //list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
    int buf[]= {47,22,81,46,94,95,90,22,55,91,6,83,49,65,10,32,41,26,83,99,14,85,42,99,89,69,30,92,32,74,9,81,5,9};
    int buflen = sizeof(buf)/sizeof(int);


    struct ListNode* list1 = NULL;
    
#if 1
    for(int i = 0;i<buflen;i++)
        append_list(&list1,buf[i]);
#else
    append_list(&list1,4);
    append_list(&list1,2);
    append_list(&list1,2);
    append_list(&list1,3);
#endif

    printlist(list1);

    //int max = pairSum(list1);
    int max = pairSum2(list1);
    printf("max =%d\n",max);
    freelist(list1);
    //freelist(list2);
    return 0;
}
