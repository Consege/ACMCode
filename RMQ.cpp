void Initial()
{
    for(int i=1; i<=n; i++)
        dp[i][0]=num[i];
    for(int j=1; (1<<j)<=n; j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return max(dp[L][k],dp[R-(1<<k)+1][k]);
}