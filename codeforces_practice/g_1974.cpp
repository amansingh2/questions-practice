#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;cin>>t;
    while(t--){

        int n , x ; cin >> n >> x;
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }

        int curr_money = 0;

        priority_queue<int> pq;


        for(int i = 0 ; i < n ; i++){
            if(curr_money >= arr[i]){
                pq.push(arr[i]);
                curr_money -= arr[i];
            }else if(pq.size() > 0 && pq.top() > arr[i] && curr_money < arr[i]){
                curr_money += pq.top();
                pq.pop();
                pq.push(arr[i]);
                curr_money -= arr[i];
            }
            curr_money += x;
        }

        cout<<pq.size()<<endl;






    }
    return 0;
}
