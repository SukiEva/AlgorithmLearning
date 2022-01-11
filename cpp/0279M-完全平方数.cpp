/*
 * @Author: SukiEva
 * @Date: 2022-01-11 21:39:38
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (j - i * i >= 0 && dp[j - i * i] != INT32_MAX) {
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
        return dp[n];
    }
};