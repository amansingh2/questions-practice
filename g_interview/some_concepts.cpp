#include <iostream>
#include <queue>
#include <vector>

int main() {
    auto cmp = [](int left, int right) { return left > right; };

    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);

    pq.push(10);
    pq.push(20);
    pq.push(5);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    // Output will be: 5 10 20

    return 0;
}
