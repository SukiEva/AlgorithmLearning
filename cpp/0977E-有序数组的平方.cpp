/*
 * @Author: SukiEva
 * @Date: 2021-12-13 09:12:57
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1, k = j; i <= j;) {
            int ii = nums[i] * nums[i];
            int jj = nums[j] * nums[j];
            if (ii > jj) {
                ans[k--] = ii;
                i++;
            } else {
                ans[k--] = jj;
                j--;
            }
        }

        return ans;
    }
};