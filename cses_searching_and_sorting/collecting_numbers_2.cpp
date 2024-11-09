#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
->1 to n , numbers given exactely once
->our task is to calculate numbers in increasing order
-> Given m operations that swap two numbers in the array, task is to report the number of rounds after 
each operation.
*/
int32_t main(){
    int n , q ; cin >> n >> q;
    vector<int>arr(n + 1);
    vector<int> pos(n + 1);

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int ans = 1;

    for(int i = 1 ; i < n ; i++){
        ans += (pos[i] > pos[i + 1]);
    }

    set<pair<int,int>>st;

    while(q--){
        int l , r ; cin >> l >> r;

        if(arr[l] + 1 <= n){
            st.insert({arr[l] , arr[l] + 1});
        }
        if(arr[l] - 1 >= 1){
            st.insert({arr[l] - 1 , arr[l]});
        }

        if(arr[r] + 1 <= n){
            st.insert({arr[r] , arr[r] + 1});
        }
        if(arr[r] - 1 >= 1){
            st.insert({arr[r] - 1, arr[r]});
        }

        for(auto it : st){
            ans -= (pos[it.first] > pos[it.second]);
        }
        swap(arr[l] , arr[r]);

        pos[arr[l]] = l;
        pos[arr[r]] = r;

        for(auto it : st){
            ans += (pos[it.first] > pos[it.second]);
        }

        cout<<ans<<endl;

        st.clear();




    }


    return 0;
}
/*
You are given an array that contains each number between 1 \dots n exactly once. 
Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible.
Given m operations that swap two numbers in the array, your task is to report the number of rounds after 
each operation.

Input
The first line has two integers n and m: the array size and the number of operations.
The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
Finally, there are m lines that describe the operations. 
Each line has two integers a and b: the numbers at positions a and b are swapped.
Output
Print m integers: the number of rounds after each swap.
Constraints

1 \le n, m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
4 2 1 5 3
2 3
1 5
2 3

5C2 -> 10 , noI -> 5
Output:
2
3
4
*/