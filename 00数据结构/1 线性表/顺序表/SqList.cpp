// Created on 自闭每一天.
#include <iostream>
#include "SqList.h"
using namespace std;

bool ListInsert(SqList &L, int i, ElemType e){  // O(n)
    if (i<1 || i>L.length+1) return false;  
    if (L.length >= MaxSize) return false;
    for (int j=L.length; j>=i; j--)
        L.data[j]=L.data[j-1];
    L.data[i-1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType e){  // O(n)
    if (i<1 || i>L.length+1) return false;  
    e=L.data[i-1];
    for (int j=i; j<L.length; j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}

int LocateElem(SqList &L, ElemType e){  //按值查找 O(n) 按位置查找 O(1)
    for (int i=0; i<L.length; i++)
        if (L.data[i]==e)
            return i+1;
    return 0;
}

int main(){
    SqList SqList1;
    ListInsert(SqList1,1,333);
    cout<<LocateElem(SqList1,333)<<endl;
    return 0;
}
