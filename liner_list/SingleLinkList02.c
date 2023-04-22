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

 //初始化一个单链表
bool initList(LinkList *L) { //L是一个二级指针
  (*L) = NULL;
  return true;
}

//按位序插入结点操作（不带头结点）
//注意这里也要使用二级指针，头指针还是NULL
bool listInsert(LinkList *L, int i, ElemType e) {
  if (i < 1)
    return false;
  if (i == 1) { //插入第1个结点的操作与其他结点的操作不同
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = (*L);
    (*L) = s; //头指针指向新结点
    return true;
  }
  LNode *p;//指针p指向当前扫描到的结点
  int j = 1;//当前p指向的是第几个结点
  p = (*L);//p指向第一个结点（注意：不是头结点）
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

//头插法创建单链表
bool listHeadInsert(LinkList *L) {
  *L = NULL;
  ElemType x;
  scanf("%d", &x);
  LNode *s;
  while (x != 9999) {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = *L;
    *L = s;
    scanf("%d", &x);
  }
  return true;
}

//尾插法创建单链表
bool listTailInsert(LinkList *L) {
  *L = NULL;
  ElemType x;
  scanf("%d", &x);
  LNode *s, *r;
  r = *L;
  while (x != 9999) {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;
    if (*L == NULL) {
      *L = s;
      r = *L;
    } else {
      r->next = s;
      r = s;
    }
    scanf("%d", &x);
  }
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

//根据位序删除结点
bool listDelete(LinkList *L, int i, ElemType *e) {
  if (i < 1)
    return false;
  LNode *p = *L;//指向当前扫描到的结点
  int j = 1;//当前p指向的是第1个结点
  if (i == 1) {
    *e = (*L)->data;
    *L = (*L)->next;
    free(p);
    return true;
  }
  while (p != NULL && j < i - 1) {
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

//删除指定结点p，时间复杂度为O(1),偷梁换柱
//但是如果是删除最后一个结点，该函数会报错
bool deleteNode(LNode *p) {
  if (p == NULL || p->next == NULL)
    return false;
  LNode *q = p->next;
  p->data = q->data;
  p->next = q->next;
  free(q);
  return true;
}

//按位置查找
LNode *getElemByLocation(LNode *p, int pos) {
  int j = 1;//记录当前指向的结点，初始结点时第一个数据结点
  if (pos < 1)
    return NULL;
  if (pos == 1)
    return p;
  while (p && j < pos) {
    p = p->next;
    j++;
  }
  if (p == NULL)
    return NULL;//没有第i-1个元素
  return p;
}

//按值查找
LNode *getElemByValue(LinkList L, ElemType e) {
  if (L == NULL)
    return false;
  LNode *p = L;
  while (p != NULL && p->data != e)
    p = p->next;
  return p;//找到后返回该点的指针，否则返回NULL
}

//求表长
int getLength(LinkList L) {
  if (L == NULL)
    return 0;
  int j = 1;
  LNode *p = L;
  while (p->next != NULL) {
    j++;
    p = p->next;
  }
  return j;
}

//判断单链表是否为空（带头结点）
bool isEmpty(LinkList L) {
  if (L == NULL) {
    return true;
  } else {
    return false;
  }
}

//打印单链表
void printList(LNode *p) {
  if (p == NULL)
    return;
  while (p != NULL) {
    printf("%d\t", p->data);
    p = p->next;
  }
  printf("\n");
}

int main() {
  LinkList L;
  // initList(&L);
  // listInsert(&L, 1, 1);
  // listInsert(&L, 2, 3);
  // listInsert(&L, 3, 5);
  // listInsert(&L, 4, 7);
  listTailInsert(&L);
  printList(L);
  printf("表长:%d\n", getLength(L));
  
  

  // LNode *result = getElemByLocation(L, 3);
  // printf("查询结点值是:%d\n", result->data);

  ElemType e;
  listDelete(&L, 1, &e);
  printf("删除结点的值是:%d\n", e);
  printList(L);
  printf("表长:%d\n", getLength(L));

  return 0;
}
