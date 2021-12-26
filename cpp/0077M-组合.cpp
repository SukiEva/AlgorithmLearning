/*
 * @Author: SukiEva
 * @Date: 2021-12-26 13:39:15
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> tmp;

    void dfs(int n, int k, int idx) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx; i <= n - (k - tmp.size()) + 1; i++) {
            tmp.push_back(i);
            dfs(n, k, i + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};