#include <bits/stdc++.h>
using namespace std;
//typedef node pair<int,int>;
const int nmax=1e6+10;
int n,m;
vector<int> a[nmax];
bool vs[nmax];
void dfs(int u)
{
    vs[u]=true;
    for(auto v:a[u])
        if(!vs[v])
    {
        dfs(v);
    }
}
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vs[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:a[u])
            if(!vs[v])
        {
            q.push(v);
            vs[v]=true;
        }

    }
}
int main()
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    bfs(1);
    bool ok;
    for(int i=1;i<=n;i++)
        if(!vs[i])
        {cout<<i<<" ";
        ok=true;}
        if(!ok) cout<<0<<"\n";

    return 0;
}
