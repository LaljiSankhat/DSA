int vis[v] = {0};
    int pathVisited[v] = {0};
    vector<int> safeNodes;
    int check[v] = {0};
    
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, adj, vis, pathVisited, check);
        }
    }

    for(int i = 0; i < v; i++){
        if(check[i] == 1){
            safeNodes.push_back(v);
        }
    }

    return safeNodes;