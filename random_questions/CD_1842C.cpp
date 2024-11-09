#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[1000000];
int solve(vector<int> & arr , int i , int n ,int val, int res){
    if(i > n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int ans2 = 0;
    int ans1 = 0;

    if(arr[i] == val){
        ans1 = res + max(solve(arr,i+1,n,0,0) , solve(arr , i + 1 , n , val , res + 1));
    }else{
        ans2 = max(solve(arr,i+1,n,0,0) , solve(arr , i + 1 , n , val , res + 1));
    }

    return dp[i] = max(ans1 , ans2);
}
int32_t main(){
    int t;cin>>t;
    while(t--){
        int n ; cin >> n;
        vector<int>arr(n+1);
        for(int i = 1 ; i <= n ; i++){
            cin>>arr[i];
        }
        memset(dp,-1,sizeof (dp));
        int ans = solve(arr,1,n,0,0);
        cout<<ans<<endl;

    }
    return 0;
}