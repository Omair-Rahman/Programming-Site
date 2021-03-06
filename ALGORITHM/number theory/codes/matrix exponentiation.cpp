// Problem name : nth term
// Algorithm : Matrix Expo
// Contest/Practice : Off line Practice
// Source : Light Oj
// Comment : Matha betha :(
// Date : 26-jul-2014

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


#define MOD 10007

using namespace std;

#ifndef ONLINE_JUDGE
#  define print(x) cout<<x<<endl;
#else
#  define print(x) 0
#endif

class matrix
{
    public:
        int col,row;
        int v[4][4];
} ;

int mod_value(int num)
{
    return num%MOD;
}

matrix matrix_mul(matrix A,matrix B)
{
    assert(A.col==B.row);
    matrix C;
    C.row=C.col=A.col;
    int sum=0;
    for(int i=0;i<A.row;i++)
    {
        for(int j=0;j<B.col;j++)
        {
            sum=0;
            for(int k=0;k<A.col;k++)
             {
                 sum+=(A.v[i][k]*B.v[k][j]);
                 sum=mod_value(sum);
             }
             C.v[i][j]=sum;
        }
    }
    return C;
}

matrix expo(matrix X,int n)
{
    if(n==1) return X;
    else if(n%2)
    {
        return matrix_mul(X,expo(X,n-1));
    }
    else
    {
        matrix L=expo(X,n/2);
        return matrix_mul(L,L);
    }
}

int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        int  a,b,c,n;
        while(t--)
        {
            scanf("%d %d %d %d",&n,&a,&b,&c);
            matrix my;
            my.row=my.col=4;
            my.v[0][0]=a,my.v[0][2]=b,my.v[0][3]=c;
            my.v[1][0]=my.v[2][1]=my.v[3][3]=1;
            my.v[0][1]=my.v[1][1]=my.v[1][2]=my.v[1][3]=my.v[2][0]=my.v[2][2]=my.v[2][3]=my.v[3][0]=my.v[3][1]=my.v[3][2]=0;
            int  ans;
            printf("Case %d: ",tcase++);
            if(n<=2)
                printf("%d\n",0);
            else
            {
                my=expo(my,n-2);
                printf("%d\n",my.v[0][3]);
            }
        }
    }
    return 0;
}

//          | a 0 b c |^(m-2)     | f(2) |
//          | 1 0 0 0 |           | f(1) |
//    M=    | 0 1 0 0 |        X  | f(0) |
//          | 0 0 0 1 |           |  1   |
//
//    ?????????????????? f(n<=2)==0
//    ????????? n-2 ?????? M ????????????????????????????????? ??????????????? m[0][0]=m[0][1]=m[0][2]=0 ????????? ?????? ?????????
//    ???????????? m[0][3] = (n-3)*(a*b+c) ????????????
//    ????????? ???????????? m[0][3] ?????? ???????????????????????? ??????????????? ????????? ???
