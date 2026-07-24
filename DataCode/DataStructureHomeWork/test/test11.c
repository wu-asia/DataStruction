// 计算各顶点最早发生时间 ve
void CalcVE(GraphAdjList *G, int cntTopo){
    int i, u, v;
    EdgeNode *p;
    for (i = 0; i < G->n; i++) ve[i] = 0;
    // 按拓扑正序遍历
    for (i = 0; i < cntTopo; i++){
        u = topoSeq[i];
        p = G->vertex[u].firstedge;
        while (p != NULL){
            v = p->adjvex;
            if (ve[v] < ve[u] + p->weight) ve[v] = ve[u] + p->weight;
            p = p->nextedge;
        }
    }
}