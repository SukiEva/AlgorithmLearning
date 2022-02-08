/*
 * @Author: SukiEva
 * @Date: 2022-02-08 20:23:37
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

// 约瑟夫环
// dp[i] = (dp[i-1]+m)%i
class Solution {
   public:
    int lastRemaining(int n, int m) {
        int x = 0;  // dp[1]
        for (int i = 2; i <= n; i++) {
            x = (x + m) % i;
        }
        return x;
    }
};