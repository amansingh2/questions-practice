#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;cin>>t;
    while(t--){
        int m , x ; cin >> m >> x;
        // m -> nunber of months
        // x -> monthly salary
        int mx = 1e15;

        vector<int> cost(m) , happiness(m);

        int max_happiness  = 0;

        for(int i = 0 ; i < m ; i++){
            cin >> cost[i];
            cin >> happiness[i];
            max_happiness += happiness[i];
        }

        vector<int> dp (max_happiness + 1 , mx);
        dp[0] = 0LL;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = max_happiness ; j >= happiness[i] ; j--){
                if(dp[j - happiness[i]] + cost[i] <= i * x){
                    dp[j] = min(dp[j] , dp[j - happiness[i]] + cost[i]);
                }
            }
        }

        for(int i = max_happiness ; i >= 0 ; i--){
            if(dp[i] != mx){
                cout<<i<<endl;
                break;
            }
        }

    }
    return 0;
}
/*

For the 𝑖 -th month (1≤𝑖≤𝑚), there'll be a single opportunity of paying cost 𝑐𝑖 pounds 
to obtain happiness ℎ𝑖.

Borrowing is not allowed. Money earned in the 𝑖-th month can only be spent in a later 𝑗-th month (𝑗>𝑖).

1 <= m <= 50 
1 <= x <= 10^8
1 <= ci <= 10^8 
1 <= hi <= 10^3

output
print the maximum sum of happiness Charlie could obtain.



*/