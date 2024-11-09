#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
// ((1(3(5))))
// (()2(2)
// (()1(1))
((())2)2 -> after processing 2 what are the possible states avaialble
        -> pos -> 3 , neg -> 2 , ->
                                pos - 1 , neg -> 2
                                pos -> 2 , neg -> 1
                                pos -> 3 , neg -> 0

                                after this -> pos -> 1 , neg -> 3
                                pos -> 2 , neg -> 2
                                pos -> 3 , neg -> 1
                                after 
*/

bool solve1(string s){
    int n = s.size();
    set<pair<int,int>>states;
    int total = 0;
    states.insert({0,0});
    
    for(int  i = 0 ; i < n  ; i++){
        set<pair<int,int>> new_states;
        if(s[i] == '('){
            for(auto [a , b] : states){
                new_states.insert({a + 1 , b});
            }
            for(auto [a , b] : states){
                if(b - 1 > 0){
                    new_states.insert({a , b - 1});
                }
            }
            total += 1;
        }else if(s[i] == ')'){
            for(auto [a , b] : states){
                if(a - 1 > 0){
                    new_states.insert({a - 1 , b});
                }
            }
            for(auto [a , b] : states){
                new_states.insert({a , b + 1});
            }
            total += 1;
        }else{
            int val = s[i] - '0';
            if(total < val){
                return false;
            }
            for(auto [a , b] : states){
                for(int num_p = 0 ; num_p <= val ; num_p++){
                    int num_n = val - num_p;
                    if(num_p <= a && num_n <= b){
                        new_states.insert({a - num_p , b - num_n});
                    }
                }
            }
            total -= val;
            // cout<<new_states.size()<<endl;
        }
        states = new_states;
        
        // for(auto [a , b] : states){
        //     cout<<a<<" "<<b<<endl;
        // }
        // cout<<endl;
        // cout<<endl;
    }
    for(auto [a , b] : states){
        if(a == b){
            return true;
        }
    }
    return false;
}
int32_t main(){
    string s ; 
    cin >> s;
    
    // for(int i = 0 ; i < 28 ; i++){
    //     s += "()()())()()())()()())";
    //     s += '3';
    // }
    /*
    s += '9';
    s += '9';
    s += '9';
    s += '9';
    s += '9';
    s += '9';
    s += '9';
    s += '9';
    s += '9';
    s += '9';
    // cout<<s<<endl;
    */

    cout<<(solve1(s) == false ? "FALSE" : "TRUE")<<endl;
    // string s2;
    // int n = s.size();
    // for(int i = n - 1 ; i >= 0 ; i--){
    //     if(s[i] == ')'){
    //         s2 += '(';
    //     }else if(s[i] == '('){
    //         s2 += ')';
    //     }else{
    //         s2 += s[i];
    //     }
    // }
    // cout<<(solve(s2) == false ? "FALSE" : "TRUE")<<endl;

    return 0;
}


/*
You are given a string containing only parentheses ('(' and ')') and digits (0-9). 
At the index of a digit, you must delete a number of parentheses to the left of the 
index equal to the digit's value. Return true if it is possible to balance the parenthesis 
of the input.

Example 1 Input: ((2)) Output: False Reason: Only possible string is unbalanced: "))"

Example 2 Input: ((((2)) Output: True Reason: Only possible string is balanced: "(())"

Example 3 Input: (()1(1)) Output: True Reason: 
Multiple possible strings and one is balanced: ")())", "(())", "()))".

Background: 

1.Digits should not be included in the result string, although that doesn't matter for 
calculating the boolean result.

2.If a digit doesn't have enough characters to the left to delete, then return false.

*/




/*
9999 + 1 -> 100000


*/