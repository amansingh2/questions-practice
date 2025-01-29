#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
vector<int>solve(vector<vector<int>> & vp , int x){
    vector<int>r1;
    int i = 0;
    int j = vp.size() - 1;
    while(i < j){
        if(vp[i][2] + vp[j][2] == x){
            vector<int>res;
            res.push_back(vp[i][0]);
            res.push_back(vp[i][1]);
            res.push_back(vp[j][0]);
            res.push_back(vp[j][1]);
            sort(res.begin() , res.end());
            // cout<<"a"<<endl;
            bool flag = true;
            for(int it = 1 ; it < 4 ; it++){
                if(res[it] == res[it - 1]){
                    flag = false;
                }
            }
            // i++;
            j--;
            if(flag){
                return res;
            }
        }else if(vp[i][2] + vp[j][2] > x){
            j--;
        }else{
            i++;
        }
    }
    return r1;
}
*/

int32_t main(){
    int n , x ; cin >> n >> x;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    // vector<vector<int>>vp;
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = i + 1 ; j < n ; j++){
    //         vector<int>v;
    //         v.push_back(i + 1);
    //         v.push_back(j + 1);
    //         v.push_back(arr[i] + arr[j]);
    //         vp.push_back(v);
    //     }
    // }

    // sort(vp.begin() , vp.end() , [](auto a , auto b){
    //     return a[2] < b[2];
    // });
    // cout<<(int)vp.size()<<endl;
    // for(int i : vp[vp.size() - 1]){
    //     // cout<<i<<" ";
    // }
    // for(auto i : vp){
        // cout<<i[2]<<" ";
    // }
    // cout<<endl;
    // vector<int> ans = solve(vp , x);
    vector<int>ans;
    map<int , pair<int , int>>mp;
// socho kaise hua !!
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            int sum = arr[i] + arr[j];
            int req_sum = x - sum;
            if(mp.find(req_sum) != mp.end()){
                cout<<i + 1 << " " << j + 1 << " " << mp[req_sum].first + 1 <<" "<<mp[req_sum].second + 1<<endl;
                return 0;
            }
        }
        for(int j = 0 ; j < i ; j++){
            mp[arr[i] + arr[j]] = {i , j};
        }   
    }

    cout<<"IMPOSSIBLE"<<endl;    
    return 0;
}

/*
You are given an array of n integers, and your task is to find four values (at distinct positions) 
whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
Print four integers: the positions of the values. If there are several solutions, 
you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints

1 \le n \le 1000
1 \le x,a_i \le 10^9

Example
Input:
8 15
3 2 5 8 1 3 2 3

Output:
2 4 6 7
*/