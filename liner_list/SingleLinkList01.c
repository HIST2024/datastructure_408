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

//头插法创建单链表
//逆向建立单链表
bool listHeadInsert(LinkList *L) {
  (*L) = (LNode *)malloc(sizeof(LNode));//申请头结点空间，头指针指向头结点
  if ((*L) == NULL)
    return false;
  (*L)->next = NULL;
  LNode *s;
  ElemType value;
  scanf("%d", &value);
  while (value != 9999) {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = value;
    s->next = (*L)->next;//s的next指向原本链表的第一个结点
    (*L)->next = s;//头结点的next，指向新的结点
    scanf("%d", &value);
  }
  return true;
}

//尾插法建立单链表
//正向建立单链表
bool listTailInsert(LinkList *L) {
  ElemType value;
  (*L) = (LNode *)malloc(sizeof(LNode));//申请头结点空间，头指针指向头结点
  if ((*L) == NULL)
    return false;
  LNode *s, *r = (*L);//s用来指向申请的新结点,r是始终指向链表尾
  scanf("%d", &value);
  while (value != 9999) {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = value;
    r->next = s;//新结点给尾结点的next指针
    r = s;//r指向新的表尾结点
    scanf("%d", &value);
  }
  r->next = NULL;//让尾结点的next为NULL
  return true;
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

//在p结点之前插入元素e,时间复杂度O(1)，偷梁换柱
bool insertPriorNode01(LNode *p, ElemType e) {
  if (p == NULL)
    return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s; //s连接到p之后
  ElemType temp = p->data;//交换数据域部分
  p->data = s->data;
  s->data = temp;
  return true;
}

//在p结点之前插入元素e,时间复杂度O(n)
bool insertPriorNode02(LinkList L, LNode *p, ElemType e) {
  if (L == NULL || p == NULL)
    return false;
  LNode *h;//指针h指向当前扫描到的结点
  h = L;//h结点指向头结点，从头结点开始扫描
  while (h != NULL && h->next != p) {
    h = h->next;
  }
  if (h == NULL)
    return false;
  insertNextNode(h, e);
  return true;
}

//按位置查找
LNode *getElemByLocation(LNode *p, int pos) {
  if (pos < 1)
    return NULL;//查找位置不合法
  int j = 0;//记录当前指向的结点，初始结点时头结点
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
  LNode *p = L->next;
  while (p != NULL && p->data != e)
    p = p->next;
  return p;//找到后返回该点的指针，否则返回NULL
}

//根据位序删除结点操作
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

//删除指定结点p，时间复杂度为O(1),偷梁换柱
//但是如果是删除最后一个结点，该函数会报错
bool deleteNode(LNode *p) {
  if (p == NULL || p->next == NULL)
    return false;
  LNode *q = p->next; //令q指向*p的后继节点
  p->data = p->next->data;//和后继节点交换数据域
  p->next = q->next;//将*q结点从链中“断开”
  free(q);//释放后继结点的存储空间
  return true;
}

//求表长
int getLength(LinkList L) {
  if (L->next == NULL)
    return 0;
  int j = 1;
  LNode *p = L->next;
  while (p->next != NULL) {
    j++;
    p = p->next;
  }
  return j;
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

int main() {
  //声明一个指向单链表的指针
  LinkList L;
  //初始化一个空链表
  // initList(&L);
  // listInsert(L, 1, 3);
  // listInsert(L, 2, 5);
  // listInsert(L, 3, 7);
  // listHeadInsert(&L);
  listTailInsert(&L);
  // listHeadInsert(&L);
  printList(L);
  LNode *result = getElemByLocation(L, 3);
  // if (result != NULL) {
  //   printf("查找到的结点值是：%d\n", result->data);
  // } else {
  //   printf("没有找到该值\n");
  // }
  // insertPriorNode01(result, 666);
  insertPriorNode02(L, result, 666);
  // ElemType e;
// listDelete(L, 1, &e);
// printf("delete elem is:%d\n", e);
  printList(L);

  printf("表的长度是：%d", getLength(L));
}