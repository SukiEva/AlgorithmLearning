/*
 * @Author: SukiEva
 * @Date: 2022-02-05 21:05:55
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

// 摩尔投票
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int votes = 0, x;  // x 是擂主
        for (int num : nums) {
            if (votes == 0) x = num;  // 没人了，选 x 当擂主
            votes += (num == x) ? 1 : -1;  // 相同：一伙人 +1，不同：同归于尽 -1
        }
        return x;  // 活下来的是出现最多的
    }
};

// 哈希
class Solution2 {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
            if (mp[num] > nums.size() / 2) return num;
        }
        return -1;
    }
};