/*
Prim's Algorithm for Minimum Spanning Tree (MST)

- Prim's Algorithm finds the Minimum Spanning Tree of a connected, undirected, weighted graph.
- It starts from any node and grows the MST by always choosing the minimum weight edge that connects a visited node to an unvisited node.

Key Steps:
    1. Start from any vertex and mark it as visited.
    2. Use a min-heap (priority queue) to pick the smallest edge connecting the MST to a new vertex.
    3. Add the selected edge and vertex to the MST.
    4. Repeat until all vertices are included in the MST.

Applications:
    - Network design (roads, electricity, computer networks)
    - Clustering data

Example:
    For edges: (0-1, 4), (0-2, 3), (1-2, 1), (1-3, 2), (2-3, 4)
    The MST could be edges: (1-2, 1), (1-3, 2), (0-2, 3) with total cost
*/

#include<iostream>
#include<vector>
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

    void primMST(vector<vector<Edge>>& g, int V, int src){
        // Keeps track of whether a vertex is already included in MST
        vector<bool> mstSet(V, false);

        // Min-heap to pick the edge with the smallest weight at every step
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Start from the source node with cost 0
        pq.push({0, src});  // pair = {cost, node}

        int totCost = 0; // Stores the total cost of the MST

        while (!pq.empty()){
            auto [cost, u] = pq.top();
            pq.pop();

            // Skip if this node is already included in MST
            if (!mstSet[u]){
                mstSet[u] = true;       // Mark current node as part of MST
                totCost += cost;        // Add edge cost to total MST cost

                // Traverse all neighbors of current node
                for (auto e : g[u]){
                    // Add edge to priority queue only if the neighbor is not in MST
                    if (!mstSet[e.v]){
                        pq.push({e.wt, e.v});
                    }
                }
            }
        }

        cout << "Total MST Cost = " << totCost << endl;
    }

int main(){
    int V = 4;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 1));
    g[1].push_back(Edge(0, 1)); // Undirected

    g[1].push_back(Edge(2, 2));
    g[2].push_back(Edge(1, 2));

    g[0].push_back(Edge(2, 4));
    g[2].push_back(Edge(0, 4));

    g[2].push_back(Edge(3, 3));
    g[3].push_back(Edge(2, 3));

    g[1].push_back(Edge(3, 5));
    g[3].push_back(Edge(1, 5));

    primMST(g, V, 0);

    return 0;
}