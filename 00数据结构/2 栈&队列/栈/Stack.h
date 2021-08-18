#ifndef STACK_HEADER_FILE
#define STACK_HEADER_FILE


#include <iostream>

#define MaxSize 50
#define Elemtype int

struct SqStack {
    Elemtype data[MaxSize];
    int top;
};

struct LStack {
    Elemtype data;
    LStack *next;
};

#endif