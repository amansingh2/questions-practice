#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    vector<double>arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    vector<vector<double>>dp(n+1 , vector<double>(n , 0.0));

    // probability of getting 0 heads after tossing only the first coin.
    dp[0][0] = 1.0 - arr[0];

    // probability of getting 1 head after tossing only the first coin.
    dp[1][0] = arr[0];

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i > 0 && j > 0){
                dp[i][j] = dp[i-1][j-1]*arr[j];
            }
            if(j > 0){
                dp[i][j] += dp[i][j-1]*(1 - arr[j]);
            }
        }
    }

    double ans = 0.0;

    for(int i = n/2 + 1 ; i <= n ; i++){
        ans += dp[i][n-1];
    }
    cout.precision(10);
    cout<<ans<<endl;

    
    return 0;
}

/*
Problem Statement 
Let N be a positive odd number. There are N coins, numbered 1,2, . . . ,N. For each i(1 ≤ i ≤ N), 
when Coin i is tossed, it comes up heads with probability pi and tails with probability 1−pi. 
Taro has tossed all the N coins. 
Find the probability of having more heads than tails. 

Constraints 
N is an odd number. 
1 ≤ N ≤ 2999 
pi is a real number and has two decimal places. 
0 < pi ​< 1 

Input 
Input is given from Standard 

Input in the following format: 
N 
p1 ​ p2 . . .  pN

*/