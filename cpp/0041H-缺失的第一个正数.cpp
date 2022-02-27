/*
 * @Author: SukiEva
 * @Date: 2022-02-27 22:07:20
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

// 原地哈希
class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > nums.size() ||
                    nums[i] == nums[nums[i] - 1])  // 相等 nums[i] == nums[idx]
                    break;
                // 交换 nums[i] 和 nums[idx]
                int idx = nums[i] - 1;  // 将要放的位置
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;  // 都存在，就是下一个数字
    }
};