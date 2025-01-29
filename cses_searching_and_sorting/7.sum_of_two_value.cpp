#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , x ; cin >> n >> x; // array size and target value!

    vector<int>arr(n,0);
    map<int , int>mp;
    // k + arr[i] == target => k = (target - arr[i])
    for(int i = 0 ;  i < n ; i++){
        cin >> arr[i];
        int k = x - arr[i];
        if(mp.find(k) != mp.end()){
            cout<<mp[k] + 1 << " "<< i + 1<<endl;
            return 0;
        }
        mp[arr[i]] = i;
    }

    cout<<"IMPOSSIBLE"<<endl;
   
    return 0;
}


/*
You are given an array of n integers, and your task is to find two values (at distinct positions) 
whose sum is x.
Input:
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,....,a_n: the array values.

Output
Print two integers: the positions of the values. 
If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints

1 <= n <= 2 * 10^5
1 <= x,a_i <= 10^9

Example
Input:
4 8
2 7 5 1

Output:
2 4
*/