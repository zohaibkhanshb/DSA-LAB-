#include <iostream>
#include <stack>
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
                adjMatrix[i][j] = 0; 
            }
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1; 
        adjMatrix[v][u] = 1; 
    }

    void dfsTraversal(int startVertex) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false; 
        }

        stack<int> s;
        s.push(startVertex);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";

                for (int i = vertices - 1; i >= 0; i--) { 
                    if (adjMatrix[current][i] == 1 && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }
        cout << endl;

        delete[] visited;
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
    graph.dfsTraversal(0);
    return 0;
}
