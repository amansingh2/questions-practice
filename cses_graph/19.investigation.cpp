#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    int e ; cin >> e;

    vector<pair<int,int>>g[n + 1];
    vector<int>min_flight(n + 1 , (int)1e7);
    min_flight[1] = 0;
    vector<int>max_flight(n + 1 , 0);
    vector<int>dist(n + 1 , LLONG_MAX/10);
    dist[1] = 0;
    vector<int>no_ways(n+1 , 1);
    no_ways[1] = 1;
    int mod = (int)1e9 + 7;


    for(int i = 0 ; i < e ; i++){
        int a,b,c; cin >> a >> b >> c;
        g[a].push_back({b , c});
    }

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

    pq.push({0 , 1});

    while(!pq.empty()){
        int node = pq.top().second;
        int weight = pq.top().first; // ye node tak ka weight hai!! , na ki node ka weight hai samjhe
        pq.pop();
        if(dist[node] < weight){
            continue;
        }
        for(auto it : g[node]){
            int n_node = it.first;
            int n_weight = it.second;
            if(dist[n_node] > weight + n_weight){
                dist[n_node] = weight + n_weight;
                min_flight[n_node] = 1 + min_flight[node];
                max_flight[n_node] = 1 + max_flight[node];
                no_ways[n_node] = no_ways[node];
                pq.push({weight + n_weight , n_node});
            }else if(dist[n_node] == (weight + n_weight)){
                min_flight[n_node] = min(min_flight[n_node] , 1 + min_flight[node]);
                max_flight[n_node] = max(max_flight[n_node] , 1 + max_flight[node]);
                (no_ways[n_node] += no_ways[node]) %= mod;
            }
        }
    }
    cout<<dist[n]<<" "<<(no_ways[n]%mod)<<" "<<min_flight[n]<<" "<<max_flight[n]<<endl;

    return 0;
}

/*
You are going to travel from Syrjälä to Lehmälä by plane. 
You would like to find answers to the following questions:

what is the minimum price of such a route?
how many minimum-price routes are there? (modulo 10^9+7)
what is the minimum number of flights in a minimum-price route?
what is the maximum number of flights in a minimum-price route?

Input
The first input line contains two integers n and m: 
the number of cities and the number of flights. 
The cities are numbered 1,2,\ldots,n. City 1 is Syrjälä, and city n is Lehmälä.
After this, there are m lines describing the flights. 
Each line has three integers a, b, and c: 
there is a flight from city a to city b with price c. 
All flights are one-way flights.
You may assume that there is a route from Syrjälä to Lehmälä.
Output
Print four integers according to the problem statement.
Constraints

1 <= n <= 10^5
1 <= m <= 2 * 10^5
1 <= a,b <= n
1 <= c <= 10^9
Example
Input:
4 5
1 4 5
1 2 4
2 4 5
1 3 2
3 4 3
Output:
5 2 1 2
*/
