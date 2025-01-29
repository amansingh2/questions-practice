#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isPos(vector<int> & arr , int k ,  int sum){
    int curr_sum = 0;
    int n = arr.size();
    int part = 1;
    for(int i = 0 ; i < n ; i++){
        curr_sum += arr[i];
        if(curr_sum > sum){
            if(arr[i] > sum){
                return false;
            }
            curr_sum = arr[i];
            part++;
        }

        if(part > k){
            return false;
        }
    }
    return part <= k;
}
int32_t main(){
    int n , k ; cin >> n >> k;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    
    int ans = (int)1e16;
    int right = ans;
    int left = 0;
    while(left <= right){
        int mid = (left + right)/2;
        if(isPos(arr , k , mid)){
            ans = min(ans , mid);
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}

/**
 You are given an array containing n positive integers.
Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.
Input
The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.
The next line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print one integer: the maximum sum in a subarray in the optimal division.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le k \le n
1 \le x_i \le 10^9

Example
Input:
5 3
2 4 7 3 5

Output:
8

Explanation: An optimal division is [2,4],[7],[3,5] where the sums of the subarrays are 6,7,8. The largest sum is the last sum 8.
*/