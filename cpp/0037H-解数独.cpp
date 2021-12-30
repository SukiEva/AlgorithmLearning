/*
 * @Author: SukiEva
 * @Date: 2021-12-28 16:32:20
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool check(int row, int col, int val, vector<vector<char>>& board) {
        for (int j = 0; j < 9; j++) {  // 检查列
            if (board[row][j] == val) return false;
        }
        for (int i = 0; i < 9; i++) {  // 检查行
            if (board[i][col] == val) return false;
        }
        // 检查 3x3
        int nRow = (row / 3) * 3;
        int nCol = (col / 3) * 3;
        for (int i = nRow; i < nRow + 3; i++) {
            for (int j = nCol; j < nCol + 3; j++)
                if (board[i][j] == val) return false;
        }
        return true;
    }

    bool dfs(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') continue;
                for (char k = '1'; k <= '9'; k++) {
                    if (check(i, j, k, board)) {
                        board[i][j] = k;
                        if (dfs(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;  // 9 个数都不行
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { dfs(board); }
};