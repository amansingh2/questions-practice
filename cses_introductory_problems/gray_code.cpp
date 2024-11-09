#include <bits/stdc++.h>
#define int long long
using namespace std;

string get_val(int n ,int  val){
    vector<int> res;
    while(val > 0){
        if(val % 2 == 0){
            res.push_back(0);
        }else{
            res.push_back(1);
        }
        val /= 2;
    }
    while((int)res.size() < n){
        res.push_back(0);
    }
    reverse(res.begin() , res.end());
    string ans;
    if(res[0] == 0){
        ans += '0';
    }else{
        ans += '1';
    }

    for(int i = 1 ; i < n ; i++){
        int k = (res[i] + res[i - 1]) % 2;
        if(k == 0){
            ans += '0';
        }else{
            ans += '1';
        }
    }

    return ans;
}

int32_t main(){
   int n ; cin >> n;
   for(int i = 0 ; i < (1 << n) ; i++){
        cout<<get_val(n , i)<<endl;
   }

    return 0;
}







/*

BRUTE - FORCE - SOLUTION!

string get_val(int n ,int  val){
    string res;
    while(val > 0){
        if(val % 2 == 0){
            res.push_back('0');
        }else{
            res.push_back('1');
        }
        val /= 2;
    }
    while((int)res.size() < n){
        res.push_back('0');
    }
    reverse(res.begin() , res.end());
    return res;
}
bool can_take(string & a , string & b){
    int cnt_a = 0;
    int cnt_b = 0;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] == '1'){
            cnt_a++;
        }
        if(b[i] == '1'){
            cnt_b++;
        }
    }
    return (abs(cnt_a - cnt_b) == 1 ? true : false);
}
bool solve(string  prev , vector<string> & bits , unordered_set<string>& st , int & cnt , int n , vector<string> & ans){
    if(cnt == ((1 << n))){
        return true;
    }
    for(auto & s : bits){
        if(can_take(prev , s) && st.find(s) == st.end()){
            st.insert(s);
            // cout<<s<<endl;
            ans.emplace_back(s);
            cnt++;
            if(solve(s , bits , st , cnt , n , ans)){
                return true;
            }
            ans.pop_back();
            st.erase(st.find(s));
            cnt--;
            // return false;
        }
    }
    return false;
}

int32_t main(){
    int n ; cin >> n;
    // vector<string> g[n+1];
    vector<string>bits;
    string prev;
    unordered_set<string>st;
    vector<string> ans;
    for(int i = 0 ; i < (1 << n) ; i++){
        // int x = __builtin_popcount(i);
        string res = get_val(n , i);
        if(i == 0){
            prev = res;
            // cout<<res<<endl;
            ans.emplace_back(res);
            st.insert(res);
            // continue;
        }
        // cout<<res<<endl;
        // g[x].push_back(res);
        bits.push_back(res);
    }
    // cout<<bits.size()<<endl;
    int cnt = 1;
    solve(prev , bits , st , cnt , n , ans);
    // cout<<(can_take("0001" , "0000") ? "YES" : "NO")<<endl;
    // cout<<(can_take("0010" , "1001") ? "YES" : "NO" )<<endl;
    // cout<<get_val(n , n - 5)<<endl;
    // int i = 0;
    // for(auto v : g){
    //     cout<<i<<" "<<v.size()<<endl;
    //     i++;
    // }
    // cout<<endl;
    // i = 0;
    // for(auto v : g){
    //     // cout<<i<<" "<<v.size() - 1 <<endl;
    //     i++;
    // }
    for(auto & it : ans){
        cout<<it<<endl;
    }



    return 0;
}
*/
/*
A Gray code is a list of all 2^n bit strings of length n, 
where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n.
Input
The only input line has an integer n.
Output
Print 2^n lines that describe the Gray code. You can print any valid solution.
Constraints

1 <= n <= 16
Example
Input:
2
Output:
00
01
11
10
*/



