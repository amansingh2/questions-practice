#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n , k ; cin >> n >> k;
    vector<pair<int , int>>arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin() , arr.end() , [] (auto a , auto b){
        return a.first < b.first;
    });

    int cnt = 0;
    // for(auto [a , b] : arr){
    //     cout<<a<<"  "<<b<<endl;
    // }
    // multiset<int>st;
    multiset<int>st;

    // for(int i = 0 ; i < n ; i++){
    //     int end = arr[i].second;
    //     int s = arr[i].first;
    //     if(st.size() < k){
    //         st.insert((-1*(end))); 
    //     }else{
    //         int val = -1*s;
    //         auto x = st.lower_bound(val) ;
    //         if(x != st.end()){
    //             st.erase(st.find((*x)));
    //             st.insert((-1*end));
    //         }else{
    //             cnt++;
    //             // cout<<cnt<<" ";
    //         }
    //     }
    // }
    int ans = 0 ;

    for(int i = 0 ; i < n ; i++){
        if(st.size() < k){
            st.insert(arr[i].second);
        }else{
            auto small = st.begin();
            auto large = st.rbegin();

            if(arr[i].first >= (*small)){
                ans++;
                st.erase(st.begin());
                st.insert(arr[i].second);
            }else if(arr[i].second < (*large)){
                st.erase(st.find(*large));
                st.insert(arr[i].second);
            }
        }
    }

    cout<<ans + st.size()<< endl;
    
    return 0;
}


/*
In a movie festival, n movies will be shown. Syrjälä's movie club consists of k members, who will be all attending the festival.
You know the starting and ending time of each movie. What is the maximum total number of movies the club members can watch entirely if they act optimally?
Input
The first input line has two integers n and k: the number of movies and club members.
After this, there are n lines that describe the movies. Each line has two integers a and b: 
the starting and ending time of a movie.
Output
Print one integer: the maximum total number of movies.
Constraints

1 \le k \le n \le 2 \cdot 10^5
1 \le a < b \le 10^9

Example
Input:
5 2
1 5
8 10
3 6
2 5
6 9

Output:
4
*/