#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs(int src , vector<bool> &vis , vector<int> g[]){
    vis[src] = true;
    for(int n_node : g[src]){
        if(!vis[n_node]){
            dfs(n_node , vis , g);
        }
    }
}

int32_t main(){
    int n , m ; cin >> n >> m; // n -> no. of cities , m -> no. of roads!
    vector<int> g[n + 1];

    for(int i = 0 ; i < m ; i++){
        int a , b ; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<pair<int,int>>vp;
    vector<bool>vis(n+1 , false);

    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            if(i != 1){
                vp.push_back({i-1 , i});
            }
            dfs(i , vis , g);
        }
    }

    cout<<(int)vp.size()<<endl;

    for(auto [a , b] : vp){
        cout<<a<<" "<<b<<endl;
    }




    return 0;
}
/*
Byteland has n cities, and m roads between them. The goal is to construct new roads so that there 
is a route between any two cities.
Your task is to find out the minimum number of roads required, 
and also determine which roads should be built.

Input
The first input line has two integers n and m: the number of cities and roads. 
The cities are numbered 1,2,.......,n.
After that, there are m lines describing the roads. Each line has two integers a and b: 
there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.

Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.

Constraints
1 <= n <= 10^5
1 <= m <= 2 * 10^5
1 <= a,b <= n

Example
Input:
4 2    // these are not edges , these are no of nodes and no of edges!
1 2
3 4

Output:
1
2 3
*/