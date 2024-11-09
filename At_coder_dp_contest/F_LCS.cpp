#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    string s , t ; cin >> s >> t;
    int n = s.size() , m = t.size();

    vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , 0));


    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }


    // cout<<dp[n][m];

    string res;

    int i = n , j = m;
    while(i >= 1 && j >= 1){
        if(s[i - 1] == t[j - 1]){   // dp[i][j] == (1 + dp[i-1][j-1]) galat hai socho kyu ? 
            res.push_back(s[i-1]);
            i--;
            j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }

    reverse(res.begin() , res.end());

    cout<<res;




    return 0;
}

/*
Problem Statement 
You are given strings s and t. 
Find one longest string that is a subsequence of both s and t. 

Notes A subsequence of a string x is the string obtained by removing 
zero or more characters from x and concatenating the remaining characters without 
changing the order. 

Constraints 
s and t are strings consisting of lowercase English letters. 
1 ≤ ∣s∣,∣t∣ ≤ 3000


Input
Input is given from Standard Input in the following format:
s
t

*/