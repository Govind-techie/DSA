// Memory Address: When a variable is initialized, it is stored in the computer’s memory at a specific location, which is called a memory address.

//Note : & Operator is used to print or fetch the memory location at which respective variable is stored.

#include<iostream>
using namespace std;

int main(){
    int a = 10;
    cout << &a << endl; // Prints Memory Address of variable (a).
    return 0;
}