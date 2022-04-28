typedef int Data;
typedef int boolean;

typedef struct _node {
    Data data;
    struct _node * next;
    struct _node * prev;
} Node;

//double dummy linked list
typedef struct _dbDLinkedList {
    Node * head;
    Node * tail;
    Node * cur;
    int numOfData;
} DBDLinkedList;

typedef DBDLinkedList List;

//functions
void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);

Data LRemove(List * plist);
int LCount(List * plist);
