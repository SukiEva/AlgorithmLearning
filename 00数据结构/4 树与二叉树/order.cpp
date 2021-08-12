#include "Tree.h"
using namespace std;


void PreOrder(BiTree* T){
    if (T!=nullptr){
        cout<<T->data;
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree* T){
    if (T!=nullptr){
        InOrder(T->lchild);
        cout<<T->data;
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree* T){
    if (T!=nullptr){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout<<T->data;
    }
}

BiTree* build(){
    BiTree* h = new BiTree(1);
    BiTree* p = h;
    for (int i=2; i<=5; i++){
        BiTree *tmp = new BiTree(i);
        if (p->lchild==nullptr) p->lchild=tmp;
        else if (p->rchild==nullptr) p->rchild=tmp;
        else {
            p = p->lchild;
            p ->lchild = tmp;
        }
    }
    return h;
}

int main(){
    BiTree* T = build();
    PreOrder(T);
    build() 


    return 0;
}

