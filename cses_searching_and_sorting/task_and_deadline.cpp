#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    vector<int>v(n); // think why?
    int total = 0;

    for(int i = 0 ;i < n ; i++){
        cin >> v[i];
        int d  ; cin >> d;
        total += d;
    }
    sort(v.begin() , v.end());
    int aux = 0;
    for(int i : v){
        aux += i;
        total -= aux; // think why?
    }

    cout<< total << endl;
    
    
    return 0;
}

/*
You have to process n tasks. Each task has a duration and a deadline, and you will process the tasks in some order one after another. 
Your reward for a task is d-f where d is its deadline and f is your finishing time. (The starting time is 0, 
and you have to process all tasks even if a task would yield negative reward.)
What is your maximum reward if you act optimally?
Input
The first input line has an integer n: the number of tasks.
After this, there are n lines that describe the tasks. Each line has two integers a and d: 
the duration and deadline of the task.
Output
Print one integer: the maximum reward.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a,d \le 10^6

Example
Input:
3
6 10
8 15
5 12

Output:
2
*/