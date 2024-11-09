#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;

    cout<<0<<endl;

    for(int i = 2 ; i <= n ; i++){
        int total = (i * i * (i * i - 1))/2;
        int attack = 4 * (i - 1) * (i - 2);
        cout<<total - attack<<endl;
    }
    
    return 0;
}

/*
Your task is to count for k=1,2,\ldots,n the number of ways two knights can be 
placed on a k * k chessboard so that they do not attack each other.
Input
The only input line contains an integer n.
Output
Print n integers: the results.
Constraints

1 <= n <= 10000

Example
Input:
8

Output:
0
6
28
96
252
550
1056
1848

*/