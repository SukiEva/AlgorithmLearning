/*
 * @Author: SukiEva
 * @Date: 2022-02-07 20:08:39
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(vector<int>& candidates, int target, int sum, int idx) {
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx;
             i < candidates.size() && sum + candidates[i] <= target; i++) {
            tmp.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i);
            tmp.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return ans;
    }
};