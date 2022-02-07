/*
 * @Author: SukiEva
 * @Date: 2022-02-07 20:33:27
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
    void dfs(vector<int>& nums, int idx) {
        if (tmp.size() > 1) ans.push_back(tmp);
        if (idx >= nums.size()) return;
        vector<bool> vis(201, false);
        for (int i = idx; i < nums.size(); i++) {
            if (vis[nums[i] + 100]) continue;
            if (!tmp.empty() && tmp.back() > nums[i]) continue;
            tmp.push_back(nums[i]);
            vis[nums[i] + 100] = true;
            dfs(nums, i + 1);
            tmp.pop_back();
        }
    }

   public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};