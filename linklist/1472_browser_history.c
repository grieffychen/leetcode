/*
1472. Design Browser History

You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
 

Example:

Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
 

Constraints:

1 <= homepage.length <= 20
1 <= url.length <= 20
1 <= steps <= 100
homepage and url consist of  '.' or lower case English letters.
At most 5000 calls will be made to visit, back, and forward.

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

typedef struct hnode_tag{
    char* history;
    struct hnode_tag *next;
    struct hnode_tag *pre;
}hnode_t,*phnode_t;

#if 1
typedef struct {
    phnode_t head;
    phnode_t cur;
}BrowserHistory;

#else
typedef struct {
    phnode_t history_list;
    phnode_t curlisthead;
}BrowserHistory;
#endif
phnode_t create_node(char *url);
void append_list(phnode_t *head,char* url);
void print_history(phnode_t head);
void freehistory(phnode_t head);

phnode_t create_node(char *url)
{
    phnode_t node = (phnode_t) malloc(sizeof(struct hnode_tag));
    node->history = url;
    node->next = NULL;
    node->pre = NULL;
}

#if 1
void append_list(phnode_t *head,char* url)
{
    phnode_t n = create_node(url);
    if(*head == NULL){
        *head = n;
        return ;
    }
    phnode_t cur = *head;
    n->pre = cur;
    cur->next = n;
}

void print_history(phnode_t head)
{
    printf("forward: ");
    phnode_t cur = head;
    while(cur->next){
        printf("%s ->",cur->history);
        cur=cur->next;
    }
    printf("%s ->NULL\n",cur->history);
    printf("backward: ");
    while(cur->pre){
        printf("%s ->",cur->history);
        cur=cur->pre;
    }
    printf("%s ->NULL\n",cur->history);
}

void freehistory(phnode_t head)
{
    while(head){
        phnode_t temp = head;
        head=head->next;
        free(temp);
    }
}

BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory *obj = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    obj->cur = NULL;
    append_list(&obj->cur,homepage);
    obj->head = obj->cur;
    return obj;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    if(obj->cur->next)
        freehistory(obj->cur->next);
    obj->cur->next = NULL;        
    append_list(&obj->cur,url);
    obj->cur=obj->cur->next;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    phnode_t cur = obj->cur;
    int cnt = 0;
    //char *url = NULL;
    while(cur->pre!=NULL){
        cnt++;
        cur=cur->pre;
        if(cnt == steps)
            break;
    }
    //url = cur->history;
    obj->cur = cur;    
    //return url;
    return obj->cur->history;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    phnode_t cur = obj->cur;
    int cnt = 0 ;
    //char *url = NULL;
    while(cur->next){
        cnt++;
        cur=cur->next;
        if(cnt==steps)
            break;
    }
    obj->cur = cur;
    return obj->cur->history;
}

void browserHistoryFree(BrowserHistory* obj) {
    freehistory(obj->head);
    obj->cur = NULL;
    obj->head = NULL;
}

int main(int argc, char** argv)
{
#if 0    
    phnode_t testlist = NULL;
    append_list(&testlist,"leetcode.com");
    append_list(&testlist,"google.com");
    append_list(&testlist,"facebook.com");
    append_list(&testlist,"youtube.com");
    print_history(testlist);
    freehistory(testlist);
#endif
    BrowserHistory* browse_obj = browserHistoryCreate("leetcode.com");
    
    browserHistoryVisit(browse_obj,"google.com");
#if 1    
    browserHistoryVisit(browse_obj,"facebook.com");    
    browserHistoryVisit(browse_obj,"youtube.com");
    print_history(browse_obj->cur);

    char *h1 = browserHistoryBack(browse_obj,1);
    printf("history bk: %s\n",h1);
    char *h2 = browserHistoryBack(browse_obj,1);
    printf("history bk: %s\n",h2);
    //char *h3 = browserHistoryBack(browse_obj,7);
    //printf("history bk: %s\n",h3);
    char *f1 = browserHistoryForward(browse_obj,1);
    printf("history fw: %s\n",f1);

    browserHistoryVisit(browse_obj,"linkedin.com");
    print_history(browse_obj->cur);
#else   
    print_history(browse_obj->curlisthead);
    char *h1 = browserHistoryBack(browse_obj,1);
    printf("history bk: %s\n",h1);
    browserHistoryVisit(browse_obj,"linkedin.com");
    print_history(browse_obj->curlisthead);    
#endif
    browserHistoryFree(browse_obj);
    return 0;
}

#else
void append_list(phnode_t *head,char* url)
{
    phnode_t n = create_node(url);
    if(*head == NULL){
        *head = n;
        return ;
    }
    phnode_t cur = *head;
    while(cur->next){
        cur=cur->next;
    }
    n->pre = cur;
    cur->next = n;
}
void print_history(phnode_t head)
{
    printf("forward: ");
    phnode_t cur = head;
    while(cur->next){
        printf("%s ->",cur->history);
        cur=cur->next;
    }
    printf("%s ->NULL\n",cur->history);
    printf("backward: ");
    while(cur->pre){
        printf("%s ->",cur->history);
        cur=cur->pre;
    }
    printf("%s ->NULL\n",cur->history);
}
void freehistory(phnode_t head)
{
    while(head){
        phnode_t temp = head;
        head=head->next;
        free(temp);
    }
}

BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory *obj = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    obj->history_list = NULL;
    append_list(&obj->history_list,homepage);
    obj->curlisthead = obj->history_list;
    return obj;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    if(obj->curlisthead->next)
        freehistory(obj->curlisthead->next);
    obj->curlisthead->next = NULL;        
    append_list(&obj->history_list,url);
    obj->curlisthead = obj->curlisthead->next;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    phnode_t cur = obj->curlisthead;
    int cnt = 0;
    //char *url = NULL;
    while(cur->pre!=NULL){
        cnt++;
        cur=cur->pre;
        if(cnt == steps)
            break;
    }
    //url = cur->history;
    obj->curlisthead = cur;    
    //return url;
    return obj->curlisthead->history;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    phnode_t cur = obj->curlisthead;
    int cnt = 0 ;
    //char *url = NULL;
    while(cur->next){
        cnt++;
        cur=cur->next;
        if(cnt==steps)
            break;
    }
    obj->curlisthead = cur;
    return obj->curlisthead->history;
}

void browserHistoryFree(BrowserHistory* obj) {
    freehistory(obj->history_list);
    obj->curlisthead = NULL;
    obj->history_list = NULL;
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);
 
 * char* param_2 = browserHistoryBack(obj, steps);
 
 * char* param_3 = browserHistoryForward(obj, steps);
 
 * browserHistoryFree(obj);
*/

