/*
 * @Author: SukiEva
 * @Date: 2021-12-14 09:17:12
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end())
                return {i, mp[target - nums[i]]};
            else
                mp[nums[i]] = i;
        }
        return {};
    }
};