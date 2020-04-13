#include<bits/stdc++.h>
#define ll long long int
#define inf INT_MAX
#define pb push_back
using namespace std;
ll n = 4;
void dijkstra(ll g[][4],ll v){
	map<ll,ll>m;
	ll i;
	for(i=0;i<n;i++)
		m[i]=0;
	m[v]=1;
	ll a[n];
	for(i=0;i<n;i++){
		a[i]=g[v][i];
	}
	for(int j=1;j<n;j++){
		ll min = inf,w=inf;
		for(i=0;i<n;i++){
			if(a[i]<=min && m[i]==0){
				w = i;
				min = a[i];
			}
		}
		m[w]=1;
		for(i=0;i<n;i++){
			if(a[w]+g[w][i]<a[i] && m[i]==0)
				a[i]=a[w]+g[w][i];
		}
	}
	for(i=0;i<n;i++){
		if(a[i]!=INT_MAX)
				cout<<a[i]<<" ";
		else
			cout<<"inf"<<" ";
	}
	cout<<endl;
}
vector<pair<pair<ll,ll>,ll>>edges;
vector<ll>weights;
void bellmanford(ll g[][4]){
	ll i,j;
	for(i=0;i<n+1;i++)
		weights.push_back(0);
	for(i=0;i<n;i++){
		pair<ll,ll> p;
		p.first = n;
		p.second = i;
		pair<pair<ll,ll>,ll>p1;
		p1.first = p;
		p1.second = 0;
		edges.pb(p1);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(g[i][j]!=INT_MAX && i!=j){
				pair<ll,ll> p;
				p.first = i;
				p.second = j;
				pair<pair<ll,ll>,ll>p1;
				p1.first = p;
				p1.second = g[i][j];
				edges.pb(p1);			
			}
		}
	}
	for(j=0;j<edges.size();j++){
		cout<<edges[j].first.first<<","<<edges[j].first.second<<" "<<edges[j].second<<endl; 
	}
	for(i=0;i<n+1;i++){
		for(j=0;j<edges.size();j++){
			if(weights[edges[j].first.second]>weights[edges[j].first.first] + edges[j].second)
				weights[edges[j].first.second] = weights[edges[j].first.first] + edges[j].second;
		}
	}
	for(i=0;i<n;i++)
		cout<<weights[i]<<" ";
	cout<<endl;
	cout<<"The original graph is"<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(g[i][j]!=INT_MAX)
				cout<<g[i][j]<<" ";
			else
				cout<<"inf"<<" ";
		}
		cout<<endl;
	}
	for(j=n;j<edges.size();j++){
		cout<<edges[j].first.first<<","<<edges[j].first.second<<" "<<edges[j].second<<endl; 	
		edges[j].second = edges[j].second + weights[edges[j].first.first] - weights[edges[j].first.second]; 
		g[edges[j].first.first][edges[j].first.second] = edges[j].second; 	
	}
	cout<<"The modified graph is"<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(g[i][j]!=INT_MAX)
				cout<<g[i][j]<<" ";
			else
				cout<<"inf"<<" ";
		}
		cout<<endl;
	}
}
void apspgreedy(ll g[][4]){
	ll i,j,k;
	bellmanford(g);
	cout<<"The shortest paths are"<<endl;
	for(i=0;i<n;i++){
		dijkstra(g,i);
	}
}
int main(){
	ll g[4][4]={{0,3,inf,7},{8,0,2,inf},{5,inf,0,1},{2,inf,inf,0}};
	apspgreedy(g);
	return 0;
}
