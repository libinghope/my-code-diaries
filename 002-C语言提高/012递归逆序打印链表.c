#include <stdio.h>
#include <stdlib.h>

typedef struct _link_node
{
    int data;
    struct _link_node *next;

} LinkNode;


//递归方法打印链表
void printLink(LinkNode *head)
{
    LinkNode *p = head;

    //首先定义递归退出的条件
    if (!p){return;}
    printLink(p->next);
    printf("----%d----\n", p->data);
}

//递归方法释放链表
void freeLink(LinkNode * head){
    LinkNode *p = head;
    if(!p){ return; }
    freeLink(p->next);
    free(p); 
}

int main()
{
    //先构造一个链表
    LinkNode *headNode = (LinkNode *)malloc(sizeof(LinkNode));
    LinkNode *p = headNode;
    p->data = 0;
    p->next = NULL;
    for (int i = 1; i < 11; i++)
    {
        LinkNode *q = (LinkNode *)malloc(sizeof(LinkNode));
        q->data = i;
        p->next = q;
        q->next = NULL;
        p = q;
    }
    printLink(headNode);


    freeLink(headNode);
    system("pause");
    return 0;
}