#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#include <bits/stdc++.h>
using namespace std;

string mult(string a, string b)
{
    int len= a.length() + b.length();
    string result(len, '0'),ret;
    int num;
    int i, j;
    int last_pos_i, last_pos_j, last_pos_k;
    last_pos_i= len - 1;
    for (i= b.length() - 1; i >= 0; i --)
    {
        last_pos_j= last_pos_i;
        for (j= a.length() - 1; j >=0; j --)
        {
            last_pos_k= last_pos_j;
            num= INT(a[j]) * INT(b[i]);
            while (num)
            {
                num += INT(result[last_pos_k]);
                result[last_pos_k]= CHAR(num % 10);
                num= num / 10;
                last_pos_k --;
            }
            last_pos_j --;
        }
        last_pos_i --;
    }

    if(result[0]==48)
        result.erase(0,1);

    if(result[0]==48)
        return "0";
    return result;
}

string add(string a,string b)
{
    string num,str;
    int len1=a.length(),len2=b.length();
    if(len1<len2)
        {
            swap(a,b);
            swap(len1,len2);
        }
    for(int i=len1-1,j=len2-1;i>=0;i--,j--)
    {
        int temp=0,n1,n2;
        n1=a[i]-48;
        if(j<0)
            n2=0;
        else
        n2=b[j]-48;
        if(n1+n2>9)
        {
            temp=(n1+n2)%10;
            num.push_back(temp+48);
            if(i==0)
                num.push_back(49);
            else
               a[i-1]+=1;
        }
        else
        num.push_back(n1+n2+48);
    }
    for(int i=num.length()-1;i>=0;i--)
    {
        str.push_back(num[i]);
    }
    return str;

}

string div(string a,int b)
{
    int len=a.length(),sum=0,flag=0;
    string num;
        for(int K=0; K<len; K++)
        {
            sum=sum*10;
            sum=sum+(a[K]-48);
            if(sum<b&&flag==1)
              num.push_back(48);
            else if(sum>=b)
                {
                    num.push_back(sum/b+48);
                    sum=sum%b;
                    flag=1;
                }
        }
            if(!flag)
            num.push_back(48);

   return num;
}


