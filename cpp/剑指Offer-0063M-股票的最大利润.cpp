/*
 * @Author: SukiEva
 * @Date: 2022-01-21 13:14:02
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int ans = 0;
        int low = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - low);
            low = min(prices[i], low);
        }
        if (ans < 0) return 0;
        return ans;
    }
};