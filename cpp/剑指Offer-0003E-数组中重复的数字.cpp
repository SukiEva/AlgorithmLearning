/*
 * @Author: SukiEva
 * @Date: 2022-01-16 14:15:30
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> ust;
        for (int num : nums) {
            if (ust.count(num))
                return num;
            else
                ust.insert(num);
        }
        return 0;
    }
};