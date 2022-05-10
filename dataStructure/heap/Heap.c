#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

void HeapInit(Heap * ph, PriorityComp pc){
    ph = (Heap *)malloc(sizeof(Heap));
    ph->numOfData = 0;
}

int HIsEmpty(Heap * ph){
    if (ph->heapArr[0] == NULL){
        return TRUE;
    } else{
        return FALSE;
    }
}

void HInsert(Heap * ph, HData data){
    int idx = ph->numOfData;
    ph->heapArr[idx + 1] = data;
    while (idx > 1) {
        if ( comp(ph->heapArr[idx], ph->heapArr[idx + 1]) == TRUE){ HData tmp = ph->heapArr[idx + 1];
            ph->heapArr[idx + 1] = ph->heapArr[idx];
            ph->heapArr[idx] = tmp;
            idx = idx / 2;
        }
        else break;
    }
    ph->numOfData++;

}

HData HDelete(Heap * ph){
    HData retData = ph->heapArr[1];
    HData lastData = ph->heapArr[ph->numOfData];
    ph->heapArr[1] = lastData;
    ph->heapArr[ph->numOfData == NULL];
    ph->numOfData--;

    int idx = 1;
    while (TRUE){
        HData childData;
        int childIdx = idx*2;
        HData left = ph->heapArr[childIdx];
        HData right = ph->heapArr[childIdx + 1];
        if (comp( left, right) == TRUE){
            childData = left;
        } else
            childData = right;
            childIdx = childIdx + 1;
        if (comp( childData, lastData)){
            ph->heapArr[childIdx] = lastData;
            ph->heapArr[idx] = childData;
        } else break;

        idx = idx*2;
    }

    return retData;
}
