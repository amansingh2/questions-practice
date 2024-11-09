#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs(int src, vector<int> g[] , vector<bool> & vis , vector<int>&col , int c , bool & flag){
    col[src] = c;
    vis[src] = true;

    for(int i : g[src]){
        if(!vis[i]){
            dfs(i,g,vis,col,-1*c,flag);
        }else if(vis[i]){
            if(col[i] != -1*c){
                flag = false;
                return;
            }
        }
    }
}

int32_t main(){
    int n , m ; cin >> n >> m;
    vector<int>g[n+1];
    for(int i = 0  ; i < m ; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int>col(n+1,0);
    vector<bool>vis(n+1,false);
    bool flag = true;
    for(int i = 1; i <= n ; i++){
        if(!vis[i]){
            flag = true;
            dfs(i,g,vis,col,1,flag);
            if(!flag){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        cout<<(col[i] == 1 ? col[i] : 2)<<" ";
    }
    cout<<endl;

    return 0;
}