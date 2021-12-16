/*
 * @Author: SukiEva
 * @Date: 2021-12-16 15:22:12
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int nx[needle.size() + 1];
        getNext(needle, nx);
        while (i < haystack.size() && j < needle.size()) {
            while (-1 != j && haystack[i] != needle[j]) j = nx[j];
            i++, j++;
        }
        if (j == needle.size()) return i - j;
        return -1;
    }

    void getNext(const string& s, int* nx) {
        int i = 0;
        int j = nx[0] = -1;
        while (i < s.size()) {
            while (-1 != j && s[i] != s[j]) j = nx[j];
            if (s[++i] == s[++j])
                nx[i] = nx[j];
            else
                nx[i] = j;
        }
    }
};