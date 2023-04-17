#include<stdio.h>
#define MaxSize 10
typedef int Elemtype;
//静态分配
typedef struct {
  Elemtype data[MaxSize];
  int length;
}SeqList;

//初始化顺序表
void initList(SeqList *L) {
  for (int i = 0; i < MaxSize;i++) {
    L->data[i] = 0;
  }
  L->length = 0;
}

//插入元素
void listInsert(SeqList *L, int i, Elemtype e) {
  if (i < 1 || i > L->length + 1) {
    printf("listInsert error1");
    return;
  }
  if (L->length >= MaxSize) {
    printf("listInsert error2");
    return;
  }
  for (int j = L->length; j >= i;j--) {
    L->data[j] = L->data[j - 1];
  }
  L->data[i - 1] = e;
  L->length++;//顺序表长度加一
}

//删除元素
void listDelete(SeqList *L, int i, Elemtype *e) {
  if (i < 1 || i >L->length) {
    printf("listDelete error1!");
    return;
  }
  *e = L->data[i - 1];
  for (int j = i; j < L->length; j++) {
    L->data[j - 1] = L->data[j];
  }
  L->length--;
}

//按位查找
Elemtype getElem(SeqList L, int i) {
  if (i < 1 || i >L.length) {
    printf("listDelete error1!");
    return -1;
  }
  return L.data[i - 1];
}

//按值查找
int locateElem(SeqList *L, Elemtype e) {
  for (int i = 0; i < L->length; i++) {
    if (e == L->data[i]) {
      return i + 1;//返回该值的位序
    }
  }
  return -1;//返回-1表示顺序表中没有该值
}

//打印顺序表
void printList(SeqList *L) {
  for (int i = 0; i < L->length; i++) {
    printf("%d\t", L->data[i]);
  }
  printf("\n");
}

int main01() {
  SeqList L;
  initList(&L);
  listInsert(&L, 1, 3);
  listInsert(&L, 2, 5);
  listInsert(&L, 3, 7);
  printList(&L);

  Elemtype e;
  listDelete(&L, 2, &e);
  printList(&L);
  printf("delete element is = %d\n", e);

  printf("第二个元素是:%d\n", getElem(L, 2));

  if (locateElem(&L, 7) != -1) {
    printf("7的位置是:%d", locateElem(&L, 7));
  } else {
    printf("顺序表中没有7");
  }

}