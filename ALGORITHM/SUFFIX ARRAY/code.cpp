/*

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: Tutorial
       Platform: https://tanvir002700.wordpress.com/2015/01/13/suffix-array/
      Algorithm: Suffix array & longest common prefix
  Author's Name: RC Tushar

----------------------------------------------------
let the light of the Shelley moon die tonight
let the sky cover herself with dark shroud, tonight
but not the hope that promised to live
Just say her, dear, don't sleep tonight
die another day, die another night
----------------------------------------------------

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
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define sz(x) ((int)x.size())
#define eps 1e-15
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define inf (1<<29)
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define bit_cnt(x)   __builtin_popcount(x)
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())

using namespace std;

int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};                        //4 Direction
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
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef pair< int, pii> ipii;
typedef pair< int, string> pis;
typedef pair< string,int> psi;

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


ll sat(ll n,ll pos)
{
    return n=n | (1LL<<pos);
}
ll reset(ll N,ll pos)
{
    return N= N & ~(1LL<<pos);
}
bool cak(ll n,ll pos)
{
    return (bool)(n&(1LL<<pos));
}

ll binPow(ll a, ll q, ll mud)
{
    a %= mud;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, mud)) % mud;
}

pll ex_clid(ll a,ll b)
{
    if(b==0)
        return pll(1,0);
    pll d=ex_clid(b,a%b);
    return pll(d.S,d.F-d.S*(a/b));
}

ll mod_inv(ll n,ll md)
{
    pll d=ex_clid(n,md);
    return ((d.F%md)+md)%md;
}


template<class T>
double dif(T &a,T& b)
{
    double ans=(a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
    return sqrt(ans);
}

#define M    100000
#define mod  1000000007
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))

// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct st
{
    int idx;
    int f,s;

    bool operator <(const st &op)const
    {
        if(op.f==f)
            return s<op.s;
        return f<op.f;
    }
}ara[M+5];

int rnk[15][M+4];
string str;

pii ans[M+4];
int LCP[M+5];

// longest common prefix builder O(nlogn)
void build_LCP_array(int step)
{
    LCP[0] = 0;
    int n = str.size(), i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = ara[i - 1].idx;
        id2 = ara[i].idx;
        LCP[i] = 0;
        for(j = step - 1; j >= 0&&id1<n&&id2<n; j--)
            if(rnk[j][id1] == rnk[j][id2] )
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
    }
}

vector<int> kasai(string s, vector<int> sa)  // LCP builder O(n)
{
    int n=s.size(),k=0;
    vector<int> lcp(n,0);
    vector<int> pos(n,0);

    for(int i=0; i<n; i++)
        pos[sa[i]]=i;

    for(int i=0; i<n; i++, k?k--:0)
    {
        if(pos[i]==n-1) {k=0; continue;}
        int j=sa[pos[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[pos[i]]=k;
    }
    return lcp;
}

int main()
{
    int n,m;

    cin>>str;
    n=str.size();

    for(int i=0;i<n;i++)   // initializing rank by first character
        rnk[0][i]=str[i];

    int jump,i;
    for(i=1,jump=1;jump<=n;i++,jump*=2) // jump will occur by 1,2,4,8... steps
    {
        for(int j=0;j<n;j++)           // j is starting of every suffix
        {
            ara[j].idx=j;              // assigning new current id position
            ara[j].f=rnk[i-1][j];      // first element will be jth suffix's rank in previous step
            ara[j].s=j+jump<n?rnk[i-1][j+jump]:-1;  // second element will be (j+jump)th rank suffix's rank in previous step
        }

        sort(ara,ara+n);      //sorting based on two elements

        rnk[i][ara[0].idx]=0;
        for(int j=1;j<n;j++)           // assigning rank after sorting. If value of current pair is equal to value of previous pair then assign
            if(ara[j-1].f==ara[j].f&&ara[j-1].s==ara[j].s)   // same rank, otherwise new rank
                rnk[i][ara[j].idx]=rnk[i][ara[j-1].idx];
            else
                rnk[i][ara[j].idx]=j;
    }

    // printing final sorted suffix
    int tot=i-1;

    for(int i=0;i<n;i++)
    {
        ans[i].F=rnk[tot][i];
        ans[i].S=i;
    }

    sort(ans,ans+n);
    for(int i=0;i<n;i++)
    {
        for(int j=ans[i].S;j<n;j++)
            cout<<str[j];
        cout<<endl;
    }
    cout<<endl;

     //Building Longest common prefix O(nlogn)

    build_LCP_array(tot+1);

    for(int i=0;i<n;i++)
        cout<<i<<' '<<LCP[i]<<endl;

    cout<<endl;
    //Building Longest common prefix O(n) kasai algorithm

    vi mara;
    for(int i=0;i<n;i++)
        mara.pb(ara[i].idx);

    mara=kasai(str,mara);

    for(int i=0;i<n;i++)
        cout<<i<<' '<<mara[i]<<endl;

    return 0;
}

