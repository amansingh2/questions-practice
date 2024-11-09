#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
1 , 99 , 100
mean -> 67 / 66 
67 -> (100 - 67) + (99 - 67) + (67 - 1) -> 33 + 32 + 66 -> 131
66 -> (100 - 66) + (99 - 66) + (66 - 1) -> 34 + 33 + 65 -> 132
median = 99 -> (100 - 99) + (99 - 99) + (99 - 1) -> 1 + 0 + 98 -> 100
*/

int32_t main(){
    int n ; cin >> n;
    int k ; cin >> k;
 
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
 
    multiset<int> left , right;
    int ls = 0 , rs = 0;

    for(int i = 0 ; i < n  ; i++){
        if(i >= k){
            if(left.find(arr[i - k]) != left.end()){
                left.erase(left.find(arr[i - k]));
                ls -= arr[i - k];
            }else{
                right.erase(right.find(arr[i - k]));
                rs -= arr[i - k];
            }
        }
        left.insert(arr[i]);
        ls += arr[i];

        right.insert(*left.rbegin());
        rs += (*left.rbegin());

        ls -= *prev(left.end());
        left.erase(prev(left.end()));
 
        if(left.size() < right.size()){
            left.insert(*right.begin());
            ls += *right.begin();
            rs -= *right.begin();
            right.erase(right.begin());
        }
        if(i + 1 >= k){
            // cout<<*(left.rbegin())<<" ";
            int median = *(left.rbegin());
            cout << median * (left.size()) - ls + rs - median * (right.size())<<" ";
        }
    }
    
    return 0;
}
/*
You are given an array of n integers. Your task is to calculate for each window of k elements, 
from left to right, the minimum total cost of making all elements equal.
You can increase or decrease each element with cost x where x is the difference between the new and the 
original value. The total cost is the sum of such costs.
Input
The first input line contains two integers n and k: the number of elements and the size of the window.
Then there are n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Output n-k+1 values: the costs.
Constraints

1 \le k \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9

Example
Input:
8 3
2 4 3 5 8 1 2 1

Output:
2 2 5 7 7 1
    
    

*/