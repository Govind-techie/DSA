/*
Dijkstra's Algorithm (Shortest Path in Weighted Graph)

- Dijkstra's Algorithm finds the shortest path from a source node to all other nodes in a weighted graph with non-negative edge weights.
- It uses a priority queue (min-heap) to always expand the nearest unvisited node.

Key Steps:
    1. Initialize distances from the source to all nodes as infinity, except the source itself (distance 0).
    2. Use a min-heap (priority queue) to pick the node with the smallest distance.
    3. For each neighbor, if a shorter path is found, update its distance and add it to the queue.
    4. Repeat until all nodes are processed.

Applications:
    - Shortest path in maps and navigation systems
    - Network routing
    - Pathfinding in games

Example:
    For edges: (0-1, 4), (0-2, 1), (2-1, 2), (1-3, 1), (2-3, 5)
    Shortest path from 0 to 3: 0 → 2 → 1 → 3 (cost: 7)

Key Points about Dijkstra's Algorithm:

- Works only for graphs with non-negative edge weights.
  If the graph has negative weights, use Bellman-Ford instead.

  - It finds the shortest distance from the source node to all other nodes.

- Uses a greedy approach and a min-heap (priority queue) 
  to always pick the node with the smallest current distance.

- Time Complexity: O((V + E) * log V) when using a priority queue with adjacency list.

- Space Complexity: O(V + E)
*/

#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<utility>
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
    }
    cout << endl;
}

void dijkstra(int src, const vector<vector<Edge>>& g, int V) {
    vector<int> dist(V, INT_MAX); // store shortest distance from src to each node, initialized to infinity

    // Min heap to always get the node with the smallest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // push source node with distance 0
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; // get node with smallest distance
        pq.pop();

        // check all neighbours of node u
        for (auto edge : g[u]) {
            int v = edge.v;      // neighbour node
            int wt = edge.wt;    // weight of edge u -> v

            // if shorter path to v is found
            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt; // update distance
                pq.push({dist[v], v});  // push updated distance to heap
            }
        }
    }

    print(dist); // print final shortest distances
}

int main() {
    int V = 6;
    vector<vector<Edge>> g(V); // graph as adjacency list

    g[0].push_back(Edge(1, 1)); // edge from 0 to 1 with weight 1
    g[0].push_back(Edge(3, 4)); // edge from 0 to 3 with weight 4

    g[1].push_back(Edge(2, 2)); // edge from 1 to 2 with weight 2
    g[1].push_back(Edge(3, 6)); // edge from 1 to 3 with weight 6

    g[2].push_back(Edge(4, 1)); // edge from 2 to 4 with weight 1

    g[3].push_back(Edge(4, 3)); // edge from 3 to 4 with weight 3

    g[4].push_back(Edge(5, 2)); // edge from 4 to 5 with weight 2

    /*
    Graph implementation commonly used for Dijkstra and Bellman-Ford algorithms.

    - u  : Source node
    - v  : Adjacent (neighbour) node
    - wt : Weight of the edge from u to v

    - g[u] is a vector that stores all outgoing edges from node u.
    - Each edge is represented as an object of the Edge class.

    - Edge(v, wt) creates an edge from u to v with the given weight.
    - g[u].push_back(Edge(v, wt)) adds this edge to u's adjacency list.
    */

    dijkstra(0, g, V); // Time Complexity: O((V + E) * log V),

    /*
    NOTE: If we pick any node as the source, Dijkstra will calculate 
    the shortest distances starting from that node only.
    Nodes that are not reachable from the source will have a distance of infinity (INT_MAX).

    Example: If we run Dijkstra with source node = 1,
    final dist = 2147483647 0 2 6 3 5
    → dist[0] = 2147483647 means node 0 is not reachable from node 1, thus value is infinity
    → dist[1] = 0 because it's the source itself 
    */

    return 0;
}