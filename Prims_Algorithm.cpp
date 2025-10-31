#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // undirected graph
    }

    vector<int> key(n, INT_MAX);   // minimum edge weight to connect each vertex
    vector<bool> mst(n, false);    // track included vertices
    vector<int> parent(n, -1);     // store MST parent
    key[0] = 0; 
    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        // pick the minimum key vertex not in MST
        for (int v = 0; v < n; v++) {
            if (!mst[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }
        mst[u] = true;
        // update key values of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "  (" << graph[i][parent[i]] << ")\n";
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total Weight = " << totalWeight << "\n";
}
