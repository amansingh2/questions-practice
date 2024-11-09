// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// // (a+b-(c+a)+d-f)
// // a + a -> 2a
// std::string simplifyEquation(const std::string& equation) {
//     std::unordered_map<char, int> terms;
//     int sign = 1; // Current sign (1 for positive, -1 for negative)
//     int n = equation.length();
//     for (int i = 0; i < n; ++i) {
//         if (equation[i] == '+') {
//             sign = 1;
//         } else if (equation[i] == '-') {
//             sign = -1;
//         } else if (std::isalpha(equation[i])) {
//             // If the character is a letter (variable)
//             terms[equation[i]] += sign;
//         } else if (equation[i] == '(') {
//             int j = i, balance = 0;
//             std::string subExpr;
//             while (j < n) {
//                 if (equation[j] == '(') balance++;
//                 if (equation[j] == ')') balance--;
//                 if (balance == 0) break;
//                 subExpr += equation[j];
//                 j++;
//             }
//             subExpr += ')';
//             std::string subResult = simplifyEquation(subExpr.substr(1, subExpr.length() - 2));
//             std::istringstream iss(subResult);
//             char variable;
//             int count;
//             while (iss >> count >> variable) {
//                 terms[variable] += sign * count;
//             }
//             i = j;
//         }
//     }

//     // Construct the simplified equation string
//     std::ostringstream result;
//     for (const auto& term : terms) {
//         if (term.second == 0) continue;
//         if (result.tellp() != 0 && term.second > 0) result << '+';
//         if (term.second == 1) result << term.first;
//         else if (term.second == -1) result << '-' << term.first;
//         else result << term.second << term.first;
//     }

//     return result.str();
// }
// int32_t main(){
//     int t = 1;
//     while(t--){
//         std::string equation;
//         std::cin >> equation;
//         cout<<simplifyEquation(equation)<<endl;;
//     }
//     return 0;
// }




#include <iostream>
#include <vector>
#include <algorithm>

int findBestArrivalTime(const std::vector<int>& bus_schedule, const std::vector<int>& arrival_times, int capacity) {
    std::vector<int> arrivals = arrival_times;
    std::sort(arrivals.begin(), arrivals.end());
    
    int bus_count = bus_schedule.size();
    int people_count = arrivals.size();
    
    int people_index = 0;
    int last_bus_time = bus_schedule[bus_count - 1];
    int current_capacity = 0;

    for (int i = 0; i < bus_count; ++i) {
        int bus_time = bus_schedule[i];
        current_capacity = 0;

        while (people_index < people_count && arrivals[people_index] <= bus_time && current_capacity < capacity) {
            ++people_index;
            ++current_capacity;
        }
    }

    // If the last bus is not full, you can arrive at the last bus time
    if (current_capacity < capacity) {
        return last_bus_time;
    }

    // Otherwise, you should arrive just before the last person who took the last bus
    return arrivals[people_index - 1] - 1;
}

int main() {
    std::vector<int> bus_schedule = {9, 10, 11};
    std::vector<int> arrival_times = {8, 9, 10};
    int capacity = 2;

    int best_time = findBestArrivalTime(bus_schedule, arrival_times, capacity);
    std::cout << "You should arrive at: " << best_time << std::endl;

    return 0;
}