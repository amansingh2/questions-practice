#include<bits/stdc++.h>
using namespace std;
void dfs(int src , vector<int> g [] , vector<int>& dp ,vector<bool> & vis){
    vis[src] = true;
    int res = 0;
    for(int node : g[src]){
        if(!vis[node]){
            dfs(node , g , dp , vis);
            res += (1 + dp[node]);
        }
    }
    dp[src] = res;
}
int main(){
    int n ; cin >> n;
    vector<int>g[n + 1];
    for(int i = 2 ; i <= n ; i++){
        int v;
        cin >> v;
        g[v].push_back(i);
    }
    vector<bool>vis(n+1, false);
    vector<int>dp(n + 1 , 0);

    dfs(1 , g , dp , vis);

    for(int i = 1 ; i <= n ; i++){
        if(i != n){
            cout<<dp[i]<<" ";
        }else{
            cout<<dp[i];
        }
    }
}