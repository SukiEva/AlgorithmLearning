/*
 * @Author: SukiEva
 * @Date: 2021-12-26 14:26:27
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

    void dfs(vector<int>& candidates, int target, int idx, int sum) {
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx;
             i < candidates.size() && sum + candidates[i] <= target; i++) {
            tmp.push_back(candidates[i]);
            dfs(candidates, target, i, sum + candidates[i]);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 排序剪枝
        dfs(candidates, target, 0, 0);
        return ans;
    }
};