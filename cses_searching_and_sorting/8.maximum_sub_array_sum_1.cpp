#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ;  cin >> n;
    vector<int>arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int curr_sum = 0;
    int ans = INT_MIN;

    for(int i = 0 ; i < n  ; i++){
        curr_sum += arr[i];
        ans = max(ans , curr_sum);
        if(curr_sum <= 0){ // think for the ordering of this , that matter ans solves 2 problems!
            curr_sum  = 0;
        }
    }

    cout<<ans<<endl;

    return 0;
}

/*
Given an array of n integers, your task is to find the maximum sum of values in a contiguous, 
nonempty subarray.

Input
The first input line has an integer n: the size of the array.
The second line has n integers x_1,x_2,.......,x_n: the array values.

Output
Print one integer: the maximum subarray sum.
Constraints:
1 <= n <= 2 * 10^5
-10^9 <= x_i <= 10^9

Example
Input:
8
-1 3 -2 5 3 -5 2 2
Output:
9
*/