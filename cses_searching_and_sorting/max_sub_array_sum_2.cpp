#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , a , b ; cin >> n >> a >> b;
    vector<int> arr(n);
    for(int i =  0 ;  i < n  ; i++){
        cin >> arr[i];
    }
    int maxSum = -1e15;
/*
    // naive approach
    for(int i =  0 ; i < n ; i++){
        for(int len = a ; len <= b ; len++){
            if(i + len < n){
                int sum = 0;
                for(int x = i ;  x < i + len ; x++){
                    sum += arr[x];
                }
                if(sum > maxSum){
                    maxSum = sum;
                }
            }
        }
    }
*/
/*
    // using prefix sum
    vector<int> pref (n + 1 , 0);
    for(int i = 1 ; i <= n ; i++){
        pref[i] = pref[i - 1] + arr[i - 1];
    }
    // for(int i = 0 ; i <= n ; i++){
    //     cout<<pref[i]<<" ";
    // }
    // cout<<endl;
    for(int i = 1 ; i <= n ; i++){
        for(int len = a ; len <= b ; len++){
            if(i + len <= n){
                int sum = pref[i + len - 1] - pref[i - 1];
                if(sum > maxSum){
                    // if(sum == 182){
                    //     cout<<pref[i + len ]<<"  "<< pref[i - 1]<<"  " <<i<<" "<<i + len << endl;;
                    // }
                    maxSum = sum;
                }
            }
        }
    }
*/

    // we can use set to do it
    // erase at i + a , insert at i + b + 1 then increment i -> i + 1
    /*

    vector<int> pref (n + 1);
    for(int i = 1 ; i <= n ; i++){
        pref[i] = pref[i - 1] + arr[i - 1];
    }

    set<pair<int , int> > st;


    for(int i = a; i<= b ; i++){
        st.insert({pref[i] , i});
    }

    for(int i = 1 ; i <= n - a + 1 ; i++){
        int sum = st.rbegin()->first - pref[i - 1];
        maxSum = max(maxSum , sum);
        st.erase({pref[i + a -1] , i + a - 1});
        if(i + b <= n){
            st.insert({pref[i + b] , i + b});
        }
    }
    */

    // using deque , we can solve it as well !

    list<int> ls;
    vector<int> pref (n + 1);
    for(int i = 1 ; i <= n ; i++){
        pref[i] = pref[i - 1] + arr[i - 1];
    }
    for(int i = a ; i <= b ; i++){
        while(ls.size() > 0 && ls.back() < pref[i]){
            ls.pop_back();
        }
        ls.push_back(pref[i]);
    }

    for(int i = 1 ; i <= n - a + 1 ; i++){

        int sum = ls.front() - pref[i - 1];
        // cout<<sum<<endl;
        maxSum = max(sum , maxSum);
        if(pref[i + a - 1] == ls.front()){
            ls.pop_front();
        }
        while(i + b <= n && ls.size() > 0 && ls.back() < pref[i + b]){
            ls.pop_back();
        }
        if(i + b <= n){
            ls.push_back(pref[i + b]);
        }
    }


    cout<<maxSum<<endl;
    return 0;
}
/*
Given an array of n integers, your task is to find the maximum sum of values in a contiguous subarray 
with length between a and b.
Input
The first input line has three integers n, a and b: the size of the array and 
the minimum and maximum subarray length.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Output
Print one integer: the maximum subarray sum.
Constraints

1 <= n <= 2 * 10^5 
1 <= a <= b <= n
-10^9 <= x_i <= 10^9

Example
Input:
8 1 2
-1 3 -2 5 3 -5 2 2

Output:
8
*/