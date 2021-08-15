#include "Tree.h"
using namespace std;

// ? 插入
void BST_Insert(BiTree* T, Elemtype k) {
    /* 用 malloc 分配内存创建
    T = (BiTree*)malloc(sizeof(BiTree));
    T->data = k;
    T->lchild = T->rchild = nullptr;
    */
    if (T == nullptr)
        T = new BiTree(k);  // 直接 new ， 自动分配内存
    else if (k == T->data)
        return;
    else if (k < T->data)
        BST_Insert(T->lchild, k);
    else
        BST_Insert(T->rchild, k);
}

// ? 查找
BiTree* BST_Search(BiTree* T, Elemtype k) {
    while (T != nullptr && T->data != k) {
        if (T->data > k)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}

// ? 删除结点
bool DeleteNode(BiTree* T, BiTree* par) {
    BiTree* tmp;
    // - 1. T为叶子结点，直接删除
    if (T->lchild == nullptr && T->rchild == nullptr) {
        if (par == T) {
            delete T;
            return false;
        }
        if (par->lchild == T)
            par->lchild = nullptr;
        else
            par->rchild = nullptr;
        delete T;
    }
    // - 2. T左子树为空，用右子树替代当前结点
    else if (T->lchild == nullptr) {
        tmp = T->rchild;
        T->data = tmp->data;
        T->lchild = tmp->lchild;
        T->rchild = tmp->rchild;
        delete tmp;
    }
    // - 2. T右子树为空，用左子树替代当前结点
    else if (T->rchild == nullptr) {
        tmp = T->lchild;
        T->data = tmp->data;
        T->lchild = tmp->lchild;
        T->rchild = tmp->rchild;
        delete tmp;
    }
    // - 3. T左右子树均不为空，用右子树的最小结点替代
    else {
        tmp = T;
        BiTree* minnode = T->rchild;
        while (minnode->lchild != nullptr) {
            tmp = minnode;  // 记录最小结点的父结点
            minnode = minnode->lchild;
        }
        T->data = minnode->data;

        // ! 下面画图可以更好理解
        if (tmp != T)  // while执行，说明T的右子树有左子树
            tmp->lchild =
                minnode
                    ->rchild;  // 让最小结点的右子树（可能存在）跟在其父结点的左边
        else  // T的右子树没有左子树，此时tmp=T
            tmp->rchild = minnode->rchild;  // 右子树的右子树上移
        delete minnode;
    }
    return true;
}

// ? 删除
BiTree* BST_Delete(BiTree* T, Elemtype k) {
    BiTree *p = T, *par = T;
    while (p != nullptr && k != p->data) {
        par = p;
        if (k < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    bool tag = true;
    if (p != nullptr) tag = DeleteNode(p, par);
    if (!tag) return nullptr;
    return T;
}