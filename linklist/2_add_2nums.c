/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

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

#define bf 0
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
    //struct ListNode* lh = *head;
    //empty list
    if(*head ==NULL){
        struct ListNode* node = createnode(val);
        *head = node;
        return;
    }
    // not empty list 
    struct ListNode* lh = *head;
    struct ListNode* node = createnode(val);
    while(lh->next){
        lh=lh->next;
    }
    lh->next = node;
}

void printflist(struct ListNode* head){
    while(head){
        printf("%d->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void freelist(struct ListNode** head){
    struct ListNode* h = *head;

    while(h){
        struct ListNode* temp = h;
        h=h->next;
        if(temp)
            free(temp);
    }
    *head = NULL;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
#if bf
    int l1val = 0;
    int p = 0;
    while(l1){
        l1val = l1val+l1->val*((int)pow(10,p));
        p++;
        l1=l1->next;
    }
    printf("l1val=%d\n",l1val);

    int l2val = 0;
    p = 0;
    while(l2){
        l2val = l2val+l2->val*((int)pow(10,p));
        p++;
        l2=l2->next;
    }
    printf("l2val=%d\n",l2val);

    int sum = l1val+l2val;

    struct ListNode* anslist = NULL;
    if(sum==0){
        appendlist(&anslist,0);
        return anslist;
    }   

    while(sum){
        int val = sum%10;
        appendlist(&anslist,val);
        sum=sum/10;
    }

    return anslist;
#else
    int carry = 0;
    struct ListNode* anslist = NULL;
    while(l1 ||l2||carry){
        int l1val = 0;
        int l2val = 0;
        //int sum = 0;
        
        int mod =0;
        if(l1){
            //printf("l1=%d\n",l1->val);
            l1val = l1->val;
        }
        if(l2){
            //printf("l2=%d\n",l2->val);
            l2val = l2->val;
        }
        mod = (l1val+l2val+carry) %10;
        carry = (l1val+l2val+carry)/10;
        
        appendlist(&anslist,mod);
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;

    }
    return anslist;
#endif    
}

int main(int argc, char** argv)
{
    //int l1[] = {2,4,3};
    //int l2[] = {5,6,4};
    int l1[] = {9,9,9,9,9,9,9};
    int l2[] = {9,9,9,9};
    //int l1[] = {9};
    //int l2[] = {1,9,9,9,9,9,9,9,9,9};
    
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;
    for(int i = 0;i<sizeof(l1)/sizeof(int);i++){
        appendlist(&list1,l1[i]);
    }
    for(int i = 0;i<sizeof(l2)/sizeof(int);i++){
        appendlist(&list2,l2[i]);
    }
    printflist(list1);
    printflist(list2);

    struct ListNode* anslist = addTwoNumbers(list1,list2);
    printflist(anslist);
    freelist(&list1);
    freelist(&list2);
    return 0;
}
