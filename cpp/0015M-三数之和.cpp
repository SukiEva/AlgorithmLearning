/*
 * @Author: SukiEva
 * @Date: 2021-12-15 08:49:41
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

// 排序 + 去重
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[right - 1] == nums[right])
                        right--;
                    while (left < right && nums[left + 1] == nums[left]) left++;
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};