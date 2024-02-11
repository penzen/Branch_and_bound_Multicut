
#include <iostream>
#include <vector>
#include <algorithm>
/*
class Graph {
private:
    int V; // Number of vertices
    std::vector<std::vector<int>> adjList; // Adjacency list representation

public:
    // Constructor to initialize the graph with 'V' vertices
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // Function to add an edge between two vertices
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // For undirected graph, add edge both ways
    }

    // Function to print the adjacency list representation of the graph
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            std::cout << "Adjacency list of vertex " << v << ":\n";
            std::cout << "Head";
            for (int i : adjList[v]) {
                std::cout << " -> " << i;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the graph
    graph.printGraph();

    return 0;
}
*/
// C++ program to print connected components in
// an undirected graph
#include <bits/stdc++.h>
using namespace std;
 
// Graph class represents a undirected graph
// using adjacency list representation
class Graph {
    int V; // No. of vertices
 
    // Pointer to an array containing adjacency lists
    list<int>* adj;
 
    // A function used by DFS
    void DFSUtil(int v, bool visited[]);
 
public:
    Graph(int V); // Constructor
    ~Graph();
    void addEdge(int v, int w);
    void connectedComponents();
};
 
// Method to print connected components in an
// undirected graph
void Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            // print all reachable vertices
            // from v
            DFSUtil(v, visited);
 
            cout << "\n";
        }
    }
    delete[] visited;
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
Graph::~Graph() { delete[] adj; }
 
// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
/*
// Create a graph given in the above diagram
    Graph g(5); // 5 vertices numbered from 0 to 4
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
 
    cout << "Following are connected components \n";
    g.connectedComponents();
*/
 
// Driver code
int main()
{

    
    
    int target = 4;

    // Using the vector's find() method (C++20 and later)
    

    
    vector<int> numbers = {1, 4, 2, 8, 5};
    auto it = std::find(numbers.begin(), numbers.end(), 5);  // Find the value 5

    if (it != numbers.end()) {
        std::cout << "Found 5 at index: " << std::distance(numbers.begin(), it) << std::endl;
    } else {
        std::cout << "Value 5 not found." << std::endl;
    }
    
    
    return 0;
}



 


