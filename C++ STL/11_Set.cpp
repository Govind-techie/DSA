/*

Set:
A set is a data structure in C++ that stores unique elements in sorted order by default. It automatically removes duplicates and allows fast searching (O(log n) time complexity).

Think of it like a basket of unique fruits:
• If you try to add the same fruit twice, it won’t be duplicated.
• The fruits are always arranged in a sorted manner.

Note : For unordered storage with faster access, use unordered_set.

*/

#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int>s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    s.insert(1); // In Set we can't insert or store dupicate values.

    cout << "Size : " << s.size() << endl; // Output : 5 (It doesn't stored duplicate (1) value)

    for (int val : s){
        cout << val << " "; // It only prints unique values stored in set in sorted order.
    }

    cout << endl;

    return 0;
}