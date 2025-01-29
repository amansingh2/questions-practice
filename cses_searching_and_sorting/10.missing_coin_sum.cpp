#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    vector<int>arr(n , 0);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    sort(arr.begin() , arr.end());
    int ans = accumulate(arr.begin() , arr.end() , 0LL) + 1;

    int curr_max = 0;


    for(int i = 0 ; i < n ; i++){
        if(curr_max + 1 < arr[i]){
            ans = min(ans , curr_max + 1);
        }
        curr_max += arr[i];
    }


    cout<<ans<<endl;;

    
    return 0;
}


/*
You have n coins with positive integer values. What is the smallest sum you cannot create using a 
subset of the coins?

Input
The first input line has an integer n: the number of coins.
The second line has n integers x_1,x_2,....,x_n: the value of each coin.

Output
Print one integer: the smallest coin sum.

Constraints:
1 <= n <= 2 * 10^5
1 <= x_i <= 10^9

Example
Input:
5
2 9 1 2 7

Output:
6
*/