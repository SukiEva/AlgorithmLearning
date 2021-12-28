/*
 * @Author: SukiEva
 * @Date: 2021-12-28 16:07:25
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<vector<string>> ans;

    /*
     * 递归遍历行
     * 循环遍历列
     */
    void dfs(int row, int n, vector<string>& chess) {
        if (row == n) {
            ans.push_back(chess);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (check(row, col, n, chess)) {
                chess[row][col] = 'Q';
                dfs(row + 1, n, chess);
                chess[row][col] = '.';
            }
        }
    }

    /*
     *不能同行（递归过程中进行了同行检查）
     *不能同列
     *不能同斜线 （45度和135度角）
     */
    bool check(int row, int col, int n, vector<string>& chess) {
        // 检查列，剪枝
        for (int i = 0; i < row; i++) {
            if (chess[i][col] == 'Q') return false;
        }
        // ∠45°
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chess[i][j] == 'Q') return false;
        }
        // ∠135°
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chess[i][j] == 'Q') return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n, string(n, '.'));
        dfs(0, n, chess);
        return ans;
    }
};