#include <stdio.h>
#include <stdlib.h>


void nullCheck (int * ptr){
    if (ptr == NULL){
        printf("null\n");
    } else{
        printf("notnull %p %d\n", ptr, *ptr);
    }
}

int main (void){
  //don't forget initializing
    int * ptr1 = NULL;
    int * ptr2 = NULL;
    nullCheck(ptr1);
    ptr1 = (int*)malloc(sizeof(int));
    ptr2 = malloc(sizeof(int));
    *ptr1 = 3;

    nullCheck(ptr1);

    free(ptr1);

    nullCheck(ptr1);

}
