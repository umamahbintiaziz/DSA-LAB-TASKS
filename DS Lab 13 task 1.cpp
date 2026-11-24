#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<pair<int, int>> adj[10];

public:
    Graph(int v) {
        V = v;
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
    }

    void display() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto edge : adj[i]) {
                cout << "(" << edge.first << ", "
                     << edge.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 7);

    g.display();

    return 0;
}
