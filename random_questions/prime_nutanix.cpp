#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int N = (int)1e6;
    vector<bool>sieve(N+1,true);
    sieve[0] = sieve[1] = false;
    for(int i = 2 ; i*i <= N ; i++){
        if(sieve[i]){
            for(int j = i*i ; j <= N ; j += i){
                sieve[j] = false;
            }
        }
    }
    vector<int>primes;
    for(int i = 2 ; i <= N ; i++){
        if(sieve[i]){
            primes.push_back(i);
        }
    }
    int t; cin >> t;
    while(t--){
        int n ; cin >> n;
        vector<int>ans;
        int sm = 0;
        for(int i = 0,j = 0 ;j < n && i < primes.size() ; i++){
            if(sm < primes[i]){
                ans.push_back(primes[i]);
                sm += primes[i];
                j++;
            }
        }
        for(int i : ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}