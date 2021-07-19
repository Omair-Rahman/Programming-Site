/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name:
       Platform: http://ami-alavola.rhcloud.com/?p=231
     Algorithom: RABINCARP ALGO FOR STRING MATCHING
  Author's Name: RC Tushar


                 শুনেছি তোমার ভীষণ রাগ ?
                              সে কি রাগ , নাকি
                                     মগজ কোণায়  পচন ধরা
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
#define M 200000
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
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


//~~~~~~~~~~~~CODE STARTING POINT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void make_hash(ll *ara,ll base,int len)
{
    ll p=1;
    for(int i=0; i<=len; i++)
    {
        ara[i]=p;
        p=(p*base)%MOD;
    }
}



int main()
{
    string str="dfsdbcdghdbcdgsdgbcdfg",vtr="bcd";

    int len=str.size()-1;
    int ben=vtr.size()-1;

    ll ara[len+3],mara[len+3],bash1=0,mash1=0,bash2=0,mash2=0,base1=999983,base2=1009;

    // USING DOUBLE HASH TO BE MORE CONFIRM
    make_hash(ara,base1,ben);
    make_hash(mara,base2,ben);


    //hash=(hash+s[i]*pow[len-i])%MOD;
    // h+=s[i]*p^(len-i)

    for(int i=0; vtr[i]; i++)
    {
        bash1=(bash1+vtr[i]*ara[ben-i])%MOD;
        mash1=(mash1+str[i]*ara[ben-i])%MOD;

        bash2=(bash2+vtr[i]*mara[ben-i])%MOD;
        mash2=(mash2+str[i]*mara[ben-i])%MOD;
    }

    // hash=(hash-s[i-len-1]*pow[len])%MOD  >> removing first element of pattern from main hash
    // hash=(hash+MOD)%MOD >> repairing negative mod value
    // hash=((hash*base)+s[i])%MOD  >> adding new element in hashing

    // TOTAL FORMULA-> h=(h-s[i-len-1]*p^len) * p+s[i];
    int cnt=0;
    if(mash1==bash1&&mash2==bash2)
        cnt++;

    for(int i=ben+1; str[i]; i++)
    {
        mash1=(mash1-str[i-ben-1]*ara[ben])%MOD;
        mash1=(mash1+MOD)%MOD;
        mash1=((mash1*base1)+str[i])%MOD;

        mash2=(mash2-str[i-ben-1]*mara[ben])%MOD;
        mash2=(mash2+MOD)%MOD;
        mash2=((mash2*base2)+str[i])%MOD;

        if(mash1==bash1&&mash2==bash2)
            cnt++;
//    cout<<mash1<<' '<<bash1<<' '<<mash2<<' '<<bash2<<endl;
//  PS;
    }

    cout<<cnt<<endl;

    return 0;
}


