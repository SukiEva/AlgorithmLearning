#ifndef TREE_HEADER_FILE
#define TREE_HEADER_FILE

#include <iostream>
#define Elemtype int

struct BiTree{
    Elemtype data;
    BiTree *lchild, *rchild;
    BiTree():data(),lchild(),rchild(){}
    BiTree(ElemType x): data(x),lchild(nullptr),rchild(nullptr){}
};

#endif