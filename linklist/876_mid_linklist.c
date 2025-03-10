/*
876. Middle of the Linked List
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

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


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* listarr[100];
    int len = 0;

    while(head){
        listarr[len++] = head;
        head= head->next;
    }
    if(len%2==0)
        return listarr[len/2+1];
    else
        return listarr[len/2];
}

void append(struct ListNode **head, int val)
{
    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    if(*head == NULL){
        *head = node;
        return;
    }
    struct ListNode *cur = *head;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = node;
}
void printlist(struct ListNode *head)
{
    while(head){
        printf("%d->",head->val);
        head=head->next;
    }
    printf("\n");
}

void freelist(struct ListNode *head)
{
    while (head){
        struct ListNode *n = head;
        head = head->next;
        free(n);
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
    struct ListNode *midhead = middleNode(head);
    printlist(midhead);
    freelist(head);
    return 0;
}
