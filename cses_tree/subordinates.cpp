#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(int src ,vector<int> g[] , vector<bool> & vis , vector<int> & dp){
    vis[src] = true;
    int res = 0;

    for(int i : g[src]){
        if(!vis[i]){
            solve(i , g , vis , dp);
            res += 1 + dp[i];
        }
    }

    dp[src] = res;
}

int32_t main(){
    int n ; cin >> n;
    vector<int>g[n + 1];

    vector<int>dp(n + 1 , 0);

    for(int i = 2 ; i <= n ; i++){
        int a ; cin >> a;
        g[a].push_back(i);
    }
    vector<bool>vis(n+1 , false);
    solve(1 , g , vis , dp);
    for(int i = 1 ; i <= n ; i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}

/*
 Given the structure of a company, your task is to calculate for each 
 employee the number of their subordinates.
Input
The first input line has an integer n: the number of employees. 
The employees are numbered 1,2,\dots,n, and employee 1 is the general director of the company.
After this, there are n-1 integers: for each employee 2,3,\dots,n their direct boss in the company.
Output
Print n integers: for each employee 1,2,\dots,n the number of their subordinates.
Constraints

1 \le n \le 2 \cdot 10^5

Example
Input:
5
1 1 2 3

Output:
4 1 1 0 0 
*/