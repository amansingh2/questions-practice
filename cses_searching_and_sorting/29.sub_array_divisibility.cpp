#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        arr[i] %= n;
        arr[i]  = (arr[i] + n) % n;
    }

    int ans = 0 ;
    map<int , int > mp;
    mp[0]++;
    int cs = 0 ;
    for(int i = 0  ; i < n ; i++){
        cs += arr[i];
        cs %= n;
        ans += mp[cs];
        mp[cs]++;

    }

    cout<<ans<<endl;



    

    
    return 0;
}
/*
Given an array of n integers, your task is to count the number of 
subarrays where the sum of values is divisible by n.
Input
The first input line has an integer n: the size of the array.
The next line has n integers a_1,a_2,\dots,a_n: the contents of the array.
Output
Print one integer: the required number of subarrays.
Constraints

1 \le n \le 2 \cdot 10^5
-10^9 \le a_i \le 10^9

Example
Input:
5
3 1 2 7 4

Output:
1
*/