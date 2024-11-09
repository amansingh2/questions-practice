//CSES shortest route - 1

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    vector<pair<int,int>> g [n + 1];
    for(int i = 0 ; i < m ; i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    pq.push({0,1});
    vector<int>dist(n+1,(int)1e15);
    dist[1] = 0;
    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(wt > dist[node]){
            continue;     // bahut bada optimization bhai;
        }
        for(auto x : g[node]){
            int e_node = x.first;
            int e_wt = x.second;
            if(wt + e_wt < dist[e_node]){
                dist[e_node] = wt + e_wt;
                pq.push({wt + e_wt,e_node});
            }

        }
    }
    for(int i = 1 ; i  <= n ; i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}