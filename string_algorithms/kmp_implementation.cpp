#include <bits/stdc++.h>
#define int long long
using namespace std;

// int get_index(string s , string p){
//     int m = p.size();
//     int n = s.size();

//     vector<int>lps(m + 1 , 0);

//     for(int i = )
// }

vector<int> prefix_function (string Z) {

    int n = (int) Z.length();

    vector<int> F (n);

     F[0]=0;

    for (int i=1; i<n; ++i) {

        int j = F[i-1];

        while (j > 0 && Z[i] != Z[j]) j = F[j-1];

        if (Z[i] == Z[j])  ++j;

        F[i] = j;

    }

    return F;
}

vector<int> calculateLPS(string s){
    int n = s.size();
    vector<int>lps(n, 0);
    int j = 0;

    for(int i = 1; i < n ;){
        if(s[i] == s[j]){
            lps[i] = j + 1;
            i++;
            j++;
        }else{
            if(j != 0){
                j = lps[j - 1]; // yeha pe kai baar hit karega in case of mismatch , dhyan do bhai Aman!
                                //one of the most imp line ! parent chid type of kaam karega!
            }else{              // ni hua to like uske pichhe wala kaha se aaya tha aise sochega kind of 
                lps[i] = 0;
                i++;
                j = 0;
            }

        }
    }
    return lps;
}
int32_t main(){
    string s ; cin >> s;
    vector<int> v = prefix_function(s);
    vector<int>v2 = calculateLPS(s);
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v2[i]<<"  "<<s[i]<<" " << v[i]<<endl;
    }
    cout<<endl;
    return 0;
}
