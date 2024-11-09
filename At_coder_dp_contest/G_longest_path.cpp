#include <bits/stdc++.h>
#define int long long
using namespace std;


void dfs(int src , vector<int>&max_len , vector<int>g[]){

    int mx = -1;

    for(int v : g[src]){
        if(max_len[v] == -1){
            dfs(v , max_len , g);
        }
        mx = max(mx , max_len[v]);
    }

    max_len[src] = 1 + mx;

}

int32_t main(){
    int vertices , edges ; cin >> vertices >> edges;

    vector<int> g[vertices + 1];

    for(int e =  0 ; e < edges ; e++){
        int x , y; cin >> x >> y;
        g[x].push_back(y);
    }

    vector<int>max_len(vertices + 1 , -1);

    vector<bool>vis(vertices + 1, false);
    int ans = 0;

    for(int v = 1 ; v <= vertices ; v++){
        if(max_len[v] == -1){
            dfs(v , max_len , g);
        }
    }

    for(int i : max_len){
        ans = max(ans , i);
    }
    cout<<ans;
}


/*
Problem Statement 
There is a directed graph G with N vertices and M edges. 
The vertices are numbered 1,2,…,N, and for each i (1 ≤ i ≤ M),
the i-th directed edge goes from Vertex xi ​to yi. 
G does not contain directed cycles. 

Find the length of the longest directed path in G. 
Here, the length of a directed path is the number of edges in it. 

Constraints 
All values in input are integers. 
2≤N≤10^5 
1≤M≤10^5 
1 ≤ xi ,yi ​≤ N 
All pairs (xi ​,yi) are distinct. 
G does not contain directed cycles.


Input is given from Standard Input in the following format: 
N M 
x1 ​ y1 ​ 
x2 ​ y2
*/