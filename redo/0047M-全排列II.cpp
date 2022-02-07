/*
 * @Author: SukiEva
 * @Date: 2022-02-07 20:50:16
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
    bool vis[10] = {false};

    void dfs(vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;
            tmp.push_back(nums[i]);
            vis[i] = true;
            dfs(nums);
            tmp.pop_back();
            vis[i] = false;
        }
    }

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums);
        return ans;
    }
};