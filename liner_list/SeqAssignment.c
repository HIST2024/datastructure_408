#include<stdio.h>
#include<stdlib.h>
#include "./seqlist01.c"

//删除最小元素，并返回删除的值,空出的位置由最后一个元素来填补，若顺序表为空，显示出错信息
void question01(SeqList *L, Elemtype *e) {
  if (L->length == 0) {
    printf("error! list is empty!");
    return;
  }
  Elemtype minElem = L->data[0];
  int pos = 0;
  for (int i = 1; i < L->length; i++) {
    if (L->data[i] < minElem) {
      pos = i;
      minElem = L->data[i];
    }
  }
  *e = minElem;
  L->data[pos] = L->data[L->length - 1];
  L->length--;
}

//设计一个高效算法，将顺序表中元素逆置，要求空间复杂度O(1)
void question02(SeqList *L) {
  Elemtype temp = 0;
  for (int i = 0; i < L->length / 2;i++) {
    temp = L->data[i];
    L->data[i] = L->data[L->length - 1 - i];
    L->data[L->length - 1 - i] = temp;
  }
}

//删除顺序表中所有值为x的元素，时间复杂度O(n)、空间复杂度O(1)
void question03_01(SeqList *L, Elemtype x) {
  int k = 0;//记录值不等于x的元素个数
  for (int i = 0; i < L->length; i++) {
    if (L->data[i] != x) {
      L->data[k] = L->data[i];
      k++;//不等于x的元素增1
    }
  }
  L->length = k;//顺序表的长度等于k
}
void question03_02(SeqList *L, Elemtype x) {
  int k = 0, i = 0; //k值记录等于x的元素个数
  while (i < L->length) {
    if (L->data[i] == x)
      k++;
    else
      L->data[i - k] = L->data[i];//当前元素前移k个位置
    i++;
  }
  L->length = L->length - k;//顺序表L的长度递减
}

//
void question04(SeqList *L, int s, int t) {
  
}

// 删除[s,t]区间的内容，如果输入错误给出提示
void question05(SeqList *L, int s, int t) {
  int k = 0;
  if (s >= t || L->length == 0) {
    printf("error! question04");
    return;
  }
  for (int i = 0; i < L->length; i++) {
    if (L->data[i] >= s && L->data[i] <= t)
      k++;
    else
      L->data[i - k] = L->data[i];
  }
  L->length -= k;
}

void main() {
  SeqList L;
  initList(&L);
  listInsert(&L, 1, 3);
  listInsert(&L, 2, 5);
  listInsert(&L, 3, 7);
  listInsert(&L, 4, 9);
  listInsert(&L, 5, 11);
  listInsert(&L, 6, 13);
  listInsert(&L, 7, 17);
  printList(&L);

  // Elemtype e;
  // question01(&L, &e);
  // printList(&L);
  // printf("删除的最小元素是:%d", e);

  // question03_02(&L, 3);
  // printList(&L);

  question05(&L, 5, 13);
  printList(&L);
}