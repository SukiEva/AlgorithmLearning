/*
 * @Author: SukiEva
 * @Date: 2022-02-04 20:18:54
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT32_MAX;
        int sum = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            sum += nums[r];
            if (sum < target) continue;
            while (sum - nums[l] >= target) {
                sum -= nums[l++];
            }
            ans = min(ans, r - l + 1);
        }
        if (ans == INT32_MAX) return 0;
        return ans;
    }
};