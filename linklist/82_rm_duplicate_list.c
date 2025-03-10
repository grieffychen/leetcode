/*
82. Remove Duplicates from Sorted List II

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

 

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur = head;
    
    struct ListNode* pre = (struct ListNode*) malloc(sizeof(struct ListNode));
    pre->next = head;
    struct ListNode* dummy = pre;
    //bool is_dup = false;
    while(cur){
        bool is_dup = false;
        //struct ListNode* n = cur->next;
        //while(n&&(cur->val == n->val)){
        printf("cur=%p\n",cur);
        while(cur->next&&(cur->val == cur->next->val)){
            //n=n->next;
            cur=cur->next;
            is_dup = true;
        }
        printf("val=%d cur=%p next =%p\n",cur->val,cur,cur->next);
        if(is_dup){
            pre->next = cur->next;
            is_dup = false;
        }else{
            pre = cur;
        }
        cur=cur->next;
    }
    return dummy->next;
}

int main(int argc, char** argv)
{
    //int nums[] = {1,2,3,3,4,4,5};
    //int k =2;
    int nums[] = {1,1,1,2,3};
    //int nums[] = {1,2,3,3,4,4,5};
    //int k = 4;
    struct ListNode* listhead = NULL;
    for (int i = 0;i<sizeof(nums)/sizeof(int);i++){
        appendlist(&listhead,nums[i]);
    }
    printlist(listhead);
    printlistnode(listhead);
    //printf("=========================\n");
    struct ListNode* anslist = deleteDuplicates(listhead);
    printf("=========================\n");
    printlist(anslist);
    //printlistnode(anslist);
    if(listhead)
        freelist(&listhead);
    return 0;
}
