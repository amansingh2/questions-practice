#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[100000]
int tree[4 * 100000 + 1];


void build(int st , int end , int t_node){

    if(st == end){
        tree[t_node] = arr[st];
    }

    int mid = (st + end)/2;

    build(st , mid , 2*t_node);
    build(mid + 1 , end , 2*t_node + 1);

    tree[t_node] = max(tree[2*t_node] , tree[2*t_node + 1]);

}

int query(int l , int r , int curr_st_of_arr , int curr_end_of_arr , int t_node){
    if(l >= st_of_arr && r <= end_of_arr){
        return tree[t_node];
    }

    if(l > curr_end_of_arr || r < curr_st_of_arr){
        return 1e9 ; // we are out of bound here!
    }

    int mid = (curr_end_of_arr + curr_st_of_arr)/2;

    int val1 = query(l , r , curr_st_of_arr , mid , 2*t_node);
    int val2 = query(l , r , mid + 1 , curr_end_of_arr , 2*t_node + 1);

    return min(val1 , val2);

}

void update(int val_to_be_updated , int index_to_be_chaged , int st , int end , int t_node){
    if(st == end){
        arr[index_to_be_chaged] = val_to_be_updated;
        tree[t_node] = val_to_be_updated;
    }
    int mid = (st + end)/2;
    if(index_to_be_chaged >= st && index_to_be_chaged <= mid){
        update(val_to_be_updated , index_to_be_chaged , st , mid , t_node * 2);
    }else{
        update(val_to_be_updated , index_to_be_chaged , mid + 1 , end , t_node * 2 + 1);
    }

    tree[t_node] = min(tree[t_node * 2 + 1] , tree[t_node * 2]);
}


int32_t main(){
    int n ; cin >> n;
    for(int i = 1 ; i <= n ;i++){
        cin >> arr[i];
    }

    build(1 , n , 1);
    
    return 0;
}   