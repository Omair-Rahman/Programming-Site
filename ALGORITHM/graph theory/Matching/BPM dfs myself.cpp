
//
//MAKES THE MAXIMUM MATCH FROM A BIPERTITE GRAPH.
//HERE GRAPHS ARE IN TWO SET AND VISITING STARTS
//ASSUMING FROM LEFT SIDE.
//
//EVERYTIME WHEN IT FINDS AN UNIQUE MATCH,IT RETURNS TRUE.
//OTHERWISE IT TRIES TO CALL DFS(V) TO REPLACE THE PREVIOUS MATCH.
//



bool dfs2(int u)
{
    for(int i = 0; i < G3[u].size(); i++)
    {
        int v = G3[u][i];
        if(vis[v])
            continue;
        vis[v] = true;
        if(y[v] == -1 || dfs2(y[v]))
        {
            y[v] = u;
            return true;
        }
    }
    return false;
}
int match()
{
    int  years  =  0 ;
    memset(y, -1, sizeof(y));
    for(int i = 1; i <= scc_cnt; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs2(i))
            ++ years;
    }
    return years;
}
