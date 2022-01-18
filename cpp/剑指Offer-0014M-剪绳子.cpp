/*
 * @Author: SukiEva
 * @Date: 2022-01-18 17:51:31
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 2; j < i; j++) {
                dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
            }
        }
        return dp[n];
    }
};