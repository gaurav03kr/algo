#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Performs Topological Sorting on a Directed Acyclic Graph (DAG)
 *        using Kahn’s Algorithm (BFS-based approach).
 *
 * @details
 * Kahn’s Algorithm works by repeatedly removing nodes with in-degree 0
 * and reducing the in-degree of their neighbors.
 *
 * Time Complexity:  O(V + E)
 * Space Complexity: O(V)
 */

class Graph {
private:
    int V;                              // Number of vertices
    vector<vector<int>> adj;            // Adjacency list representation

public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add directed edge u -> v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Perform Kahn’s Algorithm
    vector<int> topologicalSort() {
        vector<int> indegree(V, 0);

        // Step 1: Compute in-degrees of all vertices
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        // Step 2: Push all vertices with indegree 0 into queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topoOrder;

        // Step 3: Process nodes with indegree 0
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            // Decrease indegree of neighbors
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Step 4: Check if topological sorting was possible (DAG check)
        if ((int)topoOrder.size() != V) {
            cerr << "Error: The graph is not a DAG (cycle detected)." << endl;
            return {};
        }

        return topoOrder;
    }
};

// ----------- DRIVER CODE -----------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);
    cout << "Enter " << E << " directed edges (u v):"<<endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<int> topo = g.topologicalSort();

    if (!topo.empty()) {
        cout << "Topological Order: ";
        for (int node : topo)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}

/*
---------------------------------------------------------------
🧪 SAMPLE INPUT
6 6
5 2
5 0
4 0
4 1
2 3
3 1

---------------------------------------------------------------
✅ SAMPLE OUTPUT
Topological Order: 4 5 0 2 3 1

(Other valid orders like 5 4 2 0 3 1 are also acceptable.)

---------------------------------------------------------------
🔍 EXPLANATION
Vertices: 6 (0 to 5)
Edges:
5 → 2, 5 → 0
4 → 0, 4 → 1
2 → 3, 3 → 1

This graph is a DAG, and the topological ordering represents
a valid sequence of task completion or dependency resolution.
---------------------------------------------------------------
*/
