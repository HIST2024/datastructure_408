#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;
typedef struct LNode {
  ElemType data;
  struct LNode *next;
}LNode, *LinkList;

/*
  不带头结点的单链表
 */

 //初始化一个单链表(带头结点)
bool initList(LinkList *L, ElemType e) { //L是一个二级指针
  (*L) = (LNode *)malloc(sizeof(LNode));
  if ((*L) == NULL) {
    return false;
  }
  (*L)->next = NULL;
  (*L)->data = e;
  return true;
}

//按位序插入结点操作（不带头结点）
bool listInsert(LinkList L, int i, ElemType e) {
  if (i < 1)
    return false;
  if (i == 1) { //插入第1个结点的操作与其他结点的操作不同
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = L;
    L = s; //头指针指向新结点
    return true;
  }
  LNode *p;//指针p指向当前扫描到的结点
  int j = 1;//当前p指向的是第几个结点
  p = L;//p指向第一个结点（注意：不是头结点）
  while (p != NULL && j < i - 1) {//循环找到第i-1个结点
    p = p->next;
    j++;
  }
  if (p == NULL) //i值不合法
    return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

//在p结点之前插入元素e,时间复杂度O(1)
bool insertPriorNode01(LNode *p, LNode *s) {
  if (p == NULL || s == NULL)
    return false;
  s->next = p->next;
  p->next = s; //s连接到p之后
  ElemType temp = p->data;//交换数据域部分
  p->data = s->data;
  s->data = temp;
  return true;
}

//打印单链表
void printList(LinkList L) {
  if (L == NULL)
    return;
  LNode *p = L;
  while (p != NULL) {
    printf("%d\t", p->data);
    p = p->next;
  }
  printf("\n");
}

int main() {
  LinkList L;
  initList(&L, 1);
  listInsert(L, 2, 3);
  listInsert(L, 3, 5);
  listInsert(L, 4, 7);
  printList(L);

  return 0;
}
