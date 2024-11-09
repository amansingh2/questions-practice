#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , m ; cin >> n >> m ;

    vector<int> g[n+1];
    vector<int> ind(n+1,0);

    for(int i = 0 ; i < m ; i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        ind[b]++;
    }

    queue<int>q;
    for(int i = 1 ; i <= n ;  i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    vector<int>res;
    for(;!q.empty() ; q.pop()){
        int node = q.front();
        res.push_back(node);
        for(int nei_node : g[node]){
            ind[nei_node]--;
            if(ind[nei_node] == 0){
                q.push(nei_node);
            }
        }
    }

    if(res.size() != n){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i : res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}