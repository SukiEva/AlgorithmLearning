/*
 * @Author: SukiEva
 * @Date: 2022-02-13 21:12:50
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> printNumbers(int n) {
        vector<int> ans;
        for (int i = 1; i < pow(10, n); i++) {
            ans.push_back(i);
        }
        return ans;
    }
};