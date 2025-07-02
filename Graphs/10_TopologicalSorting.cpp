/*
Topological Sorting

- Topological sorting is the linear ordering of vertices in a Directed Acyclic Graph (DAG)
  such that for every directed edge u -> v, vertex u comes before v in the ordering.
- Only possible for DAGs (graphs with no cycles).

Key Points:
    1. Used to schedule tasks, resolve dependencies, and order compilation steps.
    2. Can be implemented using DFS (store nodes in stack after visiting all neighbors)
       or using Kahn's Algorithm (BFS with in-degree counting).

Example:
    For edges: 5->0, 4->0, 5->2, 2->3, 3->1, 4->1
    One possible topological order: 5 4 2 3 1 0

NOTE => Linear order of vertices such that for every u -› v, u comes before v in sequence.
*/

#include<iostream>
#include<vector>
#include<list>
#include<stack>
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

    // ----- TOPOLOGICAL SORTING DFS APPROACH-----
    void dfs(int src, vector<bool>& vis, stack<int>& s) {
        vis[src] = true; // mark the current node as visited

        for (int v : adjList[src]) { // explore all adjacent nodes
            if (!vis[v]) {
                dfs(v, vis, s); // recursively visit unvisited neighbors
            }
        }

        s.push(src); // push current node after visiting all dependencies
    }

    void print(stack<int>& s) {
        while (!s.empty()) {
            cout << s.top() << " "; // print top of the stack
            s.pop(); // remove the printed node
        }
        cout << endl;
    }

    void topoSort(int V) {
        vector<bool> vis(V, false); // keep track of visited nodes
        stack<int> s; // stack to store topological order

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, s); // run DFS for unvisited node
            }
        }

        print(s); // print nodes in topological order
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

    g.topoSort(V);
    return 0;
}