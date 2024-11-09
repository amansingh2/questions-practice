#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){

    int n; cin >> n;

    int k;
    vector<int>pos(n);

    for(int i = 0 ; i < n ; i++){
        cin >> k;
        k--;
        pos[k] = i;
    }
    int ans = 1;

    for(int i = 0 ; i < n - 1; i++){
        ans += (pos[i] > pos[i + 1]);
    }

    cout<<ans<<endl;

    return 0;
}


/*
You are given an array that contains each number between 1 \dots n exactly once. 
Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible. 
What will be the total number of rounds?
Input
The first line has an integer n: the array size.
The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
Output
Print one integer: the number of rounds.
Constraints

1 <= n <= 2 * 10^5

Example
Input:
5
4 2 1 5 3

Output:
3
*/