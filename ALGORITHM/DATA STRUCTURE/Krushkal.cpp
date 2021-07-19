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

using namespace std;
int par[100];
struct edge
{
    int u,v,w;
    bool operator < (const edge &p)const
    {
        return w<p.w;
    }
};

vector<edge>e;
int REP(int n)
{
    return(par[n]==n)?n:par[n]=REP(par[n]);
}

int MST(int n)
{
    int u,v,cnt,sum;
    sort(all(e));
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
    }
    cnt=0,sum=0;
    int len=e.size();
    for(int i=0;i<len;i++)
    {
        u=REP(e[i].u);
        v=REP(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            cnt++;
            sum+=e[i].w;
            if(cnt==n-1)
                break;
        }
    }
    return sum;
}

int main()
{


    edge get;
    int n,i,ED;
    s(n);
    s(ED);

    loop(i,0,ED)
    {
        s(get.u);
        s(get.v);
        s(get.w);
        e.push_back(get);
    }

    cout<<MST(n)<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<REP(i)<<endl;
    }
    return 0;
}



