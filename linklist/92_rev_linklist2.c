/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse 
the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

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

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
	if(head==NULL ||(left==right) ){
		return head;
	}
	
	struct ListNode *dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
	dummy->val = -1;
	dummy->next = head;
	struct ListNode* pre = dummy;
	for (int i = 1;i<left;i++){
		pre=pre->next;
	}
	struct ListNode* cur = pre->next;
	struct ListNode* after = cur->next;
	for(int i = 0;i<right-left;i++){
		cur->next = after->next;
		after->next = pre->next;
		pre->next = after;
		after = cur->next;
	
	}	
	return dummy->next;	    
}

struct ListNode *create_node(int val)
{
	struct ListNode* n =(struct ListNode*)malloc(sizeof(struct ListNode));
	n->val = val;
	n->next = NULL;
	return n;
}

void append_list(struct ListNode** head,int val)
{
	struct ListNode* n = create_node(val);
	if(*head == NULL){
		*head = n;
		return;
	}
	struct ListNode* cur = *head;
	while(cur->next){
		cur= cur->next;
	}
	cur->next = n;
}

void print_list(struct ListNode *head)
{
	while(head){
		printf("%d ->",head->val);
		head = head->next;
	}
	printf("NULL\n");
}

void freelist(struct ListNode** head)
{
	struct ListNode *cur = *head;
	while(cur){
		struct ListNode *temp = cur;
		cur=cur->next;
		free(temp);
	}
	*head = NULL;
}


int main(int argc, char**argv)
{
	struct ListNode *head = NULL;
	append_list(&head,1);
	append_list(&head,2);
	append_list(&head,3);
	append_list(&head,4);
	append_list(&head,5);
	print_list(head);
	struct ListNode* revh =  reverseBetween(head,2,4);
	print_list(head);

	freelist(&head);
	return 0;
}
