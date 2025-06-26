/*
Cycle Detection in an Undirected Graph - (DFS)

- A cycle exists if you can start at a node and return to it by traversing edges, visiting at least one other node.
- In DFS, a cycle is found if you reach a visited node that is not the parent.
- Useful for checking if a graph is a tree or finding redundant connections.

Example: 
    0 - 1
    |   |
    3 - 2
    (Cycle: {0-1-2-3-0})
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

    // Checks for a cycle in an undirected graph using DFS
    bool dfsCycleDetection(int src, vector<bool>& vis, int par) {
    vis[src] = true; // Mark the current node as visited

        for (int v : adjList[src]) { // Traverse all neighbors
            if (!vis[v]) {
                // If neighbor is not visited, do DFS on it
                if (dfsCycleDetection(v, vis, src)) return true; // If cycle found in recursion, return true
            } else {
                // If neighbor is visited and not parent, cycle exists
                if (v != par) return true;
            }
        }
        return false; // No cycle found from this path
    }
};

int main(){
    int V = 6;
    Graph g(V);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0); // Cycle connection
    g.addEdge(3,5);

    vector<bool>vis(V,false);
    if (g.dfsCycleDetection(0,vis,-1)){
        cout << "Cycle Detected" << endl;
    }else{
        cout << "Cycle Undetected" << endl;
    }

    return 0;
}