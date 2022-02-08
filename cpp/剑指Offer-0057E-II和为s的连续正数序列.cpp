/*
 * @Author: SukiEva
 * @Date: 2022-02-08 20:08:30
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        deque<int> tmp;
        int sum = 0;
        for (int l = 1, r = 1; r <= target / 2 + 1; r++) {
            sum += r;
            tmp.push_back(r);
            while (sum > target) {
                sum -= l++;
                tmp.pop_front();
            }
            if (sum == target) {
                ans.push_back(vector<int>(tmp.begin(), tmp.end()));
            }
        }
        return ans;
    }
};