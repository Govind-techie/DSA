/*
Priority Queue for Pairs in C++

- The STL priority_queue can store pairs (e.g., pair<string, int>).
- By default, priority_queue compares pairs by the first element, then the second (lexicographical order).
- To customize the priority (e.g., based on the second value), define a custom comparator struct.
  * The comparator should overload operator() and return true if p1 has lower priority than p2.
- Use the custom comparator as the third template argument in priority_queue.
- Useful for problems where you need to process pairs based on a specific field (e.g., marks, frequency, etc.).
- Example: To prioritize based on the second value of the pair, provide a comparator that compares p1.second and p2.second.
*/

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<queue>
using namespace std;

// Custom comparison structure for priority queue
struct ComparePairs {
    // The function that determines how to compare pairs
    // We compare pairs based on their second value (marks), and prioritize the smaller ones first
    bool operator () (const pair<string,int>& p1, const pair<string,int>& p2) {
        return p1.second > p2.second; // True means p1 should come after p2 (min-heap behavior)
    }
};

int main() {
    // Default priority_queue: max-heap based on the first value of the pair (alphabetically)
    priority_queue<pair<string, int>> pq1;

    // Adding students to the priority queue (name, marks)
    pq1.push({"ABC", 85});
    pq1.push({"LMN", 60});
    pq1.push({"PQR", 78});
    pq1.push({"XYZ", 94});

    // Printing the top element and removing it until the queue is empty
    cout << "Priority Queue 1 (Default Max-Heap based on name):" << endl;
    while (!pq1.empty()) {
        // Output top student (by name) and marks
        cout << "top : " << pq1.top().first << ", " << pq1.top().second << endl;
        pq1.pop();  // Remove the top element after processing it
    }
    cout << endl;

    // Custom priority_queue: min-heap based on the second value of the pair (marks)
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePairs> pq2;

    // Adding students to the priority queue (name, marks)
    pq2.push({"ABC", 85});
    pq2.push({"LMN", 60});
    pq2.push({"PQR", 78});
    pq2.push({"XYZ", 94});

    // Printing the top element and removing it until the queue is empty
    cout << "Priority Queue 2 (Min-Heap based on marks):" << endl;
    while (!pq2.empty()) {
        // Output top student (with the lowest marks) and their marks
        cout << "top : " << pq2.top().first << ", " << pq2.top().second << endl;
        pq2.pop();  // Remove the top element after processing it
    }
    
    return 0;
}