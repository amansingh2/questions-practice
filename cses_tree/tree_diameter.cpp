#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution{
    public : 
        vector<int>g [];
        int n;
        Solution(vector<int> g []  , n ){
            this.g = g;
            this.n = n;
        }

        int solveUsingBFS(){

        }
}

int32_t main(){
    int n ; cin >> n;

    vector<int> g[n + 1];

    for(int i = 1 ; i < n ; i++){
        int a , b ; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    return 0;
}

/*
You are given a tree consisting of n nodes.
The diameter of a tree is the maximum distance between two nodes. 
Your task is to determine the diameter of the tree.
Input
The first input line contains an integer n: the number of nodes. 
The nodes are numbered 1,2,.....,n.
Then there are n-1 lines describing the edges. 
Each line contains two integers a and b: there is an edge between nodes a and b.
Output
Print one integer: the diameter of the tree.
Constraints

1 <= n <= 2 * 10^5
1 <= a,b <= n

Example
Input:
5
1 2
1 3
3 4
3 5
Output:
3
Explanation: The diameter corresponds to the path 2 -> 1 -> 3 -> 5.
*/

            
