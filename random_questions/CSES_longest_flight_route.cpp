#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , m ; cin >> n >> m;
    vector<int>g[n+1];
    for(int i = 0 ; i < m ; i++){
        int a,b;cin >> a>> b;
        g[a].push_back(b);
    }

    // has to visit from 1 to n 

    return 0;
}