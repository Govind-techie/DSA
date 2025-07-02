/*
Problem: Course Schedule II (Find Order of Courses)

Given the total number of courses and a list of prerequisite pairs,
return any possible order in which all courses can be finished. 
If it is not possible to finish all courses (i.e., there is a cycle), return an empty list.

Input:
    - Number of courses (n)
    - List of prerequisite pairs (each pair [a, b] means to take course a you must first take course b)

Output:
    - A list representing a valid order to take all courses, or an empty list if impossible.

Example:
    Input:
        n = 4
        prerequisites = [[1,0],[2,1],[3,2]]
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Graph class for course schedule (topological sort with cycle detection)
class Graph {
    int V; // number of courses (nodes)
    vector<vector<int>> adj; // adjacency list

    // DFS to detect cycle using coloring method:
    // 0 = unvisited, 1 = visiting, 2 = visited
    bool dfsCycle(int u, vector<int>& state) {
        state[u] = 1; // mark as visiting
        for (int v : adj[u]) {
            if (state[v] == 0) {
                if (dfsCycle(v, state)) return true; // cycle found in deeper path
            } else if (state[v] == 1) {
                return true; // back-edge found → cycle
            }
        }
        state[u] = 2; // mark as fully processed
        return false;
    }

    // Standard DFS for topological sorting
    void topoDFS(int u, vector<bool>& vis, stack<int>& st) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) topoDFS(v, vis, st);
        }
        st.push(u); // backtrack push to stack
    }

public:
    // Constructor to initialize graph
    Graph(int n) : V(n), adj(n) {}

    // Function to add a directed edge from u to v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Returns topological order of courses if no cycle exists
    vector<int> findOrder() {
        vector<int> state(V, 0); // state for cycle detection
        for (int i = 0; i < V; ++i)
            if (state[i] == 0 && dfsCycle(i, state)) return {}; // if cycle found, return empty

        // No cycle found, proceed to topological sort
        vector<bool> vis(V, false);
        stack<int> st;
        for (int i = 0; i < V; ++i)
            if (!vis[i]) topoDFS(i, vis, st);

        // Convert stack to vector (reverse of finishing times)
        vector<int> order;
        while (!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }
};

int main() {
    int numCourses = 4;

    // Each pair: to take course a, you must first complete course b → edge from b → a
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    Graph g(numCourses);

    // Add edges based on prerequisites
    for (auto& p : prerequisites)
        g.addEdge(p[1], p[0]); // b → a

    // Try to get a valid topological order (course order)
    vector<int> order = g.findOrder();
    if (order.empty()) {
        cout << "cycle\n"; // If empty, it means there's a cycle in the graph
    } else {
        for (int x : order) cout << x << " "; // Print valid course order
        cout << endl;
    }

    return 0;
}