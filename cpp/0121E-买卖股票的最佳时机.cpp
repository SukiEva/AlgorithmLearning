/*
 * @Author: SukiEva
 * @Date: 2022-01-13 15:58:40
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
        int minn = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - minn > 0) ans = max(ans, prices[i] - minn);
            minn = min(minn, prices[i]);
        }
        return ans;
    }
};