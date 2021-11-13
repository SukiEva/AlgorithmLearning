#include "Queue.h"
using namespace std;

void InitSqQueue(SqQueue *Q) { Q->rear = Q->front = 0; }

bool SqIsEmpty(SqQueue *Q) { return Q->rear == Q->front; }

bool SqEnQueue(SqQueue *Q, Elemtype x) {
    if ((Q->rear + 1) % MaxSize == Q->front) return false;  // 队满
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;  // 队尾指针+1取模
    return true;
}

bool SqDeQueue(SqQueue *Q, Elemtype &x) {
    if (SqIsEmpty(Q)) return false;  // 队空
    x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;  // 队头指针+1取模
    return true;
}

void InitLQueue(LQueue *Q) {
    Q->front = Q->rear = new LNode;
    Q->front->next = nullptr;
}

bool LIsEmpty(LQueue *Q) { return Q->front == Q->rear; }

void LEnQueue(LQueue *Q, Elemtype x) {
    LNode *s = new LNode;
    s->data = x;
    s->next = nullptr;
    Q->rear->next = s;
    Q->rear = s;
}

bool LDeQueue(LQueue *Q, Elemtype &x){
    if (LIsEmpty(Q)) return false; 
    LNode *p = Q->front->next;
    x = p->data;
    Q->front->next=p->next;
    if (Q->rear==p) Q->rear=Q->front; // 若只有一个结点，删除后变空
    delete p;
    return true;
}