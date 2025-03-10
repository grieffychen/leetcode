#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct node_tag{
    int pid;
    struct node_tag *next;
}node_t,*pnode_t;

pnode_t create_node(int person_id);
void display(pnode_t pcqhead);
void release(pnode_t pcqhead);

pnode_t create_node(int person_id)
{
    pnode_t n = (pnode_t) malloc(sizeof(struct node_tag));
    n->pid = person_id;
    n->next = NULL;
}

void display(pnode_t pcqhead)
{
    //pnode_t head = pcqhead;
    pnode_t cur = pcqhead;
    while(cur->next!=pcqhead){
        printf("[%p ,%d]-->",cur,cur->pid);
        cur = cur->next;
    }
    printf("[%p %d]-->%p\n",cur,cur->pid,cur->next);
}

void release(pnode_t pcqhead)
{
    //pnode_t head = pcqhead;
    pnode_t cur = pcqhead;
    while(cur->next!=pcqhead){
        pnode_t temp = cur;
        cur=cur->next;
        free(temp);
    }
    free(cur);

}

int main(const int argc, const char **argv)
{
    if (argc!=3){
        printf("josephus problem , input people number and count k\n");
        printf("./josephus <num of people> <k interval count>\n");
        return 0;
    }
    int num = atoi(argv[1]);
    int k= atoi(argv[2]);
    printf("nf =%d k=%d\n",num,k);
    pnode_t p_cque_head = NULL;
    for(int i = 0;i<num;i++){
        pnode_t node = create_node(i+1);
        if(p_cque_head == NULL){
            node->next = node;
            p_cque_head = node;
        }else{
            pnode_t cur = p_cque_head;
            while(cur->next!=p_cque_head)
                cur=cur->next;
            node->next = p_cque_head;
            cur->next = node;
        }
    }
    display(p_cque_head);
    int nfp =num;
    int cnt=1;
    pnode_t cpid = p_cque_head;
    while(1){
        if(cnt==k){
            pnode_t temp = cpid->next;
            cpid->next = temp->next;
            printf("remove temp%p %d ",temp,temp->pid);
            free(temp);
            cnt = 0;
            nfp--;
            printf("nfp=%d \n",nfp);
        }
        if(nfp<=k)
            break;
        cpid=cpid->next;
        cnt++;
    }
    display(cpid);

    printf("the people left\n");


    release(cpid);


    return 0;
}