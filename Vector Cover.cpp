#include<iostream>
using namespace std;

#define V 6

void printVertexCover(int Graph[][V], int vertices) {
    bool visited[V] = {false};  // Initialize all vertices as unvisited

    // Iterate through each vertex
    for (int u = 0; u < vertices; u++) {
        if (!visited[u]) {
            // Find an adjacent unvisited vertex
            for (int v = 0; v < vertices; v++) {
                if (Graph[u][v] == 1 && !visited[v]) {
                    visited[v] = true;  // Mark only the adjacent vertex as visited
                    break;
                }
            }
        }
    }

    // Print the Vertex Cover
    cout << "Vertex Cover: ";
    for (int i = 0; i < vertices; i++) {
        if (visited[i])
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    int vertices = 6;
    int Graph[][6] = {
        {0, 1, 0, 1, 1, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 1}
    };

    printVertexCover(Graph, vertices);

    return 0;
}
