/*

61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
 

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
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* c = head;
    int ridx = 0;
    int len = 0;
    //struct ListNode* pre = NULL;
    //move to end of list and make it a circular list

    while(c->next){
        c=c->next;
        len++;
    }
    c->next = head;
    len++;
    printf("len =%d\n",len);
    int target_idx = len - k%len;
    printf("target =%d\n",target_idx);
    
    struct ListNode* pre = NULL;
    c = head;
    while(c->next){
        if(ridx ==target_idx){
            break;
        }
        ridx++;
        pre = c;
        c=c->next;
    }
    pre->next = NULL;

    return c;
}

int main(int argc, char** argv)
{
    //int nums[] = {1, 2, 3,4,5};
    //int k =2;
    //int nums[] = {1, 2, 3,4,5,6};
    int nums[] = {0,1, 2};
    int k = 4;
    struct ListNode* listhead = NULL;
    for (int i = 0;i<sizeof(nums)/sizeof(int);i++){
        appendlist(&listhead,nums[i]);
    }
    printlist(listhead);
    //printlistnode(listhead);
    //printf("=========================\n");
    struct ListNode* anslist = rotateRight(listhead,k);
    printf("=========================\n");
    printlist(anslist);
    //printlistnode(anslist);
    if(anslist)
        freelist(&anslist);
    return 0;
}
