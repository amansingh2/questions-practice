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
Delivery:
Gitika has N boxes and she wants to send them from Allahabad to Ayodhya as soon as possible. 
She has informed you of the weights of each box and has asked you to hire trucks from her best friend's agency. 
These trucks have a special carrying capacity of W Kgs , they cannot carry more that W kgs.

You need to calculate the minimum number of trucks required to deliver all the boxes as soon as possible.

Input:
The first input line contains two integers, N and W: 
the number of boxes and the maximum carrying weight of the truck.
The second line contains N integers W1 , W2 ..Wi.. Wn  representing the weight of each box.

Output:
Print one integer: the minimum number of trucks required.



Constraints

1 <= n <= 20
1 <= x <= 10^9
1 <= wi <= x

Example
Input:
4 10
4 8 6 1

Output:
2

*/