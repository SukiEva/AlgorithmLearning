/*
 * @Author: SukiEva
 * @Date: 2022-02-15 22:11:34
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> dp(n, 1);  // 严格单调增，类似单调栈，更新栈顶
        int ans = 0;
        for (int num : nums) {
            int l = 0, r = ans;
            while (l < r) {
                int m = (l + r) / 2;
                if (dp[m] < num)
                    l = m + 1;
                else
                    r = m;
            }
            dp[l] = num;
            if (ans == r) ans++;
        }
        return ans;
    }
};