#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    set<int>st;

    for(int i = 0 ; i < n ; i++){
        int x ;
        cin >> x;
        st.insert(x);
    }

    cout<<(int)st.size()<<endl;

    return 0;
}


/*
You are given a list of n integers, and your task is to calculate the number of distinct values in the list.
Input
The first input line has an integer n: the number of values.
The second line has n integers x_1,x_2,.....,x_n.

Output
Print one integers: the number of distinct values.
Constraints

1 <= n <= 2 .... 10^5
1 <= x_i <= 10^9

Example
Input:
5
2 3 2 2 3

Output:
2
*/