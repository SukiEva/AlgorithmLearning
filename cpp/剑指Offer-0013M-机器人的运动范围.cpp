/*
 * @Author: SukiEva
 * @Date: 2022-01-17 13:55:40
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    bool check(int row, int col, int k) {
        int sum = 0;
        while (row) {
            sum += row % 10;
            row /= 10;
        }
        while (col) {
            sum += col % 10;
            col /= 10;
        }
        if (sum > k) return false;
        return true;
    }

   public:
    int movingCount(int m, int n, int k) {
        int dx[] = {0, 1};
        int dy[] = {1, 0};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> que;
        que.push({0, 0});
        vis[0][0] = true;
        int ans = 1;
        while (!que.empty()) {
            pair<int, int> p = que.front();
            que.pop();
            int x = p.first;
            int y = p.second;
            for (int i = 0; i < 2; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < m && 0 <= ny && ny < n && !vis[nx][ny] &&
                    check(nx, ny, k)) {
                    vis[nx][ny] = true;
                    ans++;
                    que.push({nx, ny});
                }
            }
        }
        return ans;
    }
};