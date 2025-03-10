/*
86. Partition List

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
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

struct ListNode* partition(struct ListNode* head, int x) {
    //struct ListNode *smallhead = NULL;
    struct ListNode *cur = head;
    int vec[200];
    int len = 0;
    while(cur){
        if(cur->val<x){
            vec[len++] = cur->val;
        }
        cur=cur->next;
    }
    cur = head;
    while(cur){
        if(cur->val>=x)
            vec[len++]=cur->val;
        cur=cur->next;
    }
    
    for(int i = 0;i<len;i++)
        printf("%d ",vec[i]);
    printf("\n");
    cur = head;
    len = 0;
    while(cur){
        cur->val = vec[len++];
        cur=cur->next;
    }

    return head;
}

struct ListNode* create_node(int val)
{
    struct ListNode* n = (struct ListNode*) malloc(sizeof(struct ListNode));
    n->val = val;
    n->next = NULL;
    return n;
}

void appendlist(struct ListNode** head,int val)
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

void printlist(struct ListNode* head)
{
    while(head){
        printf("%d->",head->val);
        head=head->next;
    }
    printf("NULL\n");
}

void freelist(struct ListNode** head)
{
    struct ListNode* cur = *head;
    while(cur){
        struct ListNode* temp = cur;
        cur=cur->next;
        free(temp);
    }
    *head = NULL;
}
int main(int argc, char** argv)
{
    struct ListNode* head = NULL;
    int x = 3;
    appendlist(&head,1);
    appendlist(&head,4);
    appendlist(&head,3);
    appendlist(&head,2);
    appendlist(&head,5);
    appendlist(&head,2);
    printlist(head);
    partition(head,x);
    printlist(head);
    freelist(&head);
    return 0;
}
