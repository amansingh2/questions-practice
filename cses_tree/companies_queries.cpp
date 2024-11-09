#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
   int n , q;cin >> n >> q;
   vector<vector<int>>dp(n + 1 , vector<int>(21 , -1));

   for(int i = 2 ; i <= n  ; i++){
    cin >> dp[i][0];
   }
   for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= 20  ; j++){
        if(dp[i][j-1] != -1){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
   }

   while(q-- > 0){
    int node , k; cin >> node >> k;
    for(int j = 20; j >= 0; j--) {
        if(k >= (1 << j)) {
            node = dp[node][j];
            k -= (1 << j);
            if(node == -1){
                break;
            }
        }
    }
    cout<<node<<endl;
   }
    return 0;
}