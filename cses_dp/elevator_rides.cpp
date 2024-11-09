#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int n ; cin >> n;
    int x ; cin >> x;

    vector<int>v(n , 0);

    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }

    vector<pair<int,int>>dp((1 << n) , {n + 1 , x + 1});
    dp[0] = {1 , 0};

    for(int mask = 1 ; mask < (1 << n) ; mask++){
        for(int pi = 0 ; pi < n ; pi++){
            if(((mask)&(1 << pi)) != 0){
                // ith ke bina kya tha 
                auto prev = dp[((1<<pi)^(mask))];
                int w = prev.second;
                int rides = prev.first;
                // ith ko include kr rhe hai
                if(w + v[pi] <= x){
                    w += v[pi];
                }else{
                    rides++;
                    w = v[pi];
                }

                dp[mask] = min(dp[mask] , {rides , w});
            }
        }
    }

    cout<<dp[(1 << n) - 1 ].first<<endl;

    return 0;
}


/*
There are n people who want to get to the top of a building which has only one elevator. 
You know the weight of each person and the maximum allowed weight in the elevator. 
What is the minimum number of elevator rides?
Input
The first input line has two integers n and x: the number of people and the maximum allowed weight 
in the elevator.
The second line has n integers w_1,w_2,\dots,w_n: 
the weight of each person.
Output
Print one integer: the minimum number of rides.
Constraints

1 \le n \le 20
1 \le x \le 10^9
1 \le w_i \le x

Example
Input:
4 10
4 8 6 1

Output:
2
    
    

*/