#include <bits/stdc++.h>
using namespace std;

///ver �ڵ���ֵ�˳��  , R ��� �� first �ڵ��һ�γ��ֵ�λ�� ��dir ����,ver�����нڵ�����
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
        //�����һ��ԭ����������Ϊ������
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
    //��ͼ
    addEdge();

    //��ʼ��
    init();
    //dfs���ŷ������(��ver����)
    dfs(1,1);

    //����ÿһ��ѯ�� u ,v , ��first������u,v��ŷ�������г��ֵĵ�һ��λ�� ;
    int x = first[u];
    int y= first[v] ;
    if(x>y) swap(x,y) ;
    //���ŷ�������е�xλ����yλ �����С�Ľڵ㣬�������ʹ��RMQ,RMQ���������С�Ľ��
    RMQINIT(tot);
    int lca = RMQ(x,y) ;
    return 0;
}
