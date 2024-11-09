#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    vector<int>arr(n+1,0) , dp(n+1,0);
    for(int i = 1;  i <= n ; i++){
        cin >> arr[i];
    }

    if(n == 1){
        cout<<0<<endl;
        return 0;
    }
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(arr[2] - arr[1]);

    for(int i = 3 ; i <= n ; i++){
        dp[i] = min(dp[i-1] + abs(arr[i] - arr[i-1]) , dp[i-2] + abs(arr[i] - arr[i-2]));
    }

    cout<<dp[n]<<endl;

    
    return 0;
}