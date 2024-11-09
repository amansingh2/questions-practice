#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;cin>>t;
    int power [35] = {0};
    power[0] = 1;
    for(int i = 1 ; i <= 34 ; i++){
        power[i] = power[i-1]*2;
    } 
    while(t--){
        int n ; cin >> n;
        vector<int> arr (n);
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }
        int ans = 0;
        for(int i = 1; i < n ; i++){
            if(arr[i] >= arr[i-1]){
                continue;
            }
            int times = (arr[i-1] + arr[i] - 1)/arr[i];
            arr[i] *= times;
            int pow_2;
            if((times & (times - 1) )== 0){
                pow_2 = times;
            }else{
                
            }
        }
        cout<<ans<<endl;


    }
    return 0;
}