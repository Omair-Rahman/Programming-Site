/*
G[] is the left-side graph, must be bipartite
match(n): n is the number of nodes in left-side set
and returns the maximum possible matching.
Left[] and Right[] are assigned with corresponding matches
*/

vector < int > G[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];

bool dfs(int u) {
    if(visited[u]) return false;
    visited[u] = true;
    int len = G[u].size(), i, v;
    for(i=0; i<len; i++) {
        v = G[u][i];
        if(Right[v]==-1) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++) {
        v = G[u][i];
        if(dfs(Right[v])) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int match(int n) {
    int i, ret = 0;
    bool done;
    SET(Left); SET(Right);
    do {
        done = true; CLR(visited);
        for(i=0; i<n; i++) {
            if(Left[i]==-1 && dfs(i)) {
                done = false;
            }
        }
    } while(!done);
    for(i=0; i<n; i++) ret += (Left[i]!=-1);
    return ret;
}
