#include <bits/stdc++.h>
#define int long long
using namespace std;


int dp[20][10][2][2];
int solve(string & num , int n , int x , bool leading_zeros , bool tight){
    if(n == 0){
        return 1;
    }
    if(x != -1 && dp[n][x][leading_zeros][tight] != -1){
        return dp[n][x][leading_zeros][tight];
    }
    int lb = 0;
    int ub = tight ? (num[num.size() - n] - '0')  : 9;

    int ans = 0;

    for(int dig = lb ; dig <= ub ; dig++){
        if(dig == x && leading_zeros == 0){ // 0 -> means false;
            continue;
        }
        ans += solve(num , n - 1 , dig , (leading_zeros & dig == 0) , (tight & dig == ub));
    }
    return dp[n][x][leading_zeros][tight] = ans;
}

int32_t main(){
    int t = 1;
    while(t--){
        int a, b ; cin >> a >> b;
        memset(dp , -1 , sizeof(dp));
        string A = to_string(a  - 1);
        string B = to_string(b);
        int ans1 = solve(B , B.size() , -1 , 1 , 1);
        memset(dp , -1 , sizeof(dp));
        int ans2 = solve(A , A.size() , -1 , 1 , 1);
        cout<<ans1 - ans2<<endl;
    }
    return 0;
}

/*
Your task is to count the number of integers between a and b where no two adjacent digits are the same.
Input
The only input line has two integers a and b.
Output
Print one integer: the answer to the problem.
Constraints

0 <= a <= b <= 10^18

Example
Input:
123 321

Output:
171

*/
    
    
