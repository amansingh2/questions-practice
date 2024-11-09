/*
input -> string
input -> array of sting -> []

break the 1st input string different words each of the word present in the array!


abb -> [a , b] -> 
a , b , b 

aabb -> [a , ab , b]

abb
[ab , a]

abccbc
[a , bc]
cdb
[cdb , c] -> answer should be true 
time s -> size -> N
array -> avg K , M -> KNM -> N*M
space s -> (N)
// min
[]
*/

// back tracking here
/*
cdb -> 
time -> (K)^N

space -> (K)^N
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;


bool isPresent(string s , vector<string>st){
    // 
    int n = s.size();
    vector<bool>dp(n + 1 , false);
    dp[0] = true;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < st.size() ; j++){
            bool flag = false;
            string aux = st[j];
            int idx = i - 1;
            int jdx = aux.size() - 1;
            if(idx < jdx){
                //
                continue;
            }
            while(jdx >= 0){
                if(s[idx] == aux[jdx]){
                    idx--;
                    jdx--;
                }else{
                    //
                    flag = true;
                    break;
                }
            }
            if(flag){
                continue;
            }

            dp[i] = (dp[i]|dp[i - aux.size()]);
        }
    }
    return dp[n];
}




/*
let's assume
fleet manager society se order aa rhe hai
per society kitne order hai
how many delivery fllet kitni hai

ek order ko deliver same time lagta hai

5 societ hai may be {15 , 16 , 20} -> 31 



only two delivery personal are avsa

same time for every delivery!

optime delivery time 

such t

 */


bool isPos(vector<int> & orders , int dp , int ans){
    int cnt = 0;
    int curr_sum = 0;

    for(int i = 0 ; i < orders.size() ; i++){
        if(curr_sum + orders[i] > ans){
            cnt++;
            curr_sum = orders[i];
        }else if(curr_sum + orders[i] == ans){
            cnt++;
            curr_sum = 0;
        }else{
            curr_sum += orders[i];
        }
        if(orders[i] > ans){
            return false;
        }
        if(cnt > dp){
            return false;
        }
    }

    if(curr_sum != 0){
        cnt++;
    }
    return cnt <= dp;

}

int solve(vector<int> orders , int deliverParteners){
    int high = accumulate(orders.begin() , orders.end() , 0);
    // /* */ -> log(high)*(size_of(orders))
    int low = *max_element(orders.begin() , orders.end());
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low + high)/2;
        if(isPos(orders , deliverParteners , mid)){
            ans = min(ans , mid);
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int32_t main(){
    // string s ; cin >> s;
    // int len ; cin >> len;
    // vector<string>arr(len);
    // for(int i = 0 ; i < len ; i++){
    //     cin >> arr[i];
    // }
    // // cout<<"a"<<endl;
    // cout<<(isPresent(s , arr) ? "TRUE" : "FALSE")<<endl;
    int dp ; cin >> dp;
    int order ; cin >> order;
    vector<int>orders(order);

    for(int i = 0 ; i < order ; i++){
        cin >> orders[i];
    }

    cout<<solve(orders , dp)<<endl;



    return 0;
}