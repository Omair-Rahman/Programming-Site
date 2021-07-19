/*
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
#define blz(a)   __builtin_clz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define makeint(n,s)  istringstream(s)>>n
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define M 1000002
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;

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
//--------------------------------------------------------------------


int ara[]={89,3,45,67,4,6,78,98,7,9};
int pars[1000][10]; // ith index represents the node, jth index represent log power number on 2

void bosho(int n)      // Intializes the spars table
{
    loop(i,0,n)
    pars[i][0]=i;      // Initializes ith index

    for(int j=1;(1<<j)<=n;j++)          // loop will go 1,2,4,8 .. | 2^j <= N  |
        for(int i=0;i+(1<<j)-1<n;i++)   // loop will go with     | i+2^j-1 <N |

    if(ara[pars[i][j-1]]<ara[pars[i+(1<<(j-1))][j-1]])
        pars[i][j]=pars[i][j-1];     // Formula :  A[M[i][j-1]] <= A[M[i+2^(j-1)][j-1]]
    else
        pars[i][j]=pars[i+(1<<(j-1))][j-1];
}



int kuj(int i,int j)
{
    int k=log2(j-i+1);     // Log2(j-i+1)
//    cout<<k<<endl;
//    printf("pars[%d][%d] - pars[%d][%d]\n",i,k,j-(1<<k)+1,k);
//    cout<<pars[i][k]<<' '<<pars[j-(1<<k)+1][k]<<endl;
//    PS;

    if(ara[pars[i][k]]<=ara[pars[j-(1<<k)+1][k]])  // Formula: A[M[i][k]]<=A[M[j-2^k+1][k]]
        return pars[i][k];
    else
        return pars[j-(1<<k)+1][k];
}

int main()
{
    bosho(10);
    cout<<kuj(2,8)<<endl;
    return 0;
}
