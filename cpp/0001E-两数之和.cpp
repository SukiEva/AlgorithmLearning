/*
 * @Author: SukiEva
 * @Date: 2021-08-04 16:49:13
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

// https://leetcode-cn.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto it = m.find(target - nums[i]);
            if (it != m.end()) return {i, it->second};
            m[nums[i]] = i;
        }
        return {};
    }
};