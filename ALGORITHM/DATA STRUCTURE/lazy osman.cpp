 /*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
 Last Update : 25-Mar-2015
*/

/*
"
        আমি অনেক কষ্টে আছি
                                --- আবুল হাসান
        আমার এখন নিজের কাছে নিজের ছায়া খারাপ লাগে
        রাত্রিবেলা ট্রেনের বাঁশি শুনতে আমার খারাপ লাগে
        জামার বোতাম আটকাতে
        অমন কেন যত্ন করে লাগিয়ে দিতে?
        অমন কেন শরীর থেকে
        আস্তে আমার ক্লান্তিগুলো উঠিয়ে নিতে?
        তোমার বুকের নিশিথ কুসুম
        আমার মুখে ছড়িয়ে দিতে?
        জুতোর ফিতে প্রজাপতির মতন তুমি উড়িয়ে নিতে?
        বেলজিয়ামের আয়নাখানি কেন তুমি ঘরে না রেখে
        অমন কারুকাজের সাথে তোমার দুটি চোখের মধ্যে রেখে দিতে?
        রেখে দিতে?
        আমার এখন চাঁদ দেখতে খারাপ লাগে
        পাখির জুলুম, মেঘের জুলুম, খারাপ লাগে
        কথাবার্তায় দয়ালু আর পোশাকে বেশ ভদ্র মানুষ
        খারাপ লাগে,
        এই যে মানুষ মুখে একটা মনে একটা
        খারাপ লাগে
        খারাপ লাগে
        মোটের উপর আমি এখন কষ্টে আছি,
        কষ্টে আছি বুঝলে যুথী
        আমার দাঁতে আমার নাকে, আমার চোখে কষ্ট ভীষণ
        চতুর্দিকে দাবী আদায় করার
        মতো মিছিল তাদের কষ্ট ভীষণ
        বুঝলে যুথী,
        হাসি খুশী উড়নচন্ডী মানুষ
        আমার তাইতো এখন খারাপ লাগে
        খারাপ লাগে
        আর তাছাড়া আমি কি আর যীশু না হাবিজাবি
        ওদের মতো সব সহিষ্ণু?
        আমি অনেক
        কষ্টে আছি কষ্টে আছি কষ্টে আছি ।।
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

    while(b)
    {
        a=a%b;
        swap(a,b);
    }

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
inline T in()
{
    register char c=0;
    register T num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    return n?-num:num;
}

/******* ! Code start from here ! *******/

// Find Some of Differente interval of many query

int kp[100000];
int tree[4*100000];
int lazy[4*100000];

int u,v,sum,x;

void build(int nod,int l,int r)
{
    if(l==r)
    {
        tree[nod]=kp[l];
        lazy[nod]=0;
        return;
    }

    int mid=(l+r)/2;
    int left=2*nod;
    int right=2*nod+1;

    build(left,l,mid);
    build(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];
    lazy[nod]=0;
}


// update range u to v by x

void update(int nod,int l,int r)
{
    if(r<u || v<l) return;
    if(u<=l && r<=v)
    {
        tree[nod]+=(r-l+1)*x;
        lazy[nod]+=x;
        return;
    }

    int mid=(l+r)/2;
    int left=2*nod;
    int right=2*nod+1;

    if(lazy[nod])
    {
        tree[left]+=(mid-l+1)*lazy[nod];
        tree[right]+=(r-mid)*lazy[nod];

        lazy[left]+=lazy[nod];
        lazy[right]+=lazy[nod];

        lazy[nod]=0;
    }

    update(left,l,mid);
    update(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];
}

//Get sum from range u  to v

void query(int nod,int l,int r)
{
    if(r<u || v<l) return;
    if(u<=l && r<=v)
    {
        sum+=tree[nod];
        return;
    }

    int mid=(l+r)/2;
    int left=2*nod;
    int right=2*nod+1;

    if(lazy[nod])
    {
        tree[left]+=(mid-l+1)*lazy[nod];
        tree[right]+=(r-mid)*lazy[nod];

        lazy[left]+=lazy[nod];
        lazy[right]+=lazy[nod];

        lazy[nod]=0;
    }

    query(left,l,mid);
    query(right,mid+1,r);

    tree[nod]=tree[left]+tree[right];
}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
//        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int n,q;

    scanf("%d %d",&n,&q); // number of input & query

    for(int i=0;i<n;i++)
    {
        kp[i]=in<int>();
    }

    build(1,0,n-1);

    int c;

    while(q--)
    {
        scanf("%d",&c);

        if(c==1) // update
        {
            scanf("%d %d %d",&u,&v,&x);

            update(1,0,n-1);
        }
        else // query
        {
            scanf("%d %d",&u,&v);

            sum=0;
            query(1,0,n-1);

            printf("%d\n",sum);
        }
    }


    return 0;
}


