/*
 * @Author: SukiEva
 * @Date: 2022-02-04 20:27:27
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));

        int startx = 0, starty = 0;
        int offset = 1;
        int i, j;
        int loop = n / 2;
        int cnt = 1;
        while (loop--) {
            i = startx;
            j = starty;
            for (; j < n + starty - offset; j++) matrix[i][j] = cnt++;
            for (; i < n + startx - offset; i++) matrix[i][j] = cnt++;
            for (; j > startx; j--) matrix[i][j] = cnt++;
            for (; i > starty; i--) matrix[i][j] = cnt++;
            startx++;
            starty++;
            offset += 2;
        }
        if (n & 1) matrix[n / 2][n / 2] = cnt;
        return matrix;
    }
};