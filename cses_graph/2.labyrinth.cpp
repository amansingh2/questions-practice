#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , m ; cin >> n >> m;
    vector<vector<char>> lab(n , vector<char>(m));

    pair<int , int > start , end;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 'A'){
                start = {i , j};
            }
            if(lab[i][j] == 'B'){
                end = {i , j};
            }
        }
    }

    queue<pair<int , int>>qp;
    qp.push(start);
    vector<vector<pair<int,int>>>vp(n , vector<pair<int,int>>(m , {-1 , -1}));

    vp[start.first][start.second] = {-1 , -1};

    int dirx [] = {0 , 0 , 1 , -1};
    int diry [] = {1 , -1 , 0 , 0};
    bool flag = false;
    while(!qp.empty()){
        auto curr = qp.front();
        qp.pop();
        if(curr == end){
            flag = true;
            break;
        }
        int x = curr.first;
        int y = curr.second;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && lab[nx][ny] != '#'){
                vp[nx][ny] = {x , y};
                qp.push({nx , ny});
                lab[nx][ny] = '#';
            }
        }
    }
    if(flag){
        pair<int , int> p = end;
        string res;
        map<pair<int , int> , char > mp;
        mp[{0 , 1}] = 'R';
        mp[{0 , -1}] = 'L';
        mp[{1 , 0}] = 'D';
        mp[{-1 , 0}] = 'U';

        while(p != start){
            pair<int , int > val = vp[p.first][p.second];
            int x = p.first - val.first;
            int y = p.second - val.second;
            res += mp[{x,y}];
            p = val;
        }
        reverse(res.begin() , res.end());
        cout<<"YES"<<endl;
        cout<<(int)res.size()<<endl;
        cout<<res;
        return 0;
    }

    cout<<"NO"<<endl;




    // . -> floor ; # -> wall





    return 0;
}

/*
You are given a map of a labyrinth, and your task is to find a path from start to end. 
You can walk left, right, up and down.

Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth. 
Each character is . (floor), # (wall), A (start), or B (end). 
There is exactly one A and one B in the input.

Output
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description 
as a string consisting of characters L (left), R (right), U (up), and D (down). 
You can print any valid solution.

Constraints
1 <= n,m <= 1000

Example
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU
*/