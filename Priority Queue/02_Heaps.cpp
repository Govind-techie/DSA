/*
Heap Data Structure

- A heap is a special complete binary tree-based data structure.

- Two main types:
  1. Max-Heap: Parent node is always greater than or equal to its children.
  2. Min-Heap: Parent node is always less than or equal to its children.
- The largest (max-heap) or smallest (min-heap) element is always at the root.
- Commonly used to implement priority queues.
- Supports efficient insertion, deletion, and access to the root element.

- Time complexity:
  * Insertion: O(log n)
  * Deletion (remove root): O(log n)
  * Access root: O(1)

- Applications:
  * Priority queues
  * Heap sort
  * Finding kth largest/smallest element
  * Graph algorithms (like Dijkstra's, Prim's)

COMPLETE BINARY TREE (CBT):
Heap is a Complete BT (CBT)
• CBT is a BT where all levels are filled except maybe the last one, which is filled from left to right.
• Parent >= Children // Max Heap
• Parent <= Children // Min Heap


Note: In a Heap (used by a Priority Queue), the root represents the top element.
• In a max-heap, the root is the maximum element.
• In a min-heap, the root is the minimum element.

Note: The heap is not implemented as a class because doing so can increase time complexity.
*/

#include<iostream>
#include<vector>
using namespace std;

/*
Heap Implementation using Vector

- A heap can be efficiently implemented using a vector (array).

- For any node at index i:
    * Left child index  = 2 * i + 1
    * Right child index = 2 * i + 2
    * Parent index      = (i - 1) / 2  (integer division)

- Conversely, to find the parent of a node at index i:
    * Parent index = (i - 1) / 2

- Note: The above index relationships work only for a 
  Complete Binary Tree (CBT), which is the structure 
  used by heaps.

- This structure allows easy navigation between parents 
  and children without explicit pointers.

- Vectors provide dynamic resizing and contiguous memory, 
  making them ideal for heap storage.

- The heap property ensures that each parent node is either:
    * Greater than or equal to its children (max-heap), or
    * Less than or equal to its children (min-heap).
*/

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Heap {
    vector<T> heap; // Vector to hold heap elements dynamically

public:

    // Insert value into heap — Time: O(log n)
    void push(T val) {
        heap.push_back(val);              // Add at the end

        int chIdx = heap.size() - 1;      // Child index (newly added)
        int parIdx = (chIdx - 1) / 2;     // Parent index in CBT

        // Bubble up while child > parent
        while (chIdx > 0 && heap[chIdx] > heap[parIdx]) {
            swap(heap[chIdx], heap[parIdx]);
            chIdx = parIdx;
            parIdx = (chIdx - 1) / 2;
        }
    }

private:

    // Heapify down from index i — Time: O(log n)
    void heapify(int i) {
        int maxIdx = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] > heap[maxIdx]) {
            maxIdx = left;
        }
        if (right < heap.size() && heap[right] > heap[maxIdx]) {
            maxIdx = right;
        }

        if (maxIdx != i) {
            swap(heap[i], heap[maxIdx]);
            heapify(maxIdx);
        }
    }

public:

    // Remove max (top) element — Time: O(log n)
    void pop() {
        if (heap.empty()) return;

        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(0);
    }

    // Return max element — Time: O(1)
    T top() {
        if (heap.empty()) return T{}; // Return default T if empty
        return heap[0];
    }

    // Check if heap is empty — Time: O(1)
    bool empty() {
        return heap.empty();
    }
};

int main() {
    Heap<int> h;

    h.push(10);
    h.push(20);
    h.push(5);
    h.push(30);

    cout << "Top element: " << h.top() << endl; // Should print 30

    while (!h.empty()) {
        cout << "Popped: " << h.top() << endl;
        h.pop();
        cout << "Top element: " << h.top() << endl;
    }

    if (h.empty()) {
        cout << "Heap is empty now." << endl;
    }

    return 0;
}