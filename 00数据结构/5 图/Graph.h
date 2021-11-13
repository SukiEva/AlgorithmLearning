#ifndef GRAPH_HEADER_FILE
#define GRAPH_HEADER_FILE

#include <iostream>
#include <queue>
#define MaxVertexNum 100  // 顶点最大数量
#define INF 0x3f3f3f3f
typedef char VertexType;  // 顶点数据类型
typedef int EdgeType;     //  带权图权值类型

// - 邻接矩阵
struct MGraph {
    VertexType Vex[MaxVertexNum];               // 顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  // 邻接矩阵，边表
    int vexnum, arcnum;                         // 图当前顶点数和边数
};

// ! 以下为邻接矩阵 
// - 边表结点
struct ArcNode {
    int adjvex;     // 邻接顶点下标
    ArcNode* next;  // 下一条边
    // EdgeType info; // 边权值
};
// - 顶点表结点
struct VNode {
    VertexType data;  // 顶点信息
    ArcNode* first;   // 边表头指针
};
// - 邻接表
struct ALGrapg {
    VNode vertices[MaxVertexNum];  // 顶点表，一维数组
    int vexnum, arcnum;            // 顶点数和边数
};

#endif