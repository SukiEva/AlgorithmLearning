/*
 * @Author: SukiEva
 * @Date: 2022-02-05 19:38:02
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
        for (char c : s)
            if (c == ' ') cnt++;
        int n = s.size();
        s.resize(n + 2 * cnt);
        for (int l = n - 1, r = s.size() - 1; l >= 0; l--, r--) {
            if (s[l] != ' ') {
                s[r] = s[l];
                continue;
            }
            s[r--] = '0';
            s[r--] = '2';
            s[r] = '%';
        }
        return s;
    }
};