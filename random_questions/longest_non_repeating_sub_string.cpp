#include <bits/stdc++.h>
#define int long long
using namespace std;


int solve(string & s){
    unordered_map<char , int > mp;
    int ans = 0;
    for(int i = 0 , j = 0 ; i < s.size() ; i++){
        mp[s[i]]++;
        while(mp[s[i]] > 1){
            mp[s[j]]--;
            if(mp[s[j]] == 0){
                mp.erase(s[j]);
            }
            j++;
        }
        ans = max(ans , i - j + 1);
    }
    return ans;
}

int32_t main(){
    // int t;cin>>t;
    // while(t--){
        string s = "abcdefhhh";
        cout<<solve(s)<<endl;







    // }
    return 0;
}
