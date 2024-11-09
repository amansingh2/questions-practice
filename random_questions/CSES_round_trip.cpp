#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int>ans;
void dfs(int src, vector<bool> & vis, vector<int> g [], map<int,int> & mp , bool & flag){
    vis[src]  = true;
    for(auto v : g[src]){
        if(vis[v] == true && mp[v] != src){
            flag = true;
            while(mp[v] != -1){
                ans.push_back(mp[v]);
                v = mp[v];
            }
            ans.push_back(v);
            return;
        }
        if(!vis[v]){
            mp[v] = src;
            dfs(v,vis,g,mp,flag);
        }
    }
}

int32_t main(){
    int n , m ; cin >> n >> m;
    vector<int> g [n+1];
    for(int i  = 0 ; i  < m ;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool>vis(n+1,false);

    for(int i = 1 ; i <=  n  ; i ++){
        if(!vis[i]){
            map<int,int>mp;
            mp[i] = -1;
            bool flag = false;
            dfs(i,vis,g,mp,flag);
            if(flag){
                for(int it : ans){
                    cout<<it<<" ";
                }
                return 0;
            }
        }
      
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}