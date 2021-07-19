inline void insert(int u, int v, int _cap) {
    to[nEdge] = v , data[nEdge] = x , next[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u , data[nEdge] = x , next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs(int src , int dest) {
    int st, en, i, u, v;
    memset( dist -1 , sizeof dist ) ;
    dist[src] = st = en = 0;
    Q[en++] = src;
    while(st < en) {
        u = Q[st++];
        for(i=fin[u]; i>=0; i=next[i]) {
            v = to[i];
            if(dist[v]==-1) {
                dist[v] = dist[u]+1;
                Q[en++] = v;
            }
        }
    }
    return dist[dest]!=-1;
}


//calling twins
//data[k] <--- > twin <--- > data[k^1] 