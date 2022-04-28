#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq){
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq){
    if(pdeq->head == NULL){
        return true;
    }
    else{
        return false;
    }
}

void DQAddFirst(Deque * pdeq, Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pdeq->head;

    if(DQIsEmpty(pdeq)){
        pdeq->tail = newNode;
    } else{
        pdeq->head->prev = newNode;
    }

    newNode->prev = NULL; 
    pdeq->head = newNode;
}

void DQAddLast(Deque * pdeq, Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pdeq->tail;
    newNode->next = NULL;

    if(DQIsEmpty(pdeq)){
        pdeq->head = newNode;
    } else {
        pdeq->tail->next = newNode;
    }

    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque * pdeq){
    Node * rnode = pdeq->head;
    Data rdata;
    if(DQIsEmpty(pdeq)){
        printf("Deque Memory Error!");
        exit(-1);
    }
    rdata = pdeq->head->data;

    pdeq->head = pdeq->head->next;
    free(rnode);

    if(pdeq->head == NULL){
        pdeq->tail = NULL;
    } else {
        pdeq->head->prev = NULL;
    }
    return rdata;
}

Data DQRemoveLast(Deque * pdeq){
    Node * rnode = pdeq->tail;
    Data rdata;
    if(DQIsEmpty(pdeq)){
        printf("Deque Memory Error!");
        exit(-1);
    }
    rdata = pdeq->tail->data;

    pdeq->head = pdeq->tail->prev;
    free(rnode);

    if(pdeq->tail == NULL){
        pdeq->head = NULL;
    } else {
        pdeq->tail->prev = NULL;
    }
    return rdata;
}

Data DQGetFirst(Deque * pdeq){
   if(DQIsEmpty(pdeq)){
        printf("Deque Memory Error!");
        exit(-1);
    }
    return pdeq->head->data;
}

Data DQGetLast(Deque * pdeq){
   if(DQIsEmpty(pdeq)){
        printf("Deque Memory Error!");
        exit(-1);
    }
    return pdeq->tail->data;
}