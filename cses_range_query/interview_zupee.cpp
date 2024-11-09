#include <bits/stdc++.h>
#define int long long
using namespace std;


/*
[[+3, +3], [-3, -3], [0, 0], [+2, -3]] -> [[FR, FL, RR, RL], [RL, RR, FL, FR], [All], [RR, RL, FR, FL]]

 [[FR, FL, RR, RL], 
 [RL, RR, FL, FR], 
 [All], 
 [RR, RL, FR, FL]]
*/

// bool cmp(pair<int , string> a , pair<int , string> b){
//     map<string , int> v;
//     v["FR"] = 1;
//     v["FL"] = 2;
//     v["RL"] = 3;
//     v["RR"] = 4;
//     if(a.first == b.first){
//         return v[a.second] < v[b.second];
//     }
//     return a.first < b.first;
// }

bool is_all_equal(vector<pair<int , string>> & arr){
    int val = -1;
    for(auto [a ,b] : arr){
        if(val == -1){
            val = a;
            continue;
        }
        if(a != val){
            return false;
        }
    }
    return true;
}

bool is_valid(vector<pair<int , string>> & arr){
    map<int , vector<string> > mp;
    int dist = -1;
    string key = "-1";
    for(auto [a , b] : arr){
        mp[a].push_back(b);
        if(dist == -1){
            dist = a;
        }else{
            if(dist > a){
                return false;
            }
            dist = a;
        }
        if(key == "-1"){
            key = b;
        }
    }
    map<string , vector<string> > checker;
    checker["FR"].push_back("FL");
    checker["FR"].push_back("RL");
    checker["FR"].push_back("RR");

    checker["FL"].push_back("RL");
    checker["FL"].push_back("RR");
    checker["FL"].push_back("FR");

    checker["RL"].push_back("RR"); 
    checker["RL"].push_back("FR"); 
    checker["RL"].push_back("FL");  

    checker["RR"].push_back("FR");
    checker["RR"].push_back("FL");
    checker["RR"].push_back("RL");

    vector<string>vs;
    for(auto [a , b] : mp){
        if(b.size() > 1){
            for(string s : b){
                vs.push_back(s);
            }
        }
    }
    int i = 0;
    for(string s : checker[key]){
        if(s == vs[i]){
            i++;
        }
    }
    if(i == vs.size()){
        return true;
    }
    return false;
}

void process(vector<int> arr){
    map<pair<int ,int > , string> mp;

    mp[{+3 , +3}] = "FR";
    mp[{-3 , +3}] = "FL";
    mp[{-3 , -3}] = "RL";
    mp[{+3 , -3}] = "RR";
    vector<pair<int , string>> distances;

    for(auto [a , b] : mp){
        int x = arr[0];
        int y = arr[1];
        int nx = a.first;
        int ny = a.second;
        int dist = (nx - x)*(nx - x) + (ny - y)*(ny - y);
        distances.push_back({dist , b});
    }

    if(is_all_equal(distances)){
        cout<<"ALL";
        return;
    }
    // sort(distances.begin() , distances.end() , cmp);
    int i = 0;
    do {
        if(is_valid(distances)){
            break;
        }
        i++;
    }while(next_permutation(distances.begin() , distances.end()));
    // cout<<i<<" -> ";
    for(auto p : distances){
        cout<<p.second<<" ";
    }
    return;
}


void solve(vector<vector<int>> coordinates){
    for(auto v : coordinates){
        process(v);
        cout<<endl;
    }
}

int32_t main(){
    vector<vector<int>> arr = {
        {+3 , +3} , {-3 , -3} , {0 , 0} , {+2 , -3}
    };
    vector<vector<int>> arr1 = {
        {+3 , 0}
    };
    vector<vector<int>> arr2 = {
        {-3 , 0}
    };
    solve(arr);
    return 0;
}