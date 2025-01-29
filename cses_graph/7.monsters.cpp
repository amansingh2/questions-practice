#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve1(){
    int n , m ; cin >> n >> m;

    vector<vector<char> > mat(n , vector<char> (m));
    queue<pair<int,int> > q;
    vector<vector<int>>time(n , vector<int> (m , 1e9));
    vector<vector<bool> > vis(n , vector<bool> (m , false));
    queue<vector<int > > q1;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'M'){
                q.push({i , j});
                time[i][j] = 0;
                vis[i][j] = true;
            }
            if(mat[i][j] == 'A'){
                q1.push({i , j});
            }
        }
    }
    int t = 1;

    int dirx [] = {0 , 0 , 1 , -1};
    int diry [] = {1 , -1 , 0 , 0};


    while(!q.empty()){
        int len = q.size();
        while(len--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] == false && mat[nx][ny] != '#'){
                    vis[nx][ny] = true;
                    time[nx][ny] = t;
                    q.push({nx , ny});
                }
            }

        }
        t++;
    }
    // vector<int>res;
    // vis.resize(n , vector<bool> (m , false));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            vis[i][j] = false;
            // cout<<time[i][j]<<" ";
        }
        // cout<<endl;
    }
    /*
    1 -> L
    2 -> R
    3 -> U
    4 -> D
    */
    t = 1;
    bool flag = false;
    while(!q1.empty()){
        int len = q1.size();

        while(len--){
            vector<int> v = q1.front();
            int x = v[v.size() - 2];
            int y = v[v.size() - 1];
            vis[x][y] = true;
            v.pop_back();
            v.pop_back();
            if(x == 0 || x == n - 1 || y == 0 || y == m - 1){
                flag = true;
                break;
            }
            q1.pop();
            if(t > time[x][y] || mat[x][y] == '#'){
                continue;
            }
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && t < time[nx][ny] && vis[nx][ny] == false && mat[nx][ny] != '#' ){
                    vis[nx][ny] = true;
                    vector<int>v1 = v;
                    v1.push_back(i);
                    v1.push_back(nx);
                    v1.push_back(ny);
                    q1.push(v1);
                    // cout<<'aa'<<endl;
                }
            }
        }
        if(flag){
            break;
        }
        t++;
    }
/*
    int dirx [] = {0 , 0 , 1 , -1};
    int diry [] = {1 , -1 , 0 , 0};
*/
    map<int , char> mp;
    mp[0] = 'R';
    mp[1] = 'L';
    mp[2] = 'D';
    mp[3] = 'U';


    if(flag){
        vector<int> v  = q1.front();
        v.pop_back();
        v.pop_back();
        cout<<"YES"<<endl;
        cout<<v.size()<<endl;
        for(int i = 0  ; i < (int)v.size() ; i++){
            cout<<mp[v[i]];
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    solve1();
    // solve2();

  
    
    return 0;
}

void solve2(){
    int n , m ; cin >> n >> m ; // n -> rows , m -> columns!
    vector<vector<char>>lab(m , vector<char>(m));

    for(int i = 0  ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> lab[i][j];
        }
    }

}

/*

You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, 
each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares 
without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is, print a path that you can follow. 
Your plan has to work in any situation; even if the monsters know your path beforehand.

Input
The first input line has two integers n and m: the height and width of the map.
After this there are n lines of m characters describing the map. Each character is . (floor), # (wall), 
A (start), or M (monster). There is exactly one A in the input.

Output
First print "YES" if your goal is possible, and "NO" otherwise.
If your goal is possible, also print an example of a valid path (the length of the path and 
its description using characters D, U, L, and R). You can print any path, as long as its length 
is at most n \cdot m steps.
Constraints

1 <= n,m <= 1000

Example
Input:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Output:
YES
5
RRDDR
*/