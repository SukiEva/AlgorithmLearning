/*
 * @Author: SukiEva
 * @Date: 2022-01-29 21:02:58
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int joker = 0;
        for (int i = 0; i < 4; i++) {
            if (nums[i] == 0)
                joker++;
            else if (nums[i] == nums[i + 1])
                return false;
        }
        return nums[4] - nums[joker] < 5;
    }
};