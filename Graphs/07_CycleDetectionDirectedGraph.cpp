#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    vector<list<int>>adjList;
    int V;
public:
    Graph(int V){
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
    }

    bool cycleDetectionDirected(int src, vector<bool>& vis, vector<bool>& recPath) {
        vis[src] = true; // mark current node as visited
        recPath[src] = true; // add to current DFS path

        for (int v : adjList[src]) {
            if (!vis[v]) { // if neighbor not visited
                if (cycleDetectionDirected(v, vis, recPath)) return true; // check deeper
            } else if (recPath[v]) return true; // if neighbor is in current path, cycle found
        }

        recPath[src] = false; // backtrack, remove from current path
        return false; // no cycle from this node
    }

    bool dfsHelper(int V) {
        vector<bool> vis(V, false); // visited array
        vector<bool> recPath(V, false); // current path array

        for (int i = 0; i < V; i++) {
            if (!vis[i]) { // if node not visited
                if (cycleDetectionDirected(i, vis, recPath)) return true; // cycle found
            }
        }

        return false; // no cycle in any component
    }
};


int main(){
    int V = 4;
    Graph g(V);
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4); 
    g.addEdge(4,2); // BackEdge

    if (g.dfsHelper(4)){
        cout << "cycle exist\n";
    }else{
        cout << "cycle doesn't exist\n";
    }

    return 0;
}