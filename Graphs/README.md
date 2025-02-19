# Graph Data Structure in C++

## Overview
This project implements a **Graph Data Structure** in C++ using an **Adjacency List**. It supports **graph creation**, **BFS traversal**, **DFS traversal**, and **edge management**.

## Features
- **Graph Representation**: Uses an adjacency list for efficient storage.
- **Add Edge**: Connects two vertices in an **undirected graph**.
- **Display Graph**: Prints the adjacency list of the graph.
- **BFS Traversal**: Implements Breadth-First Search for level-order exploration.
- **DFS Traversal**: Implements Depth-First Search for deep exploration.

## Core Code
```cpp
class Graph {
private:
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void display() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor])
                DFSUtil(neighbor, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};
```
## Use Cases
- **Graph Representation**: Stores connections between entities.
- **Pathfinding**: BFS and DFS are useful for route finding algorithms.
- **Social Networks**: Can be used to model friendship networks.
- **AI and Games**: Used in game maps, AI pathfinding.
  
## How to Run
1. Copy the source code into a .cpp file.
2. Compile using a C++ compiler:
   ```
   g++ -o graph graph.cpp
   ```
3. Run the executable:
   ```
   ./graph
   ```

## Example Output
```
Graph Representation:
Vertex 0 -> 1 4 
Vertex 1 -> 0 2 3 4 
Vertex 2 -> 1 3 
Vertex 3 -> 1 2 4 
Vertex 4 -> 0 1 3 
BFS Traversal: 0 1 4 2 3 
DFS Traversal: 0 1 2 3 4 
```

