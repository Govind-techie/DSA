/*
Breadth-First Search (BFS) - Graph Traversal Algorithm

- BFS is a fundamental g traversal technique.
- It explores all neighbors of a node before moving to the next level.
- BFS uses a queue data structure to keep track of nodes to visit.
- It is commonly used to find the shortest path in unweighted graphs.

Key Points:
    1. BFS starts from a given source node.
    2. Visits all nodes at the current depth before going deeper.
    3. Useful for:
        - Shortest path in unweighted graphs
        - Level order traversal in trees
        - Finding connected components

Time Complexity: O(V + E)
    - V = Number of vertices
    - E = Number of edges

Typical Steps:
    1. Mark the starting node as visited and enqueue it.
    2. While the queue is not empty:
        a. Dequeue a node from the queue.
        b. Visit all its unvisited neighbors, mark them as visited, and enqueue them.

Note: In BFS it states that travel to immediate neighbours first
*/

#include<iostream>
#include<vector>
#include<list> 
#include<queue>
using namespace std;

class Graph {
    int V; 
    vector<list<int>> adjList;
public:
    Graph(int V) {
        this->V = V;          
        adjList.resize(V);     
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Function to perform Breadth-First Search (BFS) starting from node 0
    void BFS(int st) { // O(V+E)
        queue<int> q; // Create a queue to keep track of nodes to visit
        vector<bool> vis(V, false); // Create a visited array to mark visited nodes

    q.push(st); // Start BFS from the given starting node
    vis[st] = true; // Mark the starting node as visited

        while (!q.empty()) { // Keep running until all reachable nodes are visited
            int u = q.front(); // Get the front node from the queue
            q.pop(); // Remove it from the queue

            cout << u << " "; // Print the current node (or process it)

            // Go through all neighbors of the current node
            for (int v : adjList[u]) {
                if (!vis[v]) { // If the neighbor hasn't been visited yet
                    q.push(v); // Add it to the queue for future processing
                    vis[v] = true; // Mark the neighbor as visited
                }
            }
        }

        cout << endl; // Print a new line after BFS is done
    }
};

int main(){

    Graph g (7);
    g.addEdge (0,1);
    g.addEdge (0,2);
    g.addEdge (1,3);
    g.addEdge (2,4);
    g.addEdge (3,4);
    g.addEdge (3,5);
    g.addEdge (4,5);
    g.addEdge (5,6);

    int st = 3;

    g.BFS(st);

    return 0;
}