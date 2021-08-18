#ifndef QUEUE_HEADER_FILE
#define QUEUE_HEADER_FILE

#include <iostream>
#define MaxSize 50
#define Elemtype int

struct SqQueue {
    Elemtype data[MaxSize];
    int front, rear;
};

struct LNode {
    Elemtype data;
    LNode *next;
};

struct LQueue {
    LNode *front, *rear;
};

#endif