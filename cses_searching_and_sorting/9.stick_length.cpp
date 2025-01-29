#include <bits/stdc++.h>
#define int long long
using namespace std;

// median pe distance minimum hota hai from all points but think why ????????!!!1

int32_t main(){
    int n ; cin >> n;
    vector<int>arr(n , 0);

    for(int i  = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr.begin() , arr.end());
    int ans = 1e15;


    int left_sum = 0;
    int right_sum = accumulate(arr.begin() , arr.end() , 0LL); // LL parameter dena bahut jaruri hai!

    for(int i = 0 ; i < n ; i++){
        right_sum -= arr[i];
        // cout<<right_sum<<endl;
        int curr_ans = abs(right_sum - (n - 1 - i)*arr[i]);
        // // if(i == n - 1)
        // // cout<<right_sum<<" , "<<curr_ans<<endl;

        curr_ans += abs(i*arr[i] - left_sum) ;
        left_sum += arr[i];
        // // cout<<left_sum<<endl;
        ans = min(ans , curr_ans);
    }
    cout<<ans<<endl;


    return 0;
}

/*
There are n sticks with some lengths. Your task is to modify the sticks so that each stick 
has the same length.
You can either lengthen and shorten each stick.
Both operations cost x where x is the difference between the new and original length.
What is the minimum total cost?

Input
The first input line contains an integer n: the number of sticks.
Then there are n integers: p_1,p_2,....,p_n: the lengths of the sticks.

Output
Print one integer: the minimum total cost.
Constraints

1 <= n <= 2 * 10^5
1 <= p_i <= 10^9

Example
Input:
5
2 3 1 5 2

Output:
5
*/