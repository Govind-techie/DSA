/*
Problem: Nearby Cars (Return Indices)

You are given the coordinates of N cars on a 2D plane. Each car is located at (x, y).
Your task is to find the indices of the K cars that are closest to the origin (0, 0).
The distance is calculated using the squared Euclidean distance: dist = x^2 + y^2.

Input:
- A vector of N pairs where each pair represents the (x, y) position of a car.
- An integer K representing the number of closest cars to return.

Output:
- Print the indices (0-based) of the K closest cars to the origin. 
- The output order doesn't matter.

Note:
- We use squared distance to avoid computing square roots, as relative distances remain the same.

Example:

Input: {{1, 2}, {-2, 4}, {3, 1}, {0, 1}, {-1, -1}}, K = 3

Output: 
car3
car4
car0

Explanation:
The distances from the origin are:
Car0: 1² + 2² = 5  
Car1: (-2)² + 4² = 20  
Car2: 3² + 1² = 10  
Car3: 0² + 1² = 1  
Car4: (-1)² + (-1)² = 2  

The three cars with the smallest distances are at indices 3, 4, and 0.
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Custom class to represent a Car with its index and squared distance from the origin
class Car {
public:
    int idx;     // Index of the car in the original input vector
    int distSq;  // Squared distance from the origin (0,0)

    // Constructor to initialize index and distance
    Car(int idx, int distSq) {
        this->idx = idx;
        this->distSq = distSq;
    }

    // Overloading the < operator to make a min-heap based on distance
    // Priority Queue in C++ is a max-heap by default, so we reverse the logic
    bool operator < (const Car &obj) const {
        return this->distSq > obj.distSq; // smaller distSq = higher priority
    }
};

// Function to find and print the indexes of the K nearest cars to the origin
void nearbyCars(vector<pair<int,int>> pos, int K) { // Time Complexity: O(k*logn + n)
    vector<Car> cars;

    // Step 1: Calculate squared distance of each car and store as Car object
    for (int i = 0 ; i < pos.size() ; i++) { // O(n)
        int distSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second); // x^2 + y^2
        cars.push_back(Car(i, distSq)); // Create and add Car object with index and distance
    }

    // Step 2: Use a min-heap (priority_queue) to get cars with smallest distances first
    priority_queue<Car> pq(cars.begin(), cars.end()); // O(n)

    // Step 3: Extract top K closest cars
    for (int i = 0 ; i < K ; i++) { // O(k)
        cout << "car" << pq.top().idx << endl; // Print index of car
        pq.pop(); // Remove the car from the heap (O(logn))
    }
}

int main() {
    // Initialize car positions as (x, y) coordinates
    vector<pair<int, int>> pos;
    pos.push_back(make_pair(3, 3)); // car0
    pos.push_back(make_pair(5, -1)); // car1
    pos.push_back(make_pair(-2, 4)); // car2

    int K = 2; // Number of nearest cars to find

    nearbyCars(pos, K);

    return 0;
}