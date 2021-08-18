#include <bits/stdc++.h>
using namespace std;

void SelectSort(int a[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int k = i;
        for (int j = i + 1; j < len; j++) {
            if (a[j] < a[k]) k = j;
        }
        if (i != k) swap(a[i], a[k]);
    }
}