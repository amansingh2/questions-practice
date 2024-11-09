//CSES shortest route - 1

#include <bits/stdc++.h>
#define int long long
using namespace std;

void bfs(vector<int> g [] , vector<bool> & vis, map<int,int> & parent, int src, int dest){
    queue<int>q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i : g[node]){
            if(i == dest){
                parent[i] = node;
                vis[i] = true;
                return;
            }
            if(!vis[i]){
                parent[i] = node;
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    
    vector<int>g [n+1];
    for(int i = 0 ; i < m ; i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool>vis(n+1,false);
    map<int,int>parent;
    parent[1] = 1;
    bfs(g,vis,parent,1,n);
    if(!vis[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }else{
        vector<int>ans;
        int i = n;
        while(parent[i] != i){
            ans.push_back(i);
            i = parent[i];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        cout<<(int)ans.size()<<endl;
        for(int it : ans){
            cout<<it<<" ";
        }
    }





    return 0;
}