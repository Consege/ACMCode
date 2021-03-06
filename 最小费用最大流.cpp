#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxn=2007;
const int INF=0x7fffffff;
struct Edge {
    int from,to,cap,flow,cost;
};
struct MCMF {
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];  //是否在队列中
    int d[maxn];    //bellman-ford
    int p[maxn];    //上一条弧
    int a[maxn];    //可改进量

    void init(int n) {
        this->n=n;
        for(int i=0; i<=n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int cap,int cost) {     //cost 是每流过一个单位所需费用
        edges.push_back((Edge) {
            from,to,cap,0,cost
        });
        edges.push_back((Edge) {
            to,from,0,0,-cost
        });
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool BellmanFord(int s,int t,int &flow,int& cost) {
        for(int i=0; i<=n; i++) d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=0;
        inq[s]=1;
        p[s]=0;
        a[s]=INF;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty()) {
            int u=Q.front();
            Q.pop();
            inq[u]=0;
            for(int i=0; i<G[u].size(); i++) {
                Edge&e =edges[G[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost) {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]) {
                        Q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        if(d[t]==INF)  return false;  //s-t 不连通，失败退出
        flow+=a[t];
        cost+=d[t]*a[t];
        int u=t;
        while(u!=s) {
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
            u=edges[p[u]].from;
        }
        return true;
    }

    int Mincost(int s,int t) { //求最大流的最小费用
        int flow=0,cost=0;
        while(BellmanFord(s,t,flow,cost));
        return cost;
    }
} mcmf;

int main() {
    int n,m;
    cin>>n>>m;
    int u,v,c;
    mcmf.init(n+2);
    while(m--) {
		//c为费用
        cin>>u>>v>>c;
        mcmf.AddEdge(u,v,1,c);
        mcmf.AddEdge(v,u,1,c);
    }

   //这里是增加一个超级源点和超级汇点，视题目而定
    mcmf.AddEdge(0, 1, 2, 0);
    mcmf.AddEdge(n, n+1, 2, 0);
	
    cout<<mcmf.Mincost(0, n+1)<<endl;
    return 0 ;
}
