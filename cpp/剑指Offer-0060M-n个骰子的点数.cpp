/*
 * @Author: SukiEva
 * @Date: 2022-02-12 21:29:20
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0 / 6);
        for (int i = 2; i <= n; i++) {
            // 和的范围是 [n,6n] 个数是 6n-n + 1 = 5n+1
            vector<double> tmp(5 * i + 1, 0);
            for (int j = 0; j < dp.size(); j++) {  //
                for (int k = 0; k < 6; k++)
                    tmp[j + k] += dp[j] / 6.0;  // 概率 x 1/6
            }
            dp = tmp;
        }
        return dp;
    }
};