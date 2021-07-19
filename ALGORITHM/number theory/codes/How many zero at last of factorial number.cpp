#include<iostream>
#include<cstdio>

using namespace std;

int Zero_counter(int num)
{
    int pow_5=5, counter=0;
    while(pow_5<=num)
    {
        counter+=num/pow_5;
        pow_5*=5;
    }
    return counter;
}

int main()
{
    int num;
    scanf("%d",&num);
    num=Zero_counter(num);
    cout<<num<<endl;
    return 0;
}
