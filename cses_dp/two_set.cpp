#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;

    int sum = (n * (n + 1)) / 2;

    if(sum % 2 == 1){
        cout<<0;
        return 0;
    }

    sum /= 2;

    // vector<int> dp(sum + 1 , 0);
    // dp[0] = 1;
    vector<vector<int> > dp(n + 1 , vector<int> (sum + 1 , 0 ) );
    dp[0][0] = 1;
    int mod = 1e9 + 7;

    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = sum ; j >= 0 ; j--){
    //         if(j + i <= sum){
    //             dp[j + i] += dp[j];
    //             dp[j + i] %= mod;
    //         }
    //     }
    // }
    // for(int i : dp){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= sum ; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - i >= 0){
                dp[i][j] += dp[i - 1][j - i];
                dp[i][j] %= mod;
            }
        }
    }
    // for(auto i : dp){
    //     for(int j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[n][sum]<<endl;

    return 0;
}