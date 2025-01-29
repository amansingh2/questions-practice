#include <bits/stdc++.h>
#define int long long
using namespace std;
void print_arr(vector<int>arr){
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
// approach 2nd
void solve(vector<int> &a , vector<int> &s , int n , int m , int k){
    sort(a.begin() , a.end());
    sort(s.begin() , s.end());

    int ans = 0;

    list<int>ls;
    for(int i : a){
        ls.push_back(i);
    }

    for(int i : s){
        while(ls.size() > 0 && i - ls.front() > k){
            ls.pop_front();
        }
        if(abs(ls.front() - i) <= k){
            ans++;
            ls.pop_front();
        }
    }

    cout<<ans<<endl;
}
int32_t main(){
    int n , m , k ; cin >> n >> m >> k;

    vector<int>a(n , 0) , s(m , 0);
    for(int i = 0  ; i < n ; i++){
        cin >> a[i];              // apartment sizes
    }

    for(int j = 0 ; j < m ; j++){
        cin >> s[j];            // desired sizes , answer can at max be 'm';
    }
    solve(a , s , n , m , k);
    // sort(a.begin() , a.end());
    // sort(s.begin() , s.end());

    // print_arr(a);
    // print_arr(s);

    // int ans = 0;
    // int i = 0 , j = 0;

    // while(i < n && j < m){
    //     if(abs(a[i] - s[j]) <= k){
    //         // cout<<i << " " << j << " "<< a[i] - s[j] << " "<<s[j] - a[i]<<endl;
    //         ans++ , i++ , j++;
    //     }else if(a[i] > s[j]){
    //         j++;
    //     }else{
    //         i++;
    //     }
    // }

    // cout<<ans<<endl;


    return 0;
}


/*
There are n applicants and m free apartments. 
Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
Each applicant has a desired apartment size, 
and they will accept any apartment whose size is close enough to the desired size.


Input
The first input line has three integers n, m, and k: 
the number of applicants, the number of apartments, and the maximum allowed difference.
The next line contains n integers a_1, a_2, ... a_n: the desired apartment size of each applicant. 
If the desired size of an applicant is x, they will accept any apartment whose size is between x-k and x+k.
The last line contains m integers b_1, b_2, .... b_m: the size of each apartment.

Output
Print one integer: the number of applicants who will get an apartment.
Constraints

1 <= n, m <= 2*10^5
0 <= k <= 10^9
1 <= a_i, b_i <= 10^9

Example
Input:
4 3 5
60 45 80 60
30 60 75

Output:
2
*/