/*
 * @Author: SukiEva
 * @Date: 2021-12-30 19:23:12
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

// 贪心统计峰值
class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int ans = 1;
        int pre = 0;
        for (int i = 1; i < nums.size(); i++) {
            int cur = nums[i] - nums[i - 1];
            if ((pre >= 0 && cur < 0) || (pre <= 0 && cur > 0)) {
                ans++;
                pre = cur;
            }
        }
        return ans;
    }
};

// dp[i][0]: i下标作为山峰的摆动序列长度
// dp[i][1]: i下标作为山谷的摆动序列长度
class Solution2 {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        int dp[nums.size()][2];
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {  // 山峰
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
            for (int j = 0; j < i; j++) {
                if (nums[i] < nums[j]) {  // 山谷
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};