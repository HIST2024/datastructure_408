#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;
typedef struct LNode {
  ElemType data;
  struct LNode *next;
}LNode, *LinkList;

/*
  循环单链表
 */

bool initList(LinkList *L) {
  *L = (LNode *)malloc(sizeof(LNode));
  if (*L == NULL)
    return false;
  (*L)->next == L; //头结点next指向头结点
  return true;
}

//判断链表是否为空
bool isEmpty(LinkList L) {
  if (L->next == L)
    return true;
  else
    return false;
}

//判断节点p是不是表尾结点
bool isTail(LinkList L, LNode *p) {
  if (p->next == L)
    return true;
  else
    return false;
}

int main() {
  LinkList L;
  initList(&L);
  
}