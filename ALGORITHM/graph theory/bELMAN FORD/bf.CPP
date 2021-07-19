/* Problem Name: 1225 - Digit Counting
       Platform: UVA
     Algorithom: Math Simulation
   Coder's Name: Rc Tushar
*/


#include<bits/stdc++.h>

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
#define makeint(n,s)  istringstream(s)>>n
#define BOUNDARY(i,j,Row,Col) ((i >= 1 && i <=Row) && (j >= 1 && j <=Col))
#define M  1002
using namespace std;

#ifdef DEBUG
#define debug(args...)            {dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

//int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1};                       //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;


//~~~~~~~~~~~~~~~~~CODE STARTING POINT~~~~~~~~~~~~~~~~~~~~~~



#define MAXE 10000
#define MAXN 100
int main()
{
    int node,edge;
    int d[MAXN],edge_u[MAXE],edge_v[MAXE],edge_cost[MAXE];
    cin>>node>>edge;

    for(int i=1; i<=node; i++)
        d[i]=1000000000;
    d[1]=0; //distance to source is 0

    for(int i=1; i<=edge; i++)
        cin>>edge_u[i]>>edge_v[i]>>edge_cost[i];

    int neg_cycle=false;
    for(int step=1; step<=node; step++)
    {
        int updated=false;
        for(int i=1; i<=edge; i++)
        {
            int u=edge_u[i],v=edge_v[i];
            if(d[u]+edge_cost[i]<d[v])
            {
                updated=true;
                if(step==node)neg_cycle=true; //If we can update in n'th step, there is a negative cycle
                d[v]=d[u]+edge_cost[i];
            }
        }
        if(updated==false)break; //If we can't update in a any step, no need to try anymore
    }

    if(neg_cycle==false)
        for(int i=1; i<=node; i++)cout<<d[i]<<endl;
    else puts("Negative cycle detected");

    return 0;
}



