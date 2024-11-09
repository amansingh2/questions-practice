#include <bits/stdc++.h>
#define int long long
using namespace std;

int get_parent(int child , vector<int>& parent){
    while(parent[child] != child){
        parent[child] = parent[parent[child]]; // path compression
        child = parent[child];
    }
    return child;
}
void join_by_size(int u , int v , vector<int> & parent , vector<int> & size_of_nodes){
    int top_parent_u = get_parent(u,parent);
    int top_parent_v = get_parent(v,parent);

    if(top_parent_u == top_parent_v){
        return ;
    }

    if(size_of_nodes[top_parent_u] > size_of_nodes[top_parent_v]){
        size_of_nodes[top_parent_u] += size_of_nodes[top_parent_v];
        parent[top_parent_v] = top_parent_u;
    }else{
        size_of_nodes[top_parent_v] += size_of_nodes[top_parent_u];
        parent[top_parent_u] = top_parent_v;
    }
}
int32_t main(){
    int t;cin>>t;
    while(t--){
        int n ; cin >> n;
        vector<int>arr()










    }
    return 0;
}
