/*
 * @Author: SukiEva
 * @Date: 2022-02-04 19:48:58
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n = 0;
        for (int num : nums) n ^= num;  // n = x ^ y
        int m = 1;
        while ((n & m) == 0) m <<= 1;  // m = (x ^ y)的首位 1
        int x = 0, y = 0;
        for (int num : nums) {  // 划分数组，保证子数组异或时为 0
            if (num & m)
                x ^= num;
            else
                y ^= num;
        }
        return {x, y};
    }
};