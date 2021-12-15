/*
 * @Author: SukiEva
 * @Date: 2021-12-15 09:02:42
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    if (nums[i] + nums[j] < target - nums[left] - nums[right])
                        left++;
                    else if (nums[i] + nums[j] >
                             target - nums[left] - nums[right])
                        right--;
                    else {
                        ans.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        right--;
                        left++;
                    }
                }
            }
        }

        return ans;
    }
};