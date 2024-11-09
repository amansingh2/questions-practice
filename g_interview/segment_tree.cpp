#include <bits/stdc++.h>
#define int long long
using namespace std;
int tree[10000];
int arr[100];
void build(int left , int right , int treeNode){
    if(left == right){
        tree[treeNode] = arr[left];
        return ;
    }
    int mid = (left + right)/2;

    build(left , mid , 2*treeNode);
    build(mid + 1 , right , 2*treeNode + 1);
    tree[treeNode] = min(tree[2*treeNode] , tree[2*treeNode + 1]);
}
int query(int left , int right , int L , int R , int treeNode){
    if(R < left || L > right){
        return INT_MAX;
    }
    if(R == right && L == left){
        return tree[treeNode];
    }
    int mid = (left + right)/2;
    int v1 = query(left , mid , L , R , 2*treeNode);
    int v2 = query(left , mid , L , R , 2*treeNode + 1);

    return min(v1 , v2);
}
int32_t main(){
    int n ; cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    build(1 , n , 1);
    return 0;
}