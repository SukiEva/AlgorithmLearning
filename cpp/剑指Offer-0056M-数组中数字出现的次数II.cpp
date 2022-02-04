/*
 * @Author: SukiEva
 * @Date: 2022-02-04 20:03:49
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
        int n = 0, m = 0;
        for (int num : nums) {
            n = n ^ num & ~m;
            m = m ^ num & ~n;
        }

        return n;
    }
};