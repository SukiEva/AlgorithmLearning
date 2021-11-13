#include <iostream>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn = 1e4;
int cost[maxn][maxn];

// 连通图才能用
int prim(int n) {
    vector<int> mincost(n + 1, INF);
    vector<int> vis(n + 1, 0);
    mincost[0] = 0;
    int ans = 0;
    while (1) {
        int v = -1;  // 访问的结点下标
        for (int i = 0; i < n; i++)
            if (!vis[i] && (v == -1 || mincost[i] < mincost[v])) v = i;
        if (v == -1) break;
        vis[v] = 1;
        ans += mincost[v];
        for (int i = 0; i < n; i++) mincost[i] = min(mincost[i], cost[v][i]);
    }
    return ans;
}
