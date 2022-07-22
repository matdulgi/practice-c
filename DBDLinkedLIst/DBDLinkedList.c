#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

#define true 1
#define false 0

/*
typedef struct _dbDLinkedList {
    Node * head;
    Node * tail;
    Node * cur;
    int numOfData;
} DBDLinkedList;

typedef struct _node {
    Data data;
    struct _node * next;
    struct _node * prev;
} Node;
*/


void ListInit(List * plist){
    plist=(List*)malloc(sizeof(List));
    plist->numOfData=0;

//dummy node
    Node * headNode = (Node *)malloc(sizeof(Node));
    Node * tailNode = (Node *)malloc(sizeof(Node));
    (*headNode).data=0;
    (*headNode).prev=NULL;
    (*headNode).next=tailNode;
    (*tailNode).data=0;
    (*tailNode).prev=headNode;
    (*tailNode).next=NULL;

    plist->head =headNode;
    plist->tail =headNode;
    plist->cur = NULL;
}

// policy : append last
void LInsert(List * plist, Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    (*newNode).data = data;

    Node * tailNode = plist->tail;
    Node * lastNode = (*tailNode).prev;
    (*lastNode).next = newNode;
    (*tailNode).prev = newNode;

    (*newNode).prev = lastNode;
    (*newNode).next = tailNode;
}

boolean LFirst(List * plist, Data * pdata){
    Node * firstNode = plist->head->next;
    if (firstNode == NULL){
        return false;
    }
    plist->cur = firstNode;
    *pdata = (*firstNode).data;
    return true;
}

boolean LNext(List * plist, Data * pdata){
    Node * nextNode = plist->cur->next;
    if (nextNode == NULL){
        return false;
    }
    *pdata = (*nextNode).data;
    return true;
}

Data LRemove(List * plist){
    Node * curNode = plist->cur;
    Node * prevNode = (*curNode).prev;
    Node * nextNode = (*curNode).next;
    Data data = curNode->data;

    free(curNode);
    prevNode->next=nextNode;
    nextNode->prev=prevNode;

    plist->numOfData--;

    return data;
}

int LCount(List * plist){
    return plist->numOfData;
}
