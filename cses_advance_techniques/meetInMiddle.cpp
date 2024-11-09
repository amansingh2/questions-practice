#include <bits/stdc++.h>
using namespace std;

// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, x;
    cin >> n >> x; // Input array size and required sum
    int n1 = n / 2;
    int n2 = n - n1;

    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i]; // Input elements of first half of array
    }

    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i]; // Input elements of second half of array
    }

    unordered_map<long long, int > map;
    for (int mask = 0; mask < (1 << n1); mask++) {
        long long aux_sum = 0;
        for (int i = 0; i < n1; i++) {
            if ((1 << i) & mask) {
                aux_sum += arr1[i];
            }
        }
        map[aux_sum]++;
    }

    long long ans = 0;
    for (int mask = 0; mask < (1 << n2); mask++) {
        long long aux_sum = 0;
        for (int i = 0; i < n2; i++) {
            if ((1 << i) & mask) {
                aux_sum += arr2[i];
            }
        }
        if(map.count(x - aux_sum)){
            ans += map[x - aux_sum];
        }
    }

    cout << ans; // Output the number of ways to create the sum x
    return 0;
}
