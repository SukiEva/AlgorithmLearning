/*
 * @Author: SukiEva
 * @Date: 2022-02-05 13:07:02
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) break;                         // 剪枝
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // 去重
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0)
                    l++;
                else if (sum > 0)
                    r--;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    l++, r--;
                }
            }
        }
        return ans;
    }
};