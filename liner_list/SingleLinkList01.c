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
//逆向建立单链表
LinkList listHeadInsert(LinkList *L) {
  LNode *s;
  ElemType x;
  (*L) = (LinkList)malloc(sizeof(LNode));//创建头结点
  (*L)->next = NULL;//初始位空链表
  scanf("%d", &x);//输入结点的值
  while (x != 9999) {//输入9999表示结束
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = (*L)->next;
    (*L)->next = s;
    scanf("%d", &x);
  }
  return *L;
}

//尾插法建立单链表
//正向建立单链表
// LinkList listTailInsert(LinkList *L) {
//   ElemType x;
//   (*L) = (LinkList)malloc(sizeof(LNode));//创建头结点
//   (*L)->next = NULL;
//   LNode *s, *r = (*L); //r为表尾指针
//   scanf("%d", &x); //输入结点的值
//   while (x != 9999) { //输入9999表示结束
//     s = (LNode *)malloc(sizeof(LNode));
//     s->data = x;
//     s->next = s;
//     r = s; //r指向新的表尾结点
//     scanf("%d", &x);
//   }
//   r->next = NULL; //尾结点指针置空
//   return *L;
// }

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
  return true;
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

//删除指定结点p，时间复杂度为O(1),偷梁换柱
//但是如果是删除最后一个结点，该函数会报错
bool deleteNode(LNode *p) {
  if (p == NULL)
    return false;
  LNode *q = p->next; //令q指向*p的后继节点
  p->data = p->next->data;//和后继节点交换数据域
  p->next = q->next;//将*q结点从链中“断开”
  free(q);//释放后继结点的存储空间
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
  printList(L);
  ElemType e;
  listDelete(L, 1, &e);
  printf("delete elem is:%d\n", e);
  printList(L);
}