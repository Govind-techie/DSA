# **DSA Journey Repository 🚀**

Welcome to my **Data Structures and Algorithms (DSA)** learning journey! This repository contains all my notes, code, and progress throughout my DSA exploration. I aim to regularly update this repository as I learn new concepts, solve problems, and enhance my understanding.

## 📚 Topics Covered

### **Arrays**
- **Basics of Arrays**: Understanding array declaration, initialization, and memory layout.
- **Loops Over Arrays**: Iterating through arrays using different loop constructs.
- **Pass by Reference**: Understanding how arrays are passed to functions and their behavior.
- **Linear Search Algorithm**: Implementing and analyzing the linear search algorithm.
- **Reverse Array**: Reversing an array using the Two-Pointer Approach.
- **Intersection of Two Arrays**: Implementing a function to find common elements between two arrays.

### **2D Arrays**
- **Basics of 2D Arrays**: Understanding declaration, initialization, and accessing elements using row and column indices.
- **Row-wise and Column-wise Traversal**: Iterating through 2D arrays by rows and columns.
- **Linear Search in 2D Arrays**: Searching for an element by traversing a 2D matrix.
- **Important Problems**: Solving problems like Spiral Matrix Traversal, Matrix Transposition, and Searching in a Sorted Matrix.

### **Vectors**
- **Basics of Vectors**: Understanding vector declaration, initialization, and dynamic resizing.
- **Vector Functions**: Exploring common vector functions like `push_back()`, `pop_back()`, `size()`, `at()`, etc., and their usage.
- **For-Each Loop**: Using the range-based `for` each loop to iterate over vectors and access their elements directly.
- **Static Memory Allocation**: Memory is allocated at compile-time for fixed-size arrays.
- **Dynamic Memory Allocation**: Memory is allocated at runtime for structures like vectors, with dynamic resizing.

### **Strings and Character Arrays**
- **Basics of Strings**: Understanding C++ `string` class, declaration, and initialization.
- **Important String Functions**: Using functions like `length()`, `find()`, `substr()`, `append()`, `erase()`, etc.
- **Character Arrays**: Working with traditional character arrays (`char arr[]`) and manual operations like input, output, and string termination with `\0`.
- **String Problems Solved**:
  - **Valid Palindrome**
  - **Valid Anagram**

### **Kadane's Algorithm**
- **Kadane's Algorithm**:  
  Kadane's algorithm is an efficient method to find the maximum sum of a contiguous subarray in an array of numbers. It operates in **O(n)** time, making it significantly faster than the brute-force approach.

### **Moore's Voting Algorithm**
- **Moore's Voting Algorithm**:  
  This algorithm helps find the majority element (the element that appears more than **n / 2** times) in an array. It maintains a candidate and a counter. If the counter reaches zero, a new candidate is chosen. The algorithm runs in **O(n)** time with constant space.

### **Time and Space Complexity**
- **Time Complexity**: Understanding how algorithms scale with input size.
- **Space Complexity**: Evaluating the memory usage of algorithms.
- **Big O Notation**: Used to describe the worst-case performance of an algorithm.

### **Binary Exponentiation**
- **Binary Exponentiation**:  
  An efficient method to calculate **x^n** in **O(log n)** time using exponentiation by squaring.

### **Pointers**
- **Basics of Pointers**: Memory addresses, dereferencing, and pointer arithmetic.
- **Pointer to Pointer**: Storing addresses of pointers.
- **Dynamic Memory Allocation**: Using `new` and `delete`.
- **Pointer and Arrays**: Understanding arrays as pointers and using pointer arithmetic.

### **Bit Manipulation**
- **Introduction to Bits**: Understanding binary representation and bit-level operations.
- **Bitwise Operators**: Using `AND (&)`, `OR (|)`, `XOR (^)`, `NOT (~)`, `Left Shift (<<)`, and `Right Shift (>>)` operators.
- **Common Bit Tricks**: Checking even/odd, swapping numbers, counting set bits, turning bits on/off.
- **Applications**: Solving problems like finding the unique number, checking power of two, and more.

