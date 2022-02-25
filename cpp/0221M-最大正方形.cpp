/*
 * @Author: SukiEva
 * @Date: 2022-02-25 14:58:31
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

// dp[i][j]：以 [i,j] 为右下角的最大正方形变长
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1],
                                        dp[i - 1][j]}) +
                                   1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};