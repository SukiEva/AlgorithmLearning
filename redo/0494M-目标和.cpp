/*
 * @Author: SukiEva
 * @Date: 2022-02-11 19:44:57
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

// 分为两部分
// l - r = target
// l + r = sum
// l = (sum+target)/2
class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (abs(target) > sum || (sum + target) & 1) return 0;
        target = (sum + target) >> 1;
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};