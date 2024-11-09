// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// int solve(vector<int> & arr){
//     int cnt = 1;
//     int ans = 1;
//     int n = arr.size();

//     int res = arr[0];
//     int sum = arr[0];

//     for(int i = 1 ; i < n ; i++){
//         if(arr[i] - arr[i-1] == 1){
//             cnt++;
//             sum = sum + arr[i];


//         }else{
//             cnt = 1;
//             sum = arr[i];
//         }
//         ans += cnt;
//         res += sum;
//     }

//     cnt = 0;
//     sum = 0;

//     for(int i = 1 ; i < n ; i++){
//         if(arr[i] - arr[i-1] == -1){
//             cnt++;
//             if(sum == 0){
//                 sum = sum + arr[i] + arr[i - 1];
//             }else{
//                 sum += arr[i];
//             }
            
//         }else{
//             cnt = 0;
//             sum = 0;
//         }
//         ans += cnt;
//         res += sum;
//     }

//     return res;
// }

// /*

// -> O(N * N) -> 
// Ex: arr = [9,2,3,4,5,6,5] // 6
// So ans should be sum of all the good subarrays which are:

// [2], [3], [4], [5], [6], [5] // 25
// [2,3], [3,4], [4,5], [5,6], [6,5]
// [2,3,4], [3,4,5], [4,5,6]
// [2,3,4,5], [3,4,5,6]
// [2,3,4,5,6]

// 2 3 4 -> 5

// 5
// 4 5
// 3 4 5
// 2 3 4 5

// 4 * 5 + 3 * 4 + 2 * 3 + 1 * 2 -> 

// 5 
// 2 3 4 5
// 5
// 3 4 5
// 4 5

// */
int solve(vector<int>arr){
    int n = arr.size();
    int sum = 0;
    int ans = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(i == 0){
            sum += arr[i];
            ans += arr[i];
        }else if(arr[i] - arr[i - 1]){
            int aux = 0;
            for(int k = i ; k >= 0 ; k--){
                aux += arr[k];
                ans += aux;
                if(k > 0 && arr[k] - arr[k - 1] != 1){
                    break;
                }
            }
        }else{

        }

    }
}
int32_t main(){
    int t;cin>>t;
    while(t--){
        vector<int> arr = {2,3,4,5,6,5};
        cout<<solve(arr)<<endl;



    }
    return 0;
}


