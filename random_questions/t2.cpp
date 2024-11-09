#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    vector<int>res;
    vector<int> last;
    vector<int>current;
    int it = 0;
    while(it < t){
        int n ; cin >> n;
        if(it == 0){
            last.resize(n);
            for(int i = 0 ; i < n ; i++){
                cin >> last[i];
            }
            res = last;
        }else{
            current.clear();
            current.resize(n);
            res.clear();
            for(int i = 0  ; i  < n  ; i++){
                cin >> current[i];
            }
            for(int i = 0 , j = 0  ; i < current.size() && j < last.size() ; ){
                if(current[i] == last[j]){
                    res.push_back(current[i]);
                    i++;
                    j++;
                }else if(current[i] > last[j]){
                    j++;
                }else{
                    i++;
                }
            }
            last = res;
        }
        it++;
    }
    for(int i : res ){
        cout<<i<<" ";
    }
    return 0;
}