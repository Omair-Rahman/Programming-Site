int rocky(int i,int j)
{
    if(i>=0&&i<n&&j>=0&&j<n)
    {
        if(dp[i][j]!=-1)
        return dp[i][j];
        int rem=-10;
        rem=max(rocky(i+1,j)+ara[i][j],rem);
        rem=max(rocky(i,j+1)+ara[i][j],rem);
        return dp[i][j]=rem;
    }
    else
        return 0;
}
