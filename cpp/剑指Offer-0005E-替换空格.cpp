/*
 * @Author: SukiEva
 * @Date: 2021-12-16 09:44:45
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    string replaceSpace(string s) {
        int cnt = 0;
        for (auto c : s)
            if (c == ' ') cnt++;
        int left = s.size() - 1;
        s.resize(s.size() + 2 * cnt);
        int right = s.size() - 1;
        for (; left < right; left--, right--) {
            if (s[left] != ' ') {
                s[right] = s[left];
                continue;
            }
            s[right--] = '0';
            s[right--] = '2';
            s[right] = '%';
        }
        return s;
    }
};