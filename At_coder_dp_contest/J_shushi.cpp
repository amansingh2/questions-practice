#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    vector<int>arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    
    return 0;
}

/*
Problem Statement 
There are N dishes, numbered 1,2, . . . ,N. 
Initially, for each i (1 ≤ i ≤ N), Dish i has ai (1 ≤ ai ​≤ 3) pieces of sushi on it. 
Taro will perform the following operation repeatedly until all the pieces of sushi are eaten: 
Roll a die that shows the numbers 1,2, . . . ,N with equal probabilities, and let i be the outcome. 
If there are some pieces of sushi on Dish i, eat one of them; if there is none, do nothing. 
Find the expected number of times the operation is performed before all the pieces of sushi are eaten. 

Constraints 
All values in input are integers. 
1 ≤ N ≤ 300 
1 ≤ ai ≤ 3 

Input 
Input is given from Standard Input in the following format: 
N 
a1 ​a2 . . . aN 

Output 
Print the expected number of times the operation is performed before all the pieces of sushi are eaten. 
The output is considered correct when the relative difference is not greater than 10^-9 .
*/