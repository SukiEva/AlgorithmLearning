/*
 * @Author: SukiEva
 * @Date: 2021-12-27 14:37:36
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
        ans.push_back(tmp);
        if (idx >= nums.size()) return;
        for (int i = idx; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            dfs(nums, i + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};