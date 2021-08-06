#ifndef LNODE_HEADER
#define LNODE_HEADER

#define ElemType int
struct LNode{
    ElemType data;
    LNode *next;
    LNode():data(),next(){}
    LNode(ElemType x): data(x),next(NULL){}
};

struct DNode{
    ElemType data;
    DNode *pre,*next;
};

#endif
