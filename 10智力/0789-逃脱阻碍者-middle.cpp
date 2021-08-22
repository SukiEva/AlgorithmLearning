// https://leetcode-cn.com/problems/escape-the-ghosts/
/*
设玩家起点、阻碍者起点、终点分别为 ss、ee 和 tt，
计算两点距离的函数为 dist(x,y)dist(x,y)。

假设玩家从 ss 到 tt 的路径中会经过点 kk，当且仅当
dist(e, k) <= dist(s,k)
即「阻碍者起点与点 k 的距离」小于等于「玩家起点与点 k的距离」时，
阻碍者可以在点 k 抓到玩家。

由于「玩家到终点」以及「阻碍者到终点」的路径存在公共部分
dist(k,t)dist(k,t)，可推导出：

dist(e, k) + dist(k, t) <= dist(s, k) + dist(k, t)
dist(e,k)+dist(k,t)<=dist(s,k)+dist(k,t)

即得证 如果一个阻碍者能够抓到玩家，那么该阻碍者必然不会比玩家更晚到达终点。
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = ManhattanDistance(0, 0, target[0], target[1]);
        for (auto ghost : ghosts) {
            if (ManhattanDistance(ghost[0], ghost[1], target[0], target[1]) <=
                dist)
                return false;
        }
        return true;
    }
    int ManhattanDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};