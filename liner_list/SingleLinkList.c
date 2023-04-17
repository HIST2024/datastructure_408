#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;
typedef struct LNode {
  ElemType data;
  struct LNode *next;
}LNode, *LinkList;

//初始化一个单链表，带头结点
bool initList(LinkList L) {
  L = (LNode *)malloc(sizeof(LNode));
  if (L == NULL) {
    return false;
  }
  L->next = NULL;
  return true;
}

//头插法建立单链表
void listHeadInsert() {
  
}

void main() {
  //声明一个指向单链表的指针
  LinkList L;
  //初始化一个空链表
  initList(L);
}