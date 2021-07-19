
int ara[100000];
int tree[4*100000];
int lazy[4*100000];

int ii,jj,sum,x;
void init(int nod,int b,int e)
{
    if(b==e)
    {
        tree[nod]=ara[b];
        lazy[nod]=0;
        return;
    }

    int mid=(b+e)/2;
    int left=2*nod;
    int right=2*nod+1;

    build(left,b,mid);
    build(right,mid+1,e);
    tree[nod]=tree[left]+tree[right];
    lazy[nod]=0;
}

// update range ii to jj by x
void update(int nod,int b,int e)
{
    if(ii>e || jj<b) return;
    if(b>=ii&&e<=jj)
    {
        tree[nod]+=(e-b+1)*x;
        lazy[nod]+=x;
        return;
    }

    int mid=(b+e)/2;
    int left=2*nod;
    int right=2*nod+1;

    if(lazy[nod])
    {
        tree[left]+=(mid-b+1)*lazy[nod];
        tree[right]+=(e-mid)*lazy[nod];
        lazy[left]+=lazy[nod];
        lazy[right]+=lazy[nod];
        lazy[nod]=0;
    }

    update(left,b,mid);
    update(right,mid+1,e);
    tree[nod]=tree[left]+tree[right];
}

//Get sum from range ii  to jj

int query(int nod,int b,int e)
{
    if(ii>e||jj<b) return;
    if(b>=i&&e<=j)
        return tree[nod];

    int mid=(b+e)/2;
    int left=2*nod;
    int right=2*nod+1;

    if(lazy[nod])
    {
        tree[left]+=(mid-l+1)*lazy[nod];
        tree[right]+=(r-mid)*lazy[nod];
        lazy[left]+=lazy[nod];
        lazy[right]+=lazy[nod];
        lazy[nod]=0;
    }

    int p1=query(left,b,mid);
    int p2=query(right,mid+1,e);
    return p1+p2;
}
