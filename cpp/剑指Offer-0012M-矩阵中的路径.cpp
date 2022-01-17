/*
 * @Author: SukiEva
 * @Date: 2022-01-17 14:12:07
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

   private:
    int m, n;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    bool dfs(vector<vector<char>>& board, string word, int row, int col,
             int index) {
        if (row < 0 || col < 0 || row >= m || col >= n ||
            board[row][col] != word[index])
            return false;
        if (index == word.size() - 1) return true;
        board[row][col] = '#';
        bool ans;
        for (int i = 0; i < 4; i++) {
            ans = ans || dfs(board, word, row + dx[i], col + dy[i], index + 1);
        }
        board[row][col] = word[index];
        return ans;
    }
};