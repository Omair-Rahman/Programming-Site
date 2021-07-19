/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
    Problem Name:
        Platform:
      Algorithom:
    Coder's Name: RC Tushar

~~~ Never Show Your Arrogance.Keep In Mind,You Were Born From A Drop Of Impure Liquid ~~~

*/

#include<bits/stdc++.h>
#define pi 2*acos(0.0)
#define PS system("pause")
#define siter(n,T1)  for(set<T1>::iterator it=n.begin();it!=n.end();it++)
#define miter(n,T1,T2)  for(map<T1,T2>::iterator it=n.begin();it!=n.end();it++)
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
#define M 100000
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("sum.in","r",stdin);
//freopen("sum.out","w",stdout);
typedef vector<int> vi;
typedef pair<int,int> pii;


//FAST_INPUT
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

// ~~~~~~~~~~~~~~~ CODE STARTING POINT ~~~~~~~~~~~~~~~~

ll tree[M*3],ara[M+2],add[M*3]={},mul[M*3],upd[M*3]={},cp,x;
int i,j;

void init(int nod,int b,int e)
{
    if(e==b)
    {
        tree[nod]=ara[b];
        return;
    }

    int mid=(b+e)/2;
    int left=nod*2;
    int right=left+1;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[nod]=(tree[left]+tree[right])%MOD;
    mul[nod]=1;
}


void update(int nod,int b,int e)
{
    if(i>e||j<b)
        return;
    if(b>=i&&e<=j)
    {
        if(cp==1)
        {
            tree[nod]=(tree[nod]+((e-b+1)*x)%MOD)%MOD;
            add[nod]=(add[nod]+x)%MOD;
        }
        else if(cp==2)
        {
            tree[nod]=((tree[nod]%MOD)*(x%MOD))%MOD;
            mul[nod]=((mul[nod]%MOD)*(x%MOD))%MOD;
            add[nod]=((add[nod]%MOD)*(x%MOD))%MOD;
        }
        else if(cp==3)
        {
            tree[nod]=((e-b+1)*(x%MOD))%MOD;
            upd[nod]=x;
            add[nod]=0;
            mul[nod]=1;
        }
        return;
    }

    int mid=(b+e)/2;
    int left=nod*2;
    int right=left+1;

    if(upd[nod])
    {
        tree[left]=((mid-b+1)*upd[nod])%MOD;
        tree[right]=((e-mid)*upd[nod])%MOD;
        upd[left]=upd[nod];
        upd[right]=upd[nod];
        add[left]=add[right]=0;
        mul[left]=mul[right]=1;
        upd[nod]=0;
    }
    if(mul[nod]!=1)
    {
        tree[left]=(tree[left]*mul[nod])%MOD;
        tree[right]=(tree[right]*mul[nod])%MOD;
        mul[left]=(mul[left]*mul[nod])%MOD;
        mul[right]=(mul[right]*mul[nod])%MOD;
        add[left]=(add[left]*mul[nod])%MOD;
        add[right]=(add[right]*mul[nod])%MOD;
        mul[nod]=1;
    }

    if(add[nod])
    {
        tree[left]= (tree[left]+((mid-b+1)*add[nod])%MOD)%MOD;
        tree[right]= (tree[right]+((e-mid)*add[nod])%MOD)%MOD;
        add[left]=(add[left]+add[nod])%MOD;
        add[right]=(add[right]+add[nod])%MOD;
        add[nod]=0;
    }

    update(left,b,mid);
    update(right,mid+1,e);

    tree[nod]=(tree[left]+tree[right])%MOD;
}


ll qury(int nod,int b,int e)
{
    if(i>e||j<b)
        return 0;
    if(b>=i&&e<=j)
        return tree[nod]%MOD;

    int mid=(b+e)/2;
    int left=nod*2;
    int right=left+1;

    if(upd[nod])
    {
        tree[left]=((mid-b+1)*upd[nod])%MOD;
        tree[right]=((e-mid)*upd[nod])%MOD;
        upd[left]=upd[nod];
        upd[right]=upd[nod];
        add[left]=add[right]=0;
        mul[left]=mul[right]=1;
        upd[nod]=0;
    }

    if(mul[nod]!=1)
    {
        tree[left]=(tree[left]*mul[nod])%MOD;
        tree[right]=(tree[right]*mul[nod])%MOD;
        mul[left]=(mul[left]*mul[nod])%MOD;
        mul[right]=(mul[right]*mul[nod])%MOD;
        add[left]=(add[left]*mul[nod])%MOD;
        add[right]=(add[right]*mul[nod])%MOD;
        mul[nod]=1;
    }

    if(add[nod])
    {
        tree[left]= (tree[left]+((mid-b+1)*add[nod])%MOD)%MOD;
        tree[right]= (tree[right]+((e-mid)*add[nod])%MOD)%MOD;
        add[left]=(add[left]+add[nod])%MOD;
        add[right]=(add[right]+add[nod])%MOD;
        add[nod]=0;
    }


    ll  p1=qury(left,b,mid);
    ll  p2=qury(right,mid+1,e);
    return (p1+p2)%MOD;
}

int main()
{
    ll n,q;
    fs(n);
    fs(q);

    loop(k,1,n+1)
    fs(ara[k]);

    init(1,1,n);

    loop(k,0,q)
    {
        fs(cp);
        fs(i);
        fs(j);

        switch(cp)
        {
        case 1:
            fs(x);
            update(1,1,n);
            break;
        case 2:
            fs(x);
            update(1,1,n);
            break;
        case 3:
            fs(x);
            update(1,1,n);
            break;
        case 4:
            pf("%lld\n",qury(1,1,n));
        }
    }

    return 0;
}
