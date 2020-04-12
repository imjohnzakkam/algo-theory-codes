#include<bits/stdc++.h>
#define ll long long int
#define inf INT_MAX
using namespace std;
ll n = 4;
void apsp(ll g[][4]){
	ll i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(g[j][k]>g[j][i] + g[i][k]){
					g[j][k] = g[j][i] + g[i][k];
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	ll g[4][4]={{0,3,inf,7},{8,0,2,inf},{5,inf,0,1},{2,inf,inf,0}};
	apsp(g);
	return 0;
}
