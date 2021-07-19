

/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name:
       Platform:
     Algorithom:
  Author's Name: RC Tushar



                 শুনেছি তোমার ভীষণ রাগ ?
                              সে কি রাগ , নাকি
                                     মগজ কোণে পচন ধরা
                 পুরনো কোডের বাগ ?


 ~~~     Never Lost Hope     ~~~
*/
#include<bits/stdc++.h>
#define pi 2*acos(0.0)
#define PS system("pause")
#define siter(n,T1)  for(set<T1>::iterator it=n.begin();it!=n.end();it++)
#define miter(n,T1,T2)  for(map<T1,T2>::iterator it=n.begin();it!=n.end();it++)
#define meter(n,T1,T2)  for(map<T1,T2>::iterator it=n.end();it!=n.begin();it--)
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
#define inf (1<<30)
#define pb push_back
#define ppb pop_back
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
#define ull unsigned long long int
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
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())
#define M 100003
using namespace std;

//int dx[]= {1,0,-1,0};
//int dy[]= {0,1,0,-1};                        //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,bool> pib;
typedef pair<double,int> pdi;
typedef pair<int,char> pic;
typedef pair< int, pii> ipii;


//TEMPLATES
template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}


int st(int n,int pos)
{
    return n=n | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool ck(int n,int pos)
{
    return (bool)(n&(1<<pos));
}

ll binPow(ll a, ll q, ll mud)
{
    a %= mud;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, mud)) % mud;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int L[M+5]; //লেভেল
int sp[M+4][22]; //স্পার্স টেবিল
int par[M+4]; //প্যারেন্ট
vector<int>g[M+5];

void dfs(int from,int u,int dep)
{
    par[u]=from;             // u নোড এর প্যারেন্ট এসাইন হচ্ছে
    L[u]=dep;              //  u নোডের লেভেল আপডেট হচ্ছে
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

void init(int n)
{
    Mems(sp,-1);
    for(int i=0;i<=n;i++)
    sp[i][0]=par[i];
    for(int i=0;i<=n;i++)
        for(int j=1;(1<<j)<n;j++)   // jth parent of ith node
        {
            if(sp[i][j-1]!=-1)
            sp[i][j]=sp[sp[i][j-1]][j-1];  // p^x th par = par of p^(x-1)th par. EXMPL: 2^3 th parent= parent of 2^2 th parent
        }
}


int qury(int n,int a,int b)
{
    if(L[a]<L[b])
        swap(a,b);
    int lg=log2(L[a]);
    for(int i=lg;i>=0;i--)
        if(L[a]-(1<<i)>=L[b])
            a=sp[a][i];
    if(a==b)
        return a;
    for(int i=log2(L[a]);i>=0;i--)
        if(sp[a][i]!=-1&&sp[a][i]!=sp[b][i]){
            a=sp[a][i];
            b=sp[b][i];
        }
    return par[a];
}

int main()
{
    g[0].pb(1);
    g[0].pb(2);
    g[0].pb(3);
    g[0].pb(8);
    g[2].pb(4);
    g[4].pb(5);
    g[5].pb(7);
    g[5].pb(6);
    g[6].pb(10);
    g[10].pb(11);
    g[11].pb(12);

    dfs(0,0,0);  // dfs tree
    init(12);    // spars init
    cout<<qury(12,7,8)<<endl;
    return 0;
}
