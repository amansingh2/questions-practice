#include <iostream>
#include <map>
#include <list>
#include <stdexcept>
using namespace std;

class LinkedHashMap {
public:
    // Adds a key-value pair to the map
    void insert(int key, int value) {
        // Check if the key already exists
        auto it = map.find(key);
        if (it != map.end()) {
            // Update the value and move the key to the back of the order list
            it->second.second = value;
            order.splice(order.end(), order, it->second.first);
        } else {
            // Insert new key-value pair
            order.push_back(key);
            map[key] = { --order.end(), value };
        }
    }

    // Removes a key-value pair from the map
    void erase(int key) {
        auto it = map.find(key);
        if (it != map.end()) {
            order.erase(it->second.first);
            map.erase(it);
        }
    }

    // Removes the first key-value pair from the map
    void remove_first() {
        if (!order.empty()) {
            int key = order.front();
            order.pop_front();
            map.erase(key);
        } else {
            throw std::out_of_range("Map is empty");
        }
    }

    // Retrieves the value associated with the key
    int& at(int key) {
        auto it = map.find(key);
        if (it != map.end()) {
            return it->second.second;
        } else {
            throw std::out_of_range("Key not found");
        }
    }

    // Retrieves the value associated with the key (const version)
    const int& at(int key) const {
        auto it = map.find(key);
        if (it != map.end()) {
            return it->second.second;
        } else {
            throw std::out_of_range("Key not found");
        }
    }

    // Checks if the map contains a key
    bool contains(int key) const {
        return map.find(key) != map.end();
    }

    // Clears the map
    void clear() {
        map.clear();
        order.clear();
    }

    // Size of the map
    size_t size() const {
        return map.size();
    }

    // Check if the map is empty
    bool empty() const {
        return map.empty();
    }

    // Iterator to the beginning of the map in insertion order
    auto begin() {
        return order.begin();
    }

    // Iterator to the end of the map in insertion order
    auto end() {
        return order.end();
    }

private:
    map< int,  pair<list<int>::iterator, int>  >map;
    list<int> order;
};

int main() {
    LinkedHashMap lhm;
    lhm.insert(1, 100);
    lhm.insert(2, 200);
    lhm.insert(3, 300);

    std::cout << "LinkedHashMap contents in insertion order:" << std::endl;
    for (const auto& key : lhm) {
        std::cout << key << ": " << lhm.at(key) << std::endl;
    }

    lhm.remove_first();

    std::cout << "After removing the first element:" << std::endl;
    for (const auto& key : lhm) {
        std::cout << key << ": " << lhm.at(key) << std::endl;
    }

    return 0;
}
