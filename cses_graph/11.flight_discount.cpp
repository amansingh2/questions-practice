#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
dp[i][0] -> not used disocunt coupen!
dp[i][1] -> discount coupen is used , cant use any further more!
*/

// dp se bhi ho sakta hai but mujhe states ni samajh aa rhe hai!
/*
            10      12          15          14
        1   ->  2   ->   3      ->    5     ->      8
[0,0][0,0]  [10,5]  [22 , 16]      [37,29]        [51 , 43]

*/

int32_t main(){
    int n , e ; cin >> n >> e;
    vector<vector<int>> g[n  + 1];

    for(int i = 0 ; i < e ; i++){
        int s , d , w ; cin >> s >> d >> w;
        g[s].push_back({d , w});
    }
    priority_queue<vector<int> , vector<vector<int> > , greater<vector<int>>> pq;
    // queue<vector<int>>pq;
    //{dist , src , usedOrNotused}!
    // queue<int>pq;
    // pq.push({0 , 1 , 0});
    pq.push({0 , 1 , 0});
    // 0 -> not used flight , 1 -> flight
    // pq.push(1);
    // vector<vector<int>>dp(n + 1 , vector<int> (2 , INT_MAX));
    int mxv = 1e16;
    vector<int>dp_with_discount(n + 1 , mxv);
    vector<int>dp_with_out_discount(n + 1 , mxv);
    dp_with_discount[1] = dp_with_out_discount[1] = 0LL;

    while(!pq.empty()){
        int node = pq.top()[1];
        int weight = pq.top()[0];
        int flight_used = pq.top()[2];
        pq.pop();
        if(flight_used == 1 && dp_with_discount[node] < weight){
            continue;
        }
        if(flight_used == 0 && dp_with_out_discount[node] < weight){
            continue;
        }

        for(auto it : g[node]){
            int e_weight = it[1];
            int n_node = it[0];
            if(flight_used == 1){
                if(e_weight + weight < dp_with_discount[n_node]){
                    dp_with_discount[n_node] = e_weight + weight;
                    pq.push({e_weight + weight , n_node , 1});
                }
            }else{
                if(weight + e_weight < dp_with_out_discount[n_node]){
                    pq.push({weight + e_weight , n_node , 0});
                    dp_with_out_discount[n_node] = weight + e_weight ;
                }
                if(weight + e_weight/2 < dp_with_discount[n_node]){
                    dp_with_discount[n_node] = weight + e_weight/2;
                    pq.push({weight + e_weight/2 , n_node , 1});
                }
                
            }

        }
    }



    // vector<int>ans(n + 1 , LLONG_MAX/10LL);
    // ans[1] = 0;
   
    // vector<bool>vis(n + 1 , false);

 
    // for(int i : ans ){
    //     // cout<<i<<endl;
    // }
    cout<< min(dp_with_discount[n] , dp_with_out_discount[n])<<endl;
    return 0;
}

/*
Your task is to find a minimum-price flight route from Syrjälä to Metsälä. 
You have one discount coupon, using which you can halve the price of any single flight during the route. 
However, you can only use the coupon once.
When you use the discount coupon for a flight whose price is x, 
its price becomes \lfloor x/2 \rfloor (it is rounded down to an integer).
Input
The first input line has two integers n and m: the number of cities and flight connections. 
The cities are numbered 1,2,\ldots,n. City 1 is Syrjälä, and city n is Metsälä.
After this there are m lines describing the flights. 
Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. 
Each flight is unidirectional.
You can assume that it is always possible to get from Syrjälä to Metsälä.
Output
Print one integer: the price of the cheapest route from Syrjälä to Metsälä.
Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n
1 \le c \le 10^9

Example
Input:
3 4
1 2 3
2 3 1
1 3 7
2 1 5

Output:
2

*/