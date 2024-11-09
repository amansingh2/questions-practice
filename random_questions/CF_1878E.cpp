#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n ; cin >> n;
        vector<int> arr (n);
        for(int i = 0 ;  i < n ; i++){
            cin>>arr[i];
        }










        int q;cin>>q;
        while(q--){
            int l , k ; cin >> l >> k;
            l -= 1;
            if(arr[l] < k){
                cout<<-1<<" ";
                continue;
            }
            
        }







    }
    return 0;
}