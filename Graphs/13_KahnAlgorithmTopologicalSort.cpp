/*
Kahn's Algorithm for Topological Sorting (BFS Approach)

- Kahn's Algorithm is used to find a topological order of vertices in a Directed Acyclic Graph (DAG).
- It uses in-degree (number of incoming edges) for each node and a queue to process nodes with in-degree 0.

Key Steps:
    1. Compute in-degree for each vertex.
    2. Add all vertices with in-degree 0 to a queue.
    3. While the queue is not empty:
        a. Remove a vertex from the queue and add it to the topological order.
        b. For each neighbor, decrease its in-degree by 1.
        c. If a neighbor's in-degree becomes 0, add it to the queue.
    4. If all vertices are processed, a valid topological order exists.
       If not, the graph contains a cycle.

Example:
    For edges: 5->0, 4->0, 5->2, 2->3, 3->1, 4->1
    One possible topological order: 4 5 0 2 3 1

IMP PROPERTY: A DAG has atleast one vertex with in-degree 0 & atleast one vertex with out-degree 0.
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
    }

    void dfs(int src, vector<bool>& vis, vector<int>& indegree) {
        vis[src] = true;
        for (int v : adjList[src]) {
            indegree[v]++; // Increase in-degree for every neighbor (edge from src → v)
            if (!vis[v]) {
                dfs(v, vis, indegree); // Continue DFS traversal
            }
        }
    }

    // Function to compute in-degree of each node using DFS
    vector<int> inDegree(int V) {
        vector<int> indegree(V, 0);   // Stores in-degree for each node
        vector<bool> vis(V, false);   // Keeps track of visited nodes
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, indegree); // Run DFS on unvisited node
            }
        }
        return indegree; // Return the final in-degree array
    }

    // Function to perform Topological Sort using Kahn's Algorithm (BFS)
    void topoSort() {
        vector<int> indegree = inDegree(V); // Step 1: Get in-degree of each node
        queue<int> q;

        // Step 2: Push all nodes with in-degree 0 into the queue (i.e., no dependencies)
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Process the nodes in BFS manner
        while (!q.empty()) {
            int curr = q.front(); // Get the node at front of queue
            q.pop();
            cout << curr << " ";  // Print the node in topological order

            // Step 4: Reduce in-degree of all neighbors of current node
            for (int v : adjList[curr]) {
                indegree[v]--;            // One dependency is now processed
                if (indegree[v] == 0) {   // If no dependencies left, push into queue
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main(){
    int V = 6;
    Graph g(V);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.addEdge(4,0);

    g.topoSort();

    return 0;
}