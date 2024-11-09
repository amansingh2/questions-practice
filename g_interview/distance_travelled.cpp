#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(vector<int>&arr , int i , int n , int curr_filled , int capacity , vector<vector<int>>& dp){
    if(i == n || curr_filled < 0){
        return 0;
    }
    if(dp[i][curr_filled] != -1){
        return dp[i][curr_filled];
    }
    
    int res = 0;
    if(curr_filled == 0){
        res = solve(arr , i + 1 , n , curr_filled + 1 , capacity , dp);
    }else if(curr_filled  < capacity){
        res = max(  arr[i] + solve(arr , i + 1 , n , curr_filled - 1 , capacity , dp) ,
                    solve(arr , i + 1 , n , curr_filled + 1 , capacity , dp) );
    }else{
        res = max(arr[i] +  solve(arr , i + 1 , n , curr_filled - 1 , capacity , dp) , 
                solve(arr , i + 1 , n , curr_filled  , capacity , dp) );
    }

    return dp[i][curr_filled] = res;
}

int32_t main(){
    int n , k ; cin >> n >> k;
    vector<int>arr(n, 0);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(n + 1 , vector<int>(k + 1 , -1));
    cout<<solve(arr , 0 , n , 1 , k , dp)<<endl;

    return 0;
}




/*
Question - Suppose you are driving a car. You are given an speed array. 
The distance which can be travelled on ith day is speed[i]. 
You have k tank capacity and each day consumes 1 amount of fuel. 
Now, you can pass any ith day to refuel and gain 1 fuel but it is limited by the tank capacity. 

If you already have a full tank then you will gain nothing. 
Assuming you will start with a full tank, 
What is the maximum distance which can be travelled?

Example
speed = [5,30,0,25,0,1,9]
k=3


speed = [5, 10, 6]
k = 1

*/