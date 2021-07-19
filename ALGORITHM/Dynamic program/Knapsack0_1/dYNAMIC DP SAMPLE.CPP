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
#include <cstring>
#include <cmath>
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
#define sqr(x) ( (x)* (x) )
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define MAX 1001
#define len 2601

using namespace std;


//SAMPLE INPUT:
//5 10   TOTAL ITEM & SIZE_OF_KNAPSACK

//7 400
//1 120
//4 280
//3 150
//4 200

//ANS 600 >>> ITEM 2,3,5

int cost[10],wit[10],DP[10][10];
int n,cap,dir[10][10];
int knap(int i,int w)
{
    int p1=0,p2=0;
    if(i==n+1)
        return 0;
    if(DP[i][w]!=-1)
        return DP[i][w];
    if(w+wit[i]<=cap)
        p1=cost[i]+knap(i+1,w+wit[i]);
    p2=knap(i+1,w);
    if(p1>p2)
    {
        dir[i][w]=1;
        return DP[i][w]=p1;
    }
    else
    {
        dir[i][w]=2;
        return DP[i][w]=p2;
    }
}
void print_item(int i,int w)
{
    if(dir[i][w]==-1)
        return;
    if(dir[i][w]==1)
    {
        cout<<i<<endl;
        print_item(i+1,w+wit[i]);
    }
    else if(dir[i][w]==2)
        print_item(i+1,w);
}

int main()
{
    memset(dir,-1,sizeof(dir));

    int i,j;
     memset(DP,-1,sizeof(DP));
    cin>>n>>cap;
    for(int i=1;i<=n;i++)
    {
        s(wit[i]);
        s(cost[i]);
    }
    cout<<knap(1,0)<<endl;
    print_item(1,0);

}


