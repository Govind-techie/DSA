/*
Depth-First Search (DFS) - Graph Traversal Algorithm

- DFS is a fundamental graph traversal technique.
- It explores as far as possible along each branch before backtracking.
- DFS uses a stack data structure (can be implemented using recursion or an explicit stack).
- It is commonly used for path finding, cycle detection, and topological sorting.

Key Points:
    1. DFS starts from a given source node.
    2. Visits a node, then recursively visits all its unvisited neighbors.
    3. Useful for:
        - Path finding in mazes/graphs
        - Detecting cycles in a graph
        - Topological sorting in DAGs
        - Finding connected components

Time Complexity: O(V + E)
    - V = Number of vertices
    - E = Number of edges

Typical Steps:
    1. Mark the starting node as visited and process it.
    2. For each unvisited neighbor, recursively perform DFS.

Note: In DFS, you go deep into a branch before backtracking to explore other
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

// Graph class using adjacency list representation
class Graph {
    int V; // Number of vertices (nodes) in the graph
    vector<list<int>> adjList; // Vector of lists to store neighbors for each vertex

public:
    // Constructor to initialize the graph
    Graph(int V) {
        this->V = V;           // Set the number of vertices
        adjList.resize(V);     // Create V empty lists (one for each vertex)
    }

    // Adds an undirected edge between two vertices u and v
    void addEdge(int u, int v){
        adjList[u].push_back(v); // Add v to u's neighbor list
        adjList[v].push_back(u); // Add u to v's neighbor list (since undirected)
    }

    void printGraph(){
        for (int u = 0 ; u < V ; u++){
            // Get the list of neighbors for current vertex u
            list<int> neighbours = adjList[u];

            // Print the vertex and its neighbors
            cout << u << " : ";
            for (int v : neighbours){
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // Depth-First Search (DFS) function to traverse a graph
    void DFS(int u, vector<bool>& vis) { // O(V+E)
        // Mark the current node as visited
        vis[u] = true;

        // Print the current node (you can also store it in a result vector)
        cout << u << " ";

        // Visit all adjacent nodes of 'u'
        for (int v : adjList[u]) {
            // If the neighbor 'v' is not visited, recursively call DFS on it
            if (!vis[v]) {
                DFS(v, vis);
            }
        }
    }
};

int main(){
    int V = 7;
    Graph g (V);
    g.addEdge (0,1);
    g.addEdge (0,2);
    g.addEdge (1,3);
    g.addEdge (2,4);
    g.addEdge (3,4);
    g.addEdge (3,5);
    g.addEdge (4,5);
    g.addEdge (5,6);

    vector<bool>vis(V,false);
    int src = 0; // Source node of graph (staring node)
    g.DFS(src,vis);
    cout << endl;
    return 0;
}