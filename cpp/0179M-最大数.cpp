/*
 * @Author: SukiEva
 * @Date: 2022-02-22 12:26:52
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    void qsort(vector<string>& nums, int l, int r) {
        int i = l, j = r;
        string m = nums[l + ((r - l) >> 1)];
        do {
            while (nums[i] + m < m + nums[i]) i++;
            while (nums[j] + m > m + nums[j]) j--;
            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        } while (i <= j);
        if (l < j) qsort(nums, l, j);
        if (i < r) qsort(nums, i, r);
    }

   public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int num : nums) strs.push_back(to_string(num));
        qsort(strs, 0, strs.size() - 1);
        string ans = "";
        for (int i = strs.size() - 1; i >= 0; i--) {
            ans += strs[i];
            if (i && i == strs.size() - 1 && strs[i] == "0") break;
        }
        return ans;
    }
};
