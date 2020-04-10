#include<bits/stdc++.h>
#define ll long long int
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define max 1000
#define LL_MAX INT_MAX
#define nl cout << endl;
using namespace std;
ll n;
struct edge {ll u,v,wt;};

void addedge(vpl G[], ll u, ll v, ll wt)
    { G[u].push_back(make_pair(v, wt)); }

void bellmanford(vpl G[], ll src)
{
    ll dist[n];
    for(ll i=0;i<n;i++)
    dist[i]=LL_MAX;
    dist[src]=0;
    ll v,w;
    for(ll i=1;i<=n-1;i++)
    {
        for(ll u=0;u<n;u++)
        {
            for (auto it=G[u].begin();it!=G[u].end();it++) 
            { 
                v = it->first; 
                w = it->second; 
                if(dist[u]!=LL_MAX && dist[v]>dist[u]+w)
                dist[v]=dist[u]+w;
                
            } 
        }
    }
    cout<<"Distances of vertices from :"<<src;nl;
    cout<<"Vertices Distance";nl;
    for(ll i=0;i<n;i++)
        {cout<<i<<"-"<<dist[i];nl;}
}

void get_graph(vpl G[])
{
    cout<<"Enter no of vertices: ";nl;
    cin>>n;
    ll u,v,w,m;
    cout<<"Enter no of edges: ";nl;
    cin>>m;
    cout<<"Enter edges(in the order : src, destination, weights ): ";
    for(ll i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        addedge(G,u,v,w);
    }
    return;
}

int32_t main()
{
    vpl G[max];
    get_graph(G);
    ll x;
    //cout << "Enter the source vertex : (start from 0) :";
    //cin >> x; 
    cout << "Bellman-Ford from source as : 0" <<x;nl;bellmanford(G,0);
    return 0;
}
