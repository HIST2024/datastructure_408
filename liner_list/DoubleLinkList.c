#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;
typedef struct DNode {
  ElemType data;
  struct DNode *prior, *next;
}DNode, *DLinklist;
/*
  带头结点的双链表
 */

 //初始化双链表
bool InitDLinklist(DLinklist *L) {
  *L = (DNode *)malloc(sizeof(DNode));
  if (*L == NULL)
    return false;
  (*L)->prior = NULL;//头结点的prior永远指向NULL
  (*L)->next = NULL;//暂时还没有后继结点
  return true;
}

//p结点后插入s结点
bool insertNextDNode(DNode *p, DNode *s) {
  if (p == NULL || s == NULL) //非法参数
    return false;
  s->next = p->next;
  if (p->next != NULL)  //如果p结点有后继节点
    p->next->prior = s;
  s->prior = p;
  p->next = s;
  return true;
}

//按位序插入
bool insertElem(DLinklist L, int pos, ElemType e) {
  if (pos < 1)
    return false;
  DNode *p = L;
  int j = 0;
  while (p && j < pos - 1) {
    p = p->next;
    j++;
  }
  if (p == NULL)
    return false;
  DNode *s = (DNode *)malloc(sizeof(DNode));
  s->data = e;
  insertNextDNode(p, s);
  return true;
}

//删除p结点的后继结点
bool deleteNextNode(DNode *p) {
  if (p == NULL)
    return false;
  DNode *q = p->next;//找到后继节点q
  if (q == NULL)
    return false; //p没有后继节点
  p->next = q->next;
  if (q->next != NULL)//q结点不是最后一个结点
    q->next->prior = p;
  free(q);  //释放结点空间
  return true;
}

//销毁双链表
void destoryList(DLinklist *L) {
  //循环释放各个数据结点
  while ((*L)->next != NULL)
    deleteNextNode(L);
  free(*L);//释放头结点
  *L = NULL;//头指针指向NULL
}

//判断双链表是否为空(带头结点)
bool isEmpty(DLinklist L) {
  if (L->next == NULL)
    return true;
  else
    return false;
}

bool printList(DLinklist L) {
  if (L->next == NULL)
    return false;
  DNode *p = L->next;
  while (p) {
    printf("%d\t", p->data);
    p = p->next;
  }
  printf("\n");
  return true;
}

int main() {
  DLinklist L;
  InitDLinklist(&L);
  insertElem(L, 1, 1);
  insertElem(L, 2, 3);
  insertElem(L, 3, 5);
  insertElem(L, 4, 7);
  insertElem(L, 2, 666);
  printList(L);
}