int main(int argc, char** argv)
{
#if 0    
    phnode_t testlist = NULL;
    append_list(&testlist,"leetcode.com");
    append_list(&testlist,"google.com");
    append_list(&testlist,"facebook.com");
    append_list(&testlist,"youtube.com");
    print_history(testlist);
    freehistory(testlist);
#endif
    BrowserHistory* browse_obj = browserHistoryCreate("leetcode.com");
    
    browserHistoryVisit(browse_obj,"google.com");
#if 1    
    browserHistoryVisit(browse_obj,"facebook.com");    
    browserHistoryVisit(browse_obj,"youtube.com");
    print_history(browse_obj->curlisthead);

    char *h1 = browserHistoryBack(browse_obj,1);
    printf("history bk: %s\n",h1);
    char *h2 = browserHistoryBack(browse_obj,1);
    printf("history bk: %s\n",h2);
    //char *h3 = browserHistoryBack(browse_obj,7);
    //printf("history bk: %s\n",h3);
    char *f1 = browserHistoryForward(browse_obj,1);
    printf("history fw: %s\n",f1);

    browserHistoryVisit(browse_obj,"linkedin.com");
    print_history(browse_obj->curlisthead);
#else   
    print_history(browse_obj->curlisthead);
    char *h1 = browserHistoryBack(browse_obj,1);
    printf("history bk: %s\n",h1);
    browserHistoryVisit(browse_obj,"linkedin.com");
    print_history(browse_obj->curlisthead);    
#endif
    browserHistoryFree(browse_obj);
    return 0;
}
#endif