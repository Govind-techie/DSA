/*
Bellman-Ford Algorithm (Shortest Path in Weighted Graph with Negative Weights)

- The Bellman-Ford algorithm finds the shortest path from a source node to all other nodes in a weighted graph.
- Unlike Dijkstra's algorithm, Bellman-Ford can handle graphs with negative edge weights.
- It can also detect negative weight cycles (cycles whose total weight is negative).

Key Steps:
    1. Initialize distances from the source to all nodes as infinity, except the source itself (distance 0).
    2. Relax all edges V-1 times (V = number of vertices):
        - For each edge (u, v, weight), if distance[u] + weight < distance[v], update distance[v].
    3. Check for negative weight cycles by relaxing all edges one more time.
        - If any distance can still be updated, a negative cycle exists.

Applications:
    - Shortest path in graphs with negative weights
    - Detecting negative weight cycles
    - Currency arbitrage detection

Example:
    For edges: (0-1, 4), (0-2, 5), (1-2, -3), (2-3, 4)
    Shortest path from 0 to 3: 0 → 1 → 2 → 3 (cost 5)

Note - BF doesn't work for Negative Weight Cycles (cycles with overall negative weight).
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Edge{
public:
    int v;
    int wt;
    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

    void print(const vector<int>&dist){
        for (int d : dist){
            cout << d << " ";
        } cout << endl;
    }

    void bellmanFord(vector<vector<Edge>>& g, int V, int src) { // Time Complexity => O(V * E)
        vector<int> dist(V, INT_MAX); // Step 1: Initialize distances
        dist[src] = 0;

        // Outer Loop => O(V)
        for (int i = 0; i < V - 1; i++) { 
            // Traverse all edges V-1 times to ensure shortest paths (standard Bellman-Ford)
            
            // Inner Loop => O(E)
            for (int u = 0; u < V; u++) { // Traverse each node
                for (auto edge : g[u]) {
                    // Edge Relaxation (only if current node is reachable)
                    if (dist[u] != INT_MAX && dist[edge.v] > dist[u] + edge.wt) {
                        dist[edge.v] = dist[u] + edge.wt;
                    }
                }
            }
        }

        print(dist); // Final distances from src to all nodes
    }

int main(){
    // BellmanFord Graph
    int V = 6;
    vector<vector<Edge>>g(V);
    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,-4));

    g[2].push_back(Edge(3,2));

    g[3].push_back(Edge(4,4));

    g[4].push_back(Edge(1,-1));

    bellmanFord(g,V,0);
    return 0;
}