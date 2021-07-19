#include<bits/stdc++.h>
using namespace std ;

struct Node {
    int nd , w , idx ;
    Node() {}
    Node(int _nd , int _w , int _idx ) {
        nd = _nd ;
        w = _w ;
        idx = _idx ;
    }
};

char s[102][102] ;
vector<Node> G[20100] ;
int parent[20100] ;
int IDX[20100] ;

void insert( int u , int v , int w ) {
    G[u].push_back( Node( v , w , G[v].size() ) ) ;
    G[v].push_back( Node( u , 0 , G[u].size()-1 ) ) ;
}

int run(int source , int dest ) {

    memset(parent,-1,sizeof parent ) ;
    queue< pair<int,int> >Q;
    int mn = INT_MAX ;
    Q.push( {source,mn} ) ;

    while( !Q.empty() ) {
        pair<int,int> p = Q.front() ;
        Q.pop() ;
        int u = p.first ;
        int mn = p.second ;
        for(int i = 0 ; i < G[u].size() ; i++ ) {
            int v = G[u][i].nd ;
            if( parent[v] == -1 && G[u][i].w > 0 ) {
                parent[v] = u ;
                IDX[v] = i ;
                mn = min( mn , G[u][i].w ) ;
                if( v == dest )return mn  ;
                Q.push( {v,mn}) ;
            }
        }
    }
    return 0 ;
}



int main() {


    for( int i = dest ; i!=source ; i = parent[i] ) {
        G[parent[i]][IDX[i]].w // front edge
        G[i][ G[parent[i]][IDX[i]].idx ].w // back edge

    }

}