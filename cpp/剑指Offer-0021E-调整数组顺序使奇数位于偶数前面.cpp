/*
 * @Author: SukiEva
 * @Date: 2022-01-26 16:44:34
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        vector<int> ans(nums.size());
        for (int num : nums) {
            if (num & 1)
                ans[i++] = num;
            else
                ans[j--] = num;
        }
        return ans;
    }
};