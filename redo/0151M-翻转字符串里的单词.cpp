/*
 * @Author: SukiEva
 * @Date: 2022-02-05 19:44:00
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int p = 0, j;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            if (p) s[p++] = ' ';  // 填补空格
            for (j = i; j < s.size() && s[j] != ' '; j++) s[p++] = s[j];
            reverse(s.begin() + p - (j - i), s.begin() + p);
            i = j;
        }
        s.erase(s.begin() + p, s.end());
        return s;
    }
};