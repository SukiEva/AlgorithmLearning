#include "Stack.h"
using namespace std;

void InitStack(SqStack *s) { s->top = -1; }

bool StackEmpty(SqStack *s) { return s->top == -1; }

bool Push(SqStack *s, Elemtype x) {
    if (s->top == MaxSize - 1) return false;
    s->data[++s->top] = x;
    return true;
}

bool Pop(SqStack *s, Elemtype &x) {
    if (s->top == -1) return false;
    x = s->data[s->top--];
    return true;
}

bool GetTop(SqStack *s, Elemtype &x) {
    if (s->top == -1) return false;
    x = s->data[s->top];
    return true;
}