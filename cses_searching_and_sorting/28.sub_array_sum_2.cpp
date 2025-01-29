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

    map<int , int >mp;
    int curr_sum  = 0;

    for(int i = 0 ; i < n ; i++){
        curr_sum += arr[i];
        int req = curr_sum - x;
        if(curr_sum == x){
            ans++;
        }
        if(mp.find(req) != mp.end()){
            ans += mp[req];
        }
        mp[curr_sum]++;
    }

    cout<<ans<<endl;

    return 0;
}


/*
Given an array of n integers, your task is to count the 
number of subarrays having sum x.
Input
The first input line has two integers n and x: 
the size of the array and the target sum x.
The next line has n integers a_1,a_2,\dots,a_n: 
the contents of the array.
Output
Print one integer: the required number of subarrays.
Constraints

1 \le n \le 2 \cdot 10^5
-10^9 \le x,a_i \le 10^9

Example
Input:
5 7
2 -1 3 5 -2

Output:
2
    
    

*/