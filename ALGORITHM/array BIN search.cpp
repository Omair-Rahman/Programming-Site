#include<iostream>
#include<cstdio>
using namespace std;
int binarySearch(int arr[], int value, int left, int right)
{
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (arr[middle] == value)
            return middle;
        else if (arr[middle] > value)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}
int main()
    {
        int x[5]={2,4,7,1,9};
        cout<<binarySearch(x,9,0,5)<<endl;
    }
