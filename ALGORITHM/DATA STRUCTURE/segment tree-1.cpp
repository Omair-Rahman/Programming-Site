
int tree[m*3], ara[M];

// this funtion makes a tree from the given input array

void boshi_ja(int node,int b,int e) // node - beging index number- end index number
{
    if(b==e)
    {
        tree[node]=ara[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    boshi_ja(left,b,mid);
    boshi_ja(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

// This function updates the value of a given index
void taka_de(int node,int b,int e,int i,int taka)
{
    if(i>e||i<b)     // only range is i
        return ;
    if(e==b)
    {
        if(taka)
        {
            tree[node]+=taka;
            return;
        }
        else
        {
            pf("%d\n",tree[node]);
            tree[node]=taka;
            return;
        }

    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    taka_de(left,b,mid,i,taka);
    taka_de(right,mid+1,e,i,taka);
    tree[node]=tree[left]+tree[right];
}

//This function returns the value from ith - jth index

int hishab_kor(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)
        return 0;
    if(b>=i&&e<=j)          // be careful about this condition
        return tree[node];

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    int ans1=hishab_kor(left,b,mid,i,j);
    int ans2=hishab_kor(right,mid+1,e,i,j);
    return ans1+ans2;
}
