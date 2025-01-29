#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs(int i  , int j , int n , int m , vector<vector<char>> &map){
    if(i < 0 || j < 0 || i >= n || j >= m || map[i][j] == '#'){
        return ;
    }
    map[i][j] = '#';
    dfs(i + 1, j , n , m , map);
    dfs(i , j + 1, n , m , map);
    dfs(i , j - 1, n , m , map);
    dfs(i - 1, j , n , m , map);
}

int32_t main(){
    int n , m ; cin >> n >> m;
    vector<vector<char>>map(n , vector<char>(m));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
        }
    }

    int ans = 0;
    for(int i = 0 ;  i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(map[i][j] == '.'){
                ans++;
                dfs(i , j , n , m , map);
            }
        }
    }

    cout<<ans<<endl;



    return 0;
}

/*
You are given a map of a building, and your task is to count the number of its rooms. 
The size of the map is n * m squares, and each square is either floor or wall. 
You can walk left, right, up, and down through the floor squares.

Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).

Output
Print one integer: the number of rooms.

Constraints
1 <= n,m <= 1000

Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
*/