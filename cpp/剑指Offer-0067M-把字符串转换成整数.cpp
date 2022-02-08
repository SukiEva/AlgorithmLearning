/*
 * @Author: SukiEva
 * @Date: 2022-02-08 21:55:27
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int strToInt(string s) {
        int i = 0, n = s.size();
        bool zf = true;
        while (i < n && s[i] == ' ') i++;
        if (i > n) return 0;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') zf = false;
            if (++i > n) return 0;
        }
        long long ans = 0;
        while (i < n) {
            if (s[i] < '0' || s[i] > '9') return zf ? ans : 0 - ans;
            ans = ans * 10 + (s[i++] - '0');
            if (zf && ans > INT32_MAX) return INT32_MAX;
            if (!zf && 0 - ans < INT32_MIN) return INT32_MIN;
        }
        return zf ? ans : 0 - ans;
    }
};