#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int destination,
         vector<vector<int>>& adj,
         vector<bool>& visited) {

    if (node == destination)
        return true;

    visited[node] = true;

    for (int next : adj[node]) {

        if (!visited[next]) {
            if (dfs(next, destination, adj, visited))
                return true;
        }
    }

    return false;
}

int main() {

    int n, e;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);

    cout << "Enter edges:\n";

    for (int i = 0; i < e; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source, destination;

    cout << "Enter source: ";
    cin >> source;

    cout << "Enter destination: ";
    cin >> destination;

    vector<bool> visited(n, false);

    if (dfs(source, destination, adj, visited))
        cout << "true";
    else
        cout << "false";

    return 0;
}
