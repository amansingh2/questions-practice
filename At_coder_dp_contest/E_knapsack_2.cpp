#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int N , W ; cin >> N >> W;
    vector<pair<int,int>>vp(N);

    for(int i = 0 ; i < N ; i++){
        cin >> vp[i].first;  // weight
        cin >> vp[i].second; // value
    }

    vector<int>dp(1e5 + 5 , 1e11);
    dp[0] = 0;

    for(int i = 0 ; i < N ; i++){
        for(int v = 1e5 ; v >= vp[i].second ; v--){
            dp[v] = min(dp[v] , dp[v - vp[i].second] + vp[i].first);
        }
    }

    int ans = 0;
    for(int i = 1 ; i <= 1e5 ; i++){
        if(dp[i] <= (W)){
            ans = i;
        }
    }

    cout<<ans<<endl;

    

    return 0;
}

/*
There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wi ​ and a value of vi. 
Taro has decided to choose some of the N items and carry them home in a knapsack. 
The capacity of the knapsack is W, which means that the sum of the weights of items taken must be at most W. 
Find the maximum possible sum of the values of items that Taro takes home.


Constraints All values in input are integers. 
1 ≤ N ≤ 100 
1 ≤ W ≤ 10^9
1 ≤ wi ≤ W 
1 ≤ vi ​ ≤ 10^3




Input Input is given from Standard Input in the following format: 
N W 
w1 ​ v1
w2 ​ v2
*/