#include <bits/stdc++.h>
using namespace std;

// ? 快排划分
int Partition(int a[], int l, int r) {
    int p = a[l];
    while (l < r) {                      // l != r
        while (l < r && a[r] >= p) --r;  // r 向左扫描
        a[l] = a[r];
        while (l < r && a[l] <= p) ++l;  // l 向右扫描
        a[r] = a[l];
    }
    a[l] = p;
    return l;
}

// ? 快速排序
// - a[l] 作为基准值
void QuickSort1(int a[], int l, int r) {
    if (l < r) {
        int p = Partition(a, l, r);
        QuickSort(a, l, p - 1);
        QuickSort(a, p + 1, r);
    }
}

// ? 三数取中优化,此版本快的飞起
// https://www.cnblogs.com/chengxiao/p/6262208.html
// - 左端、中间、右端三个数，然后进行排序，将中间数作为枢纽值
void QuickSort(int a[], int l, int r) {
    int mid = a[(l + r) / 2];
    int i = l, j = r;
    do {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}