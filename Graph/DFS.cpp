#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V; // number of vertices
    vector<vector<int>> adj; // adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    void dfsUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " "; // process node

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfsUtil(neigh, visited);
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(V, false);
        dfsUtil(start, visited);
    }
};

int main() {
    Graph g(5); // 5 vertices (0..4)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "DFS starting from node 0: ";
    g.dfs(0);
    return 0;
}
