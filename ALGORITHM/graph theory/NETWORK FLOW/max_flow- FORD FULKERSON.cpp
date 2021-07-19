/*
   ALGORITHM OF MAX FLOW FORD-FULKARSON MATHOD:

   1. TAKE INPUT IN 2D GRAPH

   2. MAKE A FUNCTION OF FORD-FULKERSON WITH ARGUMENT S (SOURCE) AND T (DESTINATION)

   3. INITIALIZE PARENT

   4. RUN A LOOP OF BOOLIAN BFS FROM SOURCE TO DESTINATION WITH PARENT AND *GRAPH.
      IT WILL FIND THE AUGMENT PATH,SET THE MINIMUM PATH_FLOW AND PARENT OR RETURN FALSE
      IF NO AUGMENT PATH FOUND.

   5. IF RETUNR TRUE THEN THE VALUE OF PATH_FLOW WILL MINUS FROM ORIGINAL RISIDUAL
      GRAPH AND ADD TO THE REVERSE RISIDUAL GRAPH

   6. FINALLY PATH_FLOW WILL BE ADDED TO THE MAX_FLOW.
*/


#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

// SOURCE: http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/

// Number of vertices in given graph
#define V 6

int path_flow;
bool bfs(int graph[V][V], int s, int t, int *parent)
{
    bool visited[V];
    memset(visited, false, sizeof(visited));
    path_flow = INT_MAX;
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u==t)
            return true;
        for (int v=0; v<V; v++)
        {
            if (!visited[v] && graph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                path_flow = min(path_flow, graph[u][v]);
            }
        }
    }
  return false;
}

int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
    int parent[V];
    int max_flow = 0;

    while (bfs(graph, s, t, parent))
    {
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);

    return 0;
}
