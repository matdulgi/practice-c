#include <stdio.h>
#include <stdlib.h>


void NullCheck (int * ptr){
    if (ptr == NULL){
        printf("null\n");
    } else{
        printf("notnull %p %d\n", ptr, *ptr);
    }
}

int main (void){
    int * ptr1 = (int*)malloc(sizeof(int));
    int * ptr2 = malloc(sizeof(int));

    NullCheck(ptr1);

    free(ptr1);

    NullCheck(ptr1);

    return 0;
}