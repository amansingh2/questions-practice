#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;cin>>t;
    while(t--){
       int n;cin>>n;
       vector<int>arr(n);
       for(int i =  0 ; i < n ; i++){
        cin>>arr[i];
       }

       for(int i = n - 2; i >= 0 ; i--){

         arr[i]  =  (int)(arr[i] & arr[i+1]);
       }
        for(int i : arr){
            cout<<i<<" ";
        }
        cout<<endl;
       int q;cin>>q;
       while(q--){
        int l,k;cin>>l>>k;
        int st = l-1;
        int end = n-1;
        int best = -1;
        while(st <= end){
            int mid = (st + end)/2;
            if(arr[mid] >= k){
                best = mid;
                st = mid + 1;
            }else{
                end = mid - 1;
            }

            if(best != -1){
                cout<<best+1<<" ";
            }else{
                cout<<-1<<" ";
            }
        }

       }

       cout<<endl;

    }
    return 0;
}