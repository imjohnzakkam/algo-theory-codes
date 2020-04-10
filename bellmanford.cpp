#include<bits/stdc++.h>
#define ll long long int
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define max 1000
using namespace std;

struct edge {ll u,v,wt;};

void addedge(vpl adj[], ll u, ll v, ll wt)
{
    adj[u].push_back(make_pair(v, wt)); 
}

void bellmanford(vpl adj[], int n, int src)
{
    int dist[n];

    for(int i=0;i<n;i++)
    dist[i]=INT_MAX;

    dist[src]=0;
    int v,w;

    for(int i=1;i<=n-1;i++)
    {
        for(int u=0;u<n;u++)
        {
            for (auto it=adj[u].begin();it!=adj[u].end();it++) 
            { 
                v = it->first; 
                w = it->second; 
                if(dist[u]!=INT_MAX && dist[v]>dist[u]+w)
                dist[v]=dist[u]+w;
                
            } 
        }
    }

    cout<<"Distances of vertices from "<<src<<" :\n";
    cout<<"Vertices Distance";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<i<<"     "<<dist[i]<<endl;
    }
}

void get_graph(vector<pair<int,int> > adj[], int &n)
{
    cout<<"Enter no of vertices: "<<endl;
    cin>>n;
    int u,v,w,m;
    cout<<"Enter no of edges: "<<endl;
    cin>>m;
    cout<<"Enter edges(src,dest,weight separated by spaces): ";
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        edge_add(adj,u,v,w);
    }

}

int main()
{
    vector<pair<int,int> > adj[100];
    int n;
    get_graph(adj,n);
    bellmanford(adj,n,0);
}
