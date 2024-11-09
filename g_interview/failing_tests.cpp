#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isValid(vector<int> arr , int i , int j){
    set<int>st;
    for(int it = i ; it <= j ; it++){
        st.insert(it);
    }
    if(st.count(1) && st.count(4)){
        return true;
    }
    return false;
}
int solve()
int32_t main(){
    int n ; cin >> n;
    vector<int>arr(n);
    for(int i  = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    return 0;
}

/*
You are given n tests numbered from 1, 2, 3.... N. Each test passes individually, 
but there are two tests which when ran together fails. 
You can call a function testSuite() and pass any number of test as you want.

For example :
Given N = 5,
1, 2, 3, 4, 5

Lets say 1 and 4 are failing tests.

If you ran testSuite([1, 2, 3, 4, 5]) -> fail
If you ran testSuite([1, 2, 3]) -> pass
If you ran testSuite([1, 2, 4]) -> fail
Likewise, testSuite([1, 4]) -> fail

Can you write a algorithm (better than O(N^2) ofcourse) to find the failing tests?
*/