/*
 * @Author: SukiEva
 * @Date: 2022-02-05 13:18:17
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
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    if (nums[i] + nums[j] < target - nums[l] - nums[r])
                        l++;
                    else if (nums[i] + nums[j] > target - nums[l] - nums[r])
                        r--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        l++, r--;
                    }
                }
            }
        }
        return ans;
    }
};