#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4;

struct edge {
    int u, v;
    ll cost;
} es[maxn * maxn];
// edge path[maxn*maxn];
int par[maxn];
int ran[maxn];
int n;
int cnt = 0;
// int num=0;
bool cmp(const edge& e1, const edge& e2) { return e1.cost < e2.cost; }

void init() {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
        ran[i] = 0;
    }
}

int find(int root) {
    while (root != par[root]) root = par[root];
    return root;
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (ran[x] < ran[y])
        par[x] = y;
    else {
        par[y] = x;
        if (ran[x] == ran[y]) ran[x]++;
    }
}

bool same(int x, int y) { return find(x) == find(y); }

ll kruskal() {
    sort(es, es + cnt, cmp);
    init();
    ll ans = 0;
    for (int i = 0; i < cnt; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            ans += e.cost;
            // path[num].u=e.u;
            // path[num++].v=e.v; 可记录路径
        }
    }
    return ans;
}

void addedge(int i, int j, int w) {
    if (w != 0) {
        es[cnt].u = i;
        es[cnt].v = j;
        es[cnt++].cost = w;
    }
}