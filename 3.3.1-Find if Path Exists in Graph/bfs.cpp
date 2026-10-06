#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

    vector<vector<int>> adj(n);

    // Create adjacency list
    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    if (source == destination)
        return true;

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        for (int next : adj[node]) {

            if (next == destination)
                return true;

            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
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

    vector<vector<int>> edges(e, vector<int>(2));

    cout << "Enter edges:\n";

    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int source, destination;

    cout << "Enter source: ";
    cin >> source;

    cout << "Enter destination: ";
    cin >> destination;

    if (validPath(n, edges, source, destination))
        cout << "true";
    else
        cout << "false";

    return 0;
}
