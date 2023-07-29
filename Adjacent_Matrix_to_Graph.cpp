#include <iostream>
#include <vector>

using namespace std;

void printGraph(const vector<vector<int>>& adjMatrix, int numVertices) {
    cout << "-------------------------------------------" << endl;
    cout << "\t\tGraph:" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
   
            if (adjMatrix[i][j] == 1) {
               
                cout << "\t\t( " << i + 1 << " --> " << j + 1 << " )" << endl;
            }
        }
    }
}

int main() {
    int numVertices;

    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;

    vector<vector<int>> adjMatrix(numVertices, vector<int>(numVertices, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> adjMatrix[i][j];
        }
    }

    printGraph(adjMatrix, numVertices);

    return 0;
}
