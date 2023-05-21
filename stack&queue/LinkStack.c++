#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
typedef struct StackNode {
  int data;
  struct StackNode *next;
} StackNode;

// 定义栈结构体
typedef struct LinkedListStack {
  StackNode *top;
} LinkedListStack;

// 初始化栈
void initStack(LinkedListStack *stack) {
  stack->top = NULL;
}

// 判断栈是否为空
int isStackEmpty(LinkedListStack *stack) {
  return stack->top == NULL;
}

// 入栈操作
void push(LinkedListStack *stack, int data) {
  StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
}

// 出栈操作
int pop(LinkedListStack *stack) {
  if (isStackEmpty(stack)) {
    return -1; // 栈为空，返回错误码
  }
  StackNode *nodeToRemove = stack->top;
  int data = nodeToRemove->data;
  stack->top = nodeToRemove->next;
  free(nodeToRemove);
  return data;
}

// 获取栈顶元素
int getTop(LinkedListStack *stack) {
  if (isStackEmpty(stack)) {
    return -1; // 栈为空，返回错误码
  }
  return stack->top->data;
}

// 销毁栈
void destroyStack(LinkedListStack *stack) {
  while (!isStackEmpty(stack)) {
    pop(stack);
  }
}

// 测试
int main() {
  LinkedListStack stack;
  initStack(&stack);

  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);

  printf("Top element: %d\n", getTop(&stack));

  while (!isStackEmpty(&stack)) {
    printf("%d ", pop(&stack));
  }
  printf("\n");

  destroyStack(&stack);

  return 0;
}
