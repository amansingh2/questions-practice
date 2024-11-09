#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int , int> mp;
vector<int>path;
bool dfs(vector<bool> & vis , vector<int>g[], vector<int> & cycle_hai , int src , int cnt){
    // cout<<src<<"  "<<g[src].size()<<endl;
    vis[src] = true;
    cycle_hai[src] = 1;
    path.push_back(src);
    mp[src] = cnt;
    // cout<<src<<" mp of src  "<<mp[src]<<endl;;

    for(int nNode : g[src]){
        // cout<<src<<" "<< nNode<<endl;
        // cycle_hai[nNode] = 1;
        // cout<<src<<" -> "<<cycle_hai[src] << "  " << nNode << " ->  " << cycle_hai[nNode] << endl;;
        if(vis[nNode] == false){
            if(dfs(vis , g , cycle_hai , nNode , cnt + 1) == true){ // think ?
                return true;
            }
        }else if(cycle_hai[nNode] == 1  && abs(mp[nNode] - cnt) >= 1){
            // cout<<"gg"<<endl;
            path.push_back(nNode);
            return true;
        }
    }
    path.pop_back();
    cycle_hai[src] = 0; // think?
    return false;
}

int32_t main(){
    int n , e ; cin >> n >> e;
    vector<int>g[n+1];

    for(int i = 0 ; i < e ; i++){
        int s, d;cin >> s >> d;
        g[s].push_back(d);
    }

    vector<bool> vis(n+1, false);
    vector<int> cycle_hai(n+1, 0);

    for(int i = 1 ; i <= n ; i++){
        path.clear();
        mp.clear();
        if(!vis[i]){
            if(dfs(vis , g , cycle_hai , i , 1)){
                // for(int it : path){
                //     cout<<it<<" ";
                // }
                int flag = path.back();
                vector<int>res;
                res.push_back(flag);
                for(int it = path.size() - 2 ; it >= 0 ; it--){
                    if(path[it] == flag){
                        res.push_back(path[it]);
                        break;
                    }
                    res.push_back(path[it]);
                }
                reverse(res.begin() , res.end());
                cout<<(int)res.size()<<endl;
                for(int v : res){
                    cout<<v << " ";
                }
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}

/*
Byteland has n cities and m flight connections. Your task is to design a round trip that begins in a city, 
goes through one or more other cities, and finally returns to the starting city. Every intermediate city 
on the route has to be distinct.
Input
The first input line has two integers n and m: the number of cities and flights. 
The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the flights. Each line has two integers a and b: 
there is a flight connection from city a to city b. 
All connections are one-way flights from a city to another city.
Output
First print an integer k: the number of cities on the route. 
Then print k cities in the order they will be visited. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 5
1 3
2 1
2 4
3 2
3 4

Output:
4
2 1 3 2
*/