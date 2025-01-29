#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n ; cin >> n;
    vector<pair<int,int>> vp(n);

    for(auto &[a,b] : vp){
        cin >> a >> b;
    }

    sort(vp.begin() , vp.end() , [](const auto &p1 ,const auto &p2){
        return p1.second < p2.second;
    });

    int last = -1;
    int ans = 0;
    for(auto [a , b] : vp){
        if(a >= last){
            ans++;
            last = b;    
        }
    }

    cout<<ans<<endl;


    return 0;
}

/*
In a movie festival n movies will be shown. 
You know the starting and ending time of each movie. 
What is the maximum number of movies you can watch entirely?
Input
The first input line has an integer n: the number of movies.
After this, there are n lines that describe the movies. Each line has two integers a and b: 
the starting and ending times of a movie.

Output
Print one integer: the maximum number of movies.
Constraints

1 <= n <= 2 * 10^5
1 <= a < b * 10^9
Example

Input:
3
3 5
4 9
5 8

Output:
2

*/