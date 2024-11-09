#include <bits/stdc++.h>
#define int long long
using namespace std;

// bool solve(){
//     int n ; cin >> n;
//     vector<int> arr (n);
//     int cs = 0 ;
//     for(int i = 0 ; i < n ; i++){
//         cin >> arr[i];
//         cs += arr[i];
//     }
//     // if(n == 2){
//         // return false;
//     // }
//     /*
//     1 2 3 4 5 6 7 8
//      -> 36/2 -> 18

//     -> 17 , 16 , 15 , 14
//     -> 
//     */
//     int aux  = cs;
//     cs = (cs + 1)/2;

//     vector<int> dp(cs + 1 , false);
//     dp[0] = 1 ;

//     for(int i : arr){
//         for(int j = cs ; j - i >= 0 ; j--){
//             dp[j] += dp[j - i];
//         }
//     }
//     for(int i = 0 ; i <= cs ; i++){
//         cout<<i<<" --> "<< dp[i]<<endl;
//     }

//     if(aux % 2 == 0){
//         for(int i : arr){
//             if(i % 2 == 0 && dp[(aux - i)/2] > 2){
//                 return true;
//             }
//         }
//     }else{
//         for(int i : arr){
//             if(i % 2 == 1 && dp[(aux - i)/2] > 2){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

bool solve_asli_wala(vector<int> arr){
    int sum = 0;
    for(int i : arr){
        sum += i;
    }
    if(sum % 2 == 1){
        return false;
    }
    sum /= 2;
    vector<int> dp (sum + 1  , false);
    dp[0] = true;
    
    for(int i : arr){
        for(int j = sum ; j >= 0 ; j--){
            if(j - i >= 0){
                dp[j] = dp[j]|dp[j - i];
            }
        }
    }
    return dp[sum];
}
bool solve(){
    int n ; cin >> n;
    vector<int> arr (n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    for(int i = 0  ; i <  n ;  i++){
        vector<int>aux;
        for(int j = 0 ; j < n ; j++){
            if(i != j){
                aux.push_back(arr[j]);
            }
        }
        if(solve_asli_wala(aux)){
            return true;
        }
    }
}
int32_t main(){
    cout<<(solve()?"YES":"NO")<<endl;
    return 0;
}



/*
Round 2

You are given an array of elements. Return true if you can remove an 
element from the array and resultant array can be partitioned into two 
halves having equal sum. Else return false.

Ex - 1 > 2 > 1 > 3
Returns true because after removing 1 (i = 2), 1 + 2 = 3.

Ex - 3 > 2 > 1 > 1
Returns true because after removing 1 (i = 2), 3 = 2 + 1

Ex - 1 > 20 > 30 > 4
Returns false since no element's removal can distribute the array into two equal halves.

*/