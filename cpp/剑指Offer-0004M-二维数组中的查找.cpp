/*
 * @Author: SukiEva
 * @Date: 2022-01-16 14:24:17
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int n = matrix.size(), m = matrix[0].size();
        for (int row = 0, col = m - 1; row < n && col >= 0;) {
            int num = matrix[row][col];
            if (num > target)
                col--;
            else if (num < target)
                row++;
            else
                return true;
        }
        return false;
    }
};