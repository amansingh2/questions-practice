#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
upper_bound : immediate next element which is greater than passed value! , but if all value in multiset are smaller then ? 


lower_bound : if available then interator to that element if not then immediate greater! but if all elemets are smaller than passed parameter then ???
*/

int32_t main(){
    int n , m; cin >> n >> m;
    int x;

    multiset<int>ms;
    for(int i = 0 ; i < n ; i++){
        cin >> x;       // ticket price
        ms.insert(x);
    }

    for(int i = 0 ; i < m ; i++){
        cin >> x;       // max price that they are willing to offer in order of their arrival!
        auto it = ms.upper_bound(x);
        if(it == ms.begin()){
            cout<<-1<<endl;
        }else{
            cout<<*(--it)<<endl;
            ms.erase(it);
        }
    }
    
    return 0;
}


/*
There are n concert tickets available, each with a certain price. 
Then, m customers arrive, one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after this, 
they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input:
The first input line contains integers n and m: the number of tickets and the number of customers.
The next line contains n integers h_1,h_2,.....,h_n: the price of each ticket.
The last line contains m integers t_1,t_2,.....,t_m: the maximum price for each customer in the order 
they arrive.

Output:
Print, for each customer, the price that they will pay for their ticket. After this, 
the ticket cannot be purchased again.
If a customer cannot get any ticket, print -1.

Constraints

1 <= n, m <= 2 * 10^5
1 <= h_i, t_i <= 10^9

Example
Input:
5 3
5 3 7 8 5
4 8 3

Output:
3
8
-1
*/