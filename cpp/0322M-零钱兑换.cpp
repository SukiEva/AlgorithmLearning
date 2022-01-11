/*
 * @Author: SukiEva
 * @Date: 2022-01-11 21:28:20
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT32_MAX);
        dp[0] = 0;
        for (int coin : coins) {
            for (int j = 0; j <= amount; j++) {
                if (j - coin >= 0 && dp[j - coin] != INT32_MAX) {
                    dp[j] = min(dp[j], dp[j - coin] + 1);
                }
            }
        }
        if (dp[amount] == INT32_MAX) return -1;
        return dp[amount];
    }
};