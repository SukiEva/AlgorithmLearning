#include "Graph.h"
using namespace std;

bool vis[MaxVertexNum] = {false};

void dfs(MGraph* G, int v) {
    cout << G->Vex[v] << " ";
    vis[v] = true;
    for (int i = 0; i < G->vexnum; i++) {
        if (G->Edge[v][i] != INF && !vis[i]) dfs(G, i);
    }
}

void DFSTraverse(MGraph* G) {
    for (int i = 0; i < G->vexnum; i++) {
        // 对于非连通图，一次dfs会有遗漏，遍历一遍全部结点
        if (!vis[i]) dfs(G, i);
    }
}