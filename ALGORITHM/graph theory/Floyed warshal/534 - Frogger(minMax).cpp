

/* Problem Name: 534 - Frogger
       Platform: UVA
     Algorithom: Floyed Warshal MinMax
   Coder's Name: RC Tushar
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
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define M  202
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;
typedef pair<int,int> pii;

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

//~~~~~~~~~~~~~~~~~CODE STARTING POINT~~~~~~~~~~~~~~~~~~~~~~

inline double dist(int x,int y,int x1,int y1)
{
return sqrt(sqr(x-x1)+sqr(y-y1));
}

double ara[M][M];
int a[M],b[M];
int main()
{

int test;
while(s(test)==1)
{
    for(int i=0;i<test;i++)
        for(int j=0;j<test;j++)
       {
           if(i==j)
            ara[i][j]=0;
           else
            ara[i][j]=inf;
       }
for(int i=0;i<test;i++)
   cin>>a[i]>>b[i];

for(int i=0;i<test-1;i++)
    for(int j=i+1;j<test;j++)
    {
        ara[i][j]=dist(a[i],b[i],a[j],b[j]);
        ara[j][i]=ara[i][j];    // Keep Eye on this
    }

loop(k,0,test)
loop(i,0,test)
loop(j,0,test)
ara[i][j]=min(ara[i][j],max(ara[i][k],ara[k][j])); // This is used for MinMax

pf("%.3f\n",ara[0][1]);
}
return 0;
}



