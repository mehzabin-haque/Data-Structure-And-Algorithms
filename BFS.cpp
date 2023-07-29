#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& adjList, int startVertex) {
    int numVertices = adjList.size();
    vector<bool> visited(numVertices, false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        
        int currentVertex = q.front();
        
        q.pop();
        cout << currentVertex << " --> ";

        for (int neighbor : adjList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
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
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS traversal starting from vertex " << startVertex << ": " << endl;
    
    cout << "The order of traversing the graph using BFS algorithm " << endl;
    cout << "\t  ";
    bfs(adjList, startVertex);

    return 0;
}
