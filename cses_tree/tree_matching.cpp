#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    vector<int>g[n + 1];

    for(int i = 1 ; i < n ; i++){
        int a , b  ; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool>vis(n + 1 , false);
    

    return 0;
}


/*
You are given a tree consisting of n nodes.
A matching is a set of edges where each node is an endpoint of at most one edge. 
What is the maximum number of edges in a matching?
Input
The first input line contains an integer n: the number of nodes. 
The nodes are numbered 1,2,\ldots,n.
Then there are n-1 lines describing the edges. 
Each line contains two integers a and b: 
there is an edge between nodes a and b.
Output
Print one integer: the maximum number of pairs.

Input:

5
1 2
1 3
3 4
3 5
Output:

2
*/