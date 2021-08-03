// Created on 自闭每一天.

#include <iostream>
using namespace std;

/* static */
#define MaxSize 50
#define ElemType int
struct SqList{
    ElemType data[MaxSize];
    int length;
}SqList1;

/* dynamic 
#define InitSize 100
struct  SeqList{
    ElemType *data;
    int length;
}SeqList;
SeqList.data = new int [InitSize]; // malloc
*/

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

    ListInsert(SqList1,1,333);
    cout<<LocateElem(SqList1,333)<<endl;
    return 0;
}