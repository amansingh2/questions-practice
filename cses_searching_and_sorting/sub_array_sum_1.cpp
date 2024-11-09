#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , x ; cin >> n >> x;
    vector<int>arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int ans = 0;
    int curr_sum = 0;
    for(int i = 0, j = 0 ; i < n ; i++){
        curr_sum += arr[i];
        while(curr_sum > x){
            curr_sum -= arr[j];
            j++;
        }
        if(curr_sum == x){
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}


/*
Given an array of n positive integers, your task is to count the number of subarrays having sum x.
Input
The first input line has two integers n and x: the size of the array and the target sum x.
The next line has n integers a_1,a_2,\dots,a_n: the contents of the array.
Output
Print one integer: the required number of subarrays.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x,a_i \le 10^9

Example
Input:
5 7
2 4 1 2 7

Output:
3

*/