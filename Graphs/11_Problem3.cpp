/*
Problem: Course Schedule (Cycle Detection in Directed Graph)

Given the total number of courses and a list of prerequisite pairs,
determine if it is possible to finish all courses (i.e., the course schedule has no cycles).

Input:
    - Number of courses (n)
    - List of prerequisite pairs (each pair [a, b] means to take course a you must first take course b)

Output:
    - Return true if all courses can be finished, otherwise return false.

Example:
    Input:
        n = 4
        prerequisites = [[1,0],[2,1],[3,2]]
    Output:
        true
*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Graph class to represent a directed graph of courses
class Graph {
    int V; // number of courses (nodes)
    vector<list<int>> adj; // adjacency list to store edges

    // DFS function to detect a cycle in the graph
    bool dfsCycle(int u, vector<bool>& vis, vector<bool>& rec) {
        vis[u] = true;      // mark current node as visited
        rec[u] = true;      // mark node in current recursion path (for cycle check)

        for (int v : adj[u]) { // visit all neighbours of u
            if (!vis[v]) {
                // if neighbor not visited, DFS from it
                if (dfsCycle(v, vis, rec)) return true; // if cycle found in deeper path
            } else if (rec[v]) {
                // if neighbor is already in recursion path → cycle
                return true;
            }
        }

        rec[u] = false; // backtrack: remove from recursion path
        return false; // no cycle from this node
    }

public:
    // constructor to initialize graph with n nodes
    Graph(int n) : V(n), adj(n) {}

    // function to add a directed edge from u to v (u → v)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // function to check if all courses can be finished (i.e., no cycle)
    bool canFinish() {
        vector<bool> vis(V, false); // tracks visited nodes
        vector<bool> rec(V, false); // tracks current DFS path

        for (int i = 0; i < V; ++i) {
            // start DFS from unvisited node
            if (!vis[i]) {
                if (dfsCycle(i, vis, rec)) return false; // cycle found
            }
        }

        return true; // no cycles found, all courses can be finished
    }
};

int main() {
    int numCourses = 4;

    // prerequisites: to take course a, you must first take course b
    // Example: {1, 0} → take course 0 before 1
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    Graph g(numCourses); // create a graph with 4 courses

    // add edges to the graph based on prerequisites
    for (auto& p : prerequisites) {
        g.addEdge(p[1], p[0]); // directed edge: b → a
    }

    // check if it's possible to finish all courses
    if (g.canFinish()) {
        cout << "Yes, you can finish all courses.\n";
    } else {
        cout << "No, there's a cycle. Cannot finish all courses.\n";
    }

    return 0;
}