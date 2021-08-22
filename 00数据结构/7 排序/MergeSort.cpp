#include <bits/stdc++.h>
using namespace std;

void Merge(int a[], int begin, int mid, int end) {
    int left = begin, right = mid + 1, k = 0;
    int *temp = new int[end - begin + 1];
    //顺序选取两个有序区的较小元素，存储到t数组中
    while (left <= mid && right <= end) {
        //较小的先存入temp中
        if (a[left] <= a[right])
            temp[k++] = a[left++];
        else
            temp[k++] = a[right++];
    }
    //若比较完之后，有序区仍有剩余，则直接复制到t数组中
    while (left <= mid) temp[k++] = a[left++];
    while (right <= end) temp[k++] = a[right++];
    //将排好序的存回arr中
    for (int i = begin, k = 0; i <= end; i++, k++) a[i] = temp[k];
    //删除指针，释放空间
    delete[] temp;
}

// ? 递归
void MergeSort(int a[], int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        MergeSort(a, begin, mid);    // 左侧递归
        MergeSort(a, mid + 1, end);  // 右侧递归
        Merge(a, begin, mid, end);   // 归并
    }
}

// ? 非递归
void MergeSort2(int a[], int n) {
    int size = 1, begin, mid, end;
    while (size <= n - 1) {
        begin = 0;
        while (begin + size <= n - 1) {
            mid = begin + size - 1;
            end = mid + size;
            if (end > n - 1)  //第二个序列个数不足size
                end = n - 1;
            Merge(a, begin, mid, end);
            begin = end + 1;  //下一次归并时第一关序列的下界
        }
        size *= 2;  //扩大范围
    }
}