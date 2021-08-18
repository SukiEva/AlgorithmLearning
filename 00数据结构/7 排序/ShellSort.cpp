#include <bits/stdc++.h>
using namespace std;

// ? 按照 ShellSort 定义写出
void shellSort1(int a[], int n) {
    int i, j, k, gap;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = 0; i < gap; i++)                   // 分组
            for (int j = i + gap; j < n; j += gap)  // 组内插入排序
                if (a[j] < a[j - gap]) {            // 直接插入排序
                    int v = a[j];
                    for (int k = j - gap; k >= 0 && a[k] > v; k -= gap)
                        a[k + gap] = a[k];  // 后移
                    a[k + gap] = v;
                }
}

// ? 优化
// - 上述 i 的作用是为了确认 j 的位置，并与组内元素比较
// - 明显每次 gap 与 j-gap 就是组内比较，不需要再分组
void shellSort(int a[], int n) {
    int j, k, gap;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (j = gap; j < n; j++)
            if (a[j] < a[j - gap]) {
                int v = a[j];
                for (int k = j - gap; k >= 0 && a[k] > v; k -= gap)
                    a[k + gap] = a[k];  // 后移
                a[k + gap] = v;
            }
}