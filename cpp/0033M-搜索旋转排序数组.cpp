/*
 * @Author: SukiEva
 * @Date: 2022-01-22 20:41:01
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
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {  // [l,mid-1] 有序
                if (nums[0] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {  // [mid+1,r] 有序
                if (nums[mid] < target && target <= nums[n - 1])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};