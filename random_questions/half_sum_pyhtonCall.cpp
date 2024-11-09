#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(vector<int> & arr){
    int n = arr.size();
    int ans = -1;
    int total_sum = accumulate(arr.begin() , arr.end() , 0);
    int left_sum = 0;
    for(int i = 0 ; i < n ; i++){
        left_sum += arr[i];
        if(2*left_sum == total_sum){
            ans = i;
        }
    }
    return ans;
}

int32_t main(){
    int n ; cin >> n;
    vector<int>arr(n,0);
    for(int i = 0  ; i < n  ; i++){
        cin >> arr[i];
    }
    cout<<solve(arr) << endl;
    return 0;
}