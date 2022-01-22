/*
 * @Author: SukiEva
 * @Date: 2022-01-22 20:15:09
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int start = 0, len = 0;
        for (int i = 0; i < s.size(); i++) {
            int l1 = expand(s, i, i);      // 单个
            int l2 = expand(s, i, i + 1);  // 两个
            int l = max(l1, l2);
            if (l > len) {
                start = i - (l - 1) / 2;
                len = l;
            }
        }
        return s.substr(start, len);
    }

   private:
    int expand(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};