/*
 * @Author: SukiEva
 * @Date: 2022-02-12 21:20:11
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int a, b, c;
        a = b = c = 1;
        for (int i = 2; i <= n; i++) {
            int aa = dp[a] * 2;
            int bb = dp[b] * 3;
            int cc = dp[c] * 5;
            dp[i] = min({aa, bb, cc});
            if (dp[i] == aa) a++;
            if (dp[i] == bb) b++;
            if (dp[i] == cc) c++;
        }
        return dp[n];
    }
};