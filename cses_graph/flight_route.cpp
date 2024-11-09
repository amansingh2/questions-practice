#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                    
    cout.tie(NULL);
    int n , m , k ; cin >> n >> m >> k;

    vector<pair<int,int> > g[n + 1];

    for(int i = 1 ; i <= m ; i++){
        int s , d , w ; cin >> s >> d >> w;
        g[s].push_back({d , w});
    }

    // we have go from 1 to n!
    priority_queue<int> dist [n + 1];

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int , int > > > pq;

    dist[1].push(0);
    pq.push({0 , 1});

    while(!pq.empty()){
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if(weight > dist[node].top()){
            continue;
        }
        for(auto [a , b] : g[node]){
            int tmp_weight = b + weight;
            if(dist[a].size() < k){
                dist[a].push(tmp_weight);
                pq.push({tmp_weight , a});
            }else if(tmp_weight < dist[a].top()){
                 dist[a].pop();
                 dist[a].push(tmp_weight);
                 pq.push({tmp_weight , a});
            }
            
        }
    }

    vector<int>res;
    while(dist[n].size() > 0){
        res.push_back(dist[n].top());
        dist[n].pop();
    }
    reverse(res.begin() , res.end());

    for(int i : res){
        cout<<i<<" ";
    }





    return 0;
}

/*
Your task is to find the k shortest flight routes from Syrjälä to Metsälä. 
A route can visit the same city several times.
Note that there can be several routes with the same price and each of them should be considered 
(see the example).
Input
The first input line has three integers n, m, and k: the number of cities, 
the number of flights, and the parameter k. The cities are numbered 1,2,\ldots,n. 
City 1 is Syrjälä, and city n is Metsälä.
After this, the input has m lines describing the flights. 
Each line has three integers a, b, and c: a flight begins at city a, ends at city b, 
and its price is c. 
All flights are one-way flights.
You may assume that there are at least k distinct routes from Syrjälä to Metsälä.
Output
Print k integers: the prices of the k cheapest routes sorted according to their prices.
Constraints

2 <= n <= 10^5
1 <= m <= 2 * 10^5
1 <= a,b <= n
1 <= c <= 10^9
1 <= k <= 10

Example
Input:
4 6 3
1 2 1
1 3 3
2 3 2
2 4 6
3 2 8
3 4 1
Output:
4 4 7
Explanation: The cheapest routes are 1->3->4 (price 4),1->2->3->4 (price 4) and 1->2->4 (price 7).
*/