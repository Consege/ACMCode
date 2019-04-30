struct Rode
{
    int s,e,w;
} a[maxn];
int fa[maxn];

int Find(int x)
{
    // 路径压缩
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
bool cmp(Rode a,Rode b)
{
    return a.w<b.w;
}
int Kruskal()
{
    int ans=0;
    for(int i=1; i<=n; i++)
        fa[i]=i;
    sort(a,a+m,cmp);

    for(int i=0; i<m; i++)
    {
        int x=Find(a[i].s);
        int y=Find(a[i].e);
        if(x!=y)
        {
            ans+=a[i].w;
            fa[x]=y;
        }
    }
    return ans;
}
