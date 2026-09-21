#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;

    cout<<"Enter number of vertices: ";
    cin>>n;

    cout<<"Enter number of edges: ";
    cin>>m;

    vector<pair<int,int>> g[n];

    cout<<"Enter edges (u v weight):\n";
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    vector<int> d(n,INT_MAX),p(n,-1),vis(n,0);

    d[0]=0;
    int cost=0;

    cout<<"\nEdges in MST:\n";

    for(int k=0;k<n;k++){
        int u=-1;

        for(int i=0;i<n;i++)
            if(!vis[i] && (u==-1 || d[i]<d[u]))
                u=i;

        if(u==-1 || d[u]==INT_MAX){
            cout<<"MST does not exist";
            return 0;
        }

        vis[u]=1;

        if(p[u]!=-1){
            cout<<p[u]<<" - "<<u<<" : "<<d[u]<<endl;
            cost+=d[u];
        }

        for(auto x:g[u]){
            int v=x.first;
            int w=x.second;

            if(!vis[v] && w<d[v]){
                d[v]=w;
                p[v]=u;
            }
        }
    }

    cout<<"MST Cost = "<<cost;

    return 0;
}