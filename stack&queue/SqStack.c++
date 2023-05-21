#include<stdio.h>
#include<stdlib.h>

# define MaxSize 20
typedef int ElemType;
typedef struct {
  ElemType data[MaxSize];
  int top;
}SqStack;

void initStack(SqStack &S) {
  S.top = -1; //初始化栈顶指针
}

bool stackIsEmpty(SqStack S) {
  if (S.top == -1)
    return true;
  else
    return false;
}

//进栈
bool Push(SqStack &S,ElemType e) {
  if (S.top == MaxSize - 1)
    return false;
  S.data[++S.top] = e;  //指针先加一，再入栈
  return true;
}

//出栈
bool Pop(SqStack &S, ElemType &e) {
  if (S.top == -1)
    return false;
  e = S.data[S.top--];  //先出栈，指针再减一
  return true;
}

//读栈顶元素
bool GetTop(SqStack &S,ElemType &e) {
  if (S.top == -1)
    return false;
  e = S.data[S.top]; //e记录栈顶元素
  return true;
}

//遍历栈
bool printStack(SqStack &S) {
  int index = S.top;
  while (index != -1) {
    printf("%d ", S.data[index]);
    index--;
  }
  printf("\n");
  return true;
}

int main() {
  SqStack S;
  initStack(S);
  for (int i = 2; i < 11; i += 2)
    Push(S, i);
  printStack(S);
  return 0;
}
