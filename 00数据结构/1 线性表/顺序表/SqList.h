#ifndef HEADER_FILE
#define HEADER_FILE

#define MaxSize 50
#define ElemType int
struct SqList{
    ElemType data[MaxSize];
    int length;
};
/* dynamic 
#define InitSize 100
struct  SeqList{
    ElemType *data;
    int length;
}SeqList;
SeqList.data = new int [InitSize]; // malloc
*/
/*
bool ListInsert(SqList &L, int i, ElemType e);
bool ListDelete(SqList &L, int i, ElemType e);
int LocateElem(SqList &L, ElemType e);
*/
#endif
