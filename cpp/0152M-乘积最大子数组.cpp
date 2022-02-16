/*
 * @Author: SukiEva
 * @Date: 2022-02-16 20:04:21
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

// dp[i][0] 负数最大值
// dp[i][1] 正数最大值
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        vector<vector<long>> dp(nums.size(), vector<long>(2));
        long ans = nums[0];
        if (nums[0] < 0)
            dp[0][0] = nums[0];
        else
            dp[0][1] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                dp[i][0] = min(dp[i - 1][1] * nums[i], long(nums[i]));
                dp[i][1] = dp[i - 1][0] * nums[i];
            } else {
                dp[i][0] = dp[i - 1][0] * nums[i];
                dp[i][1] = max(dp[i - 1][1] * nums[i], long(nums[i]));
            }
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};