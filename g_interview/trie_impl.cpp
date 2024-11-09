#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs(int curr_node , string & ans , string & aux , vector<vector<int> > & trie , vector<bool> & is_ending_here){
    if(aux.size() > ans.size()){
        ans = aux;
    }
    for(int i = 0 ; i < 26  ;i++){
        int tmp = trie[curr_node][i];
        if(tmp != 0 && is_ending_here[tmp]){
            aux.push_back(char(i + 'a'));
            dfs(tmp , ans , aux , trie , is_ending_here);
            aux.pop_back();
        }
    }
}


// special trie implementation!!!!

string solve(vector<string> & arr){
    vector<vector<int>> trie(1 , vector<int>(26)); //int trie [1][26];
    vector<bool> is_ending_here(1); // bool is_terminal[1];
    int id = 0;
    for(string s : arr){
        int curr_node = 0;
        for(char c : s){
            if(trie[curr_node][c - 'a'] == 0){
                trie.push_back(vector<int>(26));
                is_ending_here.push_back(false);
                trie[curr_node][c - 'a'] = ++id;
            }
            curr_node = trie[curr_node][c - 'a'];
        }
        is_ending_here[curr_node] = true;
    }

    string ans;
    string aux;
    dfs(0 , ans , aux , trie , is_ending_here);
    return ans;
}

int32_t main(){
    int n ; cin >> n;
    vector<string> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    cout<<solve(arr);


    return 0;
}
