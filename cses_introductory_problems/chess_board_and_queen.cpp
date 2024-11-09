#include <bits/stdc++.h>
#define int long long
using namespace std;
int solve(int i , int n , set<int> & row , set<int> & left , set<int> & right , vector<string> & arr){
    if(i == n){
        return 1;
    }

    int cnt = 0;
    for(int j = 0 ; j < n ; j++){
        if(row.count(j) == 0 && left.count(j - i) == 0 && right.count(j + i) == 0 && arr[i][j] == '.'){
            row.insert(j);
            left.insert(j - i);
            right.insert(j + i);
            cnt += solve(i + 1 , n , row , left , right , arr);
            row.erase(row.find(j));
            left.erase(left.find(j - i));
            right.erase(right.find(j + i));
        }
    }
    return cnt;
}
int32_t main(){
    int n = 8;
    vector<string>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    set<int> row , col , left , right;
    cout<<solve(0 , n , row , left , right , arr)<<endl;

    return 0;
}

/*
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. 
As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. 
However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input
The input has eight lines, and each of them has eight characters. 
Each square is either free (.) or reserved (*).

Output
Print one integer: the number of ways you can place the queens.

Example
Input:

........
........
..*.....
........
........
.....**.
...*....
........
Output:
65

*/