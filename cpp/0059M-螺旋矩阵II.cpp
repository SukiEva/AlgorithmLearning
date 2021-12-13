/*
 * @Author: SukiEva
 * @Date: 2021-12-13 09:23:21
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

using namespace std;

// 左闭右开
// 按圈循环
class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        int startx, starty, loop, cnt, offset, i, j;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        startx = starty = i = j = 0;
        cnt = offset = 1;
        loop = n / 2;
        while (loop--) {
            i = startx;
            j = starty;

            for (; j < starty + n - offset; j++) matrix[i][j] = cnt++;  // 👉→
            for (; i < startx + n - offset; i++) matrix[i][j] = cnt++;  // 👇↓
            for (; j > starty; j--) matrix[i][j] = cnt++;  // 👈←
            for (; i > startx; i--) matrix[i][j] = cnt++;  // 👆↑

            startx++, starty++;  // 向内一圈
            offset += 2;         // 两个外圈长度
        }
        if (n & 1)  // 奇数中间未遍历
            matrix[n / 2][n / 2] = cnt;
        return matrix;
    }
};
