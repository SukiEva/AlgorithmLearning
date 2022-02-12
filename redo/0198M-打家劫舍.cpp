/*
 * @Author: SukiEva
 * @Date: 2022-02-12 20:13:43
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};

// 输出路径
class Solution2 {
   public:
    vector<int> rob(vector<int>& nums) {
        if (nums.size() < 2) return {nums[0]};
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = nums[0];
        dp[1][1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = max(dp[i - 2][1], dp[i - 2][0]) + nums[i];
        }
        int target = max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
        vector<int> ans;
        for (int i = dp.size() - 1; i >= 0; i--) {
            if (dp[i][1] = target) {
                ans.push_back(nums[i]);
                target -= nums[i];
            }
        }
        return ans;
    }
};