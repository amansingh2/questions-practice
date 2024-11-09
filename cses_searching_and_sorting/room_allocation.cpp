#include <bits/stdc++.h>
#define int long long
using namespace std;



int32_t main(){
    int n ; cin >> n;
    vector<vector<int>> arr;

    for(int i = 0; i < n ; i++){
        int a , b ; cin >> a >> b;
        arr.push_back({a , b , i});
    }
    sort(arr.begin() , arr.end() , [] (auto a, auto b){
        return a[0] < b[0];
    });
    int room = 1;

    vector<int>ans(n , -1);
    int room_no = 1;
    priority_queue<pair<int , int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;

    for(int i = 0 ; i < n ; i++){
        if(pq.size() == 0 || pq.top().first >= arr[i][0]){
            int end_time = arr[i][1];
            pq.push({end_time , room_no});
            ans[arr[i][2]] = room_no++;
        }else{
            auto v = pq.top();
            pq.pop();
            ans[arr[i][2]] = v.second;
            int end_time = arr[i][1];
            pq.push({end_time , v.second});
        }
    }
    cout<<room_no - 1 <<endl;
    for(int i : ans){
        cout<<i<<" ";
    }

    return 0;
}

/*
There is a large hotel, and n customers will arrive soon. 
Each customer wants to have a single room.
You know each customer's arrival and departure day. 
Two customers can stay in the same room if the departure day of the 
first customer is earlier than the arrival day of the second customer.
What is the minimum number of rooms that are needed to accommodate 
all customers? And how can the rooms be allocated?

Input
The first input line contains an integer n: the number of customers.
Then there are n lines, each of which describes one customer. 
Each line has two integers a and b: the arrival and departure day.
Output
Print first an integer k: the minimum number of rooms required.
After that, print a line that contains the room number of each 
customer in the same order as in the input. The rooms are numbered
 1,2,.......k. You can print any valid solution.
Constraints
1 <= n <= 2*10^5
1 <= a <= b <= 10^9
Example
Input:
3
1 2
2 4
4 4
Output:
2
1 2 1
*/