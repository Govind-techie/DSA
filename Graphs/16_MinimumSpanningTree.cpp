/*
Minimum Spanning Tree (MST)

- A Minimum Spanning Tree of a connected, undirected, weighted graph is a subset of the edges
  that connects all the vertices together, without any cycles, and with the minimum possible total edge weight.
- MST contains exactly (V - 1) edges, where V is the number of vertices.

Key Points:
    1. MST connects all nodes with the least total edge cost and no cycles.
    2. Common algorithms to find MST:
        - Kruskal's Algorithm (greedy, sorts edges by weight)
        - Prim's Algorithm (greedy, grows MST from a starting node)
    3. Used in network design, circuit design, and clustering.

Applications:
    - Designing least-cost networks (roads, electricity, computer networks)
    - Clustering data
    - Approximation algorithms for NP-hard problems

Example:
    For a graph with edges:
        (0-1, 4), (0-2, 3), (1-2, 1), (1-3, 2), (2-3, 4)
    The MST could be edges: (1-2, 1), (1-3, 2), (0-2, 3) with total cost 6

NOTE: MST is a subset of the edges of a connected, 
edge-weighted undirected graph that connects all the 
vertices together, without any cycles and with the 
minimum possible total edge weight.
*/

#include<iostream>
#include<vector>
using namespace std;

// ---------- BASIC MST IMPLEMENTATION ----------

// Structure to store edges
class Edge {
public:
    int u, v, wt;
    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<Edge> edges;

    // Sample directed weighted graph (edge list)
    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(1, 3, 15));
    edges.push_back(Edge(2, 3, 4));

    cout << "Graph Edges (u - v : weight):\n";
    for (auto &e : edges) {
        cout << e.u << " - " << e.v << " : " << e.wt << endl;
    }

    return 0;
}