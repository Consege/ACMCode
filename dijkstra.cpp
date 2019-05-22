int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    //times[i] = (u,v,w)
    vector<pair<int,int> > node[N+1] ;
    for(int i = 0;i<times.size();i++){
        int s = times[i][0];
        int t = times[i][1];
        int w = times[i][2];
        node[s].push_back(make_pair(t,w));            
    }
    int dis[N+1];
    int vis[N+1];
    memset(vis,0,sizeof vis);
    for(int i =0 ;i<=N;i++){
        dis[i] = 1e9;
    }
    dis[K] = 0;
    vis[K] = 1;
    for(int i = 0;i<node[K].size();i++){
        dis[node[K][i].first] = node[K][i].second;
    }
    for(int i =0;i<N;i++){
        int minn = 1e9;
        int minindex = 1;
        for(int j = 1;j<=N;j++){
            if(!vis[j] && minn>dis[j]){
                minn = dis[j];
                minindex = j;
            }
        }
        
        vis[minindex] = 1;
        for(int j = 0;j<node[minindex].size();j++){
            int v = node[minindex][j].first; 
            int w = node[minindex][j].second;
            dis[v] = min(dis[v],dis[minindex]+w);
        }
    }
    int ans = 0;
    for(int i =1;i<=N;i++){
        ans = max(ans,dis[i]);
    }
    if(ans>=1e9){
        return -1;
    }
    return ans;
    
    
}