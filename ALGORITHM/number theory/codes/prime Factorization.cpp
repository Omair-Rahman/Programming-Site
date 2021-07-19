#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#define s(n)          scanf("%d",&n)
#define MAX          1000000
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)
#define ll             long long int
using namespace std;

vector<bool> prime(MAX+3,false);
vector <int> p;
vector <int> facto;
vector<int> C;
int test,ctest=0;
void siv()
{
    prime[0]=prime[1]=true;
    for(int i=2;i<=sqrt(MAX);i++)
    {
        if(!prime[i])
        {
            for(int j=2;i*j<=MAX;j++)
                 prime[i*j]=true;
        }

    }
    for(int i=2;i<MAX;i++)
    {
        if(!prime[i])
            p.push_back(i);
    }

}
int cnt=0;
void p_f(int n)
{
    for(int i=0;p[i]<=sqrt(n);i++)  // if input is 144, p[i] prime will go till 12
    {
        if(n%p[i]==0)         // if n is divisible by p[i] prime
        {
            while(n%p[i]==0)
            {
                n/=p[i];
                facto.push_back(p[i]);  // pushing the prime that divises n
                cnt++;
            }
        }
    }
    if(n>1)
       {
         facto.push_back(n);
         cnt++;
       }

}
int main()
{
siv();
int k;
p_f(100000000);
for(int j=0;j<facto.size();j++)
{
    printf("%d ",facto[j]);
}
return 0;
}
