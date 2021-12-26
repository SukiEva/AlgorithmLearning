/*
 * @Author: SukiEva
 * @Date: 2021-12-26 13:57:02
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

    void dfs(int k, int n, int idx, int sum) {
        if (sum > n) return;
        if (tmp.size() == k) {
            if (sum != n) return;
            ans.push_back(tmp);
            return;
        }
        for (int i = idx; i <= 9 - (k - tmp.size()) + 1; i++) {
            tmp.push_back(i);
            dfs(k, n, i + 1, sum + i);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1, 0);
        return ans;
    }
};