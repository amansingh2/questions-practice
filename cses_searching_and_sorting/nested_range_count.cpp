#include <bits/stdc++.h>
// #define int long long
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
template <typename T >

using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ; 



// try to solve it using segment tree as well ! {we might need to compress the values :)}
/*
co-ordinate compression

// we need to comment - out long long think why ? 

*/
int32_t main(){
    int n ; cin >> n;
    vector<vector<int>>arr(n , vector<int> (3 , 0));

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }

    sort(arr.begin() , arr.end() , [] (const auto & a , const auto & b) {
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    });

    ordered_set<pair<int , int> > os;

    vector<int> contained(n , 0 ) , contains(n , 0);

    for(int i = 0 ; i < n ; i++){
        os.insert({arr[i][1] , -i});
        contained[arr[i][2]] = (os.size() - os.order_of_key({arr[i][1] , -i}) - 1);
    }
    os.clear();

    for(int i = n - 1 ; i >= 0 ; i--){
        os.insert({arr[i][1] , -i});
        contains[arr[i][2]] = os.order_of_key({arr[i][1] , -i});
    }

    for(int i = 0 ; i < n ; i++){
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    for(int i = 0 ; i < n ; i++){
        cout<<contained[i]<<" ";
    }
    return 0;
}

/*
Given n ranges, your task is to count for each range how many other ranges it contains 
and how many other ranges contain it.
Range [a,b] contains range [c,d] if a <= c and d <= b.
Input
The first input line has an integer n: the number of ranges.
After this, there are n lines that describe the ranges. 
Each line has two integers x and y: the range is [x,y].
You may assume that no range appears more than once in the input.
Output
First print a line that describes for each range (in the input order) 
how many other ranges it contains.
Then print a line that describes for each range (in the input order) 
how many other ranges contain it.
Constraints

1 <= n <= 2 * 10^5
1 <= x < y <= 10^9

Example
Input:
4
1 6
2 4
4 8
3 6

Output:
2 0 0 0
0 1 0 1
*/

