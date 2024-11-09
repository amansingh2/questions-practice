#include <bits/stdc++.h>
#define int long long
using namespace std;
int change(vector<int> & v1 , int b){
    vector<int>v2;
    while(b != 0){
        v2.push_back(b%10);
        b /= 10;
    }
    reverse(v2.begin() ,v2.end());
    int i = 0; 
    int j = 0;
    int ans = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] != v2[i]){
            ans++;
        }
        i++;
        j++;
    }
    while(i < v1.size()){
        ans++;
        i++;
    }
    while(j < v2.size()){
        ans++;
        j++;
    }
    return ans;
}
int32_t main(){
    int t;cin>>t;
    while(t--){
        int n ; cin >> n ; 
        string s ; cin >> s;
        vector<int>v;
        for(int i = n - 3 ; i < n  ; i++){
            v.push_back((int)(s[i] - '0'));
        }
        int nc = 4;
        int val;
        for(int i = 1 ; i < 999 ; i++){
            if(i%8 == 0){
                int aux = change(v,i);
                if(aux < nc){
                    nc = aux;
                    val = i;
                }
            }
        }
        for(int i = 0 ; i < n - 3 ; i++){
            cout<<s[i];
        }
        cout<<val<<endl;

    }
    return 0;
}