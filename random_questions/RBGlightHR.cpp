#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(vector<vector<int>> & arr, int n, int sl){
    // vector<vector<int>>aux(4,vector<int>(sl+2,0));
    // for(int i = 0 ; i < n ; i++){
    //     aux[arr[i][0]][arr[i][1]] += 1;
    //     aux[arr[i][0]][arr[i][2] + 1] -= 1;
    // }
    // for(int i = 1 ;  i <= 3  ; i++){
    //     for(int j = 1 ; j <= sl  ; j++){
    //         aux[i][j] += aux[i][j-1];
    //     }
    // }
    // int ans = 0;
    // for(int i = 1 ; i <= sl ; i++){
    //     if(aux[1][i] > 0 &&  aux[2][i] > 0 && aux[3][i] > 0){
    //         ans++;
    //     }
    // }
    // return ans;
    // map<int,set<int> > mp;
    // for(int i = 0 ; i <= sl ; i++){
    //     mp[i];
    // }
    // for(auto v : arr){
    //     for(int i = v[1] ; i <= v[2]  ; i++){
    //         mp[i].insert(v[0]);
    //     }
    //     // mp[]
    // }
    // int ans = 0;
    // for(auto [a,b] : mp){
    //     if(b.size() == 3){
    //         ans++;
    //     }
    // }
    map<int,int[3] > mp; 
    for(int i = 0 ; i <= sl ; i++){
        mp[i];
    }
    for(auto v : arr){
        // for(int i = v[1] ; i <= v[2]  ; i++){
        //     mp[i][v[0]-1]++;
        // }
        mp[v[1]][v[0]- 1] += 1;
        mp[v[2] + 1][v[0] -1] -= 1;
    }
    for(int i = 0 ; i < 3 ; i++){
        int aux = 0;
        for(auto &[a,b] : mp){
            b[i] += aux;
            aux = b[i];
        }
    }

    int ans = 0;
    for(auto [a,b] : mp){
        if(b[0] > 0 && b[1] > 0 && b[2] > 0){
            ans++;
        }
    }

    return ans;
}
int32_t main(){
        int n;cin>>n;
        int m;cin>>m;
        vector<vector<int>>arr(m,vector<int>(3,0));
        for(int i = 0 ; i < m ; i++){
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        }
        int ans = solve(arr,m,n);
        cout<<ans<<endl;
    return 0;
}
