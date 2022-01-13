/*
 * @Author: SukiEva
 * @Date: 2022-01-13 16:53:55
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1));
        for (int i = 1; i <= 2 * k; i += 2) {
            dp[0][i] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j <= 2 * k; j++) {
                if (j & 1)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};
