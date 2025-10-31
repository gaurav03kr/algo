#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Bellman-Ford Algorithm
 * Finds the shortest distance from a single source to all vertices in a weighted graph.
 * Works even with negative weights (unlike Dijkstra), but detects negative weight cycles.
 *
 * Time Complexity: O(V * E)
 * Space Complexity: O(V)
 */

// Edge structure to represent directed weighted edges
struct Edge {
    int u, v;
    int weight;
};

class Graph {
private:
    int V; // number of vertices
    vector<Edge> edges; // list of edges

public:
    Graph(int vertices) : V(vertices) {}

    // Add an edge (u -> v) with a given weight
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    // Bellman-Ford algorithm
    void bellmanFord(int source) {
        vector<int> dist(V, INT_MAX);
        dist[source] = 0;

        // Step 1: Relax all edges |V| - 1 times
        for (int i = 1; i <= V - 1; i++) {
            for (auto &edge : edges) {
                int u = edge.u;
                int v = edge.v;
                int w = edge.weight;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Step 2: Check for negative weight cycles
        for (auto &edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                cout << "Graph contains a negative weight cycle!\n";
                return;
            }
        }

        // Step 3: Print the result
        cout << "Vertex\tDistance from Source (" << source << ")\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                cout << i << "\tINF\n";
            else
                cout << i << "\t" << dist[i] << "\n";
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter edges in format (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    g.bellmanFord(source);

    return 0;
}
