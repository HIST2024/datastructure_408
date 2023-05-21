#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "./seqlist01.c"

/*
  408顺序表课后习题
 */

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
  L->length = L->length - k;//顺序表L的长度减去k
}

//删除有序顺序表值在区间[s,t]之间的值
bool question04(SeqList *L, int s, int t) {
  int i, j;
  if (s >= t || L->length == 0)
    return false;
  for (i = 0;i < L->length && L->data[i] < s;i++);//寻找值大于或等于s的第一个元素
  if (i >= L->length)
    return false;   //所有元素都小于s,返回false
  for (j = i; j < L->length && L->data[j] <= t; j++);//寻找值大于t的第一个元素
  for (; j < L->length;i++, j++)
    L->data[i] = L->data[j];  //前移，填补被删除的元素位置
  L->length = i;
  return true;
}

// 删除顺序表值在[s,t]区间的内容，如果输入错误给出提示
bool question05(SeqList *L, int s, int t) {
  int k = 0;
  if (s >= t || L->length == 0) {
    return false;
  }
  for (int i = 0; i < L->length; i++) {
    if (L->data[i] >= s && L->data[i] <= t)
      k++;
    else
      L->data[i - k] = L->data[i];
  }
  L->length -= k;
  return true;
}

//删除有序顺序表中重复的值，使表中元素值均不同
bool question06(SeqList *L) {
  if (L->length == 0)
    return false;
  int i, j;
  for (i = 0, j = 1; j < L->length;j++)
    if (L->data[i] != L->data[j])
      L->data[++i] = L->data[j];
  L->length = i + 1;
  return true;
}

//将两个有序顺序表合成一个有序顺序表表
bool question07(SeqList A, SeqList B, SeqList *L) {
  printList(&A);
  printList(&B);
  if (A.length + B.length > 20)
    return false;
  int i = 0, j = 0, k = 0;
  while (i < A.length && j < B.length) {
    if (A.data[i] <= B.data[j])
      L->data[k++] = A.data[i++];
    else
      L->data[k++] = B.data[j++];
  }
  while (i < A.length)
    L->data[k++] = A.data[i++];
  while (j < B.length)
    L->data[k++] = B.data[j++];
  L->length = k;
  return true;
}

//一维数组中依次存在两个线性表A和B，将A和B的位置互换
//思路：先将一维数组整体逆置，就变成了(逆序B和逆序A)，再将B和A分别逆置
typedef int DataType;
bool question08_step01(DataType A[], int left, int right, int arraySize) {
  if (left >= right || right >= arraySize)
    return false;
  int  mid = (left + right) / 2;
  for (int i = 0; i < mid - left; i++) {
    DataType temp = A[left + i];
    A[left + i] = A[right - i];
    A[right - i] = temp;
  }
  return true;
}

//数组作为参数其实传递的就是数组首地址，会失去精度
bool question08_step02(DataType A[], int m, int n, int arraySize) {
  question09_step01(A, 0, m + n - 1, arraySize);
  question09_step01(A, 0, n - 1, arraySize);
  question09_step01(A, n, m + n - 1, arraySize);
  for (int i = 0; i < 10;i++) {
    printf("%d\t", A[i]);
  }
  return true;
}

//有序顺序表中查找值为x的元素
//如果找到了，与后一个元素交换
//如果没有找到，将x插入顺序表，但要保证顺序表还是有序的
//因为有序这里使用折半查找
// bool question09(SeqList *L, Elemtype x) {
//   int low = 0, high = n - 1, mid;
// }

int main() {
  SeqList A;
  initList(&A);
  listInsert(&A, 1, 1);
  listInsert(&A, 2, 3);
  listInsert(&A, 3, 5);
  listInsert(&A, 4, 7);
  listInsert(&A, 5, 9);

  SeqList B;
  initList(&B);
  listInsert(&B, 1, 2);
  listInsert(&B, 2, 4);
  listInsert(&B, 3, 6);
  listInsert(&B, 4, 8);
  listInsert(&B, 5, 10);

  SeqList L;
  initList(&L);
  question07(A, B, &L);
  printList(&L);

  question08_step02(L.data, 5, 5, L.length);
}