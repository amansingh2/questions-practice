#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , k ; cin >> n >> k;
    vector<int>arr(n , 0);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int mod = 1e9 + 7;


    vector<vector<int>>dp(n + 1 , vector<int>(k+1 , 0));

    




    return 0;
}
/*
Problem Statement 
There are N children, numbered 1,2, . . . ,N. 
They have decided to share K candies among themselves. 
Here, for each i (1 ≤ i ≤ N), Child i must receive between 0 and ai ​ candies (inclusive). 
Also, no candies should be left over. 

Find the number of ways for them to share candies, modulo 10^9 +7. 
Here, two ways are said to be different when there exists a child who receives a different number of candies.


Constraints 
All values in input are integers. 
1 ≤ N ≤ 100 
0 ≤ K ≤ 10^5 
0 ≤ ai ≤ K 

Input 
Input is given from Standard Input in the following format: 
N K 
a1 ​a2 . . . . aN
*/