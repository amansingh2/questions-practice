#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        // Compare based on the first parameter (min priority)
        if (p1.first == p2.first) {
            return p1.second > p2.second;  // If first parameter is equal, compare by second parameter
        }
        return p1.first > p2.first;  // Min heap comparison
    }
};

int32_t main(){
        int n , m ; cin >> n >> m;
        vector<vector<int>> vp(m , vector<int>(4 , 0));

        for(int i = 0 ; i < m ; i++){
            cin >> vp[i][0];
        }

        for(int i = 0 ; i < m ; i++){
            cin >> vp[i][1];
        }
        for(int i = 0 ; i < m ; i++){
            vp[i][2] = i;
        }

        sort(vp.begin() , vp.end() , [](const auto & a , const auto & b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> mpq;

        for(int i = 1 ; i <= n ; i++){
            mpq.push({0 , i});
        }

        for(int i = 0 ; i < m ; i++){
            auto node = mpq.top();
            int time_to_free = node.first;
            int dp = node.second;
            if(time_to_free <= vp[i][0]){
                vp[i][3] = dp;
                mpq.pop();
                mpq.push({vp[i][0] + vp[i][1] , dp});
            }else{
                vp[i][3] = -1;
            }
        }

        sort(vp.begin() , vp.end() , [](const auto & a , const auto & b){
            return a[2] < b[2];
        });

        for(auto v : vp){
            cout<<v[3]<<" ";
        }
        cout<<endl;

    return 0;
}


/*
Order Assignment Service
A logistics company aims to develop an order assignment system that distributes orders fairly 
among delivery partners.

There are N delivery partners, indexed from 1 to N, and M orders to be processed. 
The i-th order arrives at arrival[i] and takes deliveryTime[i] to execute. 
The system assigns the order to the available delivery partner with the lowest index.

A delivery partner assigned to the i-th order is unavailable from time 
arrival[i] to arrival[i] + deliveryTime[i]. Once the time reaches arrival[i] + deliveryTime[i], 
the delivery partner becomes available for new orders.

For each order, given N, arrival, and deliveryTime, 
determine the index of the delivery partner that delivers it. 
If no delivery partner is available when the order arrives, the order is dropped, 
and the output should be -1 for that order. In case multiple orders arrive at the same time, 
the one with the smaller index is assigned first.

Input Format:
The first line contains two integers N (number of delivery partners) and M (number of orders).
The second line contains M space-separated integers representing the arrival times of the orders.
The third line contains M space-separated integers representing the delivery times for each order.
Output Format:
Output M space-separated integers representing the index of the delivery partner assigned to each order.
If an order is dropped, output -1 for that order.
*/