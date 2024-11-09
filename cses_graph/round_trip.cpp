#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int>path;
map<int , int >mp;
bool dfs(vector<int> g[] , vector<bool> & vis , int cnt , int src){
    vis[src] = true;
    path.push_back(src);
    mp[src] = cnt;
    cnt++;
    for(int nNode : g[src]){
        if(!vis[nNode]){
            if(dfs(g, vis , cnt , nNode)){
                return true;
            }
        }else{
            if(abs(mp[nNode] - cnt) >= 3){
                path.push_back(nNode);
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

int32_t main(){
    int n , e ; cin >> n >> e;
    vector<int>g[n + 1];
    for(int i = 0 ; i < e ; i++){
        int s , d ; cin >> s >> d;
        g[s].push_back(d);
        g[d].push_back(s);
    }
    queue<list<int>>q;

    vector<bool>vis(n + 1 , false);

    for(int i = 1 ; i <= n ; i++){
        if(vis[i] == false){
            mp.clear();
            path.clear();
            if(dfs(g, vis , 0 , i) && path.size() >= 2){
                int flag = path.back();  
                vector<int>res;
                res.push_back(flag);
                for(int it = path.size() - 2 ; it >= 0 ; it--){
                    if(path[it] == flag){
                        res.push_back(flag);
                        break;
                    }
                    res.push_back(path[it]);
                }
                cout<<res.size()<<endl;
                for(int v : res){
                    cout<<v<<" ";
                }
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;

    return 0;
}

/*
Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, 
goes through two or more other cities, and finally returns to the starting city. Every intermediate city on 
the route has to be distinct.
Input
The first input line has two integers n and m: the number of cities and roads. 
The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the roads. 
Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.
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
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3

*/