/*
 * @Author: SukiEva
 * @Date: 2022-01-18 20:24:31
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
        for (int i = 0; i < nums.size(); i++) {
            if (sum > 0)
                sum += nums[i];
            else
                sum = nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};