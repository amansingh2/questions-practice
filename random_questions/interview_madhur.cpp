#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[1001][1001];

int solve(int n , int m , string &s , string &t ,int i , int j){
    if(i == n || j == m){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s[i] == t[j]){
        return dp[i][j] =  1 + solve(n , m , s , t , i + 1 , j + 1);
    }else{
        return dp[i][j] = max(solve(n , m , s , t , i , j + 1) ,
        solve(n , m , s , t , i + 1, 0));
    }

}

int32_t main(){
    string s , t;
    cin >> s >> t;
    memset(dp , -1 , sizeof(dp));
    cout<<solve(s.size() , t.size() , s , t , 0 , 0);
    return 0;
}