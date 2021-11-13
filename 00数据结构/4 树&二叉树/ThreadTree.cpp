#include "Tree.h"
using namespace std;

void InThread(ThreadTree* p, ThreadTree* pre) {
    if (p != nullptr) {
        InThread(p->lchild, pre);  // 递归线索化左子树
        if (p->lchild == nullptr) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != nullptr && pre->rchild == nullptr) {  // 前驱结点的后续线索
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);  // 递归线索化右子树
    }
}

void CreateInThread(ThreadTree* T) {
    ThreadTree* pre = nullptr;
    if (T != nullptr) {
        InThread(T, pre);
        pre->lchild = nullptr;  // 处理遍历最后一个结点
        pre->rtag = 1;
    }
}

// ? 找到第一个结点
ThreadTree* FirstNode(ThreadTree* p) {
    while (!p->ltag) p = p->lchild;  // 最左下结点(不一定是叶子结点)
    return p;
}

// ? 找到p在中序下的后继
ThreadTree* NextNode(ThreadTree* p) {
    if (!p->rtag)
        return FirstNode(p->rchild);
    else
        return p->rchild;
}

// ? 中序遍历
void InOrder(ThreadTree* T) {
    for (ThreadTree* p = FirstNode(T); p != nullptr; p = NextNode(p)) {
        cout << p->data;
    }
}