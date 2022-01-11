/*
 * @Author: SukiEva
 * @Date: 2022-01-11 11:29:25
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int j = 0; j <= target; j++) {
            for (int num : nums) {
                if (j - num >= 0 &&
                    dp[j] < INT_MAX - dp[j - num]) {  // 测试中有数据相加溢出
                    dp[j] += dp[j - num];
                }
            }
        }
        return dp[target];
    }
};