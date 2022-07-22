#include <stdio.h>
#include "DBDLinkedList.h"


int main (void){

    List list;
    int data;
    ListInit(&list);

    LInsert(&list, 3);

    printf("count : %d", LCount(&list));



}