### **Recursion**
- **What is Recursion?**: A function that calls itself to solve smaller subproblems of a larger problem. Useful for tasks that can be broken down into similar subtasks.
- **Base Case and Recursive Case**: Every recursive function must have a base case to stop the recursion and a recursive case that breaks the problem down.
- **Types of Recursion**:
  - **Tail Recursion**: The recursive call is the last operation in the function.
  - **Head Recursion**: The recursive call is made before any other processing.
  - **Tree Recursion**: A function makes multiple recursive calls.
  - **Indirect Recursion**: A function calls another function which eventually calls the original function.
- **Call Stack Behavior**: Each recursive call is pushed to the stack and popped when it completes. Understanding the call stack is key to avoiding stack overflow.
- **Use Cases**: Recursion is ideal for problems like factorial, Fibonacci numbers, tree traversals, and divide-and-conquer algorithms like merge sort.

### **Object-Oriented Programming (OOP)**
- **Basic Concepts**: Understanding classes, objects, encapsulation, inheritance, polymorphism, and abstraction.
- **Constructors and Destructors**: Lifecycle of an object and memory management.
- **Types of Inheritance**: Single, Multilevel, Multiple, Hierarchical, and Hybrid inheritance with examples.
- **Real-World Examples**: Applying OOP concepts to practical C++ programs and system design.

### **Binary Search Algorithm**
- **Iterative Approach**: Uses a loop to repeatedly divide the array in half.
- **Recursive Approach**: Uses function calls to divide the array recursively.
- **Time Complexity**: **O(log n)** in a sorted array.

### **Divide and Conquer**
- **Merge Sort**: A divide-and-conquer sorting algorithm that splits the array into halves, recursively sorts them, and merges the results. Time complexity: **O(n log n)**.
- **Quick Sort**: Picks a pivot, partitions the array, and recursively sorts the partitions. Average case: **O(n log n)**, Worst case: **O(n²)**.
- **Rotated Sorted Array Search**: Modified binary search to find an element in a rotated sorted array. Time complexity: **O(log n)**.

### **Standard Template Library (STL) 🚀**
The **Standard Template Library (STL)** provides a collection of built-in **data structures** and **algorithms** in C++. It simplifies coding by offering optimized implementations of commonly used functionalities.

- **Pair**: A container that holds two values of possibly different types.
- **Vector**: A **dynamic array** that can grow or shrink automatically.
- **List**: A **doubly linked list** allowing efficient insertion and deletion.
- **Deque (Double-Ended Queue)**: Allows insertion and deletion from both the **front** and **back** in constant time.

### **Linked Lists**
- **Basics of Linked List**: Understanding nodes, pointers, and how linked lists differ from arrays in memory allocation.
- **Class Implementation of Singly Linked List**: Defining a `Node` class and managing the list through insertion, traversal, and deletion.
- **Insert at End**: Adding new elements at the end of the list using pointer manipulation.
- **Print the List**: Traversing the list and printing all node values sequentially.
- **Search in Linked List**: Recursively or iteratively checking if a value exists in the list.
- **Reverse Linked List**: Reversing the entire list by updating the `next` pointers using an iterative method.
- **Remove Nth Node from End**: Removing the nth node from the end using two-pointer (fast and slow) technique.
- **Check Palindrome**: Checking if the linked list is a palindrome by reversing the second half and comparing both halves.

### **Stacks**
- **Introduction to Stack**: A **Last In First Out (LIFO)** data structure where the last element added is the first to be removed.
- **Stack Operations**:
  - `push()`: Add an element to the top.
  - `pop()`: Remove the top element.
  - `top()` / `peek()`: View the top element without removing it.
  - `isEmpty()`: Check if the stack is empty.
- **Implementation**:
  - **Using Arrays**: Implementing a static stack using fixed-size arrays.
  - **Using Vectors**: Dynamic stack implementation using C++ vectors.
  - **Using STL Stack**: Utilizing the built-in `stack` container from STL for efficient and concise code.
- **Applications**:
  - **Valid Parentheses**: Checking for balanced brackets.
  - **Reverse a String**: Reversing characters using stack.
  - **Next Greater Element**: Finding the next greater element to the right using a monotonic stack.
  - **Call Stack Simulation**: Mimicking function call behavior using stack.

