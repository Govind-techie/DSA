/*
Problem: hasPath (Check if a Path Exists in an Undirected Graph)

Given an undirected graph and two nodes (source and destination), 
determine if there exists a path between the source and destination nodes.

Input:
    - Number of vertices (V) and edges (E)
    - List of edges (each edge connects two vertices)
    - Source node (src)
    - Destination node (dest)

Output:
    - Return true if there is a path from src to dest, otherwise return false.

Example:
    Input:
        V = 5, E = 4
        Edges: (0-1), (0-2), (3-4), (2-3)
        src = 0, dest = 4
    Output:
        true

Explanation:
    There is a path from 0 -> 2 -> 3 -> 4.
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int V;
    vector<list<int>> adjList;

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printGraph() {
        for (int u = 0; u < V; ++u) {
            cout << u << " : ";
            for (int v : adjList[u]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool hasPath(int src, int dest, vector<bool>&vis){
        if (src == dest) return true;
        vis[src] = true;
        for (int v : adjList[src]){
            if (!vis[v]){
                if(hasPath(v,dest,vis)) return true;
            }
        }
        return false;
    }
};

int main(){

    int V = 7;
    Graph g (V);
    g.addEdge (0,1);
    g.addEdge (0,2);
    g.addEdge (1,3);
    g.addEdge (2,4);
    g.addEdge (3,4);
    g.addEdge (3,5);
    g.addEdge (4,5);
    g.addEdge (5,6);

    vector<bool>vis(V,false);
    int src = 0;
    int dest = 5;
    if (g.hasPath(src,dest,vis)){
        cout << "Path Exist" << endl;
    }else{
        cout << "Path doesn't exist" << endl;
    }
    return 0;
}