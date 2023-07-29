#include <iostream>
#include <vector>

using namespace std;

void dfsRecursive(vector<vector<int>>& adjList, vector<bool>& visited, int currentVertex) {
    visited[currentVertex] = true;
    cout << currentVertex << " --> ";

    for (int neighbor : adjList[currentVertex]) {
        if (!visited[neighbor]) {
            dfsRecursive(adjList, visited, neighbor);
        }
    }
}

void dfs(vector<vector<int>>& adjList, int startVertex) {
    int numVertices = adjList.size();
    vector<bool> visited(numVertices, false);

    dfsRecursive(adjList, visited, startVertex);
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<vector<int>> adjList(numVertices);

    cout << "Enter the edges (vertex1 vertex2):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1); // If the graph is undirected
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "DFS traversal starting from vertex " << startVertex << ": " << endl;

    cout << "The order of traversing the graph using DFS algorithm " << endl;
    cout << "\t  ";

    dfs(adjList, startVertex);

    return 0;
}
