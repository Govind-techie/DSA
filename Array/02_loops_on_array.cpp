// Loops on Arrays: Loops are used to access and process each element of an array and perform operations over it efficiently.

#include<iostream>
using namespace std;

int main(){

    int marks[5]= {99,100,86,78,95};

    int size = sizeof(marks)/sizeof(int); // It stores the size of an array

    // We can use loop to print each element of an array.

    for (int i = 0 ; i < size ; i++){
        cout<<marks[i]<<endl; // Here, we use i as index as the value of i increase after ecah iteration which will act as index of each element within that array.
    }

    // we can use loops on array to take input for data which has to be stored in it.

    // Eg : We have to store price of 5 items and take its average.

    int price[5];
    int size_2 = sizeof(price)/sizeof(int);
    int total = 0;

    for (int i = 0 ; i < size_2 ; i++){
        cout<<"Enter price of items "<<i+1<<" : "; // Here, we take the item price as input in each iteration. 
        cin>>price[i]; // Store it in price array with index position as i.
    }

    for (int i = 0 ; i < size_2 ; i++){
        total += price[i]; // Here, we fetching data from price array and adding it in total varaible.
    } 

    int average = total/size_2; // Here, we store the average price by dividing (total/size of price array)

    cout<<"The average price of 5 items is : "<<average<<endl; // We, print the average price of 5 items.

    // Problem : Find the smallest and largest value from an array.

    int numbers[5];
    int size_3 = sizeof(numbers)/sizeof(int);
    int smallest = INT_MAX; // It initialize the value of smallest varaible with a random large number.
    int smallest_1 = INT_MAX; 
    int smallest_2 = INT_MAX;
    int largest = INT_MIN; // It initialize the value of largest varaible with a random small number (large negative value).
    int largest_1 = INT_MIN; 
    int largest_2 = INT_MIN; 
    // Loop for storing data in array :

    for (int i = 0 ; i < size_3 ; i++){
        cout<<"Enter number "<<i+1<<" : ";
        cin>>numbers[i];
    }

    // Loops for comparison :

    for (int i = 0 ; i < size_3 ; i++){
        if (numbers[i] < smallest){ // Here, we compare the numbers of array with the smallest value which we intiailzed with a random large number
            smallest = numbers[i]; // If the condition satisfies it changes the value within the smallest varaible and assign number of that array at particular index to it.
        } 
    }

    cout<<"The smallest no. is : "<<smallest<<endl; // After the compeletion of loop it prints the smallest number. 

    for (int i = 0 ; i < size_3 ; i++){
        if (numbers[i] > largest){ // Here, we compare the numbers in array with the largest value which we intiailzed with a random small number (large negative value).
            largest = numbers[i]; // If the condition satisfies it changes the value within the largest varaible and assign number of that array at particular index to it.
        } 
    }

    cout<<"The largest no. is : "<<largest<<endl; // After the compeletion of loop it prints the largest number. 

    // We can solve this same problem using min and max function on array :

    for (int i = 0 ; i < size_3 ; i++){
        smallest_1 = min(numbers[i],smallest_1); // min compares two value and give minimum value out of it.
    }

    for (int i = 0 ; i < size_3 ; i++){
        largest_1 = max(numbers[i],largest_1); // max compares two value and give maximum value out of it.
    }

    cout<<"The smallest no. is : "<<smallest_1<<endl; 
    cout<<"The largest no. is : "<<largest_1<<endl; 

    // Problem : we have to print the index of smallest and largest num in array :

    int indexForSmallest = 0;
    int indexForLargest = 0;

    for (int i = 0 ; i < size_3 ; i++){
        if (numbers[i] < smallest_2){
            smallest_2 = numbers[i]; 
            indexForSmallest = i;
    }
    }

    cout<<"The smallest no. index is : "<<indexForSmallest<<endl; 

    for (int i = 0 ; i < size_3 ; i++){
        if (numbers[i] > largest_2){
            largest_2 = numbers[i]; 
            indexForLargest = i;            
        } 
    }

    cout<<"The largest no. index is : "<<indexForLargest<<endl; 

    

}