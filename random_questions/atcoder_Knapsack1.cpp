#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , w ; cin >> n >> w;
                  //weight value
    vector<pair < int, int > arr (n+1);

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i].first >> arr[i].second << endl;
    }

    vector<int>dp(n+1 , 0);


    for(int i = 1 ; i <= w ; i++){
        for(int j  = 1 ; j <= n ; j++){
            if(i - arr[i].first >= 0){
                dp[i] = max(dp[i] , )
            }
        }
    }





    return 0;
}