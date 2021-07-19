

// aproach -3

int n, a[N], b[N], f[N], answer=0;
... // enter n and a[] from keyboard

for (int i=1; i<=n; i++)
{
    f[i]=lower_bound(b+1, b+answer+1, a[i])-b;
    answer=max(answer, f[i]);
    b[f[i]]=a[i];
}

printf("%d\n", answer);



vector<int> T;

int require = answer;
for (int i=n; i>=1; i--)
    if (f[i]==require)
    {
        T.push_back(a[i]);
        require--;
    }

int main()
{

    return 0;
}
