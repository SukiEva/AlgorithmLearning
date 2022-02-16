/*
 * @Author: SukiEva
 * @Date: 2022-02-16 20:01:30
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) ans ^= num;
        return ans;
    }
};