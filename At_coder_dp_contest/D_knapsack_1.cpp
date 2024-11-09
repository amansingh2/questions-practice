#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int N , W ; cin >> N >> W;
    vector<pair<int,int>>vp(N);

    for(int i = 0 ; i < N ; i++){
        cin >> vp[i].first;
        cin >> vp[i].second;
    }

    vector<int>dp(W + 1 , 0);

    for(int i = 0 ; i < N ; i++){
        for(int w = W ; w >= vp[i].first ; w--){
            dp[w] = max(dp[w - vp[i].first] + vp[i].second , dp[w]);
        }
    }

    cout<<dp[W]<<endl;

    return 0;
}

/*
There are N items, numbered 1,2,…,N. For each i ( 1≤i≤N), Item i has a weight of wi ​ and a value of vi. 
Taro has decided to choose some of the N items and carry them home in a knapsack. 
The capacity of the knapsack is W, which means that the sum of the weights of items taken must be at most W. 
Find the maximum possible sum of the values of items that Taro takes home.


Constraints All values in input are integers. 
1≤N≤100 
1≤W≤100000 
1≤wi≤ W 
1 ≤ vi ​ ≤ 10^9




Input Input is given from Standard Input in the following format: 
N W 
w1 ​ v1
w2 ​ v2
*/