/*

206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
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

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    
    while((cur!=NULL)&&(cur->next!=NULL)){
        //printf("cur=%p next=%p pr=%p\n",cur,cur->next,pre);
        struct ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        //printf("pre=%p\n",pre);
        cur = next;
        //printf("cur=%p\n",cur);
    }
    if(cur!=NULL)
        cur->next = pre;
    return cur;
}
void append(struct ListNode **head, int val)
{
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    if(*head == NULL){
        *head = node;
        return;
    }
    struct ListNode* cur = *head;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = node;
}
void printlist(struct ListNode *head)
{
    while(head){
        printf("%d->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void printlistpoint(struct ListNode *head)
{
    while(head){
        printf("%p->%p\n",head,head->next);
        head = head->next;
    }
    //printf("NULL\n");
}

void freelist(struct ListNode *head)
{
    while(head){
        struct ListNode* node = head;
        head=head->next;
        free(node);
    }
    head = NULL;
}

int main(int argc, char** argv)
{
    struct ListNode *head = NULL;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    printlist(head);
    printlistpoint(head);
    struct ListNode* revhead = reverseList(head);
    printlist(revhead);
    freelist(head);
    return 0;
}
