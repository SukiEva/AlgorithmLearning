/*
 * @Author: SukiEva
 * @Date: 2022-01-10 12:57:29
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

/*
l - r = target
l + r = sum
==> l = (target+sum)/2
==> 目标和为 l 有多少种
*/

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