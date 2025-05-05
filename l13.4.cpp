#include <iostream>
#include <queue>
using namespace std;

class Graph {
private:
    int vertices;
    int** adjMatrix;

public:
    Graph(int v) {
        vertices = v;
        adjMatrix = new int*[v];
        for (int i = 0; i < v; i++) {
            adjMatrix[i] = new int[v];
            for (int j = 0; j < v; j++) {
                adjMatrix[i][j] = 0; // Initialize adjacency matrix
            }
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1; // For undirected graph
        adjMatrix[v][u] = 1; // For undirected graph
    }

    void bfsTraversal(int startVertex) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false; // Initialize visited array
        }

        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;

        delete[] visited; // Clean up
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.bfsTraversal(0); // Output: 0 1 2 3 4
    return 0;
}
