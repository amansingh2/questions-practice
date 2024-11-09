#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int H , W , N; cin >> H >> W >> N;

    vector<vector<int>>dp(H + 1 , vector<int>(W + 1 , 0));

    for(int i = 0; i < N ; i++){
        int x , y ; cin >> x >> y;
        dp[x][y] = -1;
    }
    dp[1][1] = 1;

    for(int i = 2 ; i <= W ; i++){
        if(dp[1][i] == -1){
            break;
        }
        dp[1][i] = 1;
    }
    for(int i = 2 ; i <= H ; i++){
        if(dp[i][1] == -1){
            break;
        }
        dp[i][1] = 1;
    }
    int mod = 1e9 + 7;

    for(int i = 2 ; i <= H ; i++){
        for(int j = 2 ; j <= W ; j++){
            if(dp[i][j] != -1){
                if(dp[i][j - 1] == -1 || dp[i - 1][j] == -1){
                    if(dp[i][j - 1] == -1 && dp[i - 1][j] == -1){
                        dp[i][j] = 0;
                    }else{
                        dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
                    }
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j - 1];
                    dp[i][j] %= mod;
                }
            }
        }
    }
    // cout<<dp[1][1]<<endl;

    // for(int i = 1 ; i <= H ; i++){
    //     for(int j = 1 ; j <= W ; j++){
    //       cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[H][W];
    return 0;
}


/*
Problem Statement 
There is a grid with H horizontal rows and W vertical columns. 
Let (i,j) denote the square at the i-th row from the top and the j-th column from the left. 
In the grid, N Squares (r1 ​ ,c1),(r2 ,c2 ), . . . ,(rN ,cN ) are wall squares, 
and the others are all empty squares. 
It is guaranteed that Squares (1,1) and (H,W) are empty squares. 
Taro will start from Square (1,1) and reach (H,W) by repeatedly moving right or down to an adjacent empty square. 
Find the number of Taro's paths from Square (1,1) to (H,W), modulo 10^9 +7. 


Constraints 
All values in input are integers. 
2 ≤ H , W ≤ 10^5 
1 ≤ N ≤ 3000 
1 ≤ ri ≤ H1 ≤ ci ≤ W Squares (ri , ci ) are all distinct. 
Squares (1,1) and (H,W) are empty squares. 

Input 
Input is given from Standard Input in the following format: 
H W N 
r1 c1
r2 c2
.  .
.  .
.  .
rN cN ​
*/