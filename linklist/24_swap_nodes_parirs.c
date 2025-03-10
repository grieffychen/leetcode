/*
24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:



Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]

 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
 

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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode{
    int val;
    struct ListNode *next;    
};

struct ListNode* createnode(int val)
{
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void appendlist(struct ListNode** head,int val)
{
    struct ListNode* node = createnode(val);
    if(!(*head)){
        *head = node;
        return;
    }
    struct ListNode* h = *head;
    while(h->next){
        h=h->next;
    }
    h->next = node;
}

void printlist(struct ListNode* head)
{
    while(head){
        printf("%d ->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void printlistnode(struct ListNode* head)
{
    while(head){
        printf("%d ,%p->%p\n",head->val,head ,head->next);
        head = head->next;
    }
    //printf("NULL\n");
}

void freelist(struct ListNode** head)
{
    struct ListNode* h = *head;
    while (h){
        struct ListNode* temp = h;        
        h = h->next;
        if(temp)
            free(temp);
    }
    *head = NULL;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    int idx  = 0;
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;

    while(cur){
        if((idx%2) == 0){
            struct ListNode* next = cur->next;
            if(next){
                cur->next = next->next;
                next->next = cur;
                cur = next;
                if(pre)
                    pre->next = cur;                
                if(idx == 0)
                    head = cur;
            }
        }
        printf("%d c =%p-> n=%p\n",cur->val,cur,cur->next);
        pre = cur;
        idx++;
        cur = cur->next;
    }
    return head;
}

int main(int argc, char** argv)
{
    //int nums[] = {1, 2, 3,4};
    //int nums[] = {1, 2, 3,4,5,6};
    int nums[] = {1, 2, 3};
    struct ListNode* listhead = NULL;
    for (int i = 0;i<sizeof(nums)/sizeof(int);i++){
        appendlist(&listhead,nums[i]);
    }
    printlist(listhead);
    printlistnode(listhead);
    printf("=========================\n");
    struct ListNode* anslist = swapPairs(listhead);
    printf("=========================\n");
    printlist(anslist);
    printlistnode(anslist);
    if(listhead)
        freelist(&listhead);
    return 0;
}
