void Floyd(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            distF[i][j] = G[i][j];
            if (i != j && G[i][j] < INF)
                pathF[i][j] = i;
            else pathF[i][j] = -1;
        }
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (distF[i][k] < INF && distF[k][j] < INF && distF[i][k] + distF[k][j] < distF[i][j]){
                    distF[i][j] = distF[i][k] + distF[k][j];
                    pathF[i][j] = pathF[k][j];
                }
            }
        }
    }
}