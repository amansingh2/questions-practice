#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =  tree< int, null_type  ,less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// #define int long long

int32_t main(){
    int n , k ; cin >> n >> k;

    ordered_set<int> v;
    for(int i = 1 ; i <= n ; i++){
        v.insert(i);  
    }
    int sp = 0;
    while(v.size() > 0){
        sp %= v.size();
        int to_remove = (k + sp) % (v.size());
        sp = to_remove;
        auto it = v.find_by_order(to_remove);
        cout<<*it<<" ";
        v.erase(it);
    }
    
    return 0;
}
/*
Consider a game where there are n children (numbered 1,2, ... ,n) in a circle. 
During the game, repeatedly k children are skipped and one child is removed from the circle. 
In which order will the children be removed?
Input
The only input line has two integers n and k.
Output
Print n integers: the removal order.
Constraints

1 <= n <= 2 * 10^5
0 <= k <= 10^9

Example
Input:
7 2

Output:
3 6 2 7 5 1 4

*/