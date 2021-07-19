/*

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: Gotham PD
       Platform: Codechef (https://www.codechef.com/MAY17/problems/GPD)
      Algorithm: Persistent data structure idea of trie
  Author's Name: RC Tushar

       resource:
       https://blog.anudeep2011.com/persistent-segment-trees-explained-with-spoj-problems/
       http://www.geeksforgeeks.org/persistent-data-structures/


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

#define M    200000
#define mod  1000000007
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))

// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


ll n,r,q,key;
map<ll,ll> id;

struct node
{
    node * next[2];
    node()
    {
        next[0]=next[1]=NULL;
    }
}*mara[M+5];


void init(node * root,ll num)
{
    node * cur=root;
    int pt;
    for(int i=36; i>=0; i--)
    {
        pt=cak(num,i);
        if(cur->next[pt]==NULL)
            cur->next[pt]=new node();
        cur=cur->next[pt];
    }
}

void in(node * root,node * boot ,ll num)
{
    node * cur=root;
    node * bur=boot;

    bool flag=true;
    int pt;
    for(int i=36; i>=0; i--)
    {
        pt=cak(num,i);
        if(cur->next[pt]==NULL)
            cur->next[pt]=new node();

        if(flag&&bur->next[pt^1]!=NULL)
        cur->next[pt^1]=bur->next[pt^1];

        if(bur->next[pt]==NULL||flag==false)
            flag=false;
        else
            bur=bur->next[pt];

        cur=cur->next[pt];
    }
}

//bool khujo(node * root,ll num)
//{
//	node *cur=root;
//
//	int pt;
//	ll sum=0;
//	for(int i=36; i>=0; i--)
//	{
//		pt=cak(num,i);
//		if(cur->next[pt]==NULL)
//            return false;
//        if(pt)
//        sum=sat(sum,i);
//		cur=cur->next[pt];
//	}
//	return sum==num;
//}

int mx_qury(node * root,int num)
{
    node * cur=root;
    int pt;
    int sum=0;
    for(int i=36; i>=0; i--)
    {
        pt=cak(num,i);
        if(cur->next[pt^1]!=NULL)
        {
            sum=sat(sum,i);
            cur=cur->next[pt^1];
        }
        else
            cur=cur->next[pt];
    }
    return sum;
}

int mn_qury(node * root,int num)
{
    node * cur=root;
    int pt;
    int sum=0;
    for(int i=36; i>=0; i--)
    {
        pt=cak(num,i);
        if(cur->next[pt]!=NULL)
            cur=cur->next[pt];
        else
        {
            sum=sat(sum,i);
            cur=cur->next[pt^1];
        }
    }
    return sum;
}


int main()
{

    ll i,t,u,v,k,cnt=1;

    cin >> n >> q;
    cin >> r >> key;


    id[r]=cnt++;
    mara[id[r]]=new node();
    init(mara[id[r]],key);

    for (i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> k;

        if(!id[u])
            {
                id[u]=cnt++;
                mara[id[u]]=new node();
            }
        if(!id[v])
            {
                id[v]=cnt++;
                mara[id[v]]=new node();
            }
        in(mara[id[u]],mara[id[v]],k);
    }

//     while(cin>>v>>k)
//        cout<<khujo(mara[id[v]],k)<<endl;

    int last_answer = 0;

    for (i = 0; i < q; i++)
    {
        fs(t);
        t ^= last_answer;

        if (t == 0)
        {
            fs(v);
            fs(u);
            fs(k);

            u ^= last_answer;
            v ^= last_answer;
            k ^= last_answer;

            if(!id[u])
            {
                id[u]=cnt++;
                mara[id[u]]=new node();
            }
            if(!id[v])
            {
                id[v]=cnt++;
                mara[id[v]]=new node();
            }
            in(mara[id[u]],mara[id[v]],k);
        }
        else
        {
            fs(v);
            fs(k);

            v ^= last_answer;
            k ^= last_answer;

            ll min_answer = mn_qury(mara[id[v]],k);
            ll max_answer = mx_qury(mara[id[v]],k);

            last_answer = min_answer ^ max_answer;
            printf("%lld %lld\n",min_answer,max_answer);
        }
    }
    return 0;
}







