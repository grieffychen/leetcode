/*
143. Reorder List
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
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

struct ListNode* create_node(int val)
{
    struct ListNode* n = (struct ListNode*) malloc(sizeof(struct ListNode));
    n->val = val;
    n->next = NULL;
    return n;
}

void appendlist(struct ListNode **head , int val)
{
    struct ListNode *n = create_node(val);
    struct ListNode *cur = *head;
    if(*head==NULL){
        *head = n;
        return;
    }
    while(cur->next){
        cur= cur->next;
    }
    cur->next = n;
    return;
}

void printlist(struct ListNode *head )
{
    while(head){
        printf("%d ->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void freelist(struct ListNode **head){
    struct ListNode *cur = *head;
    while(cur){
        struct ListNode *temp = cur;
        cur=cur->next;
        free(temp);
    }
    *head = NULL;
}


void reorderList(struct ListNode* head) {
    int len = 0;
    struct ListNode* cur = head;
    while(cur){
        len++;
        cur=cur->next;
    }
    struct ListNode **stack =(struct ListNode **) malloc(sizeof(struct ListNode*)*(len/2+1));
    int top = -1;
    int idx = 0;
    cur = head;
    while(cur){
        if(idx>len/2){
            stack[++top] = cur;
        }
        idx++;     
        cur=cur->next;
    }
    for(int i = 0 ;i<=top;i++)
        printf("%d ",stack[i]->val);
    printf("\n");
    cur = head;
    while(top!=-1){
        struct ListNode* node = stack[top--];
        struct ListNode* next = cur->next;
        if(top == -1){
            if(len%2==0)
                next->next->next = NULL;
            else
                next->next = NULL;
        }
        node->next = next;
        cur->next = node;
        cur = next;
    }   
    if(stack)
        free(stack);
}


int main(int argc, char** argv)
{
    int value[] = {1,2,3,4,5,6};
    //int value[] = {1,2,3,4,5};
    struct ListNode *head = NULL;

    for (int i = 0;i<sizeof(value)/sizeof(int);i++){
        appendlist(&head,value[i]);
    }

    printlist(head);
    
    reorderList(head);
    printlist(head);
    if(head)
        freelist(&head);

    return 0;
}