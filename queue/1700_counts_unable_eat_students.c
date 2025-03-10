#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct qnode_tag{
    int st_pref;
    struct qnode_tag *next;
}qnode_t,*pqnode_t;

pqnode_t create_node(int data)
{
    pqnode_t n = (pqnode_t) malloc(sizeof(struct qnode_tag));
    n->st_pref = data;
    n->next = NULL;
    return n;
}

void enqueue(pqnode_t *pqhead , int pref)
{
    pqnode_t n = create_node(pref);
    if(*pqhead == NULL){
        *pqhead = n;
    }else{
        pqnode_t cur = *pqhead;
        while(cur->next){
            cur= cur->next;
        }
        cur->next = n;
    }
}

int dequeue(pqnode_t *pqhead)
{

    pqnode_t cur = *pqhead;
#if 0
    if(cur->next!=NULL){
        int pref = cur->st_pref;
        pqhead = cur->next;
        free(cur);
        return pref;
    }else{
        int pref = cur->st_pref;
        free(cur);
        pqhead = NULL;
        return pref;
    }
#else
    int pref = cur->st_pref;
    if(cur->next!=NULL)
        *pqhead = cur->next;
    else
        *pqhead = NULL;
    free(cur);
    return pref;
#endif
}

void release_queuue(pqnode_t *pqhead){
    pqnode_t cur = *pqhead;
    while(cur){
        pqnode_t temp = cur;
        cur= cur->next;
        free(temp);
    }
    *pqhead = NULL;
}

void print_queue(pqnode_t pqhead){
    pqnode_t cur = pqhead;
    while(cur){
        printf(" %d-->",cur->st_pref);
        cur = cur->next;
    }
    printf("NULL\n");
}


int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    pqnode_t p_listqhead = NULL;
    for (int i =0;i<studentsSize;i++){
        enqueue(&p_listqhead,students[i]);
        printf("head=%p\n",p_listqhead);
    }
    print_queue(p_listqhead);
    int top = 0;
    int try_cnt = 0;
    int remain = studentsSize;
    while(p_listqhead!=NULL){
        int student_pref = dequeue(&p_listqhead);
        if(student_pref == sandwiches[top]){
            top++;
            remain--;
            try_cnt = 0;
        }else{
            enqueue(&p_listqhead,student_pref);
            try_cnt++;
        }
        if(try_cnt == remain)
            break;
    }

    release_queuue(&p_listqhead);
    return remain;
}


int main(const int argc, const char **argv)
{
    //int students[] ={1,1,0,0};
    //int sandwitches[] ={0,1,0,1};
    int students[] ={1,1,1,0,0,1};
    int sandwitches[] ={1,0,0,0,1,1};
    int stsize = sizeof(students)/sizeof(int);
    int sandsize = sizeof(sandwitches)/sizeof(int);
    int unables = countStudents(students,stsize,sandwitches,sandsize);    


    printf("unable eat students =%d\n",unables);
    return 0;
}