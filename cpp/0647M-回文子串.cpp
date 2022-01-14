/*
 * @Author: SukiEva
 * @Date: 2022-01-14 15:56:47
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] != s[j]) continue;
                if (j - i <= 1 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};