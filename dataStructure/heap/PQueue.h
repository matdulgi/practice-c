#include "Heap.h"

typedef Heap PQueue;

typedef int PQData;

typedef int (*PriorityComp)(PQData data1, PQData data2);

void PQueueInit(PQueue * ppq, PriorityComp pc);
int PQIsEmpty(PQueue * ppq);
void PEnqueue (PQueue * ppq, PQData data);
PQData PDequeue(PQueue * ppq);