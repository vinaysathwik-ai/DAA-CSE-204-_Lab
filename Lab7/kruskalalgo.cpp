#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

bool cmp(Edge a,Edge b){
    return a.w<b.w;
}

int p[100];

int find(int x){
    return p[x]==x ? x : p[x]=find(p[x]);
}

int main(){
    int n,m;
    cout<<"Enter number of vertices: ";
    cin>>n;

    cout<<"Enter number of edges: ";
    cin>>m;

    vector<Edge> e(m);

    cout<<"Enter edges (u v weight):\n";
    for(int i=0;i<m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;

    sort(e.begin(),e.end(),cmp);

    for(int i=0;i<n;i++)
        p[i]=i;

    int cost=0;

    cout<<"\nEdges in MST:\n";

    for(auto x:e){
        int a=find(x.u);
        int b=find(x.v);

        if(a!=b){
            p[a]=b;
            cout<<x.u<<" - "<<x.v<<" : "<<x.w<<endl;
            cost+=x.w;
        }
    }

    cout<<"MST Cost = "<<cost;

    return 0;
}