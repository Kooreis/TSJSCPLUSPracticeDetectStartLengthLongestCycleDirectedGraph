```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<int>* adj;
    vector<int> cycle;
    int maxCycleLength;
    int maxCycleStart;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v, bool visited[], bool* rs, int* parent);
    void findLongestCycle();
    void printLongestCycle();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
    maxCycleLength = 0;
    maxCycleStart = -1;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS(int v, bool visited[], bool* recStack, int* parent) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < adj[v].size(); ++i) {
        int w = adj[v][i];
        if (!visited[w]) {
            parent[w] = v;
            DFS(w, visited, recStack, parent);
        }
        else if (recStack[w]) {
            vector<int> tempCycle;
            tempCycle.push_back(w);
            for (int i = v; i != w; i = parent[i]) {
                tempCycle.push_back(i);
            }
            tempCycle.push_back(w);
            if (tempCycle.size() > maxCycleLength) {
                maxCycleLength = tempCycle.size();
                maxCycleStart = w;
                cycle = tempCycle;
            }
        }
    }

    recStack[v] = false;
}

void Graph::findLongestCycle() {
    bool* visited = new bool[V];
    bool* recStack = new bool[V];
    int* parent = new int[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
        parent[i] = -1;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, visited, recStack, parent);
        }
    }
}

void Graph::printLongestCycle() {
    if (maxCycleStart == -1) {
        cout << "No cycle found." << endl;
    }
    else {
        cout << "Longest cycle length: " << maxCycleLength - 1 << endl;
        cout << "Longest cycle start: " << maxCycleStart << endl;
        cout << "Cycle: ";
        for (int i = cycle.size() - 1; i >= 0; i--) {
            cout << cycle[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.findLongestCycle();
    g.printLongestCycle();

    return 0;
}
```