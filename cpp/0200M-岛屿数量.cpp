/*
 * @Author: SukiEva
 * @Date: 2022-01-23 19:17:21
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    int m, n;
    bool vis[305][305] = {false};
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= m || col >= n ||
            grid[row][col] == '0' || vis[row][col])
            return;
        vis[row][col] = true;
        for (int i = 0; i < 4; i++) {
            dfs(grid, row + dx[i], col + dy[i]);
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};