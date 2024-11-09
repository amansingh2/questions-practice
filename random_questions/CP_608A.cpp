#include <bits/stdc++.h>
// #define int long long
using namespace std;

int main() {
    int n, s;
    std::cin >> n >> s;
    std::map<int, int> input;

    for(int i = 0; i < n; ++i) {
        int f, t;
        std::cin >> f >> t;
        input[f] = max(input[f] , t);
    }

    int totalTime = 0;
    std::vector<int> keys;

    for (const auto& pair : input) {
        keys.push_back(pair.first);
    }

    std::sort(keys.begin(), keys.end(), std::greater<int>());

    for(int i = 0; i < keys.size(); ++i) {
        int currentFloor = keys[i];
        int timeToReachFloor = s - currentFloor;
        totalTime += timeToReachFloor;
        int arrivalTimePassenger = input[currentFloor];

        totalTime = max(arrivalTimePassenger , totalTime);

        s = currentFloor;
    }

    totalTime += s;
    std::cout << totalTime << std::endl;

    return 0;
}