### **Queues**
- **Introduction to Queue**: A **First In First Out (FIFO)** data structure where the first element added is the first to be removed.
- **Queue Operations**:
  - `enqueue()`: Add an element at the rear.
  - `dequeue()`: Remove the element from the front.
  - `front()`: Access the front element.
  - `isEmpty()`: Check if the queue is empty.
- **Implementation**:
  - **Using Arrays**: Fixed-size array implementation with circular indexing.
  - **Using STL Queue**: Utilizing the built-in `queue` container from the STL.
  - **Using Deque**: Implementing queue using `deque` for double-ended flexibility.
- **Applications**:
  - **Level Order Traversal**: Traversing trees level by level.
  - **Task Scheduling**: Managing processes in operating systems.
  - **Sliding Window Problems**: Solving problems using queue or deque for efficient window management.

### **Greedy Algorithm**
- **What is Greedy Algorithm?**:  
  A problem-solving approach where decisions are made step-by-step to choose the best option at each stage with the hope that this leads to an optimal solution overall.
- **Characteristics**:
  - **Local Optimization**: Greedy algorithms make the best choice at each step.
  - **No Backtracking**: Once a decision is made, it is never reconsidered.
- **Common Problems**:
  - **Activity Selection Problem**: Choosing the maximum number of activities that don’t overlap.
  - **Fractional Knapsack Problem**: Taking items with the highest value-to-weight ratio first.
  - **Huffman Encoding**: Building an optimal prefix code for data compression.
  - **Job Sequencing with Deadlines**: Scheduling jobs to maximize profit within deadlines.
- **Time Complexity**: Varies by implementation, generally **O(n log n)** when sorting is involved.

### **Binary Search Tree**
- **Introduction**: A Binary Search Tree (BST) is a binary tree where each node has a value such that the left child is less than the node and the right child is greater.
- **Properties**:
  - Left subtree contains nodes with values less than the root.
  - Right subtree contains nodes with values greater than the root.
  - Inorder traversal of BST gives a sorted sequence.
- **Operations**:
  - **Insertion**: Recursively insert elements maintaining BST property.
  - **Search**: Recursively or iteratively search for a value.
  - **Deletion**: Handle three cases—node with no child, one child, or two children.
  - **Traversal**: Inorder, Preorder, Postorder.
  - **Minimum and Maximum**: Finding the min/max value in BST.
- **Applications**:
  - Efficient searching and insertion.
  - Used in databases and range queries.
  - Basis for self-balancing trees like AVL and Red-Black Trees.

### **Heaps / Priority Queue**

- **Introduction to Heaps**:  
  A heap is a specialized tree-based data structure that satisfies the heap property:  
  - **Max-Heap**: The key at the root must be maximum among all keys present in the heap.  
  - **Min-Heap**: The key at the root must be minimum among all keys present in the heap.  
  Heaps are commonly implemented as binary trees but are usually stored as arrays for efficient indexing.

- **Heap Properties**:  
  - Complete binary tree (all levels are fully filled except possibly the last, which is filled from left to right).  
  - Parent node is either greater than (max-heap) or less than (min-heap) its children.

- **Operations on Heaps**:
  - **Insertion**: Add the new element at the end of the heap and heapify up to maintain the heap property.  
  - **Deletion** (typically the root): Replace root with the last element, remove the last element, then heapify down.  
  - **Peek**: Access the root element (max or min) in constant time **O(1)**.

- **Time Complexity**:
  - Insertion: **O(log n)**  
  - Deletion (Extract Max/Min): **O(log n)**  
  - Peek (Get Max/Min): **O(1)**

- **Priority Queue**:  
  A data structure built on top of heaps that allows elements to be processed based on priority rather than insertion order.  
  - By default, C++ STL `priority_queue` is a max-heap.  
  - Can be customized to behave as a min-heap by using a comparator.

- **Common Use Cases**:
  - **Dijkstra’s shortest path algorithm** (using min-priority queue).  
  - **Huffman coding** (building the tree using min-heap).  
  - **Order statistics**: finding kth largest/smallest element.  
  - **Event-driven simulation**: managing events by priority.  
  - Efficiently implementing sorting algorithms like **Heap Sort**.

- **Heap Sort**:  
  A comparison-based sorting technique based on a binary heap data structure. It involves building a max-heap and repeatedly extracting the maximum element to get a sorted array. Time complexity: **O(n log n)**.