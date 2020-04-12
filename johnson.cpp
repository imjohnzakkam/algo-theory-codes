#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<queue>
#include<cstdlib>
#define INF 0x3f3f3f3f
using namespace std;
int *djk_dist;
class cmp{
public:
    bool operator()(int a,int b){
        return (djk_dist[a]>djk_dist[b]);
    }
};
void add_edge(vector<list<pair<int,int> > > &adj_list,int src,int dest, int wt){
    adj_list[src].push_back(make_pair(dest,wt));
}
void change_weights(vector<list<pair<int,int> > > &adj_list,int *h){
    int v = adj_list.size(),i;
    list<pair<int,int> > :: iterator itr;
    for(i=0;i<v;i++){
        for(itr=adj_list[i].begin();itr!=adj_list[i].end();itr++){
            itr->second += h[i] - h[itr->first];
        }
    }
}
int * bellman_ford_johnson(vector<list<pair<int,int> > > &adj_list){
    int v = adj_list.size();
    list<pair<int,int> > :: iterator itr;
    int i,j;
    list<pair<int,int> > src_list;
    for(i=0;i<v;i++){
        src_list.push_back(make_pair(i,0));
    }
    adj_list.push_back(src_list);
    int src = v;
    v++;/*sizeof(adj_list) now is v+1*/
    int *dist;
    dist = (int *)calloc(v,sizeof(int));
    for(i=0;i<v;i++)dist[i]=INF;
    dist[src] = 0;
    bool f=0;
    for(i=0;i<v-1;i++){
        /*Now traverse all edges in adj_list*/
        f=0;
        for(j=0;j<v;j++){
            if(dist[j]!=INF){
                for(itr= adj_list[j].begin();itr!=adj_list[j].end();itr++){
                    if(dist[itr->first]>dist[j]+itr->second){
                        dist[itr->first] = dist[j]+itr->second;
                        f=1;
                    }
                }
            }
        }
        if(!f)break;
    }
    f=0;
    for(j=0;j<v;j++){
            for(itr= adj_list[j].begin();itr!=adj_list[j].end();itr++){
                if(dist[itr->first]>dist[j]+itr->second){
                    dist[itr->first] = dist[j]+itr->second;
                    f=1;
                }
            }
    }
    if(f){
        return NULL;
    }
    adj_list.pop_back();
    return dist;
}
int *dijkstra(vector<list<pair<int,int> > > &adj_list, int src){
    int v = adj_list.size(), i;
    djk_dist = (int *)calloc(v, sizeof(int));
    bool sptSet[v];
    for(i=0;i<v;i++){
        djk_dist[i]=INF;
        sptSet[i]=false;
    }
    djk_dist[src]=0;
    priority_queue<int,vector<int>,cmp> pq;
    for(i=0;i<v;i++)pq.push(i);
    int node;
    list<pair<int,int> > :: iterator itr;
    while(!pq.empty()){
        node = pq.top();
        sptSet[node]=true;
        for(itr=adj_list[node].begin();itr!=adj_list[node].end();itr++){
            if(!sptSet[itr->first] && djk_dist[itr->first]>djk_dist[node]+itr->second){
                djk_dist[itr->first]=djk_dist[node]+itr->second;
            }
        }
        pq.pop();
    }
    return djk_dist;
}
void print_adj_list(vector<list<pair<int,int> > > adj_list){
    int v = adj_list.size(),i;
    list<pair<int,int> >::iterator itr;
    for(i=0;i<v;i++){
        for(itr =adj_list[i].begin();itr!=adj_list[i].end();itr++)cout << itr->second << ' ';
        cout << endl;
    }
}
void johnson_spa(vector<list<pair<int,int> > > adj_list){

    /*Get weights to assign to each vertex for readjusting each edge wt to make them positive and hence be able to apply djk*/
    int * h = bellman_ford_johnson(adj_list), i, j;
    int v = adj_list.size();
    if(!h){cout << "There is a negative cycle in graph"<<endl;return;}
    /*cout << "Before changing weights"<<endl;
    print_adj_list(adj_list);
    */
    change_weights(adj_list,h);
    /*cout << "After changing weights"<<endl;
    print_adj_list(adj_list);
    cout << "h vector is as follow : ";
    for(i=0;i<v;i++)cout << h[i]<< ' ';
    cout<<endl;
    */
    /*Now apply djk*/

    int **distances = (int **)calloc(v,sizeof(int *));
    for(i=0;i<v;i++){
         distances[i] = dijkstra(adj_list,i);
         /*we need to revert back the addition*/
         for(j=0;j<v;j++)if(i!=j && distances[i][j]!=INF)distances[i][j]+=-h[i]+h[j];
    }
    cout << "Distance Matrix is"<<endl;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(distances[i][j]!=INF)
            cout << distances[i][j] << ' ';
            else
            cout << "INF ";
        }
        cout << endl;
    }
}
int main(){
    /*
    Copy Input
    4 5
    0 1 -5
    1 2 4
    2 3 1
    0 3 3
    0 2 2
    
    */
    int i, n, e, src, dest, wt, j;
    cin >> n >> e;
    vector<list<pair<int,int> > > adj_list(n);
    for(i=0;i<e;i++){
        cin >> src >> dest >> wt;
        add_edge(adj_list,src,dest,wt);
    }
    johnson_spa(adj_list);
    return 0;
}
