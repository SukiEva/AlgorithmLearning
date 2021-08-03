#include <iostream>
#include "SqList.h"
using namespace std;

/* 1.删除最小值的元素 */
ElemType ListDeleteMin(SqList &L){
    if (L.length==0){
        cout<<"Error: no element"<<endl;
        return -1;
    }
    int Min = L.data[0];
    int MinPos = 0;    
    for (int i=1; i<L.length; i++){
        if (L.data[i]<Min){
            Min = L.data[i];
            MinPos = i;
        }
    }
    L.data[MinPos]=L.data[L.length-1];
    L.length--;
    return Min;
}

/* 2.逆置所有元素 */
void ListReverse(SqList &L){
    int len = L.length-1;
    for (int i=0; i<=len/2; i++){
        ElemType temp = L.data[i];
        L.data[i]=L.data[len-i];
        L.data[len-i]=temp;
    }
}

/* 3.删除值为x的所有元素 */
/* 记录不等于x的个数，即重组的下标 */
void ListDeleteX(SqList &L, ElemType x){
    int k = 0;
    for (int i=0; i<L.length; i++){
        if (L.data[i]!=x){
            L.data[k++]=L.data[i];
        }
    }
    L.length = k; 
}

/* 4.有序顺序表删除值在 [s,t]间的所有元素 */
bool ListDeleteBetween(SqList &L, ElemType s, ElemType t){
    if (L.length==0 || s>=t) return false;
    int sp=0,tp=0;
    bool flag = false;
    for (int i=0; i<L.length; i++){
        if (L.data[i]>s && !flag){
            sp = i;
            flag=true;
        } 
        if (flag && L.data[i]>t){
            tp = i;
            break;
        }
    }
    if (tp==0) tp=L.length-1;
    if (sp==0) return false;
    for (int i=tp; i<L.length; i++)
        L.data[sp++]=L.data[i];
    L.length = sp;
    return true;
}

/* 5.顺序表删除值在 [s,t]间的所有元素 */
bool ListDeleteBetween2(SqList &L, ElemType s, ElemType t){
    int k = 0; // 维护区间内数的个数
    if (L.length==0 || s>=t) return false;
    for (int i=0; i<L.length; i++){
        if (L.data[i]>=s && L.data[i]<=t) k++; 
        else L.data[i-k]=L.data[i]; // 将不在区间内的数向前移动 k 个单位
    }
    L.length-=k;
    return true;
}

/* 6.有序顺序表中删除值重复的元素 */
bool ListDeleteRepeat(SqList &L){
    if (L.length==0) return false;
    int k = 0;
    for (int i=1; i<L.length; i++){
        if (L.data[i]==L.data[i-1]) k++;
        else L.data[i-k] = L.data[i];
    }
    L.length -= k;
    return true;
}


int main(){
    SqList SqList1;
    SqList1.data[0]=1;
    SqList1.data[1]=2;
    SqList1.data[2]=2;
    SqList1.length=3;
    cout<<SqList1.length<<endl;
    ListDeleteRepeat(SqList1);
    for (int i=0; i<SqList1.length; i++)
        cout<<SqList1.data[i]<<" ";


    return 0;
}
