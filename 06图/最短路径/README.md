# 最短路径

参考了这篇[最短路问题--最通俗易懂的讲解](https://blog.csdn.net/sugarbliss/article/details/86511043)和《挑战程序设计竞赛》

> **最短路径是指：**
> 如果从图中某一顶点（源点）到达另一顶点（终点）的路径可能不止一条，如何
> 找到一条路径使得沿此路径上各边的权值总和（称为路径长度）达到最小。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190116170219160.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3N1Z2FyYmxpc3M=,size_16,color_FFFFFF,t_70)
## 单源最短路问题
固定一个起点，求它到其他所有点的最短路的问题。
终点也固定的问题叫做两点间最短路问题，通常当做单源最短路求解。
### Dijkstra算法（边权值非负）
> 基于贪心策略的思想，算法是按路径长度从小到大的顺序一步一步并入来求取，用来解决单源点到其余顶点的最短路径问题。
> 时间复杂度O(N^2)，堆优化后时间复杂度O(nlogn)。

**即：从剩余路径中找最短的路径，然后更新最短路径。**
d[ i ] = min { d[ j ] + (j -> i 边权值) | e=(j,i)∈E}

**邻接矩阵形式，时间复杂度为O(V^2)** 

```cpp
#define INF 0x3f3f3f3f
const int maxn=1010;
int cost[maxn][maxn];
int d[maxn];  
bool vis[maxn];
int n;

void dijkstra(int s){
	fill(d,d+n,INF);
	fill(vis,vis+n,false);
	d[s]=0;
	while (1){
		int k=-1;
		for (int i=0; i<n; i++){
			if (!vis[i] && (k==-1 || d[i]<d[k]))
				k=i;
		}
		if (k==-1) break;
		vis[k]=true;
		for (int i=0; i<n; i++){
			d[i]=min(d[i],d[i]+cost[k][i]);
		}
	}
}
```
**优先队列优化，时间复杂度O(E*logV)**

```cpp
#define INF 0x3f3f3f3f
typedef pair<int, int> P; //first：最短距离 second：顶点编号
struct edge {
	int to,cost;
};

const int maxn=1010;
int n;
vector <edge> G[maxn];
int d[maxn];

void dijkstra(int s) {
	//堆按照first从小到大顺序取出值
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d,d+n,INF);
	d[s]=0;
	que.push(P(0, s));
	while (!que.empty()) {
		P p=que.top();
		que.pop();
		int v=p.second;
		if (d[v]<p.first) continue;
		for (int i=0; i<G[v].size(); i++) {
			edge e=G[v][i];
			if (d[e.to]>d[v]+e.cost) {
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

/*void addedge(int u,int v, int w) {
	G[u].push_back({v,w});
}*/ //这样写会warning，C++11可用

void addedge(int u,int v, int w){
	edge t;
	t.to=v;
	t.cost=w;
	G[u].push_back(t);
}
```


### Bellman-Ford算法（有负边）
**时间复杂度 O(VE)** 
```cpp
#define INF 0x3f3f3f3f
struct edge {
	int from,to,cost;
};

const int maxn=550;
vector <edge> E;
int d[maxn];
int n,m; //n：V个数 m：E个数=E.size()

bool bellman_ford(int s) {
	fill(d,d+n,INF);
	d[s]=0;
	for (int i=0; i<n; i++) {
		bool flag=false;
		for (int j=0; j<m; j++) {
			int u=E[j].from;
			int v=E[j].to;
			int cost=E[j].cost;
			if (d[v]>d[u]+cost) {
				d[v]=d[u]+cost;
				flag=true;
			}
		}
		if (!flag) return true; //没有负环回路
	}
	for (int j=0; j<m; j++) {
		if (d[E[j].to]>d[E[j].from]+E[j].cost)
			return false; //有负环回路
	}
	return true; //没有负环回路
}

void addedge(int u,int v, int w){
	edge t;
	t.from=u;
	t.to=v;
	t.cost=w;
	E.push_back(t);
}
```
### SPFA算法
Spfa就是使用队列或者栈的Bellman-Ford算法的优化版本
 **时间复杂度 O(kE)** 

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200219213444801.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70)

```cpp
#define INF 0x3f3f3f3f
const int maxn=1010;

struct edge {
	int to,cost;
};

vector <edge> E[maxn];
bool vis[maxn];
int cnt[maxn]; //每个点入队列次数
int d[maxn];
int n;

bool spfa(int s) {
	fill(vis,vis+n,false);
	fill(d,d+n,INF);
	vis[s]=true;
	d[s]=0;
	queue <int> que;
	while(!que.empty()) que.pop(); 
	que.push(s);
	memset(cnt,0,sizeof(cnt));
	cnt[s]=1;
	while (!que.empty()){
		int u=que.front();
		que.pop();
		vis[u]=false;
		for (int j=0; j<E[u].size(); j++){
			int v=E[u][j].to;
			if (d[v]>d[u]+E[u][j].cost){
				d[v]=d[u]+E[u][j].cost;
				if (!vis[v]){
					vis[v]=true;
					que.push(v);
					if (++cnt[v]>n) return false;
				}
			}
		}
	}
	return true;
}

void addedge(int u,int v, int w){
	edge t;
	t.to=v;
	t.cost=w;
	E[u].push_back(t);
}
```

## 多源最短路问题
求解所有两点间最短路的问题。
### Floyd-Warshall算法
**时间复杂度O(V^3)**

```cpp
const int maxn=300;
int d[maxn][maxn]; //i,j无边时，d[i][j]=INF  i=j时，d[i][j]=0 
int n;

void warshall_floyd(){
	for (int k=0; k<n; k++){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
}
```
