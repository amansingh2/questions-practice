#include <bits/stdc++.h>
#define int long long
using namespace std;
// 1 2 3 4
// 1 2 3 4 5 
int32_t main(){
    int n ; cin >> n;
    vector<int>v;
    for(int i = 0 ; i < n ; i++){
        v.push_back(i + 1);
    }

    while(v.size() > 1){
        vector<int>v1;
        for(int i = 0 ; i < v.size() ; i++){
            if(i % 2 == 0){
                v1.push_back(v[i]);
            }else{
                cout<<v[i]<<" ";
            }
        }
        if(v.size() % 2 == 0){
            v = v1;
        }else{
            int node = v1.back();
            v1.pop_back();
            v.clear();
            v.push_back(node);
            for(int i : v1){
                v.push_back(i);
            }
        }
    }
    cout<<v[0]<<" ";
    return 0;
}
/*
Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. 
During the game, every other child is removed from the circle until there are no children left. 
In which order will the children be removed?
Input
The only input line has an integer n.
Output
Print n integers: the removal order.
Constraints

1 <= n <= 2 * 10^5

Example
Input:
7

Output:
2 4 6 1 5 3 7
*/