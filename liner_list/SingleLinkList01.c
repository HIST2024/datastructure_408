#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;
typedef struct LNode {
  ElemType data;
  struct LNode *next;
}LNode, *LinkList;

/*
  带头结点的单链表
 */

//初始化一个单链表(带头结点)
bool initList(LinkList *L) { //L是一个二级指针
  (*L) = (LNode *)malloc(sizeof(LNode));
  if ((*L) == NULL) {
    return false;
  }
  (*L)->next = NULL;
  return true;
}

//头插法建立单链表
void listHeadInsert() {

}

//尾插法建立单链表
LinkList listTailInsert(LinkList L) {

}

//按位序插入结点操作（带头结点）
bool listInsert(LinkList L, int i, ElemType e) {
  if (i < 1)
    return false;
  LNode *p;//指针p指向当前扫描到的结点
  int j = 0;//当前p指向的是第几个结点
  p = L;//L指向头结点，头结点是第0个结点
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

//在p结点后插入结点
bool insertNextNode(LNode *p, ElemType e) {
  if (p == NULL)
    return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  if (s == NULL)
    return false;
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

//在p结点之前插入元素e,时间复杂度O(n)
bool insertPriorNode02(LinkList L, LNode *p, ElemType e) {
  if (p == NULL)
    return false;
  LNode *h;//指针p指向当前扫描到的结点
  h = L;//p结点指向头结点，从头结点开始扫描
  while (h != NULL && h->next->next != p) {
    h = h->next;
  }
  if (h == NULL)
    return false;
  insertNextNode(h, e);
}

//删除结点操作,（带头结点）
bool listDelete(LinkList L, int i, ElemType *e) {
  if (i < 1)
    return false;
  LNode *p;//指针p指向当前扫描到的结点
  int j = 0;//当前p指向的是第几个结点
  p = L;//L指向头结点，头结点是第0个结点(不存数据)
  while (p != NULL && j < i - 1) {//循环找到第i-1个结点
    p = p->next;
    j++;
  }
  if (p == NULL) //i值不合法
    return false;
  if (p->next == NULL) //第i-1个结点之后已经无其他结点
    return false;
  LNode *q = p->next;
  *e = q->data;
  p->next = q->next;
  free(q);
  return true;
}

//判断单链表是否为空（带头结点）
bool isEmpty(LinkList L) {
  if (L->next == NULL) {
    return true;
  } else {
    return false;
  }
}

//打印单链表
void printList(LinkList L) {
  if (L->next == NULL)
    return;
  LNode *p = L->next;
  while (p != NULL) {
    printf("%d\t", p->data);
    p = p->next;
  }
  printf("\n");
}

void main() {
  //声明一个指向单链表的指针
  LinkList L;
  //初始化一个空链表
  initList(&L);
  listInsert(L, 1, 3);
  listInsert(L, 2, 5);
  listInsert(L, 3, 7);
  printList(L);
  ElemType e;
  listDelete(L, 1, &e);
  printf("delete elem is:%d\n", e);
  printList(L);
}