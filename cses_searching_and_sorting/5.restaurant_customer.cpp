#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve1(){ // using sorted array
    int n ; cin >> n;
    vector<int>arr(n) ,dep(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        cin >> dep[i];
    }
    sort(arr.begin() , arr.end());
    sort(dep.begin() , dep.end());
    int ans = 0;
    int curr_max  = 0;
    int i = 0 , j = 0;

    while(i < n && j < n){
        if(arr[i] < dep[j]){
            curr_max++;
            i++;
        }else {
            curr_max--;
            j++;
        }
        ans = max(ans , curr_max);
    }
    cout<<ans<<endl;
}
void solve2(){    // using map!
    int n ; cin >> n;
    // vector<int>arr(n) ,dep(n);
    map<int , int>mp;

    for(int i = 0 ; i < n ; i++){
        int a , b ; cin >> a >> b;
        mp[a] += 1;
        mp[b + 1] -= 1;
    }

    int ans = 0;
    int back = 0;

    for(auto [a , b] : mp){
        b += back;
        back = b;
        ans = max(ans , back);
    }
    cout<<ans<<endl;


}
int32_t main(){
    solve2();




    return 0;
}


/*
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?

Input
The first input line has an integer n: the number of customers.
After this, there are n lines that describe the customers. 
Each line has two integers a and b: the arrival and leaving times of a customer.
You may assume that all arrival and leaving times are distinct.

Output
Print one integer: the maximum number of customers.

Constraints
1 <= n <= 2 * 10^5
1 <= a < b <= 10^9

Example

Input:
3
5 8
2 4
3 9

Output:
2
*/