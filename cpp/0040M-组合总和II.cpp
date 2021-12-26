/*
 * @Author: SukiEva
 * @Date: 2021-12-26 14:43:44
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
    bool vis[101] = {false};

    void dfs(vector<int>& candidates, int target, int idx, int sum) {
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx;
             i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && !vis[i - 1])
                continue;  // 去重
            vis[i] = true;
            tmp.push_back(candidates[i]);
            dfs(candidates, target, i + 1, sum + candidates[i]);
            tmp.pop_back();
            vis[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return ans;
    }
};