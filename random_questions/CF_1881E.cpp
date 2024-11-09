#include <bits/stdc++.h>
#define int long long
using namespace std;
int solve(vector<int> & v , vector<int>&dp ,int i ,int n){
   if(i >= n){
        if(i == n){
            return 0;
        }
        return INT_MAX;
   }
   if(dp[i] != -1){
    return dp[i];
   }

   dp[i] = min(1 + solve(v,dp , i + 1 , n) , solve(v, dp , i + v[i] + 1, n));

    return dp[i];
}
int32_t main(){
    int t;cin>>t;
    while(t--){
        int n ; cin >> n;
        vector<int> v(n) ;
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
        }
        vector<int>dp(n,-1);

        int i = 0;
        int ans = solve(v,dp,i,n);
        cout<<ans<<endl;
    }
    return 0;
}