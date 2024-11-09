#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isPos(vector<int>&arr , int k , int time){
    int aux = 0;
    for(int i : arr){
        aux += (time / i);
        if(aux >= k){
            return true;
        }
    }
    return false;
}

int32_t main(){
    int n ; cin >> n;
    int k ; cin >> k;

    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }


    int ans = (int)1e18;
    int left = 0L;
    int right = ans;

    while(left <= right){
        int mid = left + (right - left)/2L;
        if(isPos(arr , k , mid)){
            ans = min(ans , mid);
            right = mid - 1L;
        }else{
            left = mid + 1L;
        }
    }

    cout<<ans<<endl;
    return 0;
}

/*
A factory has n machines which can be used to make products. Your goal is to make a total of t products.
For each machine, you know the number of seconds it needs to make a single product. 
The machines can work simultaneously, and you can freely decide their schedule.
What is the shortest time needed to make t products?
Input
The first input line has two integers n and t: the number of machines and products.
The next line has n integers k_1,k_2,\dots,k_n: the time needed to make a product using each machine.
Output
Print one integer: the minimum time needed to make t products.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le t \le 10^9
1 \le k_i \le 10^9

Example
Input:
3 7
3 2 5

Output:
8

Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.
*/