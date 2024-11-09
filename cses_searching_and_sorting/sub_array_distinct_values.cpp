#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , k ; cin >> n >> k;

    vector<int>arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int ans = 0;

    map<int,int>mp;

    for(int i = 0 , j = 0 ; i < n ; i++){
        mp[arr[i]]++;
        while((int)mp.size() > k){
            mp[arr[j]]--;
            if(mp[arr[j]] == 0){
                mp.erase(arr[j]);
            }
            j++;
        }
        ans += (i - j + 1);
    }

    cout<<ans<<endl;
    return 0;
}
/*
Given an array of n integers, your task is to calculate the number of subarrays that have at most k distinct values.
Input
The first input line has two integers n and k.
The next line has n integers x_1,x_2,\dots,x_n: the contents of the array.
Output
Print one integer: the number of subarrays.
Constraints

1 \le k \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9

Example
Input:
5 2
1 2 3 1 1

Output:
10
*/