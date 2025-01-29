#include <bits/stdc++.h>
#define int long long
using namespace std;
int inf = 1e15;
bool isTrue(vector<int> g [] , int node , int n){ // dono tarar se mil sakta hai kya!
    // cout<<"---"<<node<<endl;
    queue<int>q;
    q.push(1);
    vector<bool> vis(n + 1 , false);
    vis[1] = true;
    while(!q.empty()){
        int nn = q.front();
        q.pop();
        for(int i : g[nn]){
            if(!vis[i]){
                q.push(i);
                vis[i] = true;
            }
        }
    }
    vector<bool>vis2(n+1 , false);
    q.push(node);
    vis2[node] = true;


    while(!q.empty()){
        int nn = q.front();
        q.pop();
        for(int i : g[nn]){
            if(!vis2[i]){
                vis2[i] = true;
                q.push(i);
            }
        }
    }

    return vis[node] == true && vis2[n] == true;

}
void belman_ford(vector<vector<int>>&edges , int n, int s){
    vector<int>dist(n+1,-inf);
    dist[s] = 0;
    vector<int>g[n + 1];
    for(auto e : edges){
        g[e[0]].push_back(e[1]);
    }
    for(int i = 1 ; i < n ; i++){
        for(auto edge : edges){
            int src = edge[0];
            int dest = edge[1];
            int weight = edge[2];
            if(dist[src] + weight > dist[dest]){
                dist[dest] = dist[src] + weight;
            }
        }
    }
    // cout<<dist[1]<<endl;
    vector<int>d2 = dist;
    for(auto edge : edges){
        int src = edge[0];
        int dest = edge[1];
        int weight = edge[2];
        if(d2[src] + weight > d2[dest]){
            d2[dest] = d2[src] + weight;
            // cout<<src<< " " << " " << weight << " " <<  dest<<endl;
            // cout<<dist[src]<< " " << " " << weight << " " <<  dist[dest]<<endl;
            // queue<int>q;
            // vector<bool>vis(n+1 , false);
            // q.push(src);
            // vis[src] = true;
            // while(!q.empty()){
            //     int node = q.front();
            //     // cout<<node<<endl;
            //     q.pop();
            //     vis[node] = true;
            //     for(auto it : g[node]){
            //         if(!vis[it]){
            //             q.push(it);
            //         }
            //     }
            // }
            // while(!q.empty()){
            //     q.pop();
            // }
            // q.push(1);
            // vector<bool>vis2(n + 1 , false);
            // while(!q.empty()){
            //     int node = q.front();
            //     q.pop();
            //     for(auto it : g[node]){
            //         if(!vis[it]){
            //             q.push(it);
            //             vis[it] = true;
            //         }
            //     }
            // }
            // if(vis[n] == true){
            //     cout<<-1<<endl;
            //     return;
            // }
        }
    }
 
    // for(auto x : dist){
    //     cout<<x<<" ";
    // }
    // queue<int>q;
    // vector<bool>vis(n+1, false);
    // q.push(1);
    // vis[1] = true;
    // while(!q.empty()){
    //     int node = q.front();
    //     if(dist[node] != d2[node]){
    //         cout<<-1;
    //         return;
    //     }
    //     q.pop();
    //     for(int i : g[node]){
    //         if(!vis[i]){
    //             q.push(i);
    //         }
    //     }
        
    // }
    // if(dist[n] != d2[n]){
    //     cout<<-1;
    //     return ;
    // }

    for(int i = 1 ; i <= n ; i++){
        if(dist[i] != d2[i]){ 
            // cout<<i<<endl;
            if(isTrue(g , i , n)){
                cout<<-1<<endl;
                return;
            }
        }
    }
    cout<<dist[n]<<endl;
 
}
 
int32_t main(){
    // int t;cin>>t;
    // while(t--){
        int n,m;cin>>n>>m;
 
        vector<vector<int>>g;
        for(int i = 0 ; i < m ; i++){
            int a,b,c;
            cin>>a>>b>>c;
            g.push_back({a,b,c});
        }
        belman_ford(g,n,1);
    // }
    return 0;
}