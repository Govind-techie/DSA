/*
Pair in C++ STL

- pair is a container that stores two values together.
- Defined in <utility> header.
- Access values using .first and .second

Example:
    pair<int, string> p = {1, "hello"};
    cout << p.first << " " << p.second; // Output: 1 hello
*/

#include<iostream>
#include<utility>
#include<vector>
using namespace std;

// Custom comparator to sort pairs by their second value (ending time)
bool compare(pair<int,int>p1 , pair<int,int>p2){
    return p1.second < p2.second; // ascending order by second element
}

int main(){
    // Start times of activities
    vector<int> st = {0,1,2};
    // End times of activities
    vector<int> en = {9,2,4};

    // Vector of pairs to store (start, end) for each activity
    vector<pair<int,int>> pair (3 , make_pair(0,0));

    // Assigning start and end times to each pair
    pair[0] = make_pair(0,9);
    pair[1] = make_pair(1,2);
    pair[2] = make_pair(2,4);

    // Print all pairs before sorting
    for (int i = 0 ; i < pair.size() ; i++){
        cout << "["<< pair[i].first << "," << pair[i].second << "]" << endl;
    }

    // Sort pairs by end time using the custom comparator
    sort(pair.begin() , pair.end() , compare);
    
    cout << "-----------sorted---------\n";
    // Print all pairs after sorting
    for (int i = 0 ; i < pair.size() ; i++){
        cout << "["<< pair[i].first << "," << pair[i].second << "]" << endl;
    }
    return 0;
}