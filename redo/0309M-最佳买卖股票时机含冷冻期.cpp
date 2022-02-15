/*
 * @Author: SukiEva
 * @Date: 2022-02-15 21:52:20
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) -
                                             prices[i]);  // 买入
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);   // 卖出非冷冻期
            dp[i][2] = dp[i - 1][0] + prices[i];          // 刚卖出
            dp[i][3] = dp[i - 1][2];                      // 卖出冷冻期
        }
        return max({dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
    }
};