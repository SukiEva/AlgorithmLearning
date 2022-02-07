/*
 * @Author: SukiEva
 * @Date: 2022-02-07 21:05:29
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        int startx, starty, i, j;
        startx = starty = i = j = 0;
        int loop = min(m, n) / 2;
        int offset = 1;
        while (loop--) {
            i = startx;
            j = starty;
            for (; j < starty + n - offset; j++) ans.push_back(matrix[i][j]);
            for (; i < startx + m - offset; i++) ans.push_back(matrix[i][j]);
            for (; j > startx; j--) ans.push_back(matrix[i][j]);
            for (; i > starty; i--) ans.push_back(matrix[i][j]);
            startx++, starty++;
            offset += 2;
        }
        i = startx;
        j = starty;
        if (m <= n && m & 1) {
            for (; j <= starty + n - offset; j++) ans.push_back(matrix[i][j]);
        }
        if (n < m && n & 1) {
            for (; i <= startx + m - offset; i++) ans.push_back(matrix[i][j]);
        }
        return ans;
    }
};