#include<iostream>
using namespace std;

void call(int i)
{
    if(i==0)
        return;
    cout<<i<<endl;
    i--;
    call(i);
}

int main()
{
    int i=5;
    call(i);
}
