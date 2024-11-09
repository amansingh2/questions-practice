#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(vector<int> & arr){
    int id_0 = -1;
    int id_1 = -1;
    
    for(int i : arr){
        arr[++id_1] = 1;
        if(i == 0){
            arr[++id_0] = 0;
        }
    }
    for(int i : arr){
        cout<<i<<" ";
    }

}

int max_len(vector<int> & arr){
    int len = 0;
    int cs = 0;
    int ans = 0;

    for(int i : arr){
        cs += i;
        len++;
        if(cs <= 0){
            cs = 0;
            len = 0;
        }
        ans = max(ans , len);
    }
    return ans;
}
int32_t main(){
    int n ; cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    // solve(arr);
    cout<<max_len(arr)<<endl;
    return 0;
}
