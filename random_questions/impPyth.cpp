#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;cin>>t;
    int it = 0;
    vector<int>first , last , res;
    while(it < t){
        int n ; cin >> n;
        if(it == 0){
            // int a,b,c;cin>>
            first.resize(n);
            for(int i = 0 ; i < n ; i++){
                cin >> first[i];
            }
            res = first;
        }else{
            last.clear();
            res.clear();
            last.resize(n);
            for(int & i : last){
                cin >> i;
            }
            res.resize(max(last.size() , first.size()) , 0);
            for(int k = 0, i = 0 , j = 0 ; i < last.size() || j < first.size() ; i ++ , j ++){
                if(i < last.size() && j < first.size()){
                    res[k++] = first[i] + last[j];
                }else if(i < last.size()){
                    res[k++]  = last[i];
                }else{
                    res[k++] = first[i]; 
                }
            }
            first = res;
        }
    }

    for(int i : res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}