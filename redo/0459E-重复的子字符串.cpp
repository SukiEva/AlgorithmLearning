/*
 * @Author: SukiEva
 * @Date: 2022-02-05 20:14:44
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) return false;
        int n = s.size();
        vector<int> nx(n + 1);
        int i = 0, j = -1;
        nx[0] = -1;
        while (i < n) {
            while (j != -1 && s[i] != s[j]) j = nx[j];
            nx[++i] = ++j;
        }
        if (nx[n] != 0 && n % (n - nx[n]) == 0) return true;
        return false;
    }
};