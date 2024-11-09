#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs(int src , vector<int> g[] , vector<int>&dp , int curr,vector<bool>&vis){
    for(int i : g[src]){
        if(!vis[i]){
            dp[i] = max(dp[i] , curr + 1);
            dfs(i,g,dp,curr+ 1,vis);
        }

    }
}
int32_t main(){
   int n , m ; cin >> n >> m;
   vector<int>g[n+1];

   for(int i = 0 ; i < m ; i++){
        int a,b ; cin >> a >> b;
        g[a].push_back(b);
   }
   vector<int>dp(n+1,0);
   vector<bool>vis(n+1,false);
   for(int i  = 1 ; i <= n ; i++){
        dfs(i,g,dp,0,vis);
   }
   cout<<(*max_element(dp.begin() , dp.end()))<<endl;
    return 0;
}
