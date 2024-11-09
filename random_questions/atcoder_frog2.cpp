#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
        int n , k ; cin >> n >> k;
        vector<int> arr(n+1,0) , dp (n+1,0);
        dp[0] = INT_MAX;
        for(int i = 1;  i <= n ; i++){
            cin >> arr[i];
        }
        dp[1] = 0;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = INT_MAX;
            for(int j = 1 ; j <= k && (i - j) >= 1 ; j++){
                dp[i] = min(dp[i] , dp[i - j] + abs(arr[i] - arr[i - j]));
            }
        }


        cout<<dp[n]<<endl;

    return 0;
}