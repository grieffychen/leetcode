/*
141. Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?

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

bool hasCycle(struct ListNode *head) {
    return false;
}
struct ListNode* createnode(int val){
    struct ListNode *pnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    pnode->val = val;
    pnode->next = NULL;
    return pnode;
}



void append(struct ListNode **head, int val)
{
    struct ListNode *node = createnode(val);
    if (*head == NULL){
        *head = node;
        return;
    }
    struct ListNode *h = *head;
    while (h->next){
        h=h->next;
    }
    h->next = node;
}
void printlist(struct ListNode* head)
{
    //struct ListNode *cur = head;
    while(head){
        printf("%d ->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}


void freelist(struct ListNode* head)
{
    //struct ListNode *cur = head;
    while(head){
        struct ListNode *temp = head;
        head=head->next;
        free(temp);
    }
}

int main(int argc, char** argv)
{

    return 0;
}
