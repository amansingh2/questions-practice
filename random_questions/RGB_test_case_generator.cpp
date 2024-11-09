#include <bits/stdc++.h>
#define int long long
using namespace std;
int get_num(int low, int high){
    return (int)(rand() % (high - low + 1)) + low ;
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    cout<<n<<" "<<m<<endl;
    for(int i = 0 ; i < m ;i++){
        cout<<get_num(1,3)<<" ";
        int x = get_num(1,n);
        cout<<x<<" ";
        cout<<get_num(x,n)<<endl;
    }

    return 0;
}