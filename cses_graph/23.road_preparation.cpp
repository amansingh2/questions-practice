#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , m ; cin >> n >> m;
    vector<pair<int,int> >g[n + 1];


    for(int  i = 0 ; i < m ; i++){
        int a , b , c ; cin >> a >> b >> c;
        g[a].push_back({b ,c});
        g[b].push_back({a, c});
    }

    priority_queue<pair<int,int> , vector<pair<int, int>> , greater<pair<int,int>> >pq;

    int ans = 0;
    vector<bool>vis(n +1 , false);

    pq.push({0 , 1});

    while(!pq.empty()){
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if(vis[node]){
            continue;
        }
        vis[node] = true;
        ans += weight;
        for(auto it : g[node]){
            if(!vis[it.first]){
                pq.push({it.second , it.first});
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;


    return 0;
}

/*
There are n cities and m roads between them. Unfortunately, 
the condition of the roads is so poor that they cannot be used. 
Your task is to repair some of the roads so that there will be a decent route between any two cities.
For each road, you know its reparation cost, and you should find a solution where 
the total cost is as small as possible.
Input
The first input line has two integers n and m: the number of cities and roads. 
The cities are numbered 1,2.....,n.
Then, there are m lines describing the roads. 
Each line has three integers a, b and c: 
there is a road between cities a and b, and its reparation cost is c. 
All roads are two-way roads.
Every road is between two different cities, and there is at most one road between two cities.
Output
Print one integer: the minimum total reparation cost. However, 
if there are no solutions, print "IMPOSSIBLE".
Constraints

1 <= n <= 10^5
1 <= m <= 2 * 10^5
1 <= a,b <= n
1 <= c <= 10^9

Example
Input:
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4

Output:
14

*/
    
    
