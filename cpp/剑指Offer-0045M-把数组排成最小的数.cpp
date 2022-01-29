/*
 * @Author: SukiEva
 * @Date: 2022-01-29 16:24:21
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        quickSort(strs, 0, strs.size() - 1);
        string res;
        for (string s : strs) res.append(s);
        return res;
    }

   private:
    void quickSort(vector<string>& nums, int l, int r) {
        string mid = nums[l + ((r - l) >> 1)];
        int i = l, j = r;
        do {
            while (nums[i] + mid < mid + nums[i]) i++;
            while (nums[j] + mid > mid + nums[j]) j--;
            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        } while (i <= j);
        if (l < j) quickSort(nums, l, j);
        if (i < r) quickSort(nums, i, r);
    }
};

// 优先队列
class Solution2 {
   private:
    struct cmp {
        bool operator()(string& x, string& y) { return x + y > y + x; }
    };

   public:
    string minNumber(vector<int>& nums) {
        priority_queue<string, vector<string>, cmp> que;
        for (int num : nums) {
            que.push(to_string(num));
        }
        string ans = "";
        while (!que.empty()) {
            ans += que.top();
            que.pop();
        }
        return ans;
    }
};