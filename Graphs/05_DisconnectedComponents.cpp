/*
Disconnected Components in a Graph

- A disconnected component is a part of a graph where nodes are connected to each other,
  but there is no path to nodes in other components.
- In an undirected graph, the entire graph may be split into two or more disconnected components.
- Each component is a maximal set of nodes such that there is a path between any two nodes in the set.

Key Points:
    1. Disconnected components occur when not all nodes are reachable from each other.
    2. To find all components, we can use BFS or DFS starting from every unvisited node.
    3. The number of times we start a new traversal equals the number of disconnected components.

Applications:
    - Network reliability analysis
    - Social network clusters
    - Identifying isolated groups in data

Example:
    Graph:
        0 - 1     2 - 3
    Here, there are two disconnected components: {0,1} and {2,3}.
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    vector<list<int>>adjList;
public:
    Graph(int V){
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void DFS(int src, vector<bool>&vis){
        vis[src] = true;

        cout << src << " ";
        for (int v : adjList[src]){
            if (!vis[v]){
                DFS(v,vis);
            }
        }
    }
};

int main() {
    int V = 8; // Total number of vertices (0 to 7)
    Graph g(V); // Create a graph with 8 vertices
    
    // Component 0
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    // Component 1
    g.addEdge(3, 4);

    // Component 2
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    // Initialize visited array to keep track of visited nodes
    vector<bool> vis(V, false); // vis[i] = true means node i has been visited

    // Perform DFS for all components
    for (int i = 0; i < vis.size(); i++) {
        // If node i has not been visited, start DFS from there
        // This ensures we cover disconnected components as well
        if (!vis[i]) {
            g.DFS(i, vis);
        }
    }

    cout << endl;

    return 0;
}