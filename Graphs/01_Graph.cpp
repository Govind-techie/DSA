/*
Graph

A graph is a non-linear data structure consisting of:
    - A set of vertices (nodes)
    - A set of edges (connections between nodes)

Types of Graphs:
    1. Directed Graph (DiGraph): Edges have a direction.
    2. Undirected Graph: Edges do not have a direction.
    3. Weighted Graph: Edges have weights (costs,value).
    4. Unweighted Graph: Edges do not have weights.

Graph Representation:
    - Adjacency Matrix: 2D array to represent connections.
    - Adjacency List: List of lists or map for efficient storage.

Common Graph Algorithms:
    - Breadth-First Search (BFS)
    - Depth-First Search (DFS)
    - Dijkstra's Algorithm (Shortest Path)
    - Kruskal's & Prim's Algorithm (Minimum Spanning Tree)

Applications:
    - Social Networks
    - Maps & Navigation
    - Network Routing
    - Recommendation
*/

#include<iostream>
#include<vector>
#include<list> // Needed for list (used in adjacency list)
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
};

int main(){
    // Create a graph with 4 vertices (0 to 3)
    Graph g(4);

    // Add edges to the graph
    g.addEdge(0, 1); // Connect 0 and 1
    g.addEdge(1, 2); // Connect 1 and 2
    g.addEdge(1, 3); // Connect 1 and 3
    g.addEdge(2, 3); // Connect 2 and 3

    g.printGraph();

    return 0;
}