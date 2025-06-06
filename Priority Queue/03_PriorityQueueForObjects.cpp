/*
Priority Queue for Objects in C++

- The STL priority_queue can store user-defined objects (like classes or structs).
- To define the priority (ordering), overload the '<' operator in your class.
  * For max-heap: operator< should return true if 'this' has lower priority than 'obj'.
  * For min-heap: reverse the logic or use a custom comparator.
- The priority_queue will use this operator to maintain heap order.
- Useful for problems where you need to process objects based on a specific field (e.g., marks, age, etc.).
- Example: In a Student class, overload '<' to compare marks so students with higher marks have higher priority.
*/

#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Student {
public:
    string name;
    int marks;

    // Constructor to initialize a student with name and marks
    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    // Operator overloading for '<' (used by priority_queue to compare students)
    // This will make the priority_queue behave like a max-heap based on marks
    bool operator < (const Student &obj) const {
        return this->marks < obj.marks;
        // If this student has less marks than obj, it has lower priority
    }
};

int main() {
    // Create a max-heap (default behavior of priority_queue)
    // Students with higher marks will come first
    priority_queue<Student> pq;

    // Adding students to the priority queue
    pq.push(Student("ABC", 85));
    pq.push(Student("LMN", 60));
    pq.push(Student("PQR", 78));
    pq.push(Student("XYZ", 94));

    // Extracting students in order of highest marks first
    while (!pq.empty()) {
        // Print the name and marks of the student at the top
        cout << "top : " << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop(); // Remove the top student from the queue
    }

    return 0;
}