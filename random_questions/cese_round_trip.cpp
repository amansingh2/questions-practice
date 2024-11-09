#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n, m ; cin>>n>>m;
    vector<int> g [n+1];
    for(int i = 0 ; i < m ; i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }

    map<int,int>mp;
    mp[1] = 1;
    // vector<bool>vis(n+1,false);
    queue<int>q;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i : g[node]){
            if(i == 1 && mp.size() >= 2){
                
            }
        }

    }
    return 0;
}