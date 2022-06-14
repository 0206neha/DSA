#include<bits/stdc++.h>
using namespace std;

void dfs()
{

}
int main()
{
    int v,e,n,u;
    cout<<"Enter Number of vertices and edges";
    cin>>n>>e;

    vector<int>g[n];
    bool visit[n];

    for(int i=0;i<n;i++)
    {
        visit[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        cin>>v>>u;
        g[u].push_back(v);
        g[v].push_back(u); //undirected graph
    }

    dfs();

   return 0;
}