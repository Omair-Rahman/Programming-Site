
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
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include<assert.h>


#define pi 2*acos(0.0)
#define PS system("pause")
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
#define inf (1<<30)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
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
#define bit_cnt(x)   __builtin_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

using namespace std;
/*
    1.Create a struct type data and keep member u & w which will denote vertex and cost.
    Dont Forget to make a constructor and comp function.

    2.First take input as the condition says.In the BFS function the parameter is source
    and destination.Initialize d[] ara with large value in which all the distance will
    be stored.Initialize par[] ara with -1 which denote the parent of a vertex.

    3.Initialize priyority queue of struct type data. Make d[source]=0.push struct type
     constructor in queue with source and 0.
*/


typedef vector<int> vi;

const int M=100005,MAX=56789876;

vi node[M],cost[M];
int par[M],d[M];

struct vt
{
    int u,w;
    vt(int x,int y)
    {
        u=x;
        w=y;
    }
    bool operator<(const vt&p)const
    {
        return w>p.w;
    }
};

int bfs(int s,int des)
{
    Mems(par,-1);
    Mems(d,MAX);
    priority_queue<vt> q;

    q.push(vt(s,0));
    d[s]=0;
    par[s]=-1;
    while(!q.empty())
    {
        vt top=q.top();
        q.pop();
        int u,v,vcost;
        u=top.u;

        if(u==des)
            return d[u];

        for(int i=0; i<node[u].size(); i++)
        {
            v=node[u][i];

            if(d[u]+cost[u][i]<d[v])
            {
                d[v]=d[u]+cost[u][i];
                par[v]=u;
                q.push(vt(v,d[v]));
            }
        }
    }
    return -1;
}

void print_path(int des)
{
    if(par[des]==-1)
    {
        cout<<des<<' ';
        return;
    }
    print_path(par[des]);
    cout<<des<<' ';
}

void input()
{
    int a,b,n,m,c;
    s(n);
    s(m);
    for(int i=0; i<m; i++)
    {
        s(a);
        s(b);
        s(c);
        node[a].pb(b);
        node[b].pb(a);
        cost[a].pb(c);
        cost[b].pb(c);
    }

}

int main()
{
    int s,des;

    input();

    cout<<"give start and destination"<<endl;
    s(s);
    s(des);

    int x=bfs(s,des);
    if(x==-1)
        cout<<-1<<endl;
    else
    {
        cout<<"result "<<x<<endl;
        print_path(des);
    }

    return 0;
}



