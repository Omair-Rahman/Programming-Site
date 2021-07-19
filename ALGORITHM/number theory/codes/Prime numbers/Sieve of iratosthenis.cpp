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
#include <sstream>
#include <fstream>
#define s(n)          scanf("%d",&n)
#define loop(i,a,b)    for(int i=int(a);i<int(b);i++)
#define MAX 10000000
using namespace std;

 bool mark[MAX+4]={false};
 vector<int> nums;
 void siv()
 {
     int i,j,k;
     for(i=2;i<=sqrt(MAX);i=i++)
     {
         if(!mark[i])
         for(j=2;i*j<=MAX;j++)
            mark[i*j]=true;
     }
     for(int k=0;k<MAX;k++)
        if(!mark[k])
            nums.push_back(k);
 }

int main()
{
siv();
cout<<nums[456]<<endl;
return 0;
}
