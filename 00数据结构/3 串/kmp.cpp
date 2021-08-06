#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e5;
int nx[maxn];
void getnx(string x) {
    int len = x.size();
    int j = nx[0] = -1;
    int i = 0;
    while (i < len) {
        if (j == -1 || x[i] == x[j]) {
            i++, j++;
            if (x[i] == x[j])
                nx[i] = nx[j];
            else
                nx[i] = j;
        } else
            j = nx[j];
    }
}

int kmp(string s, string t) {  // s为匹配串，t为模式串
    int n = s.size();
    int m = t.size();
    int i = 0, j = 0;
    getnx(t);
    while (i < n && j < m) {
        while (-1 != j && s[i] != t[j]) j = nx[j];
        i++, j++;
    }
    if (j == m)
        return i - j;
    else
        return -1;
}