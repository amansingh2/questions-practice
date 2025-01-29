#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , m ; cin >> n >> m; // no of computers and no of connections!

    vector<int>g[n+1];

    for(int i = 0 ; i < m ; i++){
        int a , b ; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // we have to print shortest route from 1 to n if no route then print "IMPOSSIBLE"!

    queue<int>q;
    q.push(1);
    vector<bool> vis(n + 1 , false);
    vis[1] = true;
    map<int,int>parent;
    parent[1] = -1;
    bool flag = false;
    while(!q.empty()){
        int node = q.front();
        if(node == n){
            flag = true;
            break;
        }
        q.pop();
        for(int n_node : g[node]){
            if(!vis[n_node]){
                vis[n_node] = true;
                parent[n_node] = node;
                q.push(n_node);
            }
        }
    }

    if(flag){
        vector<int>way;
        int node = n;
        while(parent[node] != -1){
            way.push_back(node);
            node = parent[node];
        }
        way.push_back(1);
        reverse(way.begin() , way.end());
        cout<<(int)way.size()<<endl;
        for(int i : way){
            cout<<i<<" ";
        }
        return 0;
    }
    cout<<"IMPOSSIBLE"<<endl;

    return 0;
}

/*
Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a 
message to Maija, and if it is possible, what is the minimum number of computers on such a route.

Input
The first input line has two integers n and m: the number of computers and connections. 
The computers are numbered 1,2,.....,n. Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. Each line has two integers a and b: 
there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection 
between any two computers.

Output
If it is possible to send a message, first print k: the minimum number of computers on a valid route. 
After this, print an example of such a route. You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".

Constraints
2 <= n <= 10^5
1 <= m <= 2*10^5
1 <= a,b <= n

Example
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5
*/