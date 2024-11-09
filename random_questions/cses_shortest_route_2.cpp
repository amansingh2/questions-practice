//CSES shortest route - 2

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,m,q;cin>>n>>m>>q;
    vector<vector<int>>mat(n+1,vector<int>(n+1,(int)1e14));

    for(int i = 0 ; i < m ; i++){
        int a,b,c;cin>>a>>b>>c;
        mat[a][a] = 0;
        mat[b][b] = 0;
        mat[a][b] = min(mat[a][b],c);
        mat[b][a] = min(mat[b][a],c);
    }

    for(int k = 1  ; k  <= n ; k++){
        for(int i = 1; i <= n ; i++){
            for(int j  = 1; j <= n ; j++){
                mat[i][j] = min(mat[i][j] , mat[i][k] + mat[k][j]);
            }
        }
    }
    while(q--){
        int a , b;cin>>a>>b;
        if(mat[a][b] == (int)1e14){
            cout<<-1<<endl;;
        }else{
            cout<<mat[a][b]<<endl;
        }
    }






 
    return 0;
}