/*
 * @Author: SukiEva
 * @Date: 2021-08-17 14:09:03
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct cmp {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            return a[2] > b[2];
        }
    };

   public:
    int minimumCost(int n, vector<vector<int>> &connections) {
        vector<vector<pair<int, int>>> edge(n + 1);  // u, (v, w)
        for (auto i : connections) {
            edge[i[0]].push_back(pair(i[1], i[2]));
            edge[i[1]].push_back(pair(i[0], i[2]));
        }
        if (edge[1].size() == 0) return -1;
        priority_queue<vector<int>, vector<vector<int>>, cmp> heap;
        vector<int> vis(n + 1, 0);
        int ans = 0, cnt = 1;
        vis[1] = 1;
        for (int i = 0; i < edge[1].size(); i++)
            heap.push(vector<int>{1, edge[1][i].first, edge[1][i].second});
        while (!heap.empty()) {
            vector<int> t = heap.top();
            heap.pop();
            if (!vis[t[1]]) {
                vis[t[1]] = 1;
                ans += t[2];
                for (auto i : edge[t[1]])
                    heap.push(vector<int>{t[1], i.first, i.second});
                cnt++;
                if (cnt == n) return ans;
            }
        }

        return -1;
    }
};
