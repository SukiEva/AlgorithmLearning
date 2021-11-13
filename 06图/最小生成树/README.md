# 最小生成树

## 生成树

无向图的某个子图中任意两个顶点都能互相联通且是一棵树

> 一个连通图的生成树是指一个连通子图，它含有图中全部 n 个顶点，但只有足以构成一棵树的 n-1 条边。一颗有 n 个顶点的生成树有且仅有 n-1 条边，如果生成树中再添加一条边，则必定成环。

### BFS 生成树

连通图的 BFS 生成树：
n 个顶点，n-1 条边；

特点：

- 不存在回路；
- 少任何边都不连通；
- 加入原图的任何边，都会产生回路。

<table>
<tr>
<td>
<img src="https://img-blog.csdnimg.cn/20200513155222405.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70">
</td>
<td>
<img src="https://img-blog.csdnimg.cn/20200513155903296.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70">
</td>
</tr>
</table>

### DFS 生成树

连通图的 DFS 生成树：
n 个顶点，n-1 条边；

-- 特点：

- 不存在回路；
- 少任何边都不连通；
- 加入原图的任何边，
  都会产生回路。

<table>
<tr>
<td>
<img src="https://img-blog.csdnimg.cn/20200513155551401.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70">
</td>
<td>
<img src="https://img-blog.csdnimg.cn/20200513160009727.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70">
</td>
</tr>
</table>

## 最小生成树

边上权和最小的生成树

具体可以参考[这篇](https://blog.csdn.net/gettogetto/article/details/53216951?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

### Prim 算法

O(|V|²) => 适合边稠密的图

> 从任意一个顶点开始，每次选择一个与当前顶点集最近的一个顶点（边权最小），并将两顶点之间的边加入到树中。

<img src="https://img-blog.csdnimg.cn/20200513161324890.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="70%">

```cpp
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
```

### Kruskal 算法

O(|E|log|V|) => 适合顶点多边稀疏的图

> 按边权值顺序从小到大看一遍，如果不产生圈就把当前边加入生成树。

<img src="https://img-blog.csdnimg.cn/20200513161453854.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="70%">

```cpp
struct edge {
	int u,v;
	ll cost;
}es[maxn*maxn];
//edge path[maxn*maxn];
int par[maxn];
int ran[maxn];
int n;
int cnt=0;
//int num=0;
bool cmp(const edge& e1, const edge& e2){
	return e1.cost<e2.cost;
}

void init() {
	for (int i=0; i<=n; i++) {
		par[i]=i;
		ran[i]=0;
	}
}

int find(int root) {
	while (root!=par[root])
		root=par[root];
	return root;
}

void unite(int x, int y) {
	x=find(x);
	y=find(y);
	if (x==y) return;
	if (ran[x]<ran[y]) par[x]=y;
	else {
		par[y]=x;
		if (ran[x]==ran[y]) ran[x]++;
	}
}


bool same(int x, int y) {
	return find(x)==find(y);
}


ll kruskal() {
	sort(es,es+cnt,cmp);
	init();
	ll ans=0;
	for (int i=0; i<cnt; i++) {
		edge e=es[i];
		if (!same(e.u,e.v)) {
			unite(e.u,e.v);
			ans+=e.cost;
			//path[num].u=e.u;
			//path[num++].v=e.v; 可记录路径
		}
	}
	return ans;
}

void addedge(int i, int j, int w){
	if (w!=0) {
		es[cnt].u=i;
		es[cnt].v=j;
		es[cnt++].cost=w;
	}
}
```
