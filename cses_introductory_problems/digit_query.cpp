#include <bits/stdc++.h>
#define int long long
using namespace std;

int get_dig(int len , int num){
    vector<int>arr(len , 0);
    arr[0] = 1;
    cout<<len<<" "<<num<<endl;

    int kon_sa = num/len;
    int kon = num % len;

    if(kon != 0){
        kon_sa++;
    }
    int x = 1;
    // cout<<kon_sa<<" "<< kon << endl;
    for(int i = 0 ; i < len ; i++){ 
        int val = pow(10 , len - i - 1);
        // cout<<val<<endl;
        while(kon_sa - x >= val){
            arr[i]++;
            x += val;
        }
    }

    // cout<<"printing arr "<<endl;
    // for(int i : arr){
    //     cout<<i<<" ";
    // }
    // cout<<endl<<"printed arr "<<endl;

    if(kon == 0){
        return arr[len - 1];
    }

    return arr[kon - 1];
}

int32_t main(){
    int q;cin>>q;
    while(q--){
        int k; cin >> k;
        int x = 9;
        int t = 1;
        // if(q == 0){
        //     cout<<k<<endl;
        // }
        // continue;
        while(k - x > 0){
            k -= x;
            t++;
            x = 9 * pow(10 , t - 1) * t;
        }
        // cout<<t<<" "<<k<<endl;
        cout<<get_dig(t , k)<<endl;

    }
    return 0;
}

/*
Consider an infinite string that consists of all positive integers in increasing order:
12345678910111213141516171819202122232425...

Your task is to process q queries of the form: what is the digit at position k in the string?
Input
The first input line has an integer q: the number of queries.
After this, there are q lines that describe the queries. Each line has an integer k: 
a 1-indexed position in the string.
Output
For each query, print the corresponding digit.
Constraints

1 <= q <= 1000
1 <= k <= 10^18

Example
Input:
3
7
19
12

Output:
7
4
1
    
    

*/