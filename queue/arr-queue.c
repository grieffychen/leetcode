#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX 10
int m_queue[MAX];
int m_front = -1;
int m_rear = -1;
void insert();
int peek();
int delete_elm();
void display();

void insert()
{
    printf("please insert value\n");
    int val;
    scanf("%d",&val);
    if((m_front==-1) &&(m_rear == -1)){
        m_front = m_rear = 0;
        m_queue[m_rear] = val;
    }else if(m_rear==MAX-1){
        printf("the queue is full\n");
        return;
    }else{
        m_queue[++m_rear] = val;
    }
}

int peek()
{
    if ((m_front == -1 )|| (m_front>m_rear) ){
        printf("the queue is empty\n");
        return -1;
    }else
        return m_queue[m_front];
}

int delete_elm()
{
    if ((m_front == -1)||(m_front>m_rear)){
        printf("the queue is empty\n");
        return -1;
    }else
        return m_queue[m_front++];
}

void display()
{
    if (m_front == -1){
        printf("the queue is empty\n");
        return ;
    }
    for (int i = m_front;i<=m_rear;i++)
        printf("%d ",m_queue[i]);
    printf("\n");
}

int main(const int argc, const char **argv)
{

    int optional = -1;
    //int val =-1;
    do{
        printf("======= main menu =======\n");
        printf("1. insert element\n");
        printf("2. delete element\n");
        printf("3. peek\n");
        printf("4. display queue\n");
        printf("5. exist\n");
        scanf("%d",&optional);
        switch(optional){
            case 1:
                insert();
                break;
            case 2:
                delete_elm();
                break;
            case 3:
            {
                int val = peek();
                printf("peek =%d\n",val);
                break;
            }
            case 4:
                display();
                break;;
        }

    }while(optional !=5);
    return 0;
}