#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>
#define PS system("pause")
using namespace std;

string  arr="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int SZ=3;
vector<char>result;
vector<char>::iterator it;
int taken[]={0};
void call()
{

	if(result.size()==SZ)
	{
		for(int i=0;i<SZ;i++)
		printf("%c",result[i]);
		cout<<endl;
		return;
	}
	for(int i=0;i<SZ;i++)
	{
	    cout<<">> "<<i<<endl;
		if(taken[i]==0)
		{
			taken[i]=1;
			result.push_back(arr[i]);
			call();
			taken[i]=0;
			result.pop_back();
		}
	}
}
int main()
{
	call();
}
