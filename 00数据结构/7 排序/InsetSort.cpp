#include <bits/stdc++.h>
using namespace std;

void InsertSort(int a[], int len) {
    int i, j;
    for (i = 1; i < len; i++) {
        int v = a[i];
        for (j = i - 1; v < a[j]; j--) a[j + 1] = a[j];  // 后移
        a[j + 1] = v;
    }
}