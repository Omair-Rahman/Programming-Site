#include<bits/stdc++.h>
#define PS  system("pause")
using namespace std;


/*
K COINS ARE GIVEN UNLIMITED AND A TARGET NUMBER N:
   1. RETURN IF N CAN BE MADE BY K COINS     (table[j] |= table[j-S[i]])
   2. RETURN HOW MANY WAYS WE CAN FIND N BY THOSE COINS
      # FIRST FUNTION -> COINS ORDER DOESNT MATTER  (table[j] += table[j-S[i]])
      # SECOND FUNCTION -> COINS ORDER DOSE MATTER  (mab[i]+=mab[i-ara[j]])
*/
int without_order( int S[], int m, int n )
{
    int table[n+1];   // n =number of possibility
    //  m= number of coin

    memset(table, 0, sizeof(table));
    table[0] = 1;

    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
        {
            cout<<i<<' '<<j<<' '<<S[i]<<' '<<table[j]<<' '<<table[j-S[i]]<<endl;
            table[j] += table[j-S[i]];
        }
    return table[n];
}


int With_order(int ara[],int k,int n)
{
    int mab[n+1];
    memset(mab, 0, sizeof(mab));
    mab[0]=1;

    for(int i=1; i<=n; i++)
        for(int j=0; j<k; j++)
            if(i>=ara[j])
            {
                cout<<i<<' '<<ara[j]<<' '<<mab[i]<<' '<<mab[i-ara[j]]<<endl;
                mab[i]+=mab[i-ara[j]];
            }
    return mab[n];
}

int with_limit(int coin[],int limit[],int n,int m)    // If limited coin
{
    int pos[100]= {};

    pos[0]=1;

    for(int i=0; i<n; i++) // n is number of coins
        for(int j=m; j>=coin[i]; j--) // m is target amount to be made
            for(int k=1; k<=limit[i]; k++)
                if(j-k*coin[i]>=0)
                    pos[j]+=pos[j-k*coin[i]];
    for(int i=1; i<=m; i++)
        cout<<i<<' '<<pos[i]<<endl;
}

int main()
{
    int ara[]= {1,2,3,4,5,6};
    int lim[]= {1,1,1,1,1,1};
    cout<<With_order(ara,3,3)<<"\n\n\n";
//    cout<<without_order(ara,2,8)<<endl;
//cout<<with_limit(ara,lim,6,5)<<endl;
    return 0;
}
