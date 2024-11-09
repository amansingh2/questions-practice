#include <bits/stdc++.h>
#define int long long
using namespace std;

// kuchh videshi algorithm hai convex hull

int32_t main(){
    int N , C ; cin >> N >> C;

    vector<int>arr(N);

    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }



    






    return 0;
}

/*
Problem Statement 
There are N stones,numbered 1,2 . . ,N. For each i (1 ≤ i ≤ N), the height of Stone i is hi. 
Here, h1 < h2 < hN ​ holds. There is a frog who is initially on Stone 1. 
He will repeat the following action some number of times to reach Stone N: 
If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2, . . ,N. 

Here, a cost of (hj − hi)^2 + C is incurred, where j is the stone to land on. 

Find the minimum possible total cost incurred before the frog reaches Stone N. 

Constraints All values in input are integers. 
2 ≤ N ≤ 2×10^5 
1 ≤ C ≤ 10^12 
1 ≤ h1 < h2 < hN ​≤ 10^6 

Input 
Input is given from Standard Input in the following format: 
N C 
h1 ​h2 . . .hN ​
*/