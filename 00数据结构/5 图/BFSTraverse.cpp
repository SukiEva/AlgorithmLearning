#include "Graph.h"
using namespace std;

bool vis[MaxVertexNum] = {false};

void bfs(MGraph* G, int v) {
    vis[v];
    cout << G->Vex[v] << " ";
    queue<int> Q;
    Q.push(v);
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        for (int i = 0; i < G->vexnum; i++) {
            if (G->Edge[v][i] != INF && !vis[i]) {
                cout << G->Vex[i] << " ";
                vis[i] = true;
                Q.push(i);
            }
        }
    }
}

void BFSTraverse(MGraph* G) {
    for (int i = 0; i < G->vexnum; i++) {
        // 对于非连通图，一次bfs会有遗漏，遍历一遍全部结点
        if (!vis[i]) bfs(G, i);
    }
}
