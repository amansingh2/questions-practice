#include <bits/stdc++.h>
#define int long long
using namespace std;

class Node{
    public:
        Node * next;
        int val;
        Node(int val){
            this->val = val;
        }
};
/*
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8

2 -> 1 -> 4 -> 3-> 6 -> 5 -> 8 -> 7

1 -> null
*/

void solve(Node * node){
    while(node != NULL && node -> next != NULL){
        int v = node->next->val;
        node->next->val = node->val;
        node->val = v;
        node = node->next->next;
    }
}

int32_t main(){

    Node * node = new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    node->next->next->next = new Node(4);
    node->next->next->next->next = new Node(5);

    solve(node);

    while(node != NULL){
        cout<<node->val<<" ";
        node = node->next;
    }

    
    return 0;
}
