/*
Problem: Print All Paths Between Two Nodes

Given an undirected graph and two nodes (src and dest), print all possible simple paths from src to dest.

Input:
    - Number of vertices and edges
    - List of edges
    - Source node (src)
    - Destination node (dest)

Output:
    - All simple paths from src to dest
*/

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

class Graph {
    int V;
    vector<list<int>> adjList; 
public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // Utility function to print a path
    void print(const vector<int>& path) {
        for (int node : path) cout << node << " ";
        cout << endl;
    }

    // DFS function to find all simple paths from u to dest
    void dfs(int u, int dest, vector<int>& path, vector<bool>& visited) {
        // If destination is reached, print the current path
        if (u == dest) {
            print(path);
            return;
        }

        // Explore all unvisited neighbors of the current node
        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;        // Mark node as visited
                path.push_back(v);        // Add node to current path
                dfs(v, dest, path, visited); // Recur for neighbor
                path.pop_back();          // Backtrack
                visited[v] = false;       // Unmark node
            }
        }
    }

    // Function to start DFS from source to destination
    void allPaths(int src, int dest) {
        vector<bool> visited(V, false); // To keep track of visited nodes
        vector<int> path;               // To store current path
        path.push_back(src);            // Start path from source
        visited[src] = true;            // Mark source as visited
        dfs(src, dest, path, visited);  // Start DFS
    }
};

int main() {
    Graph g(5); 
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    int src = 0, dest = 4;
    g.allPaths(src, dest);

    return 0;
}