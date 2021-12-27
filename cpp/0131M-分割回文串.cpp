/*
 * @Author: SukiEva
 * @Date: 2021-12-27 13:46:19
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<vector<string>> ans;
    vector<string> tmp;

    bool check(string s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

    void dfs(string s, int idx) {
        if (idx >= s.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (!check(s, idx, i)) continue;
            tmp.push_back(s.substr(idx, i - idx + 1));
            dfs(s, i + 1);
            tmp.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};