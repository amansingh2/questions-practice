// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// class Seg{
//     private:
//         vector<int>arr;
//         void 

//     public:
//         Seg(vector<int> & v){
//             arr = v;
//         }
//         int n = arr.size();
//         vector<int> tree(4*n + 1 , 0);

//         void build()




// };

// int32_t main(){
//     int t;cin>>t;
//     while(t--){







//     }
//     return 0;
// }

// /*
// Given an array of n integers, your task is to process q queries of the following types:

// increase each value in range [a,b] by u
// what is the value at position k?

// Input
// The first input line has two integers n and q: the number of values and queries.
// The second line has n integers x_1,x_2,......,x_n: the array values.
// Finally, there are q lines describing the queries. Each line has three integers: 
// either "1 a b u" or "2 k".
// Output
// Print the result of each query of type 2.
// Constraints

// 1 <= n,q <= 2 * 10^5
// 1 <= x_i, u <= 10^9
// 1 <= k <= n
// 1 <= a <= b <= n

// Example
// Input:
// 8 3
// 3 2 4 5 1 1 5 3
// 2 4
// 1 2 5 1
// 2 4

// Output:
// 5
// 6
    
    


// */




#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(vector<int> & nums , vector<vector<int>> & res , int left , int right){
    if(left == right){
        res.push_back(nums);
        return ;
    }
    for(int i = left ; i <= right ; i++){
        swap(nums[i] , nums[left]);
        solve(nums , res , left + 1 , right);
        swap(nums[i] , nums[left]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    solve(nums , res , 0 , n - 1);
    return res;
}

int32_t main(){
    int n ; cin >> n;
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        arr[i] = i + 1;
    }

    vector<vector<int>> ans = permute(arr);
    map<int , int> mp;
    for(auto v : ans){
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(v[i] > v[j]){
                    cnt++;
                }
            }
        }
        mp[cnt]++;
    }

    for(auto [a , b] : mp){
        cout<<a<<"  ->  "<< b<<endl;
    }

    return 0;
}




