/*
 * @Author: SukiEva
 * @Date: 2021-12-30 20:00:45
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        for (auto num : nums) {
            if (sum > 0)
                sum += num;
            else
                sum = num;
            ans = max(sum, ans);
        }
        return ans;
    }
};