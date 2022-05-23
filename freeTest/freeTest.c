#include <stdio.h>
#include <stdlib.h>

int main (void){
  int* ptr1 = (int*)malloc(sizeof(4));
  int* ptr2 = ptr1 + 1;
  int* ptr3 = ptr1 + 2;
  int* ptr4 = ptr1 + 3;

  *ptr1 = 1;
  *(ptr1 + 1) = 2;
  *(ptr1 + 2) = 3;
  *(ptr1 + 3) = 4;

  printf("%d, %p\n", *ptr1 ,ptr1);
  printf("%d, %p\n", *ptr2 ,ptr2);
  printf("%d, %p\n", *ptr3 ,ptr3);
  printf("%d, %p\n", *ptr4 ,ptr4);

  free(ptr1);

  printf("%d, %p\n", *ptr1 ,ptr1);
  printf("%d, %p\n", *ptr2 ,ptr2);
  printf("%d, %p\n", *ptr3 ,ptr3);
  printf("%d, %p\n", *ptr4 ,ptr4);

  return 0;
}
