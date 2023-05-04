#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 50  //静态链表的最大长度
typedef int ElemType;
typedef struct {
  ElemType data;  //存储数据元素
  int next;   //下一个元素的数组下标
}SLinkList[MaxSize];

int main() {
  SLinkList L;
}