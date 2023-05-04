#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;
typedef struct DNode {
  ElemType data;
  struct DNode *prior, *next;
}DNode, *DLinklist;

/*
  循环双链表
 */

bool initDlinklist(DLinklist *L) {
  *L = (DNode *)malloc(sizeof(DNode));
  if (*L == NULL)
    return false;
  (*L)->prior = L;  //头结点的prior指向头结点
  (*L)->next = L;   //头结点的next指向头结点
  return true;
}

//判断循环双链表是否为空表
bool isEmpty(DLinklist L) {
  if (L->next == L)
    return true;
  else
    return false;
}

//判断结点p是否是循环双链表的表尾结点
bool isTail(DLinklist L, DNode *p) {
  if (p->next == L)
    return true;
  else
    return false;
}
