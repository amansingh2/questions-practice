#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
void brute_force_kaam_karta_hua(){
     // len , sum , 
    // map<pair<int , int > , >
    // sum , len!


    // len sum
    // map<int , int > dp;
    // dp[0] = 0;
    //      len....sum.....cnt;

    map< pair<int , int > , int >dp;
    dp[{0 , 0}] = 1;

    for(int i : arr){
        map< pair<int , int > , int > n_dp = dp;
        for(auto [a , b] : dp){
            n_dp[{a.first + i , a.second + 1}] += dp[{a.first , a.second}];
        }
        dp = n_dp;
        // dp[{0 , 0 }] = 1;
    }
    for(auto [a , b] : dp){
        if(a.first == k){
            cout<<a.second<<"  "<<b<<endl;
        }
    }

    // for(int i = 0 ; i <= n ; i++){
    //     cout<<i<<" --> "<<dp[n][k][i]<<endl;
    // }

}
*/

void solve(vector<int> & arr , int k){
    int n = arr.size();

        // ele....sum....len!!
    // int dp[n + 1][k + 1][n + 1];
    // vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>> (k + 1 , vector<int> (n + 1 , 0)));
    // for(int i = 0 ; i <= n ; i++){
    //     dp[i][0][0] = 1;
    // }


    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = k ; j >= 0 ; j--){
    //         if(nums[])
    //     }
    // }

    // vector<vector<int>> dp (n + 1 , vector<int> (k + 1 , 0));

    // for(int i = 0 ; i <= n ; i++){
    //     dp[i][0] = 1;
    // }

    // for(int i : arr){
    //     for(int j = k ; j >= 0 ; j--){
    //         if(j - i >= 0){
    //             for(int l = n ; l >= 1 ; l--){
    //                 dp[l][j] += dp[l - 1][j - i];
    //             }
    //         }
    //     }
    // }

    // vector<vector<int > > dp (k + 1 , vector<int> ());
    vector<map<int , int> > dp (k + 1);
    // dp[0].push_back(0);
    dp[0][0]++;

    for(int i : arr){
        for(int j = k ; j >= 0  ; j--){
            if(j - i >= 0){
                // vector<int> v = dp[j - i];
                for(auto [a , b] : dp[j - i]){
                    dp[j][a + 1] += b;
                }
                // for(auto it : dp[j]){
                //     v.push_back(it);
                // }
                // dp[j] = v;
            }
        }
    }

    // for(int i = 0 ; i <= n ; i++){
    //     cout<<i<<" --> "<<dp[i][k]<<endl;
    // }
    vector<int> sz(n + 1 , 0);
    for(auto [a , b] : dp[k]){
        // cout<<i<<" ";
        sz[a] = b;
    }
    for(int i = 0 ; i < n ; i++){
        cout<<i<<" --> "<<sz[i]<<endl;
    }
}

int32_t main(){
    int n , k ; cin >> n >> k;
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    solve(arr , k);




    return 0;
}