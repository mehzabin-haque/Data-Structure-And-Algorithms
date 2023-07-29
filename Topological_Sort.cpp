#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsTopoSort(vector<vector<int>>& adjList, vector<bool>& visited, int currentVertex, stack<int>& topoStack) {
    visited[currentVertex] = true;

    for (int neighbor : adjList[currentVertex]) {
        if (!visited[neighbor]) {
            dfsTopoSort(adjList, visited, neighbor, topoStack);
        }
    }

    topoStack.push(currentVertex);
}

vector<int> topologicalSort(vector<vector<int>>& adjList, int numVertices) {
    vector<int> result;
    stack<int> topoStack;
    vector<bool> visited(numVertices, false);

    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            dfsTopoSort(adjList, visited, i, topoStack);
        }
    }

    while (!topoStack.empty()) {
        result.push_back(topoStack.top());
        topoStack.pop();
    }

    return result;
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
    }

    vector<int> topoOrder = topologicalSort(adjList, numVertices);

    cout << "Topological Sort: ";
    for (int vertex : topoOrder) {
        cout << vertex << " --> ";
    }
    cout << endl;

    return 0;
}
