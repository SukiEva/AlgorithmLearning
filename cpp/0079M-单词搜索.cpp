/*
 * @Author: SukiEva
 * @Date: 2022-03-25 22:04:05
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int m, n, k;
    bool dfs(vector<vector<char>>& board, string word,
             vector<vector<bool>>& vis, int x, int y, int idx) {
        if (idx == k - 1) return board[x][y] == word[idx];
        if (board[x][y] != word[idx]) return false;
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
            if (dfs(board, word, vis, nx, ny, idx + 1)) return true;
        }
        vis[x][y] = false;
        return false;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        k = word.size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, vis, i, j, 0)) return true;
            }
        }
        return false;
    }
};