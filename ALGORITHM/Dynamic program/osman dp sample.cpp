/*
 Problem name : ROCK - Sweet and Sour Rock
 Algorithm : DP
 Contest/Practice : Off Line Practice
 Source : Spoj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 22-Jul-15
 Last Update : 25-Mar-2015
*/

/*
        "à¦¬à§à¦à¦à§ à¦à¦à¦¿ à¦à¦ à¦¤à§ à¦à¦¨à¦¨à§à¦¦"
                                ____ à¦®à¦¹à¦¾à¦¦à§à¦¬ à¦¸à¦¾à¦¹à¦¾
        à¦¬à§à¦à¦à§ à¦à¦à¦¿ à¦à¦ à¦¤à§ à¦à¦¨à¦¨à§à¦¦, à¦à¦ à¦à¦¨à¦¨à§à¦¦à§à¦° à¦à¦¨à§à¦¯ à¦à¦®à¦¿
        à¦¸à¦¬à¦à¦¿à¦à§ à¦®à¦¾à¦¥à¦¾ à¦ªà§à¦¤à§ à¦¨à§à¦¬à§,
        à¦¯à§ à¦à§à¦¨à§ à¦¦à§à¦à¦, à¦¯à§ à¦à§à¦¨à§ à¦¶à¦¾à¦¸à§à¦¤à¦¿-
        à¦¶à§à¦§à§ à¦à¦ à¦­à§à¦°à§à¦° à¦à¦à¦à§ à¦à¦²à§ à¦¦à§à¦¯à¦¾à¦à¦¾à¦° à¦à¦¨à§à¦¯
        à¦à¦®à¦¿ à¦ªà¦¥à§à¦° à¦­à¦¿à¦à§à¦·à§à¦ à¦¹à¦¤à§ à¦°à¦¾à¦à¦¿
        à¦à¦ à¦¯à§ à¦à§à¦²à¦¾à¦ª à¦«à§à¦²à¦à¦¿à¦° à¦¦à¦¿à¦à§ à¦¯à¦¤à§à¦à§à¦·à¦£ à¦à§à¦¶à¦¿
        à¦¤à¦¾à¦à¦¿à§à§ à¦¥à¦¾à¦à¦¤à§ à¦ªà¦¾à¦°à¦¿
        à¦à¦ à¦¸à§à¦à§ à¦à¦®à¦¿ à¦¹à¦¾à¦¸à¦¿à¦®à§à¦à§ à¦¸à¦¬ à¦¦à§à¦à¦-
        à¦®à¦¾à¦¥à¦¾ à¦ªà§à¦¤à§ à¦¨à§à¦¬à§à¥¤
        à¦¬à§à¦à¦à§ à¦à¦à¦¿ à¦à¦ à¦¤à§ à¦à¦¨à¦¨à§à¦¦, à¦à¦ à¦à¦¨à¦¨à§à¦¦à§à¦° à¦à¦¾à¦à§
        à¦à§à¦¨à§ à¦¦à§à¦à¦à¦ à¦à¦¿à¦à§ à¦¨à§
        à¦à¦ à¦¨à¦¿à¦°à§à¦¬à¦¾à¦¸à¦¨, à¦à¦ à¦¶à¦¾à¦¸à§à¦¤à¦¿, à¦à¦ à¦¦à§à¦¬à§à¦ªà¦¾à¦¨à§à¦¤à¦°;
        à¦à¦ à¦®à§à¦, à¦à¦ à¦à§à¦® à¦¬à§à¦·à§à¦à¦¿, à¦à¦ à¦¶à¦¿à¦¶à¦¿à¦°à§à¦° à¦¶à¦¬à§à¦¦à§à¦° à¦à¦¨à§à¦¯
        à¦à¦®à¦¿ à¦¸à¦¹à¦¸à§à¦° à¦¬à¦à¦°à§à¦° à¦à¦¾à¦°à¦¾à¦¦à¦¨à§à¦¡- à¦®à¦¾à¦¥à¦¾à§ à¦¨à¦¿à§à§à¦ à¦¬à§à¦à¦à§ à¦¥à¦¾à¦à¦¤à§ à¦à¦¾à¦,
        à¦¬à§à¦à¦à§ à¦à¦à¦¿ à¦à¦ à¦¤à§ à¦à¦¨à¦¨à§à¦¦, à¦à¦ à¦à¦¨à¦¨à§à¦¦à§ à¦¸à¦¬
        à¦à¦à¦¾à¦¤ à¦à¦®à¦¿ à¦®à¦¾à¦¥à¦¾ à¦ªà§à¦¤à§ à¦¨à§à¦¬à§à¥¤
*/



#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000000007
#define inf             1<<30
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define F               first
#define S               second
#define sz(x)           ((int)x.size())
#define sqr(x)          ( (x)* (x) )
#define eps             1e-9
#define lcm(x,y)        (abs(x) /gcd(x,y))* abs(y)
#define on(x,w)         x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define sf              scanf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";

typedef long long ll;
typedef unsigned long long llu;

using namespace std;


template<class T>
inline T mod_v(T num)
{
    if(num>=0)
        return num%mod;
    else
        return (num%mod+mod)%mod;
}
template<class T>
inline T gcd(T a,T b)
{
    a=abs(a);
    b=abs(b);

    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

template<class T>
T fast_pow(T n , T p)
{
    if(p==0) return 1;
    if(p%2)
    {
        T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        T g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}

template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,mod-2);
}

template<class T>
inline void debug(string S1,T S2,string S3)
{
    cout<<S1<<S2<<S3;
}

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}


template<class T>
inline int in(register T& num)
{
    register char c=0;
    num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    num=n?-num:num;
    return 1;
}

/******* ! Code start from here ! *******/

int dp[201][201][201];
int done[201][201][201]={0},cc=1;
char s[201];
int ln;

int re(int i,int z,int o)
{
    if(i==ln) return (o>z)*(o+z);

    if(done[i][z][o]==cc ) return dp[i][z][o];

    done[i][z][o]=cc;
    int &r=dp[i][z][o];
    r=0;

    r=max(r,re(i+1,z+(s[i]=='0'),o+(s[i]=='1')  ) );
    r=max(r,(o>z)*(o+z) +re(i+1,(s[i]=='0'),(s[i]=='1')  ) );

    return r;
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif


    int t;

    in(t);

    while(t--)
    {
        in(ln);
        sf("%s",s);

        pf("%d\n",re(0,0,0) );

        cc++;
    }

    return 0;
}
