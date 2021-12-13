/*
 * @Author: SukiEva
 * @Date: 2021-12-13 09:18:16
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT32_MAX;
        int sum = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
        }
        if (ans == INT32_MAX) return 0;
        return ans;
    }
};
