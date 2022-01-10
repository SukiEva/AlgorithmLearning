/*
 * @Author: SukiEva
 * @Date: 2022-01-10 12:35:37
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int stone : stones) sum += stone;
        int tmp = sum;
        sum >>= 1;
        vector<int> dp(sum + 1);
        for (int i = 0; i < stones.size(); i++) {
            for (int j = sum; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return tmp - 2 * dp[sum];
    }
};