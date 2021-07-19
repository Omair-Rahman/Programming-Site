#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include<assert.h>


#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define MOD 1000000007
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define bit_cnt(x)   __builtint_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#define M  20000
using namespace std;



/*KOSARAJU'S ALGO TO FIND STRONGLY CONNECTED COMPONENT

  SHORT EXPLAINATION: FIRST TAKE INPUT IN A AND B. THEN START A DFS1 FROM VERTEX 0.PUSH THE PATH IN A STACK. THEN TRANSPOSE THE GRAPH/ REVERSE ALL THE DIRECTION OF GRAPH.THEN START DFS2 FROM THE TOP VERTEX OF THE STACK.CHECK HOW MANY DFS2 DONE SUCCESFULLY AND SAVE THE SUCCESS NUMBER IN AN INCREMENTABLE VARIABLE.THIS VARIABLE DENOTES THE NUMBER OF SCC.

*/
vector<int> A[M],B[M],x,y; // A IS DIRECT GRAPH, B IS REVERSE GRAPH,X IS FINAL PATH
stack<int>st; // THE TOPOLOGICAL SORTED PATH AFTER FIRST DFS

bool mark[M];
bool visit[M];

void dfs1(int u)
{

    if(visit[u])
        return;
    visit[u]=true;
    for(int i=0;i<A[u].size();i++)
    {
        int v=A[u][i];
        dfs1(v);
    }
    st.push(u);
}

void dfs2(int u)
{

    if(visit[u])
        return;

    visit[u]=true;
    for(int i=0;i<B[u].size();i++)
    {
        int v=B[u][i];
        dfs2(v);
    }
    x.pb(u);
}

int main()
{

int a,b,n,m;
cin>>n>>m;

    for(int i=0;i<m;i++) // TAKING INPUT
    {
        s(a);
        s(b);
        A[a].push_back(b);
        B[b].push_back(a);
    }

    memset(visit,false,sizeof(visit)); // INITIALIZING VISIT MEMOTY AS 0
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)             // RUNNING DFS1 FROM VERTEX 0
            dfs1(i);
    }
    int u,ans=0;
    memset(visit,false,sizeof(visit)); //ANOTHER INITIALIZATION OF VISIT MEMORY AS 0

    while(!st.empty())
    {
        u=st.top();
        if(visit[u]==0)
           {
             y.pb(u);
             dfs2(u);            //RUNNING DFS2 FROM THE TOP VERTEX OF STACK
             ans++;
           }
        st.pop();
    }

     for(int i=0;i<y.size();i++)
        cout<<y[i]<<' ';
     cout<<endl;

     cout<<ans<<endl;

return 0;
}



