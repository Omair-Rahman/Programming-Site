#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

char arr[]={'a','b','c','d','c','d','c','d','c','d'};
vector<char>result;
vector<char>::iterator it;
int taken[]={0};
void call()
{
	if(result.size()==10)
	{
		for(int i=0;i<10;i++)
		printf("%c",result[i]);
		cout<<endl;
		return;
	}
	for(int i=0;i<10;i++)
	{
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
