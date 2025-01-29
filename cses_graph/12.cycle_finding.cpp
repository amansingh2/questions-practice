#include <bits/stdc++.h>
#define int long long
using namespace std;
// map<int,int>mp;
// bool dfs(int src , vector<int> g [] , vector<bool> & vis , vector<int> & cycle_batao , vector<int> & path){
//     vis[src] = true;
//     path.push_back(src);
//     cycle_batao[src] = 1;
//     // cout<<src<<" ";
//     for(int i :  g[src]){
//         if(!vis[i]){
//             if(dfs(i , g , vis , cycle_batao , path) == true){
//                 return true;
//             }
//         }else if(cycle_batao[i] == 1){
//             return true;
//         }
//     }
//     path.pop_back();
//     cycle_batao[src] = 0;
//     return false;
// }
int32_t main(){
    int n , ne ; cin >> n >> ne;
    vector<int>g[n +  1];
    vector<vector<int> > edges;
    for(int i = 0 ; i < ne  ; i++){
        int s , d , c; cin >> s >> d >> c;
        // if(s == d && c < 0){
        //     cout<<"YES"<<endl;
        //     cout<<s<<" "<<d;
        //     return 0;
        // }
        g[s].push_back(d);
        edges.push_back({s , d , c});
    }
    // vector<int>vis(n + 1 ,false);
    vector<int>dist(n + 1 , 0);

    int x  = -1;
    vector<int>kaha_se_aaya(n+1 , -1);
    for(int i = 0 ; i < n ; i++){
        x = -1;
        for(auto e : edges){
            if(dist[e[1]] > dist[e[0]] + e[2]){
                dist[e[1]] = dist[e[0]] + e[2];
                kaha_se_aaya[e[1]] = e[0];
                x = e[1]; // flag ka kaam karega last me use kr ke cycle print kr lenge!
            }
        }
    }
    
    // for(int i : possible_cycles){
        // cout<<i<<" ";
    // }
    // cout<<endl;
    if(x != -1){
        vector<int>cycle;
        for(int i = 1 ; i <= n ; i++){
            x = kaha_se_aaya[x];
        }
        for(int v = x;  ; v = kaha_se_aaya[v]){
            cycle.push_back(v);
            if(v == x && cycle.size() > 1){
                break;
            }
        }

        reverse(cycle.begin() , cycle.end());
        cout<<"YES"<<endl;
        for(int i : cycle){
            cout<<i<<" ";
        }
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
/*
You are given a directed graph, and your task is to find out if it contains a negative cycle,
 and also give an example of such a cycle.
Input
The first input line has two integers n and m: the number of nodes and edges. 
The nodes are numbered 1,2,\ldots,n.
After this, the input has m lines describing the edges. Each line has three integers a, b, and c: 
there is an edge from node a to node b whose length is c.
Output
If the graph contains a negative cycle, print first "YES", 
and then the nodes in the cycle in their correct order. If there are several negative cycles, 
you can print any of them. If there are no negative cycles, print "NO".
Constraints

1 \le n \le 2500
1 \le m \le 5000
1 \le a,b \le n
-10^9 \le c \le 10^9

Example
Input:
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

Output:
YES
1 2 4 1

*/








