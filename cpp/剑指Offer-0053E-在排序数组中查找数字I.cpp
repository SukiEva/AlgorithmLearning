/*
 * @Author: SukiEva
 * @Date: 2022-01-17 12:56:39
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else {
                int ans = 1;
                for (int i = mid + 1; i < nums.size() && nums[i] == target; i++)
                    ans++;
                for (int i = mid - 1; i >= 0 && nums[i] == target; i--) ans++;
                return ans;
            }
        }
        return 0;
    }
};