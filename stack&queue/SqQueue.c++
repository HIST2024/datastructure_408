#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef int ElemType;
typedef struct {
  ElemType data[MaxSize];
  int front, rear;
}SqQueue;

void initQueue(SqQueue &Q) {
  Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q) {
  if (Q.rear == Q.front)    //对空条件
    return true;
  else
    return false;
}

bool enqueue(SqQueue &Q,ElemType x) {
  if ((Q.rear + 1) % MaxSize == Q.front)  //队满则报错
    return false;
  Q.data[Q.rear] = x;
  Q.rear = (Q.rear + 1) % MaxSize;
  return true;
}

bool dequeue(SqQueue &Q,ElemType &x) {
  if (Q.rear == Q.front)    //对空则报错
    return false;
  x = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  return true;
}




