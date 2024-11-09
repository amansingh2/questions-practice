#include <bits/stdc++.h>
using namespace std;
int dp[3001][3001];
// vector<vector<int> > dp(3001 , vector<int>(3001,0));
int main(){
    string s , t ; cin >> s >> t;

    int n = s.size();
    int m = t. size();
    // memset(dp , 0 , sizeof (dp));
    for(int i = 0; i <= max(m,n) ; i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    string ans;
    for(int i = n ; i >= 1 ;){
        for(int j = m ; j >= 1 ;){
            if(s[i-1] == t[j-1]){
                ans += s[i-1];
                i--;
                j--;
            }else if(dp[i][j-1] > dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }

    reverse(ans.begin() , ans.end());

    cout<<ans<<endl;

    return 0;
}