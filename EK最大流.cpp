#include <bits/stdc++.h>

using namespace std;

int n , m ;
struct Edge{
    int u , v, c ,nxt,f;
}e[2005];
int head[20] ;
int pre[30],vis[30];
int cnt ;
void add(int u , int v ,int c ){
    e[cnt].u = u ,e[cnt].v = v , e[cnt].c = c ,e[cnt].nxt = head[u],e[cnt].f =0 ,head[u] = cnt++ ;
    e[cnt].u = v ,e[cnt].v =u ,e[cnt].c = 0 ,e[cnt].nxt = head[v],e[cnt].f = 0,head[v] = cnt++ ;
}

int bfs(int s,int t)
{
    queue<int> que ;
    que.push(s) ;
    memset(pre,-1,sizeof pre);
    memset(vis,0,sizeof vis);
    vis[s] = 1;
    while(!que.empty()){
        int d = que.front();
        que.pop();
        for(int i = head[d];i!=-1;i=e[i].nxt){
            if(e[i].c-e[i].f>0 && !vis[e[i].v]){
                int v = e[i].v ;
                pre[v] = i ;
                vis[v] = 1;
                if(v == t) return 1;
                que.push(v);
            }
        }
    }
    return 0;
}
int getMaxFlow(int s, int t)
{
    int maxflow = 0;
    while(1){
        if(!bfs(s,t)) return maxflow ;
        int tmp = 1e9 ;
        //记录路径
        stack<int> ways;
        for(int v =t;;){
            int i = pre[v];
            tmp = min(tmp,e[i].c - e[i].f) ;
            ways.push(i) ;
            v = e[i].u ;
            if(v==s){
                break ;
            }
        }
        //打印路径
        //print(ways);
        maxflow += tmp ;
        for(int v=t;;){
            int i = pre[v] ;
            e[i].f += tmp ;
            e[i^1].f-=tmp;
            v = e[i].u ;
            if(v == s){
                break ;
            }
        }
    }
}
int main()
{
    int  ts ;
    scanf("%d",&ts);
    for(int times = 1 ;times<=ts ;times++){
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof head);
        cnt = 0 ;
        for(int i = 0 ;i<m ;i++){
            int X , Y ,C ;
            scanf("%d%d%d",&X,&Y,&C);
            add(X,Y,C) ;
        }
        int s = 1 ,t = n ;
        int ans = getMaxFlow(s,t) ;
        printf("Case %d: %d\n",times,ans) ;

    }
    return 0;
}
