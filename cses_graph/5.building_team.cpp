#include <bits/stdc++.h>
#define int long long
using namespace std;

bool dfs(int curr_team , vector<int> &team , vector<int> g[] , int curr){
    team[curr] = curr_team;
    bool val =  true;
    for(int i : g[curr]){
        if(team[i] == 0){
            val &= dfs((curr_team == 1 ? 2 : 1) , team , g , i);  // yeha pe multiple calls honge unko sambhalna hai!
        }else if(team[i] == curr_team){
            val = false;
        }
    }
    return val;
}

int32_t main(){
    int n , m ; cin >> n >> m; //n -> no. of pupils , m -> no. of friendships!

    vector<int> g[n + 1];

    for(int i = 0 ; i < m ; i++){
        int a , b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // same as coloring problem if it contains cycle that must be of even length!
    vector<int>team(n+1 , 0);

    for(int i = 1; i <= n ; i++){
        if(team[i] == 0){
            int curr_team = 1;
            if(!dfs(curr_team , team , g , i)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        cout<<team[i]<<" ";
    }

    return 0;
}

/*
There are n pupils in Uolevi's class, and m friendships between them. 
Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. 
You can freely choose the sizes of the teams.

Input
The first input line has two integers n and m: the number of pupils and friendships. 
The pupils are numbered 1,2,....,n.
Then, there are m lines describing the friendships. Each line has two integers a and b: 
pupils a and b are friends.
Every friendship is between two different pupils. 
You can assume that there is at most one friendship between any two pupils.

Output
Print an example of how to build the teams. 
For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. 
You can print any valid team.
If there are no solutions, print "IMPOSSIBLE".

Constraints
1 <= n <= 10^5
1 <= m <= 2*10^5
1 <= a,b <= n

Example
Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2
*/