#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int x , n; cin >> x >> n;
    multiset<int>ms;
    ms.insert(x);

    for(int i = 0 ;  i < n ; i++){
        int pos ; cin >> pos;
        
    }


    return 0;
}


/*
There is a street of length x whose positions are numbered 0,1,...,x. Initially there are no traffic lights, 
but n sets of traffic lights are added to the street one after another.
Your task is to calculate the length of the longest passage without traffic lights after each addition.

Input
The first input line contains two integers x and n: the length of the street and the number of sets of 
traffic lights.
Then, the next line contains n integers p_1,p_2,....,p_n: the position of each set of traffic lights. 
Each position is distinct.

Output
Print the length of the longest passage without traffic lights after each addition.

Constraints
1 <= x <= 10^9
1 <= n <= 2 * 10^5
0 < p_i < x

Example
Input:
8 3
3 6 2

Output:
5 3 3
*/