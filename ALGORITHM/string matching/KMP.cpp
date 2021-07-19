#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi failtush(string str)
{
    int ln=str.size();
    vi pre(ln+1,0);

    pre[0]=pre[1]=0;

    int k=0;

    for(int i=2;i<=ln;i++)
    {
        while(k>0&&str[k]!=str[i-1])
            k=pre[k];
        if(str[k]==str[i-1])
            k++;
        pre[i]=k;
    }
    return pre;
}



int main()
{

    string str,ptr;
    cin>>str>>ptr;
    vi ans=failtush(ptr+"&"+str);
    for(int i=1;i<ans.size();i++)
        cout<<i<<' '<<ans[i]<<endl;

    return 0;
}
