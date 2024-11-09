#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    vector<vector<int>> v(n , vector<int> (3));
    for(int i = 0 ; i < n ; i++){
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }

    sort(v.begin() , v.end() , [] (const auto & a , const auto & b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    });

    vector<int>contains (n , 0) , contained(n , 0);
    int max_r = 0;
    for(int i = 0 ; i < n ; i++){
        if(max_r >= v[i][1]){
            contained[v[i][2]] = 1;
        }
        max_r = max(max_r , v[i][1]);
    }

    max_r =  1e15;

    for(int i = n - 1 ; i >= 0 ; i--){
        if(max_r <= v[i][1]){
            contains[v[i][2]] = 1;
        }
        max_r = min(max_r , v[i][1]);
    }

    for(int i = 0 ; i < n ; i++){
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    for(int i = 0 ; i < n ; i++){
        cout<<contained[i]<<" ";
    }

    return 0;
}   

/*
Given n ranges, your task is to determine for each range if it contains some other 
range and if some other range contains it.
Range [a] contains range [c,d] if a <= c and d <= b.

Input
The first input line has an integer n: the number of ranges.
After this, there are n lines that describe the ranges. 
Each line has two integers x and y: the range is [x,y].
You may assume that no range appears more than once in the input.

Output
First print a line that describes for each range (in the input order) 
if it contains some other range (1) or not (0).
Then print a line that describes for each range (in the input order) 
if some other range contains it (1) or not (0).
Constraints

1 <= n <= 2 * 10^5
1 <= x < y <= 10^9

Example
Input:
4
1 6
2 4
4 8
3 6

Output:
1 0 0 0
0 1 0 1
*/