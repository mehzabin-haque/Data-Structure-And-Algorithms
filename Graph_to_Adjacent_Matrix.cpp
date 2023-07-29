#include <iostream>
#include <vector>

using namespace std;

void printGraph(const vector<vector<int>>& graph) {
    for (const auto& row : graph) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    // Initialize the graph with all 0s (no edges initially)
    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (format: source destination):" << endl;
    int src, dest;
    for (int i = 0; i < edges; ++i) {
        cin >> src >> dest;
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            // For an undirected graph, set both src-dest and dest-src as 1
            graph[src][dest] = 1;
            graph[dest][src] = 1;
        } else {
            cout << "Invalid edge input! Edge ignored." << endl;
        }
    }

    cout << "\nAdjacency Matrix of the Graph:" << endl;
    printGraph(graph);

    return 0;
}
