/*
 * @Author: SukiEva
 * @Date: 2021-08-11 21:59:19
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

// https://leetcode-cn.com/problems/implement-strstr/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int nx[50005];
    void getnx(string x) {
        int m = x.size();
        int j = nx[0] = -1;
        int i = 0;
        while (i < m) {
            while (j != -1 && x[i] != x[j]) j = nx[j];
            if (x[++i] == x[++j])
                nx[i] = nx[j];
            else
                nx[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        getnx(needle);
        int n = haystack.size(), m = needle.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            while (j != -1 && haystack[i] != needle[j]) j = nx[j];
            i++, j++;
        }
        if (j == m)
            return i - j;
        else
            return -1;
    }
};