#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int start, vector<vector<int>>& adj, int n) {
        vector<bool> visited(n, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " "; // process the node

            for (auto neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int n = 6; // number of nodes
    vector<vector<int>> adj(n);

    // example edges
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    Solution s;
    cout << "BFS Traversal starting from node 0: ";
    s.bfs(0, adj, n);
    return 0;
}
