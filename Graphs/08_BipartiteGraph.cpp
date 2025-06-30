/*
Bipartite Graph

- A bipartite graph is a graph whose vertices can be divided into two disjoint sets
  such that every edge connects a vertex from one set to a vertex from the other set.
- No two vertices within the same set are adjacent.
- Bipartite graphs do not contain any odd-length cycles.

Key Points:
    1. Can be checked using BFS or DFS by trying to color the graph using two colors.
    2. If a conflict in coloring occurs (a neighbor has the same color), the graph is not bipartite.
    3. Used in matching problems, scheduling, and network flows.

Example:
    Set 1: {0, 2}
    Set 2: {1, 3}
    Edges: (0-1), (0-3), (2-1), (2-3)
    This graph is bipartite as we can color it using two colors without any conflicts.
    0 and 2 can be one color (say, red), and 1 and 3 can be another color (say, blue).
    No two adjacent vertices share the same color, satisfying the bipartite condition.
*/

#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
        adjList[v].push_back(u);
    }

    bool isBipartite(int src, vector<bool>&vis, vector<int>&color, queue<int>&q){
        vis[src] = true;
        q.push(src);
        color[src] = 0;

        while (!q.empty()){
            int u = q.front();
            q.pop();
            for (int v : adjList[u]){
                if (!vis[v]){
                    vis[v] = true;
                    q.push(v);
                    if (color[u] == -1){
                        color[v] = 1 - color[u];
                    }
                }else{
                    if (color[u] == color[v]) return false;
                }
            }
        }
        return true;
    }

    bool helper(int V){
        vector<bool>vis(V,false);
        vector<int>color(V,-1);
        queue<int>q;
        if (isBipartite(0,vis,color,q)) return true;
        return false;
    }
};

int main(){
    int V = 3;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 3);

    if (g.helper(V)){
        cout << "Bipartite Graph\n";
    }else{
        cout << "NOT Bipartite Graph\n";
    }
    return 0;
}