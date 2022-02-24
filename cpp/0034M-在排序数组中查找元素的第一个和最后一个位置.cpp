/*
 * @Author: SukiEva
 * @Date: 2022-02-24 10:22:10
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    int bsh(vector<int>& nums, int target, bool flag) {
        int l = 0, r = nums.size() - 1, ans = nums.size();
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] > target || (flag && nums[m] >= target)) {
                r = m - 1;
                ans = m;
            } else
                l = m + 1;
        }
        return ans;
    }

   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = bsh(nums, target, true);
        int r = bsh(nums, target, false) - 1;
        if (l <= r && r < nums.size()) return {l, r};
        return {-1, -1};
    }
};

class Solution2 {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] < target)
                l = m + 1;
            else if (nums[m] > target)
                r = m - 1;
            else {
                l = m;
                r = m;
                while (l > 0 && nums[l - 1] == target) l--;
                while (r < nums.size() - 1 && nums[r + 1] == target) r++;
                return {l, r};
            }
        }
        return {-1, -1};
    }
};