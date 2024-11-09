#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ;  cin >> n;
    vector<int>arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int curr_sum = 0;
    int ans = INT_MIN;

    for(int i = 0 ; i < n  ; i++){
        curr_sum += arr[i];
        ans = max(ans , curr_sum);
        if(curr_sum <= 0){ // think for the ordering of this , that matter ans solves 2 problems!
            curr_sum  = 0;
        }
    }

    cout<<ans<<endl;

    return 0;
}