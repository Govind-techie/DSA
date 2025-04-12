// Loops on Arrays: Loops are used to access and process each element of an array efficiently.

#include<iostream>
using namespace std;

int main(){

    int marks[5]= {99,100,86,78,95};

    int size = sizeof(marks)/sizeof(int); // Calculates the total number of elements in the array.

    // Using a loop to print each element of the array.

    for (int i = 0 ; i < size ; i++){
        cout<<marks[i]<<endl; // 'i' is used as an index to access elements one by one during each iteration.
    }

    // We can also use loops to input data into an array.

    // Example: Take input for the prices of 5 items and find their average.

    int price[5];
    int size_2 = sizeof(price)/sizeof(int);
    int total = 0;

    for (int i = 0 ; i < size_2 ; i++){
        cout<<"Enter price of items "<<i+1<<" : "; // Asking user to input item prices one by one.
        cin>>price[i]; // Storing the input value in the array at index 'i'.
    }

    for (int i = 0 ; i < size_2 ; i++){
        total += price[i]; // Adding each element of the array to the 'total' variable.
    } 

    int average = total/size_2; // Calculating average by dividing the total by the number of items.

    cout<<"The average price of 5 items is : "<<average<<endl; // Displaying the calculated average.

    // Problem: Find the smallest and largest values from an array.

    int numbers[5];
    int size_3 = sizeof(numbers)/sizeof(int);
    int smallest = INT_MAX; // Initializing with the maximum possible integer value.
    int smallest_1 = INT_MAX; 
    int smallest_2 = INT_MAX;
    int largest = INT_MIN; // Initializing with the minimum possible integer value.
    int largest_1 = INT_MIN; 
    int largest_2 = INT_MIN; 

    // Loop to input elements into the array:

    for (int i = 0 ; i < size_3 ; i++){
        cout<<"Enter number "<<i+1<<" : ";
        cin>>numbers[i];
    }

    // Loop to find the smallest number:

    for (int i = 0 ; i < size_3 ; i++){
        if (numbers[i] < smallest){ // If current number is smaller than the current smallest.
            smallest = numbers[i]; // Update smallest with the current number.
        } 
    }

    cout<<"The smallest no. is : "<<smallest<<endl; // Display the smallest number.

    // Loop to find the largest number:

    for (int i = 0 ; i < size_3 ; i++){
        if (numbers[i] > largest){ // If current number is larger than the current largest.
            largest = numbers[i]; // Update largest with the current number.
        } 
    }

    cout<<"The largest no. is : "<<largest<<endl; // Display the largest number.

    // We can also solve the same problem using the built-in min and max functions:

    for (int i = 0 ; i < size_3 ; i++){
        smallest_1 = min(numbers[i],smallest_1); // Updates smallest_1 with the smaller of two values.
    }

    for (int i = 0 ; i < size_3 ; i++){
        largest_1 = max(numbers[i],largest_1); // Updates largest_1 with the larger of two values.
    }

    cout<<"The smallest no. is : "<<smallest_1<<endl; 
    cout<<"The largest no. is : "<<largest_1<<endl; 

    // Problem: Print the index of the smallest and largest numbers in the array.

    int indexForSmallest = 0;
    int indexForLargest = 0;

    for (int i = 0 ; i < size_3 ; i++){
        if (numbers[i] < smallest_2){
            smallest_2 = numbers[i]; 
            indexForSmallest = i; // Store the index where the smallest number is found.
        }
    }

    cout<<"The smallest no. index is : "<<indexForSmallest<<endl; 

    for (int i = 0 ; i < size_3 ; i++){
        if (numbers[i] > largest_2){
            largest_2 = numbers[i]; 
            indexForLargest = i; // Store the index where the largest number is found.
        } 
    }

    cout<<"The largest no. index is : "<<indexForLargest<<endl; 

}