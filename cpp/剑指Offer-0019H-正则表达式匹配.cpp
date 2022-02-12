/*
 * @Author: SukiEva
 * @Date: 2022-02-12 20:49:32
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

// dp[i][j]: s前i 和 p前j 是否匹配
class Solution {
   public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1, n = p.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        for (int j = 2; j < n; j += 2)
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (p[j - 1] == '*') {          // 即 p[j-2]*
                    dp[i][j] = dp[i][j - 2] ||  //出现 0 次
                               (dp[i - 1][j] && s[i - 1] == p[j - 2]) ||  //
                               (dp[i - 1][j] && p[j - 2] == '.');         //
                } else {
                    dp[i][j] = (dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) ||  //
                               (dp[i - 1][j - 1] && p[j - 1] == '.');         //
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
