/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
Accepted
1.6M
Submissions
3.1M
Acceptance Rate
50.8%

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

void printlist(struct ListNode* head);

bool isPalindrome(struct ListNode* head){
    struct ListNode *revhead = NULL;
    struct ListNode *orihead = head;
    
    while(orihead){
        struct ListNode *node =  (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = orihead->val;
        node->next = NULL;
        if(!revhead){
            revhead = node;
        }else{
            node->next = revhead;
            revhead = node;
        }
        orihead = orihead->next;
    }
    //printlist(revhead);
    while(head && revhead){
        if(head->val != revhead->val)
            return false;
        head = head->next;
        revhead = revhead->next;
    }

    return true;
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
    struct ListNode *lista = NULL;
    append(&lista,1);
    append(&lista,1);
    append(&lista,2);
    append(&lista,1);
    append(&lista,1);
    printlist(lista);
    //isPalindrome(lista);
    printf("the list %s plaindrome\n",isPalindrome(lista)?"is":"is not");
    freelist(lista);
    return 0;
}
