#include <bits/stdc++.h>
#define int long long
using namespace std;
 
 
 
int32_t main(){
    int n ; cin >> n;
    int k ; cin >> k;
 
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
 
    multiset<int> left , right;
 
    for(int i = 0 ; i < n  ; i++){
        if(i >= k){
            if(left.find(arr[i - k]) != left.end()){
                left.erase(left.find(arr[i - k]));
            }else{
                right.erase(right.find(arr[i - k]));
            }
        }
        left.insert(arr[i]);
        right.insert(*left.rbegin());
        left.erase(prev(left.end()));
 
        if(left.size() < right.size()){
            left.insert(*right.begin());
            right.erase(right.begin());
        }
 
        
        if(i + 1 >= k){
            cout<<*(left.rbegin())<<" ";
        }
    }
    
    return 0;
}
 
/*
You are given an array of n integers. Your task is to calculate the median of each window of k elements, 
from left to right.
The median is the middle element when the elements are sorted. 
If the number of elements is even, there are two possible medians and we assume that the median is 
the smaller of them.
Input
The first input line contains two integers n and k: the number of elements and the size of the window.
Then there are n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print n-k+1 values: the medians.
Constraints
 
1 \le k \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9
 
Example
Input:
8 3
2 4 3 5 8 1 2 1
 
Output:
3 4 5 5 2 1
    
    
 
*/