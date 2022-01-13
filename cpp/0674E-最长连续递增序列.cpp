/*
 * @Author: SukiEva
 * @Date: 2022-01-13 21:05:17
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};