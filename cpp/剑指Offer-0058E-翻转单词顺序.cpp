/*
 * @Author: SukiEva
 * @Date: 2022-01-26 16:52:23
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
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < n && s[l] == ' ') l++;
        while (r >= 0 && s[r] == ' ') r--;
        string ans = "";
        for (int i = r; i >= l; i--) {
            if (s[i] != ' ') continue;
            ans += s.substr(i + 1, r - i + 1) + " ";
            while (i > l && s[i - 1] == ' ') i--;
            r = i - 1;
        }
        ans += s.substr(l, r - l + 1);
        return ans;
    }
};