# DSA Journey Repository 🚀

Welcome to my **Data Structures and Algorithms (DSA)** learning journey! This repository contains all my notes, code, and progress throughout my DSA exploration. I aim to regularly update this repository as I learn new concepts, solve problems, and enhance my understanding.

## 📚 Topics Covered

### **Arrays** 
- **Basics of Arrays**: Understanding array declaration, initialization, and memory layout.  
- **Loops Over Arrays**: Iterating through arrays using different loop constructs.  
- **Pass by Reference**: Understanding how arrays are passed to functions and their behavior.  
- **Linear Search Algorithm**: Implementing and analyzing the linear search algorithm.  
- **Reverse Array**: Reversing an array using the Two-Pointer Approach.  
- **Intersection of Two Arrays**: Implementing a function to find common elements between two arrays.  

### **Vectors**
- **Basics of Vectors**: Understanding vector declaration, initialization, and dynamic resizing.  
- **Vector Functions**: Exploring common vector functions like `push_back()`, `pop_back()`, `size()`, `at()`, etc., and their usage.  
- **For-Each Loop**: Using the range-based `for` each loop to iterate over vectors and access their elements directly.
- **Static Memory Allocation**: Memory is allocated at compile-time for fixed-size arrays.
- **Dynamic Memory Allocation**: Memory is allocated at runtime for structures like vectors, with dynamic resizing.

### **Kadane's Algorithm**
- **Kadane's Algorithm**:  
  Kadane's algorithm is an efficient method to find the maximum sum of a contiguous subarray in an array of numbers. It operates in **O(n)** time, making it significantly faster than the brute-force approach. 

### **Moore's Voting Algorithm**
- **Moore's Voting Algorithm**:  
  This algorithm helps find the majority element (the element that appears more than **n / 2** times) in an array. It maintains a candidate and a counter. If the counter reaches zero, a new candidate is chosen. The algorithm runs in **O(n)** time with constant space.


## ⏳ Time and Space Complexity
- **Time Complexity**: I have learned that time complexity measures how the execution time of an algorithm increases with respect to the input size. It helps to evaluate the efficiency of algorithms, especially for large inputs. Some of the time complexities I have studied include:
  - **O(1)**: Constant time complexity – the operation takes the same amount of time regardless of input size.
  - **O(log n)**: Logarithmic time complexity – the operation grows logarithmically with the input size (often seen in algorithms that divide the input, like binary search).
  - **O(n)**: Linear time complexity – the operation grows linearly with the input size.
  - **O(n log n)**: Log-linear time complexity – the operation grows logarithmically with respect to input size and linearly with a part of the input size (seen in efficient sorting algorithms like Merge Sort and Quick Sort).
  - **O(n^2)**: Quadratic time complexity – the operation grows quadratically as the input size increases (often caused by nested loops).
  - **O(n^3)**: Cubic time complexity – the operation grows cubically with the input size (typically due to three nested loops).
  - **O(2^n)**: Exponential time complexity – the operation grows exponentially with the input size (common in recursive algorithms like Fibonacci).
  - **O(n!)**: Factorial time complexity – the operation grows very fast as the input size increases (common in brute-force algorithms).

- **Space Complexity**: Space complexity evaluates the amount of memory required by an algorithm as the input size grows. It helps to understand the memory efficiency of an algorithm.  
- **Big O Notation**: I have also learned about Big O notation, which is used to describe the worst-case scenario for time or space complexity, providing a way to compare algorithms based on how they scale with increasing input size.

### **Binary Exponentiation**
- **Binary Exponentiation**:  
  Binary Exponentiation is a method used to efficiently calculate **x^n** (x raised to the power n) in **O(log n)** time. It works by breaking down the power calculation into smaller, more manageable steps by exploiting the properties of exponents. This approach uses the concept of exponentiation by squaring, allowing us to reduce the number of multiplications. This technique is particularly useful for large values of `n` in problems such as computing powers in modular arithmetic and optimizing algorithms like the Pow(x, n) problem.

### **Pointers**
- **Basics of Pointers**: Understanding memory addresses, dereferencing, and pointer declaration.  
- **Pointer Arithmetic**: Performing operations like increment, decrement, addition, and subtraction on pointers.  
- **Pass-by-Reference**: Using pointers to modify values inside functions without returning them.  
- **Constant Pointers**: Understanding restrictions on modifying stored addresses or pointed values.  
- **Pointer to Pointer**: Storing the address of a pointer and accessing multi-level references.  
- **Dynamic Memory Allocation**: Allocating and deallocating memory at runtime using `new` and `delete`.  
- **Pointer and Arrays**: Understanding how arrays are internally pointers and using pointer arithmetic for traversal.  
- **Undefined Behavior**: Accessing memory outside valid bounds can lead to garbage values or segmentation faults.  
