/*
 * @Author: SukiEva
 * @Date: 2022-02-22 12:50:01
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    vector<string> ans;
    void dfs(string s, int l, int r) {
        if (l < 0 || r < 0) return;
        if (l == 0 && r == 0) {
            ans.push_back(s);
            return;
        }
        if (l == r)
            dfs(s + '(', l - 1, r);  // 左右括号相等，下一个只能是 (
        else if (l < r) {  // 左括号 < 右括号， 下一个 () 都可
            dfs(s + '(', l - 1, r);
            dfs(s + ')', l, r - 1);
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return ans;
    }
};