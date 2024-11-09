#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    vector<vector<int > > arr(n+1 , vector<int>(3,0)) , dp (n + 1 , vector<int>(3,0));

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }


    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < 3 ; j++){
            dp[i][j] = arr[i][j] + max(dp[i-1][(j+1)%3] , dp[i-1][(j+2)%3]);
        }
    }

    cout<<max(dp[n][0] , max(dp[n][1] , dp[n][2]))<<endl;

    return 0;
}