/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.

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


int getDecimalValue(struct ListNode* head){
    int dec = 0;
    struct ListNode* h = head;
    while(head){
        if (head == h){
            dec = head->val;
        }else{
            dec=dec<<1;
            dec|=head->val;
        }
        head = head->next;
    }

    return dec;
}

void append(struct ListNode **head, int val)
{
    struct ListNode *node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = val;
    if(*head ==NULL){
        *head = node;
        return ;
    }
    struct ListNode* cur = *head;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = node;
}

void printlist(struct ListNode *head)
{
    //struct ListNode *cur = head;
    while(head!=NULL){
        printf("%d ->",head->val);
        head = head->next;
    }
    printf("\n");
}

void freelist(struct ListNode *head)
{
    while(head->next!=NULL)
    {
        struct ListNode *next = head->next;
        free(head);
        head = next;
    }
    head = NULL;
}

int main(int argc, char** argv)
{
    struct ListNode *head = NULL;
    append(&head,1);
    append(&head,0);
    append(&head,1);
    printlist(head);
    int dec = getDecimalValue(head);
    printf("dec =%d\n",dec);
    freelist(head);

    return 0;
}
