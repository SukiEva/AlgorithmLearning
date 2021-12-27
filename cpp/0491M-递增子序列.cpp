/*
 * @Author: SukiEva
 * @Date: 2021-12-27 16:21:52
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

    void dfs(vector<int>& nums, int idx) {
        if (tmp.size() > 1) ans.push_back(tmp);
        if (idx >= nums.size()) return;
        bool vis[205] = {false};
        for (int i = idx; i < nums.size(); i++) {
            if ((!tmp.empty() && nums[i] < tmp.back()) || vis[nums[i] + 100])
                continue;
            tmp.push_back(nums[i]);
            vis[nums[i] + 100] = true;  // 本层已经用过，去重
            dfs(nums, i + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};