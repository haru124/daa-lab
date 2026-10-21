#include <iostream>
using namespace std;

void graphColoring(int V, int graph[][6]) {

    //assign colour variable
    int color[V];
    color[0] = 0;
    for (int i = 1; i < V; i++)
        color[i] = -1;

    //assign available variable
    bool available[V];
    for (int clr = 0; clr < V; clr++)
        available[clr] = false;

    //assign available variable with unique colour
    for (int u = 1; u < V; u++) {
        for (int j = 0; j < V; j++) {
            if (graph[u][j] == 1 && color[j] != -1)
                available[color[j]] = true;
        }

        int clr;
        for (clr = 0; clr < V; clr++) {
            if (!available[clr]) {
                break;
            }
        }

        color[u] = clr;
    }

    cout << "The pattern of Graph coloring using the Greedy Algorithm" << endl;
    for (int u = 0; u < V; u++) {
        cout << "Vertex " << u << " --->  Color " << color[u] << endl;
    }
}

int main() {
    int V = 6; // number of vertices

    // Initialize the graph with adjacency matrix
    int Graph[][6] = {
        {0, 1, 0, 1, 1, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 1}
    };

    graphColoring(V, Graph);
    return 0;
}
