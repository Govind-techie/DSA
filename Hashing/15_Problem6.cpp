/*
Itinerary from Tickets (using map)

Given a map where each key is a source city and its value is the destination city, reconstruct the complete itinerary in order.
Assume the itinerary starts from the city that is only a source and never a destination.

Input:
- A map<string, string> representing tickets (source -> destination)

Output:
- The complete itinerary in order as a list of cities

Example:
Input: tickets = { {"Chennai", "Bangalore"}, {"Bombay", "Delhi"}, {"Goa", "Chennai"}, {"Delhi", "Goa"} }
Output: Bombay -> Delhi -> Goa -> Chennai -> Bangalore

Explanation: The journey starts at Bombay and follows the tickets in order.
*/

#include<iostream>
#include<unordered_map>
#include<string>
#include<utility>
#include<unordered_set>
using namespace std;

string start(unordered_map<string,string>m){
    unordered_set<string>s;
    for (pair<string,string> p : m) s.insert(p.second);

    for (pair<string,string> p : m){
        if (!s.count(p.first)){
            return p.first;
        }
    }
    return "";
}

string end(unordered_map<string,string>m){
    unordered_set<string>s;
    for (pair<string,string> p : m) s.insert(p.first);
    
    for (pair<string,string> p : m){
        if (!s.count(p.second)){
            return p.second;
        }
    }
    return "";
}

void itineraryTickets(unordered_map<string,string>m){
    string st = start(m);
    string en = end(m);

    while (st != en){
        cout << st << " -> ";
        st = m[st];
    }
    cout << en << endl;
}
int main(){
    unordered_map<string,string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    itineraryTickets(tickets);
    return 0;
}