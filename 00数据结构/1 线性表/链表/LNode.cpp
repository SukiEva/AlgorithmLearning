// Created on 自闭每一天.
#include <iostream>
#include "LNode.h"
using namespace std;

LNode *ListHeadInsert(LNode *L){ // 头插法，逆向链表
    LNode *s;
    L = new LNode;
    for (int i=1; i<=10; i++){
        s = new LNode(i);
        s->next = L->next;
        L->next = s; // 新结点插入表中，L为头指针
    }
    return L;
}

LNode *ListBackInsert(LNode *L){ // 尾插法，正向链表
    L = new LNode;
    LNode *s,*r=L;
    for (int i=1; i<=10; i++){
        s = new LNode(i);
        r->next = s;
        r = s; // r指向表尾结点
    }
    return L;
}

LNode *GetElem(LNode *L, int i){ // 按序号查找元素
    int j = 1;
    LNode *p = L->next;
    if (i==0) return L;
    if (i<1) return NULL;
    while (p && j<i){
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LNode *L, ElemType e){ // 按值查找 
    LNode *p = L;
    while (p && p->data!=e) p = p->next;
    return p;
}

void ListInsertNode(LNode *L, int i, ElemType e){
    LNode *s = new LNode(e);
    LNode *p = GetElem(L,i-1);
    s->next = p->next;
    p->next = s;  
}

int main(){

    LNode *l;
    l = ListBackInsert(l);
    ListInsertNode(l,3,100);
    LNode *p = GetElem(l,3);
    cout<<p->data;

    return 0;
}
