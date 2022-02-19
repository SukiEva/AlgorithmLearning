/*
 * @Author: SukiEva
 * @Date: 2022-02-19 22:44:52
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
};