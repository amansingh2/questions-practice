#include <bits/stdc++.h>
#define int long long
using namespace std;
//  City 1 is Syrjälä, and city n is Lehmälä.

void dfs(int src , int dest , vector<int> g[] , vector<int> & dp , vector<int> & next_node , vector<bool> & vis){
    // if(src == dest){
    //     return ;
    // } 
    // if(dp[src] != -1){
    //     return dp[src];
    // }
    // int res = 0;
    vis[src] = true;

    // for(int i : g[src]){
    //     if(vis[i] == false && dp[src] < 1 + dp[i]){
    //         next_node[i] = src;
    //         dp[src] = 1 + dp[i];
    //         dfs(i , dest , g , dp , next_node , vis);
    //     }
        
    // }
    // return dp[src] = max(res , dp[src]);


	
	for(int i : g[src]){
		if(vis[i] == false) dfs(i , dest , g , dp , next_node , vis);
		
		if((dp[i] != -1) && (dp[i] + 1 > dp[src])){
			dp[src] = dp[i] + 1;
			next_node[src] = i;
		}
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout<<"A"<<endl;
    int n , e ; cin >> n >> e;
    vector<int>g[n+1];
    // cout<<"A"<<endl;

    for(int i = 0 ; i < e ; i++){
        int s , d ; cin >> s >> d;
        g[s].push_back(d);
    }    
    vector<int>dp(n + 1 , -1);
    dp[n] = 1;
    vector<int>next_node(n + 1 , 0);
    vector<bool>vis(n + 1 , false);
    dfs(1 , n , g , dp , next_node , vis);
    // for(int i : dp){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    if(dp[1] != -1){
        // vector<int>path;
        // int i = n;
        // while(next_node[i] != 0){
        //     // cout<<i<<" ";
        //     path.push_back(i);
        //     i = next_node[i];
        // }
        // // cout<<1<<endl;
        // path.push_back(1);
        // reverse(path.begin() , path.end());
        // cout<<path.size()<<endl;
        // for(int i : path){
        //     cout<<i<<" ";
        // }

        // cout<<dp[n]<<endl;;



        cout<<dp[1]<<endl;
        int i = 1;
        while(i != 0){
            cout<<i<<" ";
            i = next_node[i];
        }

    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    // cout<<next_node[i]<<endl;
    
    return 0;
}

// /*
// Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more 
// flights through cities. 
// Of course, Uolevi wants to choose a trip that has as many cities as possible.
// Uolevi wants to fly from Syrjälä to Lehmälä so that he visits the maximum number of cities. 
// You are given the list of possible flights, and you know that there are no directed cycles in 
// the flight network.
// Input
// The first input line has two integers n and m: the number of cities and flights. 
// The cities are numbered 1,2,\dots,n. City 1 is Syrjälä, and city n is Lehmälä.
// After this, there are m lines describing the flights. Each line has two integers a and b: there is a 
// flight from city a to city b. 
// Each flight is a one-way flight.
// Output
// First print the maximum number of cities on the route. After this, print the cities in the order 
// they will be visited. 
// You can print any valid solution.
// If there are no solutions, print "IMPOSSIBLE".
// Constraints
// 2 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n
// Example
// Input:
// 5 5
// 1 2
// 2 5
// 1 3
// 3 4
// 4 5
// Output:
// 4
// 1 3 4 5
// */





// Problem Name : Longest Flight Route
// Problem Link : https://cses.fi/problemset/task/1680
// Video solution link : 
// Write here if video solution doesn't exist : icodencode@gmail.com
// Channel name & link : CodeNCode (https://www.youtube.com/@codencode)
// #include<bits/stdc++.h>
// #define vi vector<int>
// #define ll long long
// using namespace std;
// bool vis[200001];
// vi adj[200001];
// int dp[200001];
// int next_node[200001] , n;

// void dfs(int node){
// 	vis[node] = true;
	
// 	for(int v : adj[node]){
// 		if(vis[v] == false) dfs(v);
		
// 		if((dp[v] != -1) && (dp[v] + 1 > dp[node])){
// 			dp[node] = dp[v] + 1;
// 			next_node[node] = v;
// 		}
// 	}
// }
// int  main(){
// 	int m , a , b;
// 	cin>>n>>m;
	
// 	for(int i=1;i<=n;i++) dp[i] = -1;
// 	dp[n] = 1;
	
// 	for(int i=0;i<m;i++){
// 		cin>>a>>b;
// 		adj[a].push_back(b);
// 	}
	
// 	dfs(1);
	
// 	if(dp[1] == -1){
// 		cout<<"IMPOSSIBLE";
// 	}else{
// 		cout<<dp[1]<<"\n";
	
// 		int node = 1;
// 		while(node){
// 			cout<<node<<" ";
// 			node = next_node[node];
// 		}
// 	}
	
// }