/*
 * @Author: SukiEva
 * @Date: 2021-09-05 21:36:23
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

// https://leetcode-cn.com/problems/running-sum-of-1d-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i=1; i<nums.size(); i++){
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};
