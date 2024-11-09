#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
1 , 99 , 100
mean -> 67 / 66 
67 -> (100 - 67) + (99 - 67) + (67 - 1) -> 33 + 32 + 66 -> 131
66 -> (100 - 66) + (99 - 66) + (66 - 1) -> 34 + 33 + 65 -> 132
median = 99 -> (100 - 99) + (99 - 99) + (99 - 1) -> 1 + 0 + 98 -> 100
*/
 
int32_t main(){
    int n ; cin >> n;
    int k ; cin >> k;
 
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
 
    multiset<int> left , right;
    int ls = 0 , rs = 0;
    int ans = 1e9;
    for(int i = 0 ; i < n  ; i++){
        if(i >= k){
            if(left.find(arr[i - k]) != left.end()){
                left.erase(left.find(arr[i - k]));
                ls -= arr[i - k];
            }else{
                right.erase(right.find(arr[i - k]));
                rs -= arr[i - k];
            }
        }
        left.insert(arr[i]);
        ls += arr[i];
 
        right.insert(*left.rbegin());
        rs += (*left.rbegin());
 
        ls -= *prev(left.end());
        left.erase(prev(left.end()));
 
        if(left.size() < right.size()){
            left.insert(*right.begin());
            ls += *right.begin();
            rs -= *right.begin();
            right.erase(right.begin());
        }
        if(i + 1 >= k){
            // cout<<*(left.rbegin())<<" ";
            int median = *(left.rbegin());
            int k =  median * (left.size()) - ls + rs - median * (right.size());
            ans = min(ans , k);
        }
    }

    cout<<ans<<endl;
    
    return 0;
}



/*
Park
Golu and Gitika were sitting in a park when Gitika noticed there were N trees in a row. 
She challenged Golu to make at least k consecutive trees the same height. 
Since Golu has the power, granted by his grandmother, 
to increase or decrease the height of a tree by one unit per minute, 
he accepted the challenge.

Can you help Golu determine the minimum time needed to achieve what Gitika asked? 
You can assume the trees' heights are the only relevant parameter.

Input:
The first line consists of 2 integers, N (the number of trees) and K (the required number of consecutive trees with the same height).
The second line consists of N integers representing the heights of the trees.

Output:
A single line indicating the minimum time needed.


Constraints
1 <= k <= n <= 2 * 10^5
1 <= height of a tree <= 10^9

Example
Input:
4 3
8 4 2 4
Output:
2

It's good to choose [4 , 2 , 4] , and equallize their heights.

*/