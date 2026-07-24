void Dijkstra(int src){
    int dist[MAXV];
    int visited[MAXV];
    int path[MAXV];
    for (int i = 0; i < n; i++){
        dist[i] = G[src][i];
        visited[i] = 0;
        if (i != src && G[src][i] < INF) path[i] = src;
        else path[i] = -1;
    }
    dist[src] = 0;
    visited[src] = 1;
    for (int i = 1; i < n; i++){
        int min = INF;
        int u = -1;
        for (int j = 0; j < n; j++){
            if (!visited[j] && dist[j] < min){
                min = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++){
            if (!visited[v] && G[u][v] < INF && dist[u] + G[u][v] < dist[v]){
                dist[v] = dist[u] + G[u][v];
                path[v] = u;
            }
        }
    }
    printf("Dijkstra最短路径（起点：%s）\n", city[src]);
    for (int i = 0; i < n; i++)
    {
        if (i == src) continue;
        printf("\n%s -> %s\n", city[src], city[i]);
        if (dist[i] == INF){
            printf("无路径\n");
            continue;
        }
        printf("路径：");
        printDijkstraPath(path, i);
        printf("\n距离：%d\n", dist[i]);
    }
}