// Problem name : Sudo Code Of BFS
// Algorithm : BFS
// Contest/Practice :
// Source :
// Comment :
// Date :

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<assert.h>
using namespace std;

//Try to find shortest path
//from vertex (A) -> vertex (B)

#define MAX 100

vector<int>graph[MAX]; // এডজেসেন্টসি লিস্ট
vector<int>cost(MAX);

int mark[MAX],par[MAX];
int n,m;


void input()
{
    scanf("%d %d",&n,&m);  // n হল ভারটেক্স নাম্বার এবং m হল এজ নাম্বার
    int a,b;

    for(int j=1; j<=m; j++)
    {
        // A থেকে B এর দিকে  একটা পাথ আছে
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
    }

    for(int i=0; i<MAX; i++)
    {
        cost[i]=0;
        mark[i]=0;
        par[i]=0;
    }
}

int BFS(int source,int des)// প্যারামিটার হিসাবে সোর্স,ডেস্টিনেশান পাঠালাম
{
    queue<int>q;
    q.push(source);
    mark[source]=1;
    par[source]=-1;

    while(!q.empty())
    {
        int u=q.front();//শুরু ভার্টেক্সটা নিলাম
        q.pop();

        for(int i=0; i<graph[u].size(); i++)
        {
            int v=graph[u][i];
            if(mark[v]==0)
            {
                mark[v]=1;
                par[v]=u;
                q.push(v);
                cost[v]=1+cost[u];
            }
        }
    }
    return cost[des];
}

void print_path(int u)
{
    if(par[u]==-1)
    {
        cout<<u<<' ';
        return;
    }
    print_path(par[u]);
    cout<<u<<' ';
}

int main()
{
    input();
    int source,des;

    cout<<"Give source and destination"<<endl;
    cin>>source>>des;
    int result=BFS(source,des);

    cout<<"result "<<result<<endl;
    cout<<"PATH "<<endl;
    print_path(des);
    return 0;
}
