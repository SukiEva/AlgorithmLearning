#ifndef TREE_HEADER_FILE
#define TREE_HEADER_FILE

#include <iostream>
#include <queue>
#define Elemtype int

struct BiTree {
    Elemtype data;
    BiTree *lchild, *rchild;
    BiTree() : data(), lchild(), rchild() {}
    BiTree(Elemtype x) : data(x), lchild(nullptr), rchild(nullptr) {}
};

/* 
** 线索二叉树
** l/rtag = 1 => 指向左/右孩子
** l/rtag = 0 => 指向前驱/后继
*/
struct ThreadTree {
    Elemtype data;
    ThreadTree *lchild, *rchild;
    int ltag, rtag;
    ThreadTree() : data(), lchild(), rchild(), ltag(), rtag() {}
    ThreadTree(Elemtype x)
        : data(x), lchild(nullptr), rchild(nullptr), ltag(0), rtag(0) {}
};


#endif