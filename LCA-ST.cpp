#include <bits/stdc++.h>
using namespace std;

///ver 节点出现的顺序  , R 深度 ， first 节点第一次出现的位置 ，dir 距离,ver数组中节点数量
int ver[2*100005],R[2*100005],first[100005],dir[100005] ,vis[100005],tot;
int dp[2*100005][20] ;

void addEdge(int u , int v){
    e[cnt].u = u ,e[cnt].v = v ,e[cnt].nxt = head[u],head[u]=cnt++;
    e[cnt].u = v ,e[cnt].v = u ,e[cnt].nxt = head[v],head[v]=cnt++;

}

void dfs(int u,int dep){
    vis[u] = 1 ,ver[++tot]=u, R[tot] = dep , first[u] = tot;
    for(int i = head[u];i!=-1;i=e[i].nxt){
        int v = e[i].v ;
        if(!vis[v]){
            dir[v] = dir[u]+1;
            dfs(v,dep+1);
            ver[++tot] = u ,R[tot] = dep ;
        }
    }
}

void init(){
    memset(vis,0,sizeof vis) ;
    tot = 0;
    memset(dp,0,sizeof dp);
}
void RMQININT(int n){
    for(int i = 0 ;i<=n ;i++){
        dp[i][0] = i ;
    }
    for(int j = 1 ;1<<j<=n ;j++){
        //这里减一的原因是右区间为开区间
        for(int i = 0 ;i+(1<<j)-1<=n;i++){
            int x = dp[i][j-1];
            int y = dp[i+(1<<(j-1))][j-1] ;
            dp[i][j] = R[x]<R[y] ? x:y;
        }
    }

}
int RMQ(int L ,int R){
    int k ;
    while(L+(1<<(k+1)) <= R+1)k++;
    int x = dp[L][k];
    int y = dp[R-(1<<k)+1][k] ;
    return R[x]<R[y]?x:y ;
}
int main()
{
    //建图
    addEdge();

    //初始化
    init();
    //dfs获得欧拉序列(即ver数组)
    dfs(1,1);

    //对于每一个询问 u ,v , 由first数组获得u,v在欧拉序列中出现的第一个位置 ;
    int x = first[u];
    int y= first[v] ;
    if(x>y) swap(x,y) ;
    //获得欧拉序列中第x位到第y位 深度最小的节点，这个过程使用RMQ,RMQ返回深度最小的结点
    RMQINIT(tot);
    int lca = RMQ(x,y) ;
    return 0;
}
