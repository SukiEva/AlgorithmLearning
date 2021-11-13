#include <bits/stdc++.h>
using namespace std;

// - 图解 https://www.cnblogs.com/chengxiao/p/6129630.html

// ? 调整以 k 为根的子树，即 shift 操作
// - 大孩子上升，空位置下降
void HeadAdjust(int a[], int k, int len) {
    int t = a[k];
    for (int i = k * 2 + 1; i < len; i = i * 2 + 1) {
        //  如果左子结点小于右子结点，i指向右子结点
        if (i + 1 < len && a[i] < a[i + 1]) i++;
        //  如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
        if (a[i] > t) {
            a[k] = a[i];
            k = i;
        } else
            break;
    }
    a[k] = t;  // t 放在最终位置
}

// ? 堆排序
void HeapSort(int a[], int len) {
    int i;
    // - 建立大根堆
    for (i = len / 2 - 1; i >= 0; i--) HeadAdjust(a, i, len);
    // - 调整堆结构 + 交换堆顶堆低元素
    for (i = len - 1; i >= 0; i--) {
        swap(a[i], a[0]);
        HeadAdjust(a, 0, i);
    }
}