#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(vector<int> & arr , int l , int r){
    if(l == r){
        for(int i : arr){
            cout<<i<<" ";
        }
        cout<<endl;
        return ;
    }
    for(int i = l ; i <= r ; i++){
        swap(arr[i] , arr[l]);
        solve(arr , l + 1 , r);
        swap(arr[i] , arr[l]);
    }
}
int32_t main(){
    int n ; cin >> n;

    vector<int>arr;
    for(int i = 0 ; i < n ; i++){
        arr.push_back(i + 1);
    }
    solve(arr , 0 , n - 1);
    return 0;
